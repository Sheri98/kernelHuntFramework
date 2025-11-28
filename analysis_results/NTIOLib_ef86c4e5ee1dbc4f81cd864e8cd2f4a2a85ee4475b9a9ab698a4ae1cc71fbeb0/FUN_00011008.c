// Function: FUN_00011008
// Address: 00011008
// Decompiled by Ghidra


ulonglong FUN_00011008(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 local_res18 [2];
  undefined1 local_28 [16];
  undefined1 local_18 [16];
  
  local_res18[0] = 0;
  RtlInitUnicodeString(local_28,L"\\Device\\NTIOLib_MB");
  uVar2 = IoCreateDevice(param_1,0,local_28,50000,0x100,0,local_res18);
  if ((int)uVar2 < 0) {
    DAT_00013110 = 0xffffffff;
  }
  else {
    DAT_00013110 = 0;
    *(code **)(param_1 + 0x70) = FUN_000110d8;
    *(code **)(param_1 + 0x80) = FUN_000110d8;
    *(code **)(param_1 + 0xe0) = FUN_000110d8;
    *(code **)(param_1 + 0x68) = FUN_00011450;
    RtlInitUnicodeString(local_18,L"\\DosDevices\\NTIOLib_MB");
    uVar1 = IoCreateSymbolicLink(local_18,local_28);
    uVar2 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      IoDeleteDevice(local_res18[0]);
    }
  }
  return uVar2;
}

