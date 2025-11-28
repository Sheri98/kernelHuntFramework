// Function: FUN_00011580
// Address: 00011580
// Decompiled by Ghidra


void FUN_00011580(longlong param_1)

{
  if (DAT_00013068 != 0) {
    IoDeleteSymbolicLink(&DAT_00013070);
  }
  DAT_00013068 = 0;
  IoDeleteDevice(*(undefined8 *)(param_1 + 8));
  return;
}

