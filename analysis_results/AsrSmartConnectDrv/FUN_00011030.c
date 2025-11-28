// Function: FUN_00011030
// Address: 00011030
// Decompiled by Ghidra


void FUN_00011030(longlong param_1)

{
  undefined1 local_18 [16];
  
  RtlInitUnicodeString(local_18,L"\\DosDevices\\AsrSmartConnectDrv");
  IoDeleteSymbolicLink(local_18);
  IoDeleteDevice(*(undefined8 *)(param_1 + 8));
  return;
}

