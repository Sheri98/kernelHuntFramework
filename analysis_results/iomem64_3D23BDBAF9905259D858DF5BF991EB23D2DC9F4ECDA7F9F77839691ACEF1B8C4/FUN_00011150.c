// Function: FUN_00011150
// Address: 00011150
// Decompiled by Ghidra


void FUN_00011150(longlong param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  undefined1 *puVar3;
  undefined1 auStack_e8 [32];
  undefined4 local_c8;
  undefined1 local_c0;
  undefined1 *local_b8;
  undefined1 local_a0 [40];
  undefined1 local_78 [8];
  undefined1 local_70 [16];
  undefined1 local_60 [16];
  undefined1 local_50 [32];
  int local_30;
  ulonglong local_28;
  
  local_28 = DAT_00014100 ^ (ulonglong)auStack_e8;
  pwVar2 = L"\\Device\\IoMem64";
  puVar3 = local_50;
  for (lVar1 = 0x20; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = (char)*pwVar2;
    pwVar2 = (wchar_t *)((longlong)pwVar2 + 1);
    puVar3 = puVar3 + 1;
  }
  pwVar2 = L"\\DosDevices\\IoMem64";
  puVar3 = local_a0;
  for (lVar1 = 0x28; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = (char)*pwVar2;
    pwVar2 = (wchar_t *)((longlong)pwVar2 + 1);
    puVar3 = puVar3 + 1;
  }
  DAT_00014110 = (undefined1 *)MmAllocateNonCachedMemory(0x2000);
  if (DAT_00014110 != (undefined1 *)0x0) {
    puVar3 = DAT_00014110;
    for (lVar1 = 0x2000; lVar1 != 0; lVar1 = lVar1 + -1) {
      *puVar3 = 0xff;
      puVar3 = puVar3 + 1;
    }
    RtlInitUnicodeString(local_60,local_50);
    RtlInitUnicodeString(local_70,local_a0);
    local_b8 = local_78;
    local_c0 = 0;
    local_c8 = 0;
    local_30 = IoCreateDevice(param_1,0,local_60,0x22);
    if ((-1 < local_30) && (local_30 = IoCreateSymbolicLink(local_70,local_60), -1 < local_30)) {
      *(code **)(param_1 + 0x70) = FUN_00011100;
      *(code **)(param_1 + 0xe0) = FUN_000112e0;
      *(code **)(param_1 + 0x68) = FUN_00011f00;
    }
  }
  FUN_00012250(local_28 ^ (ulonglong)auStack_e8);
  return;
}

