// Function: FUN_000118b0
// Address: 000118b0
// Decompiled by Ghidra


void FUN_000118b0(longlong param_1)

{
  undefined1 local_18 [16];
  
  RtlInitUnicodeString(local_18,L"\\DosDevices\\atillk64");
  IoDeleteSymbolicLink(local_18);
  IoDeleteDevice(*(undefined8 *)(param_1 + 8));
  return;
}

