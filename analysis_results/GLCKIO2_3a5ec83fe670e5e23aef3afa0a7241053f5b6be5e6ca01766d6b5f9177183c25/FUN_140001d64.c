// Function: FUN_140001d64
// Address: 140001d64
// Decompiled by Ghidra


void FUN_140001d64(longlong param_1)

{
  int iVar1;
  undefined1 local_18 [16];
  
  RtlInitUnicodeString(local_18,L"\\DosDevices\\GLCKIo2");
  iVar1 = IoDeleteSymbolicLink(local_18);
  if (-1 < iVar1) {
    IoDeleteDevice(*(undefined8 *)(param_1 + 8));
  }
  return;
}

