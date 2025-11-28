// Function: FUN_00014410
// Address: 00014410
// Decompiled by Ghidra


void FUN_00014410(longlong param_1)

{
  wchar_t *pwVar1;
  undefined8 *puVar2;
  undefined1 auStack_a8 [32];
  uint local_88 [2];
  undefined1 local_80 [16];
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
  wchar_t local_20 [4];
  wchar_t local_18 [2];
  wchar_t local_14;
  ulonglong local_10;
  
  local_10 = DAT_00016100 ^ (ulonglong)auStack_a8;
  puVar2 = &DAT_00016148;
  local_70 = (wchar_t  [4])u__DosDevices_CPUZ141_000149a0._0_8_;
  local_68 = (wchar_t  [4])u__DosDevices_CPUZ141_000149a0._8_8_;
  local_60 = (wchar_t  [4])u__DosDevices_CPUZ141_000149a0._16_8_;
  local_58 = (wchar_t  [4])u__DosDevices_CPUZ141_000149a0._24_8_;
  local_50 = (wchar_t  [4])u__DosDevices_CPUZ141_000149a0._32_8_;
  local_48 = (wchar_t  [4])u__DosDevices_Global_CPUZ141_000149d0._0_8_;
  local_40 = (wchar_t  [4])u__DosDevices_Global_CPUZ141_000149d0._8_8_;
  local_38 = (wchar_t  [4])u__DosDevices_Global_CPUZ141_000149d0._16_8_;
  local_30 = (wchar_t  [4])u__DosDevices_Global_CPUZ141_000149d0._24_8_;
  local_28 = (wchar_t  [4])u__DosDevices_Global_CPUZ141_000149d0._32_8_;
  local_20 = (wchar_t  [4])u__DosDevices_Global_CPUZ141_000149d0._40_8_;
  local_18 = (wchar_t  [2])u__DosDevices_Global_CPUZ141_000149d0._48_4_;
  local_14 = u__DosDevices_Global_CPUZ141_000149d0[0x1a];
  do {
    if (*(int *)(puVar2 + 1) != 0) {
      MmUnmapIoSpace(*puVar2,*(int *)(puVar2 + 1));
      *(undefined4 *)(puVar2 + -1) = 0;
      *(undefined4 *)((longlong)puVar2 + -4) = 0;
      *puVar2 = 0;
      *(undefined4 *)(puVar2 + 1) = 0;
    }
    puVar2 = puVar2 + 3;
  } while ((longlong)puVar2 < 0x16448);
  PsGetVersion(local_88,0,0,0);
  pwVar1 = local_48;
  if (local_88[0] < 5) {
    pwVar1 = local_70;
  }
  RtlInitUnicodeString(local_80,pwVar1);
  IoDeleteSymbolicLink(local_80);
  IoDeleteDevice(*(undefined8 *)(param_1 + 8));
  FUN_000145d0(local_10 ^ (ulonglong)auStack_a8);
  return;
}

