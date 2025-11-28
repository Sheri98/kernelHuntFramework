// Function: FUN_000113d0
// Address: 000113d0
// Decompiled by Ghidra


void FUN_000113d0(longlong param_1)

{
  undefined8 uVar1;
  undefined1 local_c8 [2];
  undefined2 local_c6;
  undefined2 local_b8 [80];
  longlong local_18;
  
  local_18 = DAT_00013108;
  uVar1 = *(undefined8 *)(param_1 + 8);
  local_b8[0] = 0;
  RtlInitUnicodeString(local_c8,local_b8);
  local_c6 = 0xa0;
  RtlAppendUnicodeToString(local_c8,L"\\DosDevices\\");
  RtlAppendUnicodeToString(local_c8,L"ADV64DRV");
  IoDeleteSymbolicLink(local_c8);
  IoDeleteDevice(uVar1);
  FUN_000118f0(local_18);
  return;
}

