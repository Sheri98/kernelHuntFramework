// Function: FUN_00011050
// Address: 00011050
// Decompiled by Ghidra


undefined8 FUN_00011050(undefined8 param_1,undefined4 *param_2)

{
  undefined4 *in_stack_00000030;
  
  wrmsr(*param_2,*(undefined8 *)(param_2 + 1));
  *in_stack_00000030 = 0;
  return 0;
}

