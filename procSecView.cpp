#include "Header.h"

int pidSDChecker(DWORD pID)
{
	if (pID) {
		procEnum(pID);
	}
	else
	{

		procEnum(GetCurrentProcessId());
	}
	return 0;
}



void procEnum(DWORD pID)
{
	HANDLE procHandle = OpenProcess(READ_CONTROL | PROCESS_QUERY_INFORMATION, FALSE, pID);

	privEnum(procHandle);
	getPermission(procHandle);
	checkIntegrityLevel(procHandle);

}
void privEnum(HANDLE procHandle) {
	HANDLE tokHandle;
	if (OpenProcessToken(procHandle, TOKEN_QUERY, &tokHandle)) {
		DWORD rol;
		GetTokenInformation(tokHandle, TokenPrivileges, nullptr, 0, &rol);

		PTOKEN_PRIVILEGES tp = (PTOKEN_PRIVILEGES)malloc(rol);

		GetTokenInformation(tokHandle, TokenPrivileges, tp, rol, &rol);
		printf("[+] Privileges\n");
		for (int i = 0; i < tp->PrivilegeCount; i++) {
			WCHAR privName[256];
			DWORD privSize = _countof(privName);
			LookupPrivilegeName(NULL, &tp->Privileges[i].Luid, privName, &privSize);
			printf("\t %ws\n", privName);
		}


	}
	else {

		printf("%u", GetLastError());
	}
}


void getPermission(HANDLE procHandle) {
	PSECURITY_DESCRIPTOR pSD = NULL;
	DWORD size = 0;
	GetKernelObjectSecurity(procHandle, DACL_SECURITY_INFORMATION, NULL, 0, &size);
	pSD = (PSECURITY_DESCRIPTOR)malloc(size);
	if (!GetKernelObjectSecurity(procHandle, DACL_SECURITY_INFORMATION, pSD, size, &size)) {
		printf("[-] GetKernelObjectSecurity failed: %lu\n", GetLastError());
		free(pSD);
		return;
	}

	BOOL daclPresent = FALSE;
	BOOL daclDefaulted = FALSE;
	PACL pDacl = NULL;

	if (!GetSecurityDescriptorDacl(pSD, &daclPresent, &pDacl, &daclDefaulted)) {
		printf("[-] GetSecurityDescriptorDacl failed: %lu\n", GetLastError());
		free(pSD);
		return;
	}

	if (!daclPresent || pDacl == NULL) {
		printf("[!] No DACL present on the process.\n");
		free(pSD);
		return;
	}

	printf("[+] Permissions:\n");

	for (DWORD i = 0; i < pDacl->AceCount; ++i) {
		LPVOID pAce = nullptr;
		if (GetAce(pDacl, i, &pAce)) {
			ACCESS_ALLOWED_ACE* accessAce = (ACCESS_ALLOWED_ACE*)pAce;
			PSID pSid = &accessAce->SidStart;

			WCHAR name[256], domain[256];
			DWORD nameSize = sizeof(name) / sizeof(WCHAR);
			DWORD domainSize = sizeof(domain) / sizeof(WCHAR);
			SID_NAME_USE sidType;

			if (LookupAccountSid(NULL, pSid, name, &nameSize, domain, &domainSize, &sidType)) {
				printf("\t%ws\\%ws:\n", domain, name);
				PrintAccessMaskVerbose(accessAce->Mask);

			}
			else {
				printf("\t[Unknown SID]:\n");
				PrintAccessMaskVerbose(accessAce->Mask);

			}
		}
	}

	free(pSD);
}
void checkIntegrityLevel(HANDLE procHandle) {
	HANDLE hToken = NULL;

	if (!OpenProcessToken(procHandle, TOKEN_QUERY, &hToken)) {
		printf("[-] OpenProcessToken failed: %lu\n", GetLastError());
		return;
	}

	DWORD len = 0;
	GetTokenInformation(hToken, TokenIntegrityLevel, NULL, 0, &len);
	if (GetLastError() != ERROR_INSUFFICIENT_BUFFER) {
		printf("[-] GetTokenInformation (len query) failed: %lu\n", GetLastError());
		CloseHandle(hToken);
		return;
	}

	PTOKEN_MANDATORY_LABEL pTIL = (PTOKEN_MANDATORY_LABEL)malloc(len);
	if (!GetTokenInformation(hToken, TokenIntegrityLevel, pTIL, len, &len)) {
		printf("[-] GetTokenInformation failed: %lu\n", GetLastError());
		free(pTIL);
		CloseHandle(hToken);
		return;
	}

	DWORD integrityLevel = *GetSidSubAuthority(pTIL->Label.Sid,
		(DWORD)(*GetSidSubAuthorityCount(pTIL->Label.Sid) - 1));

	printf("[+] Integrity Level: ");
	if (integrityLevel >= SECURITY_MANDATORY_UNTRUSTED_RID && integrityLevel < SECURITY_MANDATORY_LOW_RID) {
		printf("Untrusted\n");
	}
	else if (integrityLevel >= SECURITY_MANDATORY_LOW_RID && integrityLevel < SECURITY_MANDATORY_MEDIUM_RID) {
		printf("Low\n");
	}
	else if (integrityLevel >= SECURITY_MANDATORY_MEDIUM_RID && integrityLevel < SECURITY_MANDATORY_HIGH_RID) {
		printf("Medium\n");
	}
	else if (integrityLevel >= SECURITY_MANDATORY_HIGH_RID && integrityLevel < SECURITY_MANDATORY_SYSTEM_RID) {
		printf("High\n");
	}
	else if (integrityLevel >= SECURITY_MANDATORY_SYSTEM_RID) {
		printf("System\n");
	}
	else {
		printf("Unknown (0x%08X)\n", integrityLevel);
	}

	free(pTIL);
	CloseHandle(hToken);
}

void PrintAccessMaskVerbose(DWORD accessMask)
{
	struct {
		DWORD flag;
		const char* name;
	} accessRights[] = {
		{ PROCESS_TERMINATE, "PROCESS_TERMINATE" },
		{ PROCESS_CREATE_THREAD, "PROCESS_CREATE_THREAD" },
		{ PROCESS_SET_SESSIONID, "PROCESS_SET_SESSIONID" },
		{ PROCESS_VM_OPERATION, "PROCESS_VM_OPERATION" },
		{ PROCESS_VM_READ, "PROCESS_VM_READ" },
		{ PROCESS_VM_WRITE, "PROCESS_VM_WRITE" },
		{ PROCESS_DUP_HANDLE, "PROCESS_DUP_HANDLE" },
		{ PROCESS_CREATE_PROCESS, "PROCESS_CREATE_PROCESS" },
		{ PROCESS_SET_QUOTA, "PROCESS_SET_QUOTA" },
		{ PROCESS_SET_INFORMATION, "PROCESS_SET_INFORMATION" },
		{ PROCESS_QUERY_INFORMATION, "PROCESS_QUERY_INFORMATION" },
		{ PROCESS_SUSPEND_RESUME, "PROCESS_SUSPEND_RESUME" },
		{ PROCESS_QUERY_LIMITED_INFORMATION, "PROCESS_QUERY_LIMITED_INFORMATION" },
		{ PROCESS_ALL_ACCESS, "PROCESS_ALL_ACCESS" },
	};

	bool found = false;
	for (const auto& right : accessRights) {
		if ((accessMask & right.flag) == right.flag) {
			printf("\t\t %s\n", right.name);
			found = true;
		}
	}

	if (!found) {
		printf("    - [No standard rights found] (Raw Mask: 0x%08X)\n", accessMask);
	}
}