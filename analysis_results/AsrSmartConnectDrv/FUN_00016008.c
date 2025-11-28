// Function: FUN_00016008
// Address: 00016008
// Decompiled by Ghidra


ulonglong FUN_00016008(longlong param_1)

{
  ulonglong *puVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 local_res18 [2];
  undefined1 local_28 [16];
  undefined1 local_18 [16];
  
  RtlInitUnicodeString(local_28,u__Device_AsrSmartConnectDrv_00016170);
  RtlInitUnicodeString(local_18,u__DosDevices_AsrSmartConnectDrv_000161b0);
  uVar3 = IoCreateDevice(param_1,0x28,local_28,0x22,0,1,local_res18);
  if (-1 < (int)uVar3) {
    uVar2 = IoCreateSymbolicLink(local_18);
    uVar3 = (ulonglong)uVar2;
    if ((int)uVar2 < 0) {
      IoDeleteDevice(local_res18[0]);
    }
    else {
      *(code **)(param_1 + 0x70) = FUN_00011008;
      *(code **)(param_1 + 0x80) = FUN_00011008;
      *(code **)(param_1 + 0xe0) = FUN_0001106c;
      *(code **)(param_1 + 0x68) = FUN_00011030;
      puVar1 = *(ulonglong **)(*(longlong *)(param_1 + 8) + 0x40);
      FUN_00012500(puVar1,0,0x28);
      uVar3 = 0;
      *puVar1 = *(ulonglong *)(param_1 + 8);
    }
  }
  return uVar3;
}

