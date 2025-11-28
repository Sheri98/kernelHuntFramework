// Function: FUN_00011640
// Address: 00011640
// Decompiled by Ghidra


undefined8 FUN_00011640(undefined4 *param_1)

{
  undefined8 in_RAX;
  undefined4 unaff_EBX;
  
  wrmsr(param_1[2],CONCAT44(param_1[3],*param_1));
  *param_1 = *param_1;
  param_1[1] = unaff_EBX;
  param_1[2] = param_1[2];
  param_1[3] = param_1[3];
  return in_RAX;
}

