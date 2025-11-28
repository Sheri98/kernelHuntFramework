// Function: FUN_00011390
// Address: 00011390
// Decompiled by Ghidra


void FUN_00011390(longlong param_1)

{
  int iVar1;
  undefined4 *puVar2;
  wchar_t *pwVar3;
  undefined1 auStack_108 [32];
  undefined4 local_e8;
  undefined1 local_e0;
  longlong *local_d8;
  uint local_c8 [2];
  longlong local_c0;
  undefined1 local_b8 [16];
  undefined1 local_a8 [16];
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  wchar_t local_78 [4];
  wchar_t local_70 [4];
  wchar_t local_68 [4];
  wchar_t local_60 [4];
  wchar_t local_58 [4];
  wchar_t local_50 [4];
  wchar_t local_48 [4];
  wchar_t local_40 [4];
  wchar_t local_38 [4];
  wchar_t local_30 [4];
  wchar_t local_28 [4];
  wchar_t local_20 [2];
  wchar_t local_1c;
  ulonglong local_18;
  
  local_18 = DAT_00016100 ^ (ulonglong)auStack_108;
  local_98 = DAT_00014980;
  local_c0 = 0;
  local_90 = DAT_00014988;
  local_88 = DAT_00014990;
  local_80 = DAT_00014998;
  local_78 = (wchar_t  [4])u__DosDevices_CPUZ141_000149a0._0_8_;
  local_70 = (wchar_t  [4])u__DosDevices_CPUZ141_000149a0._8_8_;
  local_68 = (wchar_t  [4])u__DosDevices_CPUZ141_000149a0._16_8_;
  local_60 = (wchar_t  [4])u__DosDevices_CPUZ141_000149a0._24_8_;
  local_58 = (wchar_t  [4])u__DosDevices_CPUZ141_000149a0._32_8_;
  local_50 = (wchar_t  [4])u__DosDevices_Global_CPUZ141_000149d0._0_8_;
  local_48 = (wchar_t  [4])u__DosDevices_Global_CPUZ141_000149d0._8_8_;
  local_40 = (wchar_t  [4])u__DosDevices_Global_CPUZ141_000149d0._16_8_;
  local_38 = (wchar_t  [4])u__DosDevices_Global_CPUZ141_000149d0._24_8_;
  local_30 = (wchar_t  [4])u__DosDevices_Global_CPUZ141_000149d0._32_8_;
  local_28 = (wchar_t  [4])u__DosDevices_Global_CPUZ141_000149d0._40_8_;
  local_20 = (wchar_t  [2])u__DosDevices_Global_CPUZ141_000149d0._48_4_;
  local_1c = u__DosDevices_Global_CPUZ141_000149d0[0x1a];
  RtlInitUnicodeString(local_b8,&local_98);
  local_d8 = &local_c0;
  local_e0 = 1;
  local_e8 = 0;
  iVar1 = IoCreateDevice(param_1,4,local_b8,40000);
  if (-1 < iVar1) {
    PsGetVersion(local_c8,0,0,0);
    pwVar3 = local_50;
    if (local_c8[0] < 5) {
      pwVar3 = local_78;
    }
    RtlInitUnicodeString(local_a8,pwVar3);
    iVar1 = IoCreateSymbolicLink(local_a8,local_b8);
    if (iVar1 < 0) {
      if (local_c0 != 0) {
        IoDeleteDevice();
      }
    }
    else {
      *(code **)(param_1 + 0xe0) = FUN_000115b0;
      *(code **)(param_1 + 0x80) = FUN_000115b0;
      *(code **)(param_1 + 0x70) = FUN_000115b0;
      *(code **)(param_1 + 0x68) = FUN_00014410;
      puVar2 = (undefined4 *)((longlong)&DAT_00016140 + 4);
      do {
        puVar2[-1] = 0;
        *puVar2 = 0;
        *(undefined8 *)(puVar2 + 1) = 0;
        puVar2[3] = 0;
        puVar2 = puVar2 + 6;
      } while ((longlong)puVar2 < 0x16444);
    }
  }
  FUN_000145d0(local_18 ^ (ulonglong)auStack_108);
  return;
}

