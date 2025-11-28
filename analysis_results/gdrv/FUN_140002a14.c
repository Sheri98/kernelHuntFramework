// Function: FUN_140002a14
// Address: 140002a14
// Decompiled by Ghidra


void FUN_140002a14(longlong param_1,longlong param_2,longlong param_3)

{
  ushort uVar1;
  undefined8 uVar2;
  ushort uVar3;
  undefined1 auStack_88 [32];
  undefined1 local_68 [24];
  uint local_50;
  uint local_4c;
  undefined4 local_48;
  uint local_44;
  short local_40;
  undefined2 uStack_3e;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  ulonglong local_30;
  
  local_30 = DAT_140005008 ^ (ulonglong)auStack_88;
  uVar3 = 0;
  DbgPrint("Entered SmartFanOFF");
  if ((*(int *)(param_3 + 0x10) == 0x34) && (*(int *)(param_3 + 8) == 0x34)) {
    uVar2 = *(undefined8 *)(param_1 + 0x40);
    *(undefined8 *)(param_2 + 0x38) = 0;
    uVar1 = **(ushort **)(param_2 + 0x18);
    KeAcquireInStackQueuedSpinLock(uVar2,local_68);
    for (; uVar3 < 0xb; uVar3 = uVar3 + 1) {
      local_4c = (uint)uVar3;
      local_44 = (uint)uVar1;
      local_40 = 0;
      uStack_3e = 0;
      uStack_3c = 0;
      local_38 = 0;
      uStack_34 = 0;
      local_50 = 0x113e;
      local_48 = 0;
      FUN_140001100((undefined8 *)&local_50);
      if (((local_50 & 0xff00) == 0) && (local_40 == 0xb)) {
        local_50 = 0x113e;
        local_40 = 0;
        uStack_3e = 0;
        uStack_3c = 0;
        local_38 = 0;
        uStack_34 = 0;
        local_48 = 4;
        local_4c = (uint)uVar3;
        local_44 = (uint)uVar1;
        FUN_140001100((undefined8 *)&local_50);
        uStack_3c = 0;
        local_38 = 0;
        uStack_34 = 0;
        local_50 = 0x113f;
        local_48 = 1;
        local_4c = (uint)uVar3;
        local_44 = (uint)uVar1;
        FUN_140001100((undefined8 *)&local_50);
        break;
      }
    }
    KeReleaseInStackQueuedSpinLock(local_68);
  }
  FUN_140002e40(local_30 ^ (ulonglong)auStack_88);
  return;
}

