// Function: FUN_00011c80
// Address: 00011c80
// Decompiled by Ghidra


void FUN_00011c80(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  undefined8 uVar6;
  undefined8 local_d0;
  undefined1 local_c8 [16];
  undefined4 local_b8 [2];
  undefined8 local_b0;
  undefined1 *local_a8;
  undefined4 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined1 local_88 [16];
  undefined1 local_78 [16];
  undefined1 local_68 [16];
  wchar_t local_58 [4];
  wchar_t local_50 [4];
  wchar_t local_48 [4];
  wchar_t local_40 [4];
  wchar_t local_38 [4];
  wchar_t local_30 [4];
  wchar_t local_28 [4];
  wchar_t local_20 [4];
  wchar_t local_18 [4];
  longlong local_10;
  
  local_10 = DAT_00014108;
  local_58 = (wchar_t  [4])u__Device_CITMDRV_000129e0._0_8_;
  local_50 = (wchar_t  [4])u__Device_CITMDRV_000129e0._8_8_;
  local_48 = (wchar_t  [4])u__Device_CITMDRV_000129e0._16_8_;
  local_40 = (wchar_t  [4])u__Device_CITMDRV_000129e0._24_8_;
  local_38 = (wchar_t  [4])u__DosDevices_CITMDRV_00012390._0_8_;
  local_30 = (wchar_t  [4])u__DosDevices_CITMDRV_00012390._8_8_;
  local_28 = (wchar_t  [4])u__DosDevices_CITMDRV_00012390._16_8_;
  local_20 = (wchar_t  [4])u__DosDevices_CITMDRV_00012390._24_8_;
  local_18 = (wchar_t  [4])u__DosDevices_CITMDRV_00012390._32_8_;
  RtlInitUnicodeString(local_78,L"\\??\\C:\\CITMDRV.TRC");
  local_a8 = local_78;
  puVar5 = local_68;
  puVar4 = local_b8;
  uVar2 = 0x80000000;
  local_b8[0] = 0x30;
  local_b0 = 0;
  local_a0 = 0x40;
  local_98 = 0;
  local_90 = 0;
  iVar1 = ZwOpenFile(&local_d0);
  if (-1 < iVar1) {
    ZwClose(local_d0);
  }
  DAT_00014110 = (ulonglong)(-1 < iVar1);
  if (DAT_00014110 != 0) {
    DbgPrint("CITMDRV.SYS: DriverEntry...\n");
    FUN_00011010("CITMDRV.SYS: DriverEntry...\n",uVar2,puVar4,puVar5);
  }
  RtlInitUnicodeString(local_c8);
  puVar5 = local_c8;
  uVar6 = 0x8000;
  uVar2 = 0;
  iVar1 = IoCreateDevice(param_1);
  if (iVar1 < 0) {
    if (DAT_00014110 != 0) {
      DbgPrint("CITMDRV.SYS: IoCreateDevice failed\n");
      FUN_00011010("CITMDRV.SYS: IoCreateDevice failed\n",uVar2,puVar5,uVar6);
    }
  }
  else {
    *(code **)(param_1 + 0xe0) = FUN_00011b30;
    *(code **)(param_1 + 0x80) = FUN_00011b30;
    *(code **)(param_1 + 0x70) = FUN_00011b30;
    *(code **)(param_1 + 0x68) = FUN_000111e0;
    RtlInitUnicodeString(local_88,local_38);
    puVar3 = local_c8;
    iVar1 = IoCreateSymbolicLink(local_88);
    if (iVar1 < 0) {
      if (DAT_00014110 != 0) {
        DbgPrint("CITMDRV.SYS: IoCreateSymbolicLink failed\n");
        FUN_00011010("CITMDRV.SYS: IoCreateSymbolicLink failed\n",puVar3,puVar5,uVar6);
      }
      IoDeleteDevice(0);
    }
  }
  FUN_00012290(local_10);
  return;
}

