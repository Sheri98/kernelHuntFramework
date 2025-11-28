// Function: FUN_000111e4
// Address: 000111e4
// Decompiled by Ghidra


void FUN_000111e4(void)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined1 auStack_158 [32];
  undefined1 local_138 [16];
  wchar_t local_128 [128];
  ulonglong local_28;
  
  local_28 = DAT_00014100 ^ (ulonglong)auStack_158;
  iVar3 = 0;
  if (0 < DAT_00014190) {
    puVar2 = &DAT_00014110;
    do {
      uVar1 = *puVar2;
      _snwprintf(local_128,0x3c,L"\\DosDevices\\driveragent%d");
      RtlInitUnicodeString(local_138,local_128);
      IoDeleteSymbolicLink(local_138);
      IoDeleteDevice(uVar1);
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar3 < DAT_00014190);
  }
  FUN_000127f0(local_28 ^ (ulonglong)auStack_158);
  return;
}

