// Function: FUN_14000140c
// Address: 14000140c
// Decompiled by Ghidra


void FUN_14000140c(longlong param_1,longlong param_2,longlong param_3)

{
  undefined8 uVar1;
  ushort *puVar2;
  undefined4 uVar3;
  ushort uVar4;
  undefined1 auStack_78 [32];
  undefined1 local_58 [24];
  uint local_40;
  undefined4 uStack_3c;
  uint local_38;
  uint uStack_34;
  uint local_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  ulonglong local_20;
  
  local_20 = DAT_140005008 ^ (ulonglong)auStack_78;
  DbgPrint("Entered ChkCPUSmartFan");
  if ((*(int *)(param_3 + 0x10) != 0x34) || (*(int *)(param_3 + 8) != 0x34)) goto LAB_14000158b;
  uVar1 = *(undefined8 *)(param_1 + 0x40);
  puVar2 = *(ushort **)(param_2 + 0x18);
  *(undefined8 *)(param_2 + 0x38) = 0;
  KeAcquireInStackQueuedSpinLock(uVar1,local_58);
  local_38 = 0;
  local_30 = 0;
  uStack_2c = 0;
  local_28 = 0;
  uStack_24 = 0;
  local_40 = 0x113e;
  uStack_3c = 0;
  uStack_34 = (uint)*puVar2;
  FUN_140001100((undefined8 *)&local_40);
  if (((local_40 & 0xff00) == 0) && ((local_38 | 0xff00) >> 8 <= (local_38 | 0xff))) {
    local_30 = 0;
    uStack_2c = 0;
    local_28 = 0;
    uStack_3c = 1;
    local_38 = 0;
    uStack_24 = 0;
    local_40 = 0x113e;
    uStack_34 = (uint)*puVar2;
    FUN_140001100((undefined8 *)&local_40);
    uVar3 = 1;
    if ((local_30 & 5) != 5) {
      local_30 = 0;
      uStack_2c = 0;
      local_28 = 0;
      uStack_3c = 2;
      local_38 = 0;
      uStack_24 = 0;
      local_40 = 0x113e;
      uStack_34 = (uint)*puVar2;
      FUN_140001100((undefined8 *)&local_40);
      local_30 = local_30 & 5;
      uVar3 = 2;
      if (local_30 != 5) goto LAB_14000149e;
    }
    uStack_3c = uVar3;
    uVar4 = (ushort)uStack_3c;
    uStack_2c = 0;
    local_28 = 0;
    uStack_24 = 0;
    local_40 = 0x113f;
    local_38 = 0;
    uStack_34 = (uint)*puVar2;
    local_30 = 7;
    FUN_140001100((undefined8 *)&local_40);
    puVar2[0xb] = uVar4;
    KeReleaseInStackQueuedSpinLock(local_58);
    *(undefined8 *)(param_2 + 0x38) = 0x34;
  }
  else {
LAB_14000149e:
    KeReleaseInStackQueuedSpinLock(local_58);
  }
LAB_14000158b:
  FUN_140002e40(local_20 ^ (ulonglong)auStack_78);
  return;
}

