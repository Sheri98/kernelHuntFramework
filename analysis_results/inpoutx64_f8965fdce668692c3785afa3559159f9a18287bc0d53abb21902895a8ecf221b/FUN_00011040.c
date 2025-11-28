// Function: FUN_00011040
// Address: 00011040
// Decompiled by Ghidra


void FUN_00011040(longlong param_1)

{
  undefined1 local_58 [16];
  wchar_t local_48 [4];
  wchar_t local_40 [4];
  wchar_t local_38 [4];
  wchar_t local_30 [4];
  wchar_t local_28 [4];
  wchar_t local_20 [4];
  longlong local_18;
  
  local_18 = DAT_00013108;
  local_48 = (wchar_t  [4])u__DosDevices_inpoutx64_00011a20._0_8_;
  local_40 = (wchar_t  [4])u__DosDevices_inpoutx64_00011a20._8_8_;
  local_38 = (wchar_t  [4])u__DosDevices_inpoutx64_00011a20._16_8_;
  local_30 = (wchar_t  [4])u__DosDevices_inpoutx64_00011a20._24_8_;
  local_28 = (wchar_t  [4])u__DosDevices_inpoutx64_00011a20._32_8_;
  local_20._0_4_ = u__DosDevices_inpoutx64_00011a20._40_4_;
  RtlInitUnicodeString(local_58,local_48);
  IoDeleteSymbolicLink(local_58);
  IoDeleteDevice(*(undefined8 *)(param_1 + 8));
  FUN_00011a00(local_18);
  return;
}

