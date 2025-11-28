// Function: entry
// Address: 00011f50
// Decompiled by Ghidra


int entry(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  wchar_t *pwVar4;
  uint local_d8 [2];
  longlong local_d0;
  undefined1 local_c8 [16];
  undefined1 local_b8 [16];
  undefined8 local_a8 [4];
  undefined8 local_88 [5];
  undefined8 local_60;
  
  pwVar4 = L"\\Device\\cpuz128";
  puVar3 = local_a8;
  for (lVar2 = 4; lVar2 != 0; lVar2 = lVar2 + -1) {
    *puVar3 = *(undefined8 *)pwVar4;
    pwVar4 = pwVar4 + 4;
    puVar3 = puVar3 + 1;
  }
  pwVar4 = L"\\DosDevices\\CPUZ128";
  puVar3 = local_88;
  for (lVar2 = 5; lVar2 != 0; lVar2 = lVar2 + -1) {
    *puVar3 = *(undefined8 *)pwVar4;
    pwVar4 = pwVar4 + 4;
    puVar3 = puVar3 + 1;
  }
  pwVar4 = L"\\DosDevices\\Global\\CPUZ128";
  puVar3 = &local_60;
  for (lVar2 = 6; lVar2 != 0; lVar2 = lVar2 + -1) {
    *puVar3 = *(undefined8 *)pwVar4;
    pwVar4 = pwVar4 + 4;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)puVar3 = *(undefined4 *)pwVar4;
  *(wchar_t *)((longlong)puVar3 + 4) = pwVar4[2];
  local_d0 = 0;
  RtlInitUnicodeString(local_c8,local_a8);
  iVar1 = IoCreateDevice(param_1,4,local_c8,40000,0,1,&local_d0);
  if (-1 < iVar1) {
    PsGetVersion(local_d8,0,0,0);
    puVar3 = &local_60;
    if (local_d8[0] < 5) {
      puVar3 = local_88;
    }
    RtlInitUnicodeString(local_b8,puVar3);
    iVar1 = IoCreateSymbolicLink(local_b8,local_c8);
    if (iVar1 < 0) {
      if (local_d0 != 0) {
        IoDeleteDevice();
        return iVar1;
      }
    }
    else {
      *(code **)(param_1 + 0xe0) = FUN_00011000;
      *(code **)(param_1 + 0x80) = FUN_00011000;
      *(code **)(param_1 + 0x70) = FUN_00011000;
      *(code **)(param_1 + 0x68) = FUN_00011e50;
    }
  }
  return iVar1;
}

