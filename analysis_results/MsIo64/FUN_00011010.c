// Function: FUN_00011010
// Address: 00011010
// Decompiled by Ghidra


void FUN_00011010(longlong param_1)

{
  int iVar1;
  undefined1 local_18 [16];
  
  DbgPrint("Entering MsIoUnload");
  RtlInitUnicodeString(local_18,L"\\DosDevices\\MsIo");
  iVar1 = IoDeleteSymbolicLink(local_18);
  if (-1 < iVar1) {
    IoDeleteDevice(*(undefined8 *)(param_1 + 8));
    DbgPrint("Leaving MsIoUnload");
    return;
  }
  DbgPrint("ERROR: IoDeleteSymbolicLink");
  DbgPrint("Leaving MsIoUnload");
  return;
}

