// Function: FUN_140001250
// Address: 140001250
// Decompiled by Ghidra


void FUN_140001250(longlong param_1,longlong param_2,longlong param_3)

{
  undefined8 uVar1;
  ushort *puVar2;
  undefined1 auStack_68 [32];
  undefined1 local_48 [24];
  uint local_30;
  uint local_2c;
  int local_28;
  uint local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = DAT_140005008 ^ (ulonglong)auStack_68;
  if ((*(int *)(param_3 + 0x10) == 0x34) && (*(int *)(param_3 + 8) == 0x34)) {
    uVar1 = *(undefined8 *)(param_1 + 0x40);
    *(undefined8 *)(param_2 + 0x38) = 0;
    puVar2 = *(ushort **)(param_2 + 0x18);
    KeAcquireInStackQueuedSpinLock(uVar1,local_48);
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_30 = 0x113e;
    local_2c = (uint)puVar2[0xb];
    local_28 = (uint)puVar2[9] + (uint)puVar2[8];
    local_24 = (uint)*puVar2;
    FUN_140001100((undefined8 *)&local_30);
    KeReleaseInStackQueuedSpinLock(local_48);
    if ((local_30 & 0xff00) == 0) {
      puVar2[0xb] = (ushort)local_20;
      *(undefined8 *)(param_2 + 0x38) = 0x34;
    }
  }
  FUN_140002e40(local_10 ^ (ulonglong)auStack_68);
  return;
}

