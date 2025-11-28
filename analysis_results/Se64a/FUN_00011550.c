// Function: FUN_00011550
// Address: 00011550
// Decompiled by Ghidra


undefined8 FUN_00011550(undefined8 param_1,longlong param_2)

{
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}

