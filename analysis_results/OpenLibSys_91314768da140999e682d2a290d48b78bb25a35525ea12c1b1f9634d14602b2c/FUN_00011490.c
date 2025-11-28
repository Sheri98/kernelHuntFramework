// Function: FUN_00011490
// Address: 00011490
// Decompiled by Ghidra


undefined8 FUN_00011490(undefined4 *param_1)

{
  undefined4 *in_stack_00000028;
  
  wrmsr(*param_1,*(ulonglong *)(param_1 + 2) & 0xffffffff00000000 | (ulonglong)(uint)param_1[2]);
  *in_stack_00000028 = 0;
  return 0;
}

