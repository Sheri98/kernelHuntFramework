// Function: entry
// Address: 00011f60
// Decompiled by Ghidra


ulonglong entry(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 local_38;
  undefined1 local_30 [16];
  undefined1 local_20 [24];
  
  *(code **)(param_1 + 0x70) = FUN_00011d70;
  *(code **)(param_1 + 0x80) = FUN_00011d70;
  *(code **)(param_1 + 0xe0) = FUN_00011d70;
  *(code **)(param_1 + 0x68) = FUN_00011d00;
  RtlInitUnicodeString(local_30,L"\\Device\\Asusgio");
  uVar2 = IoCreateDevice(param_1,0,local_30,0xa040,0,0,&local_38);
  if (-1 < (int)uVar2) {
    RtlInitUnicodeString(local_20,L"\\DosDevices\\Asusgio");
    uVar1 = IoCreateSymbolicLink(local_20,local_30);
    uVar2 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      IoDeleteDevice(local_38);
    }
  }
  return uVar2;
}

