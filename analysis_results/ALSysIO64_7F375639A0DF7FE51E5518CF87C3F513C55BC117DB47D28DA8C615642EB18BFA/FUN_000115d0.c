// Function: FUN_000115d0
// Address: 000115d0
// Decompiled by Ghidra


undefined8
FUN_000115d0(undefined8 param_1,undefined4 *param_2,undefined8 param_3,undefined4 *param_4,
            undefined8 param_5,undefined4 *param_6)

{
  undefined8 uVar1;
  
  uVar1 = rdmsr(*param_2);
  *param_4 = (int)((ulonglong)uVar1 >> 0x20);
  param_4[1] = (int)uVar1;
  *param_6 = 8;
  return 0;
}

