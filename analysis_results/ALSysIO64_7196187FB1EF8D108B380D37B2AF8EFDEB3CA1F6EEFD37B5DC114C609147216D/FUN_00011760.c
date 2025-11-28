// Function: FUN_00011760
// Address: 00011760
// Decompiled by Ghidra


undefined8 FUN_00011760(undefined8 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_stack_00000030;
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  DbgPrint("io 186");
  out((short)uVar1,uVar2);
  *in_stack_00000030 = 0;
  return 0;
}

