// Function: FUN_00011ce8
// Address: 00011ce8
// Decompiled by Ghidra


undefined8 FUN_00011ce8(longlong param_1)

{
  ulonglong uVar1;
  undefined8 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  
  uVar6 = 0x186;
  uVar5 = 0xc1;
  iVar3 = in(*(undefined2 *)(param_1 + 0x10));
  uVar1 = rdmsr(0x186);
  if ((uVar1 >> 0x16 & 1) != 0) {
    uVar6 = 0x187;
    uVar5 = 0xc2;
  }
  wrmsr(uVar5,0);
  wrmsr(uVar6,0x43003c);
  KeStallExecutionProcessor(*(undefined4 *)(param_1 + 4),0);
  iVar4 = in(*(undefined2 *)(param_1 + 0x10));
  uVar7 = iVar4 - iVar3;
  uVar2 = rdmsr(uVar5);
  wrmsr(uVar6,0);
  if (*(short *)(param_1 + 0x12) == 0) {
    uVar7 = uVar7 & 0xffffff;
  }
  *(uint *)(param_1 + 4) = uVar7;
  *(int *)(param_1 + 0xc) = (int)uVar2;
  *(int *)(param_1 + 8) = (int)((ulonglong)uVar2 >> 0x20);
  return 0;
}

