// Function: FUN_00011520
// Address: 00011520
// Decompiled by Ghidra


void FUN_00011520(longlong param_1)

{
  int iVar1;
  undefined1 local_98 [16];
  undefined1 local_88 [16];
  undefined1 local_78 [8];
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
  longlong local_18;
  
  local_18 = DAT_00013108;
  local_70 = (wchar_t  [4])u__Device_inpoutx64_00011a80._0_8_;
  local_68 = (wchar_t  [4])u__Device_inpoutx64_00011a80._8_8_;
  local_60 = (wchar_t  [4])u__Device_inpoutx64_00011a80._16_8_;
  local_58 = (wchar_t  [4])u__Device_inpoutx64_00011a80._24_8_;
  local_50._0_4_ = u__Device_inpoutx64_00011a80._32_4_;
  local_48 = (wchar_t  [4])u__DosDevices_inpoutx64_00011a20._0_8_;
  local_40 = (wchar_t  [4])u__DosDevices_inpoutx64_00011a20._8_8_;
  local_38 = (wchar_t  [4])u__DosDevices_inpoutx64_00011a20._16_8_;
  local_30 = (wchar_t  [4])u__DosDevices_inpoutx64_00011a20._24_8_;
  local_28 = (wchar_t  [4])u__DosDevices_inpoutx64_00011a20._32_8_;
  local_20._0_4_ = u__DosDevices_inpoutx64_00011a20._40_4_;
  RtlInitUnicodeString(local_98,local_70);
  RtlInitUnicodeString(local_88,local_48);
  iVar1 = IoCreateDevice(param_1,0,local_98,0x22,0,0,local_78);
  if (-1 < iVar1) {
    iVar1 = IoCreateSymbolicLink(local_88,local_98);
    if (-1 < iVar1) {
      *(code **)(param_1 + 0x70) = FUN_00011010;
      *(code **)(param_1 + 0xe0) = FUN_000112f0;
      *(code **)(param_1 + 0x68) = FUN_00011040;
    }
  }
  FUN_00011a00(local_18);
  return;
}

