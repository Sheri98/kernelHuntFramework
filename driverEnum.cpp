#define _CRT_SECURE_NO_WARNINGS

#include "Header.h"

inline void MyRtlInitUnicodeString(PUNICODE_STRING DestinationString, PCWSTR SourceString)
{
    if (SourceString) {
        DestinationString->Length = (USHORT)wcslen(SourceString) * sizeof(WCHAR);
        DestinationString->MaximumLength = DestinationString->Length + sizeof(WCHAR);
    }
    else {
        DestinationString->Length = 0;
        DestinationString->MaximumLength = 0;
    }
    DestinationString->Buffer = (PWSTR)SourceString;
}

vector<wstring> EnumerateDeviceObjects()
{
    vector<wstring> devices;

    // Load NT functions from ntdll.dll
    HMODULE hNtdll = GetModuleHandleW(L"ntdll.dll");
    auto NtOpenDirectoryObject = (NtOpenDirectoryObject_t)GetProcAddress(hNtdll, "NtOpenDirectoryObject");
    auto NtQueryDirectoryObject = (NtQueryDirectoryObject_t)GetProcAddress(hNtdll, "NtQueryDirectoryObject");

    if (!NtOpenDirectoryObject || !NtQueryDirectoryObject) {
        println("[-] Failed to resolve NtOpenDirectoryObject/NtQueryDirectoryObject");
        return devices;
    }

    // Prepare to open \Device directory
    UNICODE_STRING dirName;
    MyRtlInitUnicodeString(&dirName, L"\\Device");

    OBJECT_ATTRIBUTES oa;
    InitializeObjectAttributes(&oa, &dirName, OBJ_CASE_INSENSITIVE, NULL, NULL);

    HANDLE hDir = nullptr;
    NTSTATUS status = NtOpenDirectoryObject(&hDir, DIRECTORY_QUERY, &oa);
    if (status != 0 || hDir == nullptr) {
        println("[-] NtOpenDirectoryObject failed: 0x%X", status);
        return devices;
    }

    BYTE buffer[8192];
    ULONG context = 0;
    ULONG retLength = 0;

    while (true) {
        status = NtQueryDirectoryObject(
            hDir,
            buffer,
            sizeof(buffer),
            TRUE,    // ReturnSingleEntry
            FALSE,   // RestartScan
            &context,
            &retLength
        );

        if (status != 0) { // STATUS_NO_MORE_ENTRIES or error
            break;
        }

        auto entry = (OBJECT_DIRECTORY_INFORMATION*)buffer;

        if (entry->Name.Buffer && entry->TypeName.Buffer) {
            wstring type(entry->TypeName.Buffer, entry->TypeName.Length / sizeof(WCHAR));
            if (type == L"Device" || type == L"SymbolicLink") {
                wstring name(entry->Name.Buffer, entry->Name.Length / sizeof(WCHAR));
                devices.push_back(name);
            }
        }
    }

    CloseHandle(hDir);
    return devices;
}


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
                tpDrivers.push_back(_wcsdup(sqBuffer->lpBinaryPathName ));
            }
        }
    }
    return tpDrivers;


}
wstring GetBaseDriverName(const wstring& path)
{

    size_t slash = path.find_last_of(L"\\/");
    wstring name = (slash == wstring::npos) ? path : path.substr(slash + 1);

    
    if (name.length() > 4) {
        wstring lower = name;
        transform(lower.begin(), lower.end(), lower.begin(), ::towlower);
        if (lower.rfind(L".sys") == lower.length() - 4) {
            name = name.substr(0, name.length() - 4);
        }
    }

    return name;
}

void driverEnum() {
    println("[+] Enumerating Drivers");
    vector<LPWSTR> tpDrivers = driverTest();
    auto devices = EnumerateDeviceObjects();

    // Configuration - use current working directory
    char currentDir[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH, currentDir);
    string outputDir = string(currentDir);
    string jsonFilePath = outputDir + "\\driver.json";

    json j;
    j["drivers"] = json::array();

    for (auto driverPath : tpDrivers) {
        wstring base = GetBaseDriverName(driverPath);
        wprintf(L"\n[+] BaseName: %ls\n", base.c_str());

        // Convert LPWSTR to wstring
        wstring wpath(driverPath);

        // REMOVE \\??\ prefix
        if (wpath.find(L"\\??\\") == 0) {
            wpath = wpath.substr(4);  // Skip first 4 characters
        }

        // Convert wstring to string for JSON
        string cleanPath(wpath.begin(), wpath.end());

        // Add cleaned path to JSON
        j["drivers"].push_back(cleanPath);

        // Find symbolic links
        bool found = false;
        for (auto& dev : devices) {
            if (dev.find(base) != std::wstring::npos) {
                wprintf(L"\t[+] Symbolic Link: \\\\.\\%ls\n", dev.c_str());
                found = true;
            }
        }

        if (!found) {
            wprintf(L"\tNo obvious device name match found.\n");
        }
    }

    // Write JSON ONCE at the end, to the specific directory
    ofstream file(jsonFilePath);
    if (file.is_open()) {
        file << j.dump(4);  // Pretty print with 4 spaces
        file.close();
        cout << "\n[+] Driver list saved to: " << jsonFilePath << endl;
        cout << "[+] Total drivers: " << tpDrivers.size() << endl;
    }
    else {
        cerr << "[!] Failed to create driver.json at: " << jsonFilePath << endl;
    }
}

void enumerateAllDrivers() {
    println("[+] Enumerating ALL System32 Drivers (Including Microsoft)");

    SC_HANDLE scHandle = OpenSCManager(nullptr, nullptr, SC_MANAGER_ENUMERATE_SERVICE);
    if (!scHandle) {
        println("[-] Service Handle Not Opened");
        return;
    }

    DWORD retBytes = 0;
    DWORD servicesRet = 0;
    DWORD resumeHandle = 0;

    // First call to get buffer size
    EnumServicesStatusEx(scHandle, SC_ENUM_PROCESS_INFO, SERVICE_DRIVER, SERVICE_STATE_ALL,
        NULL, 0, &retBytes, &servicesRet, &resumeHandle, NULL);

    LPBYTE newBuffer = (LPBYTE)malloc(retBytes);
    if (!newBuffer) {
        println("[-] Memory allocation failed");
        CloseServiceHandle(scHandle);
        return;
    }

    // Second call to get actual data
    if (!EnumServicesStatusEx(scHandle, SC_ENUM_PROCESS_INFO, SERVICE_DRIVER, SERVICE_STATE_ALL,
        newBuffer, retBytes, &retBytes, &servicesRet, &resumeHandle, NULL)) {
        println("[-] EnumServicesStatusEx failed");
        free(newBuffer);
        CloseServiceHandle(scHandle);
        return;
    }

    ENUM_SERVICE_STATUS_PROCESS* services = (ENUM_SERVICE_STATUS_PROCESS*)newBuffer;

    // Get current directory for output
    char currentDir[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH, currentDir);
    string outputDir = string(currentDir);
    string jsonFilePath = outputDir + "\\all_drivers.json";

    json j;
    j["total_drivers"] = 0;
    j["active_drivers"] = 0;
    j["inactive_drivers"] = 0;
    j["microsoft_drivers"] = 0;
    j["third_party_drivers"] = 0;
    j["drivers"] = json::array();

    auto devices = EnumerateDeviceObjects();

    int totalCount = 0;
    int activeCount = 0;
    int inactiveCount = 0;
    int microsoftCount = 0;
    int thirdPartyCount = 0;

    for (int i = 0; i < servicesRet; i++) {
        SC_HANDLE serOpenHandle = OpenService(scHandle, services[i].lpServiceName, SERVICE_QUERY_CONFIG);
        if (!serOpenHandle) {
            continue;
        }

        DWORD sretBytes = 0;
        QueryServiceConfig(serOpenHandle, NULL, 0, &sretBytes);

        LPQUERY_SERVICE_CONFIG sqBuffer = (LPQUERY_SERVICE_CONFIG)malloc(sretBytes);
        if (!sqBuffer) {
            CloseServiceHandle(serOpenHandle);
            continue;
        }

        if (!QueryServiceConfig(serOpenHandle, sqBuffer, sretBytes, &sretBytes)) {
            free(sqBuffer);
            CloseServiceHandle(serOpenHandle);
            continue;
        }

        // Get driver path
        wstring wpath(sqBuffer->lpBinaryPathName);

        // Remove \??\ prefix if present
        if (wpath.find(L"\\??\\") == 0) {
            wpath = wpath.substr(4);
        }

        // Convert to string for JSON
        string driverPath(wpath.begin(), wpath.end());

        // Get base name
        wstring base = GetBaseDriverName(sqBuffer->lpBinaryPathName);

        // Check if third-party or Microsoft
        BOOL isThirdParty = IsThirdPartyDriver(sqBuffer->lpBinaryPathName);

        // Determine status
        bool isActive = (services[i].ServiceStatusProcess.dwCurrentState == SERVICE_RUNNING);

        // Create JSON entry
        json driverEntry;
        driverEntry["name"] = string(base.begin(), base.end());
        driverEntry["path"] = driverPath;
        driverEntry["service_name"] = WideCharToMultiByte(CP_UTF8, 0, services[i].lpServiceName, -1, NULL, 0, NULL, NULL) > 0 ?
            [&]() {
                int size = WideCharToMultiByte(CP_UTF8, 0, services[i].lpServiceName, -1, NULL, 0, NULL, NULL);
                string result(size, 0);
                WideCharToMultiByte(CP_UTF8, 0, services[i].lpServiceName, -1, &result[0], size, NULL, NULL);
                return result;
            }() : "unknown";
        driverEntry["status"] = isActive ? "ACTIVE" : "INACTIVE";
        driverEntry["type"] = isThirdParty ? "Third-Party" : "Microsoft";

        // Find symbolic links
        vector<string> symbolicLinks;
        for (auto& dev : devices) {
            if (dev.find(base) != std::wstring::npos) {
                string linkName(dev.begin(), dev.end());
                symbolicLinks.push_back("\\\\.\\"+linkName);
            }
        }
        driverEntry["symbolic_links"] = symbolicLinks;

        j["drivers"].push_back(driverEntry);

        // Update counts
        totalCount++;
        if (isActive) activeCount++;
        else inactiveCount++;
        if (isThirdParty) thirdPartyCount++;
        else microsoftCount++;

        // Console output
        wprintf(L"\n[%d] %ls\n", totalCount, base.c_str());
        wprintf(L"    Path: %ls\n", wpath.c_str());
        wprintf(L"    Status: %s\n", isActive ? L"ACTIVE" : L"INACTIVE");
        wprintf(L"    Type: %s\n", isThirdParty ? L"Third-Party" : L"Microsoft");
        if (!symbolicLinks.empty()) {
            wprintf(L"    Device: %S\n", symbolicLinks[0].c_str());
        }

        free(sqBuffer);
        CloseServiceHandle(serOpenHandle);
    }

    // Update summary
    j["total_drivers"] = totalCount;
    j["active_drivers"] = activeCount;
    j["inactive_drivers"] = inactiveCount;
    j["microsoft_drivers"] = microsoftCount;
    j["third_party_drivers"] = thirdPartyCount;

    // Write JSON
    ofstream file(jsonFilePath);
    if (file.is_open()) {
        file << j.dump(4);
        file.close();

        cout << "\n\n" << string(80, '=') << endl;
        cout << "ENUMERATION COMPLETE" << endl;
        cout << string(80, '=') << endl;
        cout << "\n[+] Results saved to: " << jsonFilePath << endl;
        cout << "\nSUMMARY:" << endl;
        cout << "  Total Drivers:      " << totalCount << endl;
        cout << "  Active Drivers:     " << activeCount << endl;
        cout << "  Inactive Drivers:   " << inactiveCount << endl;
        cout << "  Microsoft Drivers:  " << microsoftCount << endl;
        cout << "  Third-Party Drivers:" << thirdPartyCount << endl;
        cout << "\n[+] Use this file for comprehensive batch analysis" << endl;
        cout << string(80, '=') << "\n" << endl;
    }
    else {
        cerr << "[!] Failed to create all_drivers.json at: " << jsonFilePath << endl;
    }

    free(newBuffer);
    CloseServiceHandle(scHandle);
}