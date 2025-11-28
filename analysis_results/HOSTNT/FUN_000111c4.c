// Function: FUN_000111c4
// Address: 000111c4
// Decompiled by Ghidra


void FUN_000111c4(longlong param_1)

{
  undefined1 auStack_68 [32];
  undefined1 local_48 [16];
  undefined8 local_38 [5];
  ulonglong local_10;
  
  local_10 = DAT_00013100 ^ (ulonglong)auStack_68;
  FUN_00011540(local_38,(undefined8 *)L"\\DosDevices\\HOSTNT",0x26);
  RtlInitUnicodeString(local_48,local_38);
  IoDeleteSymbolicLink(local_48);
  IoDeleteDevice(*(undefined8 *)(param_1 + 8));
  FUN_000114e0(local_10 ^ (ulonglong)auStack_68);
  return;
}

