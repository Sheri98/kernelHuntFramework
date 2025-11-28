// Function: FUN_00011310
// Address: 00011310
// Decompiled by Ghidra


void FUN_00011310(longlong param_1)

{
  undefined1 auStack_78 [32];
  undefined1 local_58 [16];
  undefined8 local_48 [6];
  ulonglong local_18;
  
  local_18 = DAT_00013100 ^ (ulonglong)auStack_78;
  FUN_000115d0(local_48,(undefined8 *)L"\\DosDevices\\inpoutx64",0x2c);
  RtlInitUnicodeString(local_58,local_48);
  IoDeleteSymbolicLink(local_58);
  IoDeleteDevice(*(undefined8 *)(param_1 + 8));
  FUN_00011570(local_18 ^ (ulonglong)auStack_78);
  return;
}

