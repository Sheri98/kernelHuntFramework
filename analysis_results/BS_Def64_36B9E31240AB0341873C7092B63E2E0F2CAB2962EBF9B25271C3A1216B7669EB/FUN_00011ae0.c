// Function: FUN_00011ae0
// Address: 00011ae0
// Decompiled by Ghidra


void FUN_00011ae0(longlong param_1)

{
  undefined1 local_18 [16];
  
  RtlInitUnicodeString(local_18,L"\\DosDevices\\BS_Def");
  IoDeleteSymbolicLink(local_18);
  IoDeleteDevice(**(undefined8 **)(*(longlong *)(param_1 + 8) + 0x40));
  return;
}

