// Function: FUN_00011450
// Address: 00011450
// Decompiled by Ghidra


void FUN_00011450(longlong param_1)

{
  longlong lVar1;
  undefined1 local_18 [16];
  
  lVar1 = *(longlong *)(param_1 + 8);
  RtlInitUnicodeString(local_18,L"\\DosDevices\\NTIOLib_1_0_6");
  IoDeleteSymbolicLink(local_18);
  if (lVar1 != 0) {
    IoDeleteDevice(lVar1);
  }
  return;
}

