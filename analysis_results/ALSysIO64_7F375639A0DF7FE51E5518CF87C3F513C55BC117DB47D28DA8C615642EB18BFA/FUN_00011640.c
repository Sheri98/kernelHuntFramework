// Function: FUN_00011640
// Address: 00011640
// Decompiled by Ghidra


undefined8 FUN_00011640(undefined8 param_1,undefined4 *param_2)

{
  undefined4 *in_stack_00000030;
  
  wrmsr(*param_2,*(ulonglong *)(param_2 + 1) & 0xffffffff00000000 |
                 (ulonglong)(uint)*(ulonglong *)(param_2 + 1));
  *in_stack_00000030 = 0;
  return 0;
}

