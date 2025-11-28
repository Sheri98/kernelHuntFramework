// Function: FUN_00011750
// Address: 00011750
// Decompiled by Ghidra


void FUN_00011750(longlong param_1)

{
  undefined1 local_18 [16];
  
  RtlInitUnicodeString(local_18,L"\\DosDevices\\AsUpdateio");
  IoDeleteSymbolicLink(local_18);
  IoDeleteDevice(*(undefined8 *)(param_1 + 8));
  return;
}

