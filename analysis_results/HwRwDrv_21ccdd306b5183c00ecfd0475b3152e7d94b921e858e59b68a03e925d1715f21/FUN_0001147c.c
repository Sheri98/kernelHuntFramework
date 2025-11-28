// Function: FUN_0001147c
// Address: 0001147c
// Decompiled by Ghidra


undefined8 FUN_0001147c(undefined4 *param_1)

{
  undefined4 *in_stack_00000028;
  
  wrmsr(*param_1,*(ulonglong *)(param_1 + 1) & 0xffffffff00000000 | (ulonglong)(uint)param_1[1]);
  *in_stack_00000028 = 0;
  return 0;
}

