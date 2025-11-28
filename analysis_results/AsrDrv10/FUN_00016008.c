// Function: FUN_00016008
// Address: 00016008
// Decompiled by Ghidra


ulonglong FUN_00016008(longlong param_1)

{
  ulonglong *puVar1;
  ulonglong *puVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 local_res18 [2];
  undefined1 local_28 [16];
  undefined1 local_18 [16];
  
  RtlInitUnicodeString(local_28,u__Device_AsrDrv10_00016180);
  RtlInitUnicodeString(local_18,u__DosDevices_AsrDrv10_000161b0);
  uVar4 = IoCreateDevice(param_1,0x40,local_28,0x22,0,0,local_res18);
  if (-1 < (int)uVar4) {
    uVar3 = IoCreateSymbolicLink(local_18);
    uVar4 = (ulonglong)uVar3;
    if ((int)uVar3 < 0) {
      IoDeleteDevice(local_res18[0]);
    }
    else {
      *(code **)(param_1 + 0x70) = FUN_00011008;
      *(code **)(param_1 + 0x80) = FUN_00011008;
      *(code **)(param_1 + 0xe0) = FUN_000110a8;
      *(code **)(param_1 + 0x68) = FUN_00011030;
      puVar2 = *(ulonglong **)(*(longlong *)(param_1 + 8) + 0x40);
      FUN_000125d0(puVar2,0,0x40);
      puVar1 = puVar2 + 5;
      *puVar2 = *(ulonglong *)(param_1 + 8);
      puVar2[6] = (ulonglong)puVar1;
      *puVar1 = (ulonglong)puVar1;
      puVar2[7] = 0;
      uVar4 = 0;
    }
  }
  return uVar4;
}

