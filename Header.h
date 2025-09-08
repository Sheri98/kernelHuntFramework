#pragma once

import std;      
#include "Windows.h";  

using namespace std;

void procEnum(DWORD pID);
void privEnum(HANDLE procHandle);
void getPermission(HANDLE procHandle);
void PrintAccessMaskVerbose(DWORD accessMask);
void checkIntegrityLevel(HANDLE procHandle);
int pidSDChecker(DWORD pID);
