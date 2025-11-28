// Function: FUN_140001f1c
// Address: 140001f1c
// Decompiled by Ghidra


undefined8 FUN_140001f1c(undefined8 param_1,longlong param_2,longlong param_3)

{
  uint uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  
  lVar2 = *(longlong *)(param_2 + 0x18);
  uVar1 = *(uint *)(param_3 + 0x10);
  puVar3 = (undefined8 *)MmMapIoSpace(*(undefined8 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0x14),0);
  FUN_140003000((undefined8 *)(longlong)*(int *)(lVar2 + 0x18),puVar3,
                (ulonglong)*(uint *)(lVar2 + 0x14));
  MmUnmapIoSpace(puVar3,*(undefined4 *)(lVar2 + 0x14));
  *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar1;
  return 0;
}

