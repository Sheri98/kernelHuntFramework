// Function: FUN_00011bc0
// Address: 00011bc0
// Decompiled by Ghidra


void FUN_00011bc0(longlong param_1)

{
  undefined1 local_18 [16];
  
  RtlInitUnicodeString(local_18,L"\\??\\genericdrv");
  IoDeleteSymbolicLink(local_18);
  IoDeleteDevice(*(undefined8 *)(param_1 + 8));
  return;
}

