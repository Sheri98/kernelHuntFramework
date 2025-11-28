#include "Header.h"

WCHAR* errorCode() {
	static WCHAR wszMsgBuff[512];
	DWORD erroMess = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		GetLastError(),
		0,
		wszMsgBuff,
		512,
		NULL);

	return wszMsgBuff;

}
BOOL validateBasedOnError(auto ctlCode, auto returnedBytes, int& count, int& sus) {
	DWORD e = GetLastError();  
	if (
		e == ERROR_BAD_LENGTH ||
		e == ERROR_INSUFFICIENT_BUFFER ||
		e == ERROR_MORE_DATA ||
		e == ERROR_BUFFER_OVERFLOW || 
		e == ERROR_INVALID_USER_BUFFER
		)
	{
		if (returnedBytes > 0) {
		//	println("[+] IOCTL Code Exist || {:#010x} || {} || {}", ctlCode, returnedBytes, e);
			count++;
		}
		return FALSE;
	}
	else if
		(e == ERROR_INVALID_FUNCTION ||
			e == ERROR_CALL_NOT_IMPLEMENTED)
	{
		println("\t[-] IOCTL Code Do not Exist || {:#010x} || {} || {}", ctlCode, returnedBytes, e);
		return TRUE;
	}
	else if (e == ERROR_INVALID_PARAMETER || e == ERROR_ACCESS_DENIED || e == ERROR_NOT_SUPPORTED || e == ERROR_INVALID_USER_BUFFER
		) {
		sus++;
	}
	else {
		//println("\t[-] Unhandled Case || {:#010x} || {} || {}", ctlCode, returnedBytes,e);
		return TRUE;
	}
}

void fuzzIOCLTCodes(HANDLE deviceHandle, vector <uint32_t> ctlCodes) {
	DWORD bytes = 0;
	DWORD inputsizes[] = {8, 12, 16, 20, 24, 32, 40, 48, 64, 128, 256};
	DWORD outputsizes[] = { 8, 12, 16, 20, 24, 32, 40, 48, 64, 128, 256 };
	//BYTE outputBuff[4096];

	for (auto inputSize : inputsizes) {
	
		println("[+] Fuzzing with Input Buffsize {}", inputSize);
		int count = 0,sus=0;
		LPVOID input = VirtualAlloc(NULL, inputSize, MEM_COMMIT, PAGE_READWRITE);
		LPVOID outputBuff = VirtualAlloc(NULL, inputSize, MEM_COMMIT, PAGE_READWRITE);
		for (auto ctlCode : ctlCodes) {
			if (ctlCode == 0x80002044) {
				continue;
			}
			
			BOOL ok = DeviceIoControl(deviceHandle, ctlCode, input, inputSize, outputBuff, inputSize, &bytes, nullptr);
			DWORD err = GetLastError();
			if (!ok && validateBasedOnError(ctlCode, bytes, count,sus)) {
				continue;
			}
			
		}
		VirtualFree(input, 0, MEM_RELEASE);
		VirtualFree(outputBuff, 0, MEM_RELEASE);
		println("\t[+] No of IOCTL Codes with returned bytes {}", count);
		println("\t[+] Possible IOCTL Codes {}", sus);
	}
}

/*
void fuzzIOCLTCodes(HANDLE deviceHandle, vector <uint32_t> ctlCodes) {
	DWORD bytes = 0;
	RTCORE64_MEMORY_WRITE inputSize;
	DWORD outputsize[4096];

	//for (auto inputSize : inputsizes) {

	//	println("[+] Fuzzing with Input Buffsize {}", inputSize);
		int count = 0, sus = 0;
	//	LPVOID input = VirtualAlloc(NULL, inputSize, MEM_COMMIT, PAGE_READWRITE);
	//	LPVOID outputBuff = VirtualAlloc(NULL, inputSize, MEM_COMMIT, PAGE_READWRITE);
		for (auto ctlCode : ctlCodes) {
			if (ctlCode == 0x80002044) {
				continue;
			}

			BOOL ok = DeviceIoControl(deviceHandle, ctlCode, &inputSize, sizeof(inputSize),outputsize, sizeof(inputSize), &bytes, nullptr);
			DWORD err = GetLastError();
			if (!ok && validateBasedOnError(ctlCode, bytes, count, sus)) {
				continue;
			}

		}
		//VirtualFree(input, 0, MEM_RELEASE);
		//VirtualFree(outputBuff, 0, MEM_RELEASE);
		println("\t[+] No of IOCTL Codes with returned bytes {}", count);
		println("\t[+] Possible IOCTL Codes {}", sus);
	//}
}
*/
int	ioctMain() {
	vector <uint32_t> ctlCodes;
	ctlCodes = fuzzIOCTLMain();
	println("[+] Fuzzing with {} IOCT Codes",ctlCodes.size());
	HANDLE deviceHandle = CreateFile(L"\\\\.\\cpuz141", GENERIC_READ | GENERIC_WRITE, 0, nullptr, OPEN_EXISTING, 0, nullptr);
	if (deviceHandle == INVALID_HANDLE_VALUE) {
		printf("%ls", errorCode());
		return 1;
	}

	fuzzIOCLTCodes(deviceHandle, ctlCodes);
	return 0;
}