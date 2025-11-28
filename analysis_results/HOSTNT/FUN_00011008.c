// Function: FUN_00011008
// Address: 00011008
// Decompiled by Ghidra


void FUN_00011008(longlong param_1)

{
  int iVar1;
  undefined1 auStack_c8 [32];
  undefined4 local_a8;
  undefined1 local_a0;
  undefined8 *local_98;
  undefined8 local_88;
  undefined1 local_80 [16];
  undefined1 local_70 [16];
  wchar_t local_60 [4];
  wchar_t local_58 [4];
  wchar_t local_50 [4];
  wchar_t local_48 [2];
  wchar_t local_44;
  undefined8 local_40 [5];
  ulonglong local_18;
  
  local_18 = DAT_00013100 ^ (ulonglong)auStack_c8;
  local_88 = 0;
  local_60 = (wchar_t  [4])u__Device_HostNt_00011910._0_8_;
  local_58 = (wchar_t  [4])u__Device_HostNt_00011910._8_8_;
  local_50 = (wchar_t  [4])u__Device_HostNt_00011910._16_8_;
  local_48 = (wchar_t  [2])u__Device_HostNt_00011910._24_4_;
  local_44 = u__Device_HostNt_00011910[0xe];
  FUN_00011540(local_40,(undefined8 *)L"\\DosDevices\\HostNt",0x26);
  RtlInitUnicodeString(local_80,local_60);
  local_98 = &local_88;
  local_a0 = 1;
  local_a8 = 0;
  iVar1 = IoCreateDevice(param_1,0,local_80,0x8000);
  if (-1 < iVar1) {
    *(code **)(param_1 + 0xe0) = FUN_00011144;
    *(code **)(param_1 + 0x80) = FUN_00011144;
    *(code **)(param_1 + 0x70) = FUN_00011144;
    *(code **)(param_1 + 0x68) = FUN_000111c4;
    RtlInitUnicodeString(local_70,local_40);
    iVar1 = IoCreateSymbolicLink(local_70,local_80);
    if (iVar1 < 0) {
      IoDeleteDevice(local_88);
    }
  }
  FUN_000114e0(local_18 ^ (ulonglong)auStack_c8);
  return;
}

