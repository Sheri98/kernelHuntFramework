// Function: RtlStringCchCopyW
// Address: 140002004
// Decompiled by Ghidra


/* Library Function - Single Match
    RtlStringCchCopyW
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

uint RtlStringCchCopyW(short *param_1,longlong param_2,longlong param_3)

{
  short sVar1;
  short *psVar2;
  longlong lVar3;
  uint uVar4;
  longlong lVar5;
  
  uVar4 = 0;
  if (0x7ffffffe < param_2 - 1U) {
    uVar4 = 0xc000000d;
  }
  if ((int)uVar4 < 0) {
    if (param_2 != 0) {
      *param_1 = 0;
    }
  }
  else {
    if (param_2 != 0) {
      lVar5 = 0x7ffffffe - param_2;
      lVar3 = param_3 - (longlong)param_1;
      do {
        if ((lVar5 + param_2 == 0) || (sVar1 = *(short *)(lVar3 + (longlong)param_1), sVar1 == 0))
        break;
        *param_1 = sVar1;
        param_1 = param_1 + 1;
        param_2 = param_2 + -1;
      } while (param_2 != 0);
    }
    psVar2 = param_1 + -1;
    if (param_2 != 0) {
      psVar2 = param_1;
    }
    uVar4 = ~-(uint)(param_2 != 0) & 0x80000005;
    *psVar2 = 0;
  }
  return uVar4;
}

