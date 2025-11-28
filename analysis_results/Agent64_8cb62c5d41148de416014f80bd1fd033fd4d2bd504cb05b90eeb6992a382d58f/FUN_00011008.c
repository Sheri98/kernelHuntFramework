// Function: FUN_00011008
// Address: 00011008
// Decompiled by Ghidra


void FUN_00011008(longlong param_1)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  int iVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  undefined1 auStack_1c8 [32];
  undefined4 local_1a8;
  undefined1 local_1a0;
  longlong *local_198;
  longlong local_188;
  undefined1 local_180 [16];
  undefined1 local_170 [16];
  wchar_t local_160 [20];
  wchar_t local_138 [64];
  wchar_t local_b8 [64];
  ulonglong local_38;
  
  local_38 = DAT_00014100 ^ (ulonglong)auStack_1c8;
  DAT_00014190 = 0;
  iVar4 = 0;
  plVar5 = &DAT_00014110;
  do {
    _snwprintf(local_138,0x3c,L"\\Device\\driveragent%d");
    _snwprintf(local_b8,0x3c,L"\\DosDevices\\driveragent%d");
    _snwprintf(local_160,0x10,L"%d");
    RtlInitUnicodeString(local_180,local_138);
    local_198 = &local_188;
    local_1a0 = 0;
    local_1a8 = 0;
    iVar2 = IoCreateDevice(param_1,0xd8,local_180,0x8000);
    *plVar5 = local_188;
    FUN_00012860(*(ulonglong **)(local_188 + 0x40),0,0xd8);
    if (iVar2 < 0) break;
    RtlInitUnicodeString(local_170,local_b8);
    iVar2 = IoCreateSymbolicLink(local_170,local_180);
    if (iVar2 < 0) {
      IoDeleteDevice(local_188);
    }
    else {
      plVar1 = *(longlong **)(local_188 + 0x40);
      *(int *)((longlong)plVar1 + 0xc) = iVar4;
      *(undefined4 *)(plVar1 + 1) = 0;
      *plVar1 = local_188;
      KeInitializeDpc(local_188 + 200,FUN_000123d4);
      iVar2 = 0;
    }
    if (iVar2 < 0) break;
    iVar4 = iVar4 + 1;
    plVar5 = plVar5 + 1;
    DAT_00014190 = DAT_00014190 + 1;
  } while (iVar4 < 0x10);
  if (DAT_00014190 != 0) {
    puVar6 = (undefined8 *)(param_1 + 0x70);
    for (lVar3 = 0x1b; lVar3 != 0; lVar3 = lVar3 + -1) {
      *puVar6 = FUN_00011284;
      puVar6 = puVar6 + 1;
    }
    *(code **)(param_1 + 0x88) = FUN_00011ad4;
    *(code **)(param_1 + 0x68) = FUN_000111e4;
  }
  FUN_000127f0(local_38 ^ (ulonglong)auStack_1c8);
  return;
}

