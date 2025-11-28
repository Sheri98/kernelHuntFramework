// Function: __security_init_cookie
// Address: 14000e160
// Decompiled by Ghidra


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __security_init_cookie
   
   Library: Visual Studio 2019 Release */

void __cdecl __security_init_cookie(void)

{
  ulonglong uVar1;
  
  if ((DAT_14000a050 == 0) || (DAT_14000a050 == 0x2b992ddfa232)) {
    uVar1 = rdtsc();
    DAT_14000a050 =
         ((CONCAT44((int)(DAT_14000a050 >> 0x20),(int)uVar1) | uVar1 & 0xffffffff00000000) ^
         0x14000a050) & 0xffffffffffff;
    if (DAT_14000a050 == 0) {
      DAT_14000a050 = 0x2b992ddfa232;
    }
  }
  _DAT_14000a058 = ~DAT_14000a050;
  return;
}

