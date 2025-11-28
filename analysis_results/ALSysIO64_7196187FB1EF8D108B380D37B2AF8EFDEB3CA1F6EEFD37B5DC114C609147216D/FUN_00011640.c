// Function: FUN_00011640
// Address: 00011640
// Decompiled by Ghidra


undefined8 FUN_00011640(undefined8 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined4 *in_stack_00000030;
  
  uVar1 = *param_2;
  uVar3 = *(ulonglong *)(param_2 + 1);
  uVar2 = *(ulonglong *)(param_2 + 1);
  DbgPrint("io 52");
  wrmsr(uVar1,uVar2 & 0xffffffff00000000 | (ulonglong)(uint)uVar3);
  *in_stack_00000030 = 0;
  return 0;
}

