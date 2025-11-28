// Function: FUN_00011dc8
// Address: 00011dc8
// Decompiled by Ghidra


undefined8 FUN_00011dc8(longlong param_1)

{
  ulonglong uVar1;
  undefined8 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  iVar5 = -0x3ffefffc;
  iVar3 = in(*(undefined2 *)(param_1 + 0x10));
  iVar4 = -0x3fff0000;
  do {
    uVar1 = rdmsr(iVar4);
    iVar6 = iVar4;
    if ((uVar1 >> 0x16 & 1) == 0) break;
    iVar6 = iVar4 + 1;
    iVar5 = iVar5 + 1;
    uVar7 = iVar4 + 0x3fff0001;
    iVar4 = iVar6;
  } while (uVar7 < 3);
  wrmsr(iVar5,0);
  wrmsr(iVar6,0x430076);
  KeStallExecutionProcessor(*(undefined4 *)(param_1 + 4),0);
  iVar4 = in(*(undefined2 *)(param_1 + 0x10));
  uVar7 = iVar4 - iVar3;
  uVar2 = rdmsr(iVar5);
  wrmsr(iVar6,0);
  if (*(short *)(param_1 + 0x12) == 0) {
    uVar7 = uVar7 & 0xffffff;
  }
  *(uint *)(param_1 + 4) = uVar7;
  *(int *)(param_1 + 0xc) = (int)uVar2;
  *(int *)(param_1 + 8) = (int)((ulonglong)uVar2 >> 0x20);
  return 0;
}

