// Function: __security_init_cookie
// Address: 14000802c
// Decompiled by Ghidra


/* Library Function - Single Match
    __security_init_cookie
   
   Library: Visual Studio 2019 Release */

void __cdecl __security_init_cookie(void)

{
  ulonglong uVar1;
  
  if ((DAT_140005008 == 0) || (DAT_140005008 == 0x2b992ddfa232)) {
    uVar1 = rdtsc();
    DAT_140005008 =
         ((CONCAT44((int)(DAT_140005008 >> 0x20),(int)uVar1) | uVar1 & 0xffffffff00000000) ^
         0x140005008) & 0xffffffffffff;
    if (DAT_140005008 == 0) {
      DAT_140005008 = 0x2b992ddfa232;
    }
  }
  DAT_140005010 = ~DAT_140005008;
  return;
}

