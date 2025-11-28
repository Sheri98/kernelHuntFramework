// Function: FUN_00012240
// Address: 00012240
// Decompiled by Ghidra


int FUN_00012240(longlong param_1)

{
  undefined8 *puVar1;
  int iVar2;
  longlong lVar3;
  longlong local_res8 [2];
  undefined1 local_28 [16];
  undefined1 local_18 [24];
  
  *(code **)(param_1 + 0x70) = FUN_00011f50;
  *(code **)(param_1 + 0x80) = FUN_00011f50;
  *(code **)(param_1 + 0xe0) = FUN_00011f50;
  *(code **)(param_1 + 0x68) = FUN_00011ea0;
  *(undefined8 *)(param_1 + 0x60) = 0;
  RtlInitUnicodeString(local_28,L"\\Device\\CrystalSysInfo");
  iVar2 = IoCreateDevice(param_1,0x390,local_28,40000,0,0,local_res8);
  if (-1 < iVar2) {
    FUN_00012390(*(ulonglong **)(local_res8[0] + 0x40),0,0x390);
    RtlInitUnicodeString(local_18,L"\\DosDevices\\CrystalSysInfo");
    iVar2 = IoCreateSymbolicLink(local_18,local_28);
    if (iVar2 < 0) {
      IoDeleteDevice(local_res8[0]);
    }
  }
  DAT_00014190 = 0xffffffff;
  if (-1 < iVar2) {
    DAT_00014190 = 0;
  }
  puVar1 = *(undefined8 **)(local_res8[0] + 0x40);
  puVar1[1] = local_res8[0];
  *(undefined4 *)puVar1 = 40000;
  lVar3 = 0x10;
  do {
    *(undefined1 *)(puVar1 + 3) = 0;
    puVar1[7] = 0;
    lVar3 = lVar3 + -1;
    puVar1 = puVar1 + 7;
  } while (lVar3 != 0);
  KeInitializeDpc(local_res8[0] + 200,&DAT_00011730);
  return iVar2;
}

