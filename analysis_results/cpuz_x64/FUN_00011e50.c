// Function: FUN_00011e50
// Address: 00011e50
// Decompiled by Ghidra


void FUN_00011e50(longlong param_1)

{
  longlong lVar1;
  undefined8 *puVar2;
  wchar_t *pwVar3;
  uint local_98 [2];
  undefined1 local_90 [16];
  undefined8 local_80 [5];
  undefined8 local_58;
  
  pwVar3 = L"\\DosDevices\\CPUZ128";
  puVar2 = local_80;
  for (lVar1 = 5; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = *(undefined8 *)pwVar3;
    pwVar3 = pwVar3 + 4;
    puVar2 = puVar2 + 1;
  }
  pwVar3 = L"\\DosDevices\\Global\\CPUZ128";
  puVar2 = &local_58;
  for (lVar1 = 6; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = *(undefined8 *)pwVar3;
    pwVar3 = pwVar3 + 4;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)puVar2 = *(undefined4 *)pwVar3;
  *(wchar_t *)((longlong)puVar2 + 4) = pwVar3[2];
  PsGetVersion(local_98,0,0,0);
  puVar2 = &local_58;
  if (local_98[0] < 5) {
    puVar2 = local_80;
  }
  RtlInitUnicodeString(local_90,puVar2);
  IoDeleteSymbolicLink(local_90);
  IoDeleteDevice(*(undefined8 *)(param_1 + 8));
  return;
}

