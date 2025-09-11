#pragma once
#pragma comment(lib, "wintrust.lib")
#pragma comment(lib, "crypt32.lib")

import std;      
#include <Windows.h>
#include <wintrust.h>
#include <winioctl.h>
#include <cstdint>
#include <tchar.h>
#include <wintrust.h>
#include <Softpub.h>
#include <softpub.h>
#include <mscat.h>
#include <wincrypt.h>
#include <tchar.h>
#include <stdio.h>
#define INITGUID
#include <guiddef.h>


struct RTCORE64_MEMORY_WRITE {
    BYTE Pad0[8];
    DWORD64 Address;
    BYTE Pad1[8];
    DWORD WriteSize;
    DWORD Value;
    BYTE Pad3[16];
};

enum class method : uint8_t {
	buffer = 0,
	inDirect = 1,
	outDirect = 2,
	Neither = 3,
};
enum class access : uint8_t {

	any = 0,
	read = 1,
	write = 2,
	readWrite = 3,
};
struct ioctlCodes {
	uint16_t deviceType;
	uint16_t function;
	method method;
	access access;
};
constexpr ULONG to_win_method(method m) {
    switch (m) {
    case method::buffer:   return METHOD_BUFFERED;
    case method::inDirect: return METHOD_IN_DIRECT;
    case method::outDirect:return METHOD_OUT_DIRECT;
    case method::Neither:  return METHOD_NEITHER;
    }
    return METHOD_BUFFERED;
};
constexpr ULONG to_win_access(access a) {
    switch (a) {
    case access::any:       return FILE_ANY_ACCESS;
    case access::read:      return FILE_READ_ACCESS;
    case access::write:     return FILE_WRITE_ACCESS;
    case access::readWrite: return FILE_READ_ACCESS | FILE_WRITE_ACCESS;
    }
    return FILE_ANY_ACCESS;
};

using namespace std;
WCHAR* errorCode();
void procEnum(DWORD pID);
void privEnum(HANDLE procHandle);
void getPermission(HANDLE procHandle);
void PrintAccessMaskVerbose(DWORD accessMask);
void checkIntegrityLevel(HANDLE procHandle);
int pidSDChecker(DWORD pID);
int ioctMain();
DWORD ctlCodeGenerator(ioctlCodes& ioctlCode);
vector<uint32_t> ioctlCodeGenerator();
vector<uint32_t> fuzzIOCTLMain();
void driverEnum();

