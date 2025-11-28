// Function: FUN_00011dcc
// Address: 00011dcc
// Decompiled by Ghidra


short * FUN_00011dcc(longlong param_1,short *param_2)

{
  char *pcVar1;
  char cVar2;
  short sVar3;
  ulonglong uVar4;
  short *psVar5;
  uint uVar6;
  longlong lVar8;
  ulonglong uVar7;
  
  DbgPrint("VProEventMonitor.sys: Entry - VProEventMonitorGetProcess().\n");
  uVar4 = 0;
  uVar6 = 0;
  if (DAT_00014190 == 0) {
    lVar8 = 0x40;
    psVar5 = param_2;
    do {
      if ((lVar8 == -0x7fffffbe) ||
         (sVar3 = *(short *)(((longlong)&DAT_00012d70 - (longlong)param_2) + (longlong)psVar5),
         sVar3 == 0)) break;
      *psVar5 = sVar3;
      psVar5 = psVar5 + 1;
      lVar8 = lVar8 + -1;
    } while (lVar8 != 0);
    if (lVar8 == 0) {
      psVar5 = psVar5 + -1;
    }
    *psVar5 = 0;
  }
  else {
    pcVar1 = (char *)(param_1 + (ulonglong)DAT_00014190);
    cVar2 = *pcVar1;
    uVar7 = uVar4;
    while ((cVar2 != '\0' && (uVar6 = (uint)uVar7, (longlong)uVar4 < 0xf))) {
      uVar6 = uVar6 + 1;
      uVar7 = (ulonglong)uVar6;
      param_2[uVar4] = (short)pcVar1[uVar4];
      uVar4 = uVar4 + 1;
      cVar2 = pcVar1[uVar4];
    }
    param_2[(int)uVar6] = 0;
  }
  return param_2;
}

