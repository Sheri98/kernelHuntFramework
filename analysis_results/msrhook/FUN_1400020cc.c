// Function: FUN_1400020cc
// Address: 1400020cc
// Decompiled by Ghidra


undefined8
FUN_1400020cc(undefined4 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  memset(param_1,0,0x40);
  *param_1 = 0x40;
  *(undefined8 *)(param_1 + 2) = param_2;
  KeInitializeSpinLock(param_1 + 4);
  KeInitializeEvent(param_1 + 6,0,0);
  *(undefined8 *)(param_1 + 0xc) = param_3;
  *(undefined8 *)(param_1 + 0xe) = param_4;
  return 0;
}

