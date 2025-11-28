// Function: FUN_00011494
// Address: 00011494
// Decompiled by Ghidra


undefined8
FUN_00011494(undefined4 *param_1,undefined8 param_2,undefined8 *param_3,undefined8 param_4,
            undefined4 *param_5)

{
  undefined8 uVar1;
  
  uVar1 = rdmsr(*param_1);
  *param_3 = uVar1;
  *param_5 = 8;
  return 0;
}

