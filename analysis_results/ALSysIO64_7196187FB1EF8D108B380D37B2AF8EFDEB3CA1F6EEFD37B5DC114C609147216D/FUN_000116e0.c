// Function: FUN_000116e0
// Address: 000116e0
// Decompiled by Ghidra


undefined8
FUN_000116e0(undefined8 param_1,undefined4 *param_2,undefined8 param_3,undefined4 *param_4,
            undefined8 param_5,undefined4 *param_6)

{
  undefined4 uVar1;
  
  uVar1 = *param_2;
  DbgPrint("io 153");
  uVar1 = in((short)uVar1);
  *param_4 = uVar1;
  *param_6 = 4;
  return 0;
}

