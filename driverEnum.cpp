#include "../kernelHuntFramework/Header.h"


BOOL IsThirdPartyDriver(LPCWSTR filePath)
{
    GUID policyGUID = WINTRUST_ACTION_GENERIC_VERIFY_V2;

    WINTRUST_FILE_INFO fileInfo = { 0 };
    fileInfo.cbStruct = sizeof(fileInfo);
    fileInfo.pcwszFilePath = filePath;

    WINTRUST_DATA wintrustData = { 0 };
    wintrustData.cbStruct = sizeof(wintrustData);
    wintrustData.dwUIChoice = WTD_UI_NONE;
    wintrustData.fdwRevocationChecks = WTD_REVOKE_NONE;
    wintrustData.dwUnionChoice = WTD_CHOICE_FILE;
    wintrustData.pFile = &fileInfo;
    wintrustData.dwStateAction = WTD_STATEACTION_VERIFY;
    wintrustData.dwProvFlags = WTD_CACHE_ONLY_URL_RETRIEVAL;

    LONG status = WinVerifyTrust(NULL, &policyGUID, &wintrustData);

    if (status != ERROR_SUCCESS) {
        // Unsigned or untrusted → not third party (skip)
        return FALSE;
    }

    // Extract signer certificate
    HCERTSTORE hStore = NULL;
    HCRYPTMSG hMsg = NULL;
    DWORD encoding, contentType, formatType;

    if (!CryptQueryObject(CERT_QUERY_OBJECT_FILE,
        filePath,
        CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED_EMBED,
        CERT_QUERY_FORMAT_FLAG_BINARY,
        0,
        &encoding,
        &contentType,
        &formatType,
        &hStore,
        &hMsg,
        NULL)) {
        return FALSE;
    }

    DWORD dwSignerInfo = 0;
    if (!CryptMsgGetParam(hMsg, CMSG_SIGNER_INFO_PARAM, 0, NULL, &dwSignerInfo)) {
        CertCloseStore(hStore, 0);
        CryptMsgClose(hMsg);
        return FALSE;
    }

    BYTE* pbSignerInfo = (BYTE*)malloc(dwSignerInfo);
    if (!pbSignerInfo) {
        CertCloseStore(hStore, 0);
        CryptMsgClose(hMsg);
        return FALSE;
    }

    if (!CryptMsgGetParam(hMsg, CMSG_SIGNER_INFO_PARAM, 0, pbSignerInfo, &dwSignerInfo)) {
        free(pbSignerInfo);
        CertCloseStore(hStore, 0);
        CryptMsgClose(hMsg);
        return FALSE;
    }

    CMSG_SIGNER_INFO* pSignerInfo = (CMSG_SIGNER_INFO*)pbSignerInfo;

    CERT_INFO certInfo = { 0 };
    certInfo.Issuer = pSignerInfo->Issuer;
    certInfo.SerialNumber = pSignerInfo->SerialNumber;

    PCCERT_CONTEXT pCertContext = CertFindCertificateInStore(
        hStore,
        X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
        0,
        CERT_FIND_SUBJECT_CERT,
        (PVOID)&certInfo,
        NULL);

    BOOL result = FALSE;

    if (pCertContext) {
        WCHAR name[256];
        if (CertGetNameStringW(pCertContext,
            CERT_NAME_SIMPLE_DISPLAY_TYPE,
            0,
            NULL,
            name,
            ARRAYSIZE(name)) > 1) {
            // Check publisher
            if (wcsstr(name, L"Microsoft") == NULL) {
                result = TRUE; // signed but NOT Microsoft → third party
            }
        }
        CertFreeCertificateContext(pCertContext);
    }

    // Cleanup
    free(pbSignerInfo);
    CertCloseStore(hStore, 0);
    CryptMsgClose(hMsg);

    wintrustData.dwStateAction = WTD_STATEACTION_CLOSE;
    WinVerifyTrust(NULL, &policyGUID, &wintrustData);

    return result;
}
vector<LPWSTR> driverTest() {
    vector<LPWSTR> tpDrivers;
    SC_HANDLE scHandle;
    
    scHandle = OpenSCManager(nullptr, nullptr, SC_MANAGER_ENUMERATE_SERVICE);
    if (!scHandle) {
        println("[-] Service Handle Not Opened");
    }
    DWORD retBytes = 0;
    DWORD servicesRet = 0;
    DWORD resumeHandle = 0;
    EnumServicesStatusEx(scHandle, SC_ENUM_PROCESS_INFO, SERVICE_DRIVER, SERVICE_ACTIVE
        , NULL, 0, &retBytes, &servicesRet, &resumeHandle, NULL);

    LPBYTE newBuffer = (LPBYTE)malloc(retBytes);

    if (EnumServicesStatusEx(scHandle, SC_ENUM_PROCESS_INFO, SERVICE_DRIVER, SERVICE_ACTIVE
        , newBuffer, retBytes, &retBytes, &servicesRet, &resumeHandle, NULL)) {
        ENUM_SERVICE_STATUS_PROCESS* services = (ENUM_SERVICE_STATUS_PROCESS*)newBuffer;

        for (int i = 0; i < servicesRet; i++) {
            SC_HANDLE serOpenHandle = OpenService(scHandle, services[i].lpServiceName, SERVICE_QUERY_CONFIG);
            DWORD buffSize = 0;
            DWORD sretBytes = 0;
            QueryServiceConfig(serOpenHandle, NULL, 0, &sretBytes);
            LPQUERY_SERVICE_CONFIG  sqBuffer = (LPQUERY_SERVICE_CONFIG)malloc(sretBytes);
            QueryServiceConfig(serOpenHandle, sqBuffer, sretBytes, &sretBytes);
            if (IsThirdPartyDriver(sqBuffer->lpBinaryPathName)) {
                tpDrivers.push_back(services[i].lpServiceName);
            }
        }
    }
    return tpDrivers;


}


void driverEnum() {
    println("[+] Enumerating Drivers");
    vector<LPWSTR> tpDrivers = driverTest();
    for (auto driver : tpDrivers) {
        wchar_t deviceBuffer[65535];
        QueryDosDeviceW(driver, deviceBuffer, sizeof(deviceBuffer));
        printf("Driver = % ls || Dos Device Path = %ls || Symbolic Name =  \\\\.\\%ls\n", driver,deviceBuffer,driver);
    }


}