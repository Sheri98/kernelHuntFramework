// Function: FUN_00011f00
// Address: 00011f00
// Decompiled by Ghidra


void FUN_00011f00(longlong param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  undefined1 *puVar3;
  undefined1 auStack_88 [40];
  undefined1 local_60 [40];
  undefined1 local_38 [16];
  ulonglong local_28;
  
  local_28 = DAT_00014100 ^ (ulonglong)auStack_88;
  pwVar2 = L"\\DosDevices\\IoMem";
  puVar3 = local_60;
  for (lVar1 = 0x24; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = (char)*pwVar2;
    pwVar2 = (wchar_t *)((longlong)pwVar2 + 1);
    puVar3 = puVar3 + 1;
  }
  if (DAT_00014110 != 0) {
    MmFreeNonCachedMemory(DAT_00014110,0x2000);
  }
  RtlInitUnicodeString(local_38,local_60);
  IoDeleteSymbolicLink(local_38);
  IoDeleteDevice(*(undefined8 *)(param_1 + 8));
  FUN_00012250(local_28 ^ (ulonglong)auStack_88);
  return;
}

