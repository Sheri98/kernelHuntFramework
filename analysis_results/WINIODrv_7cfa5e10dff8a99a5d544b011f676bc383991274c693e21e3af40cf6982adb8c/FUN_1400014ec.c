// Function: FUN_1400014ec
// Address: 1400014ec
// Decompiled by Ghidra


void FUN_1400014ec(longlong param_1)

{
  int iVar1;
  undefined1 local_18 [16];
  
  RtlInitUnicodeString(local_18,L"\\DosDevices\\WinIoB");
  iVar1 = IoDeleteSymbolicLink(local_18);
  if (-1 < iVar1) {
    IoDeleteDevice(*(undefined8 *)(param_1 + 8));
  }
  return;
}

