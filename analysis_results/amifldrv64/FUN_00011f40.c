// Function: FUN_00011f40
// Address: 00011f40
// Decompiled by Ghidra


ulonglong FUN_00011f40(longlong param_1)

{
  undefined8 *puVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong local_38;
  undefined1 local_30 [16];
  undefined1 local_20 [32];
  
  RtlInitUnicodeString(local_30,L"\\Device\\genericdrv");
  uVar3 = IoCreateDevice(param_1,0x20,local_30,64000,0,0,&local_38);
  if (-1 < (int)uVar3) {
    RtlInitUnicodeString(local_20,L"\\??\\genericdrv");
    uVar2 = IoCreateSymbolicLink(local_20);
    uVar3 = (ulonglong)uVar2;
    if ((int)uVar2 < 0) {
      IoDeleteDevice(local_38);
    }
    else {
      *(code **)(param_1 + 0xe0) = FUN_00011eb0;
      *(code **)(param_1 + 0x90) = FUN_00011eb0;
      *(code **)(param_1 + 0x88) = FUN_00011eb0;
      *(code **)(param_1 + 0x80) = FUN_00011eb0;
      *(code **)(param_1 + 0x70) = FUN_00011eb0;
      *(code **)(param_1 + 0x68) = FUN_00011bc0;
      puVar1 = *(undefined8 **)(local_38 + 0x40);
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      puVar1[3] = 0;
    }
  }
  return uVar3;
}

