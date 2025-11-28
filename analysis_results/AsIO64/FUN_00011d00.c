// Function: FUN_00011d00
// Address: 00011d00
// Decompiled by Ghidra


void FUN_00011d00(longlong param_1)

{
  undefined1 local_18 [16];
  
  RtlInitUnicodeString(local_18,L"\\DosDevices\\Asusgio");
  IoDeleteSymbolicLink(local_18);
  IoDeleteDevice(*(undefined8 *)(param_1 + 8));
  return;
}

