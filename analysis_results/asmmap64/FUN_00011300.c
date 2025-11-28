// Function: FUN_00011300
// Address: 00011300
// Decompiled by Ghidra


void FUN_00011300(longlong param_1)

{
  longlong lVar1;
  undefined1 local_18 [16];
  
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 8) + 0x40);
  RtlInitUnicodeString(local_18,L"\\DosDevices\\ASMMAP64");
  IoDeleteSymbolicLink(local_18);
  IoDeleteDevice(*(undefined8 *)(lVar1 + 8));
  return;
}

