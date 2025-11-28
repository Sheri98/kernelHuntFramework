// Function: __security_init_cookie
// Address: 14000602c
// Decompiled by Ghidra


/* Library Function - Single Match
    __security_init_cookie
   
   Library: Visual Studio 2019 Release */

void __cdecl __security_init_cookie(void)

{
  ulonglong uVar1;
  
  if ((DAT_140004000 == 0) || (DAT_140004000 == 0x2b992ddfa232)) {
    uVar1 = rdtsc();
    DAT_140004000 =
         ((CONCAT44((int)(DAT_140004000 >> 0x20),(int)uVar1) | uVar1 & 0xffffffff00000000) ^
         0x140004000) & 0xffffffffffff;
    if (DAT_140004000 == 0) {
      DAT_140004000 = 0x2b992ddfa232;
    }
  }
  DAT_140004008 = ~DAT_140004000;
  return;
}

