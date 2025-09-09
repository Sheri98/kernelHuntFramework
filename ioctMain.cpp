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
void fuzzIOCLTCodes(HANDLE deviceHandle, vector <uint32_t> ctlCodes) {
	DWORD bytes = 0;
	RTCORE64_MEMORY_WRITE data;
	for (auto ctlCode : ctlCodes) {

		BOOL ok = DeviceIoControl(deviceHandle, ctlCode, &data, sizeof(data), nullptr, 0, &bytes, nullptr);
		DWORD err = GetLastError();
		if (!ok && err == ERROR_INVALID_FUNCTION) {
			printf("%ls", errorCode());
			continue;
		}
		BYTE inSmall[16] = { 0 }, outSmall[16] = { 0 };
		ok = DeviceIoControl(deviceHandle, ctlCode, inSmall, sizeof(inSmall), outSmall, sizeof(outSmall), &bytes, NULL);
		wcout << format(L"{:#010x} -> ok={} err={} bytes={}", ctlCode, ok, errorCode(), bytes) << std::endl;
	}
}
int	ioctMain() {
	vector <uint32_t> ctlCodes;
	ctlCodes = fuzzIOCTLMain();
	println("[+] Fuzzing with 1024 IOCT Codes");
	HANDLE deviceHandle= CreateFile(L"\\\\.\\Value", GENERIC_READ | GENERIC_WRITE, 0, nullptr, OPEN_EXISTING, 0, nullptr);
	if (deviceHandle == INVALID_HANDLE_VALUE) {
		printf("%ls", errorCode());
		return 1;
	}
	
	fuzzIOCLTCodes(deviceHandle, ctlCodes);
	return 0;
}