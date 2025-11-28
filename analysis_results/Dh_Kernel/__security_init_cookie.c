// Function: __security_init_cookie
// Address: 140007000
// Decompiled by Ghidra


/* Library Function - Single Match
    __security_init_cookie
   
   Library: Visual Studio 2019 Release */

void __cdecl __security_init_cookie(void)

{
  ulonglong uVar1;
  
  if ((DAT_140004010 == 0) || (DAT_140004010 == 0x2b992ddfa232)) {
    uVar1 = rdtsc();
    DAT_140004010 =
         ((CONCAT44((int)(DAT_140004010 >> 0x20),(int)uVar1) | uVar1 & 0xffffffff00000000) ^
         0x140004010) & 0xffffffffffff;
    if (DAT_140004010 == 0) {
      DAT_140004010 = 0x2b992ddfa232;
    }
  }
  DAT_140004018 = ~DAT_140004010;
  return;
}

