// Function: FUN_00011418
// Address: 00011418
// Decompiled by Ghidra


void FUN_00011418(longlong param_1)

{
  longlong lVar1;
  undefined1 local_18 [16];
  
  lVar1 = *(longlong *)(param_1 + 8);
  RtlInitUnicodeString(local_18,L"\\DosDevices\\OpenLibSys");
  IoDeleteSymbolicLink(local_18);
  if (lVar1 != 0) {
    IoDeleteDevice(lVar1);
  }
  return;
}

