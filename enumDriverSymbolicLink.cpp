#include "Header.h"

void enumDriverSymbolicLinks() {
    println("[+] Enumerating Driver Symbolic Links");
    wchar_t deviceBuffer[65535];

    if (QueryDosDeviceW(NULL, deviceBuffer, sizeof(deviceBuffer) / sizeof(wchar_t))) {
        deviceBuffer[(sizeof(deviceBuffer) / sizeof(wchar_t)) - 1] = L'\0';
        println(L"%ls", deviceBuffer); // Use a wide-character format specifier
    }
}