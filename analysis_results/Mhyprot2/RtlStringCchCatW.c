// Function: RtlStringCchCatW
// Address: 140001f34
// Decompiled by Ghidra


/* Library Function - Single Match
    RtlStringCchCatW
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

ulonglong RtlStringCchCatW(short *param_1,longlong param_2,longlong param_3)

{
  short sVar1;
  short *psVar2;
  short *psVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong lVar8;
  
  uVar5 = 0;
  uVar6 = uVar5;
  if (0x7ffffffe < param_2 - 1U) {
    uVar6 = 0xc000000d;
  }
  if (-1 < (int)uVar6) {
    psVar2 = param_1;
    lVar4 = param_2;
    if (param_2 != 0) {
      do {
        if (*psVar2 == 0) break;
        psVar2 = psVar2 + 1;
        lVar4 = lVar4 + -1;
      } while (lVar4 != 0);
    }
    uVar6 = (ulonglong)(~-(uint)(lVar4 != 0) & 0xc000000d);
    if (lVar4 != 0) {
      uVar5 = param_2 - lVar4;
    }
  }
  if (-1 < (int)uVar6) {
    psVar2 = param_1 + uVar5;
    lVar4 = param_2 - uVar5;
    if (lVar4 != 0) {
      lVar7 = uVar5 + 0x7ffffffe + (lVar4 - param_2);
      lVar8 = param_3 - (longlong)psVar2;
      do {
        if ((lVar7 == 0) || (sVar1 = *(short *)(lVar8 + (longlong)psVar2), sVar1 == 0)) break;
        *psVar2 = sVar1;
        lVar7 = lVar7 + -1;
        psVar2 = psVar2 + 1;
        lVar4 = lVar4 + -1;
      } while (lVar4 != 0);
    }
    psVar3 = psVar2 + -1;
    if (lVar4 != 0) {
      psVar3 = psVar2;
    }
    uVar6 = (ulonglong)(~-(uint)(lVar4 != 0) & 0x80000005);
    *psVar3 = 0;
  }
  return uVar6;
}

