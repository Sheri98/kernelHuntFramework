// Function: FUN_000111e0
// Address: 000111e0
// Decompiled by Ghidra


void FUN_000111e0(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  wchar_t *pwVar1;
  undefined1 local_48 [16];
  wchar_t local_38 [4];
  wchar_t local_30 [4];
  wchar_t local_28 [4];
  wchar_t local_20 [4];
  wchar_t local_18 [4];
  longlong local_10;
  
  local_10 = DAT_00014108;
  local_38 = (wchar_t  [4])u__DosDevices_CITMDRV_00012390._0_8_;
  pwVar1 = local_38;
  local_30 = (wchar_t  [4])u__DosDevices_CITMDRV_00012390._8_8_;
  local_28 = (wchar_t  [4])u__DosDevices_CITMDRV_00012390._16_8_;
  local_20 = (wchar_t  [4])u__DosDevices_CITMDRV_00012390._24_8_;
  local_18 = (wchar_t  [4])u__DosDevices_CITMDRV_00012390._32_8_;
  RtlInitUnicodeString(local_48);
  IoDeleteSymbolicLink(local_48);
  if (DAT_00014110 != 0) {
    DbgPrint("CITMDRV.SYS: unload...\n");
    FUN_00011010("CITMDRV.SYS: unload...\n",pwVar1,param_3,param_4);
  }
  IoDeleteDevice(*(undefined8 *)(param_1 + 8));
  FUN_00012290(local_10);
  return;
}

