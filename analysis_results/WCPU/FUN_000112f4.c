// Function: FUN_000112f4
// Address: 000112f4
// Decompiled by Ghidra


void FUN_000112f4(longlong param_1)

{
  longlong lVar1;
  undefined1 local_18 [16];
  
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 8) + 0x40);
  RtlInitUnicodeString(local_18,L"\\DosDevices\\WCPU");
  IoDeleteSymbolicLink(local_18);
  IoDeleteDevice(*(undefined8 *)(lVar1 + 0x18));
  return;
}

