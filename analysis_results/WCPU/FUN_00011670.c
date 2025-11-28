// Function: FUN_00011670
// Address: 00011670
// Decompiled by Ghidra


undefined8 FUN_00011670(undefined4 *param_1)

{
  undefined8 uVar1;
  undefined8 in_RAX;
  undefined4 unaff_EBX;
  
  uVar1 = rdmsr(param_1[2]);
  *param_1 = (int)uVar1;
  param_1[1] = unaff_EBX;
  param_1[2] = param_1[2];
  param_1[3] = (int)((ulonglong)uVar1 >> 0x20);
  return in_RAX;
}

