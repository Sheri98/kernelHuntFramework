// Function: FUN_00011960
// Address: 00011960
// Decompiled by Ghidra


undefined8 FUN_00011960(undefined8 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_stack_00000030;
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  DbgPrint("io 302");
  out((short)uVar1,(char)uVar2);
  *in_stack_00000030 = 0;
  return 0;
}

