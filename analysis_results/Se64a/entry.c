// Function: entry
// Address: 000115c0
// Decompiled by Ghidra


undefined8 entry(longlong param_1)

{
  longlong *plVar1;
  int iVar2;
  longlong local_38;
  undefined1 local_30 [32];
  
  local_38 = 0;
  RtlInitUnicodeString(local_30,u__Device_SE64_00013000);
  iVar2 = IoCreateDevice(param_1,200,local_30,0x8000,0,0,&local_38);
  if (-1 < iVar2) {
    *(code **)(param_1 + 0x70) = FUN_00011550;
    *(code **)(param_1 + 0x80) = FUN_00011550;
    *(code **)(param_1 + 0x100) = FUN_00011300;
    *(code **)(param_1 + 0xe0) = FUN_00011300;
    *(code **)(param_1 + 0x68) = FUN_00011580;
    RtlInitUnicodeString(&DAT_00013070,u__DosDevices_SE64_00013020);
    iVar2 = IoCreateSymbolicLink(&DAT_00013070,local_30);
    if (iVar2 < 0) {
      IoDeleteDevice(local_38);
      return 0;
    }
    DAT_00013068 = 1;
    *(uint *)(local_38 + 0x30) = *(uint *)(local_38 + 0x30) | 4;
    plVar1 = *(longlong **)(local_38 + 0x40);
    *plVar1 = local_38;
    plVar1[7] = 0;
    plVar1[8] = 0;
    *(undefined4 *)(plVar1 + 9) = 0;
  }
  return 0;
}

