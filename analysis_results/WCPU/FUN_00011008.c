// Function: FUN_00011008
// Address: 00011008
// Decompiled by Ghidra


ulonglong FUN_00011008(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  longlong local_res8 [4];
  undefined1 local_28 [16];
  undefined1 local_18 [16];
  
  *(code **)(param_1 + 0x70) = FUN_000110c8;
  *(code **)(param_1 + 0x80) = FUN_000110c8;
  *(code **)(param_1 + 0xe0) = FUN_000110c8;
  *(code **)(param_1 + 0x68) = FUN_000112f4;
  RtlInitUnicodeString(local_28,L"\\Device\\WCPU");
  uVar2 = IoCreateDevice(param_1,0x20,local_28,55000,0,0,local_res8);
  if (-1 < (int)uVar2) {
    RtlInitUnicodeString(local_18,L"\\DosDevices\\WCPU");
    uVar1 = IoCreateSymbolicLink(local_18,local_28);
    uVar2 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      IoDeleteDevice(local_res8[0]);
    }
    *(longlong *)(*(longlong *)(local_res8[0] + 0x40) + 0x18) = local_res8[0];
  }
  return uVar2;
}

