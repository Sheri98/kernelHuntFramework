// Function: FUN_000114bc
// Address: 000114bc
// Decompiled by Ghidra


undefined8
FUN_000114bc(undefined4 *param_1,undefined8 param_2,undefined8 *param_3,undefined8 param_4,
            undefined4 *param_5)

{
  undefined8 uVar1;
  
  uVar1 = rdmsr(*param_1);
  *param_3 = uVar1;
  *param_5 = 8;
  return 0;
}

