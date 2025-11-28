// Function: FUN_1400015ac
// Address: 1400015ac
// Decompiled by Ghidra


void FUN_1400015ac(longlong param_1,longlong param_2,longlong param_3)

{
  undefined8 uVar1;
  ushort *puVar2;
  bool bVar3;
  byte bVar4;
  ushort uVar5;
  undefined1 auStack_88 [32];
  undefined1 local_68 [24];
  undefined8 local_50;
  undefined4 local_48;
  uint uStack_44;
  short local_40;
  undefined2 uStack_3e;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  ulonglong local_30;
  
  local_30 = DAT_140005008 ^ (ulonglong)auStack_88;
  bVar3 = false;
  if ((*(int *)(param_3 + 0x10) == 0x34) && (*(int *)(param_3 + 8) == 0x34)) {
    uVar1 = *(undefined8 *)(param_1 + 0x40);
    puVar2 = *(ushort **)(param_2 + 0x18);
    *(undefined8 *)(param_2 + 0x38) = 0;
    KeAcquireInStackQueuedSpinLock(uVar1,local_68);
    local_48 = 0;
    local_40 = 0;
    uStack_3e = 0;
    uStack_3c = 0;
    local_38 = 0;
    uStack_34 = 0;
    uStack_44 = (uint)*puVar2;
    local_50 = 0x113e;
    FUN_140001100(&local_50);
    if (((local_50 & 0xff00) == 0) && (bVar4 = (byte)local_48, (byte)local_48 != 0)) {
      uVar5 = 1;
      do {
        if (bVar4 < uVar5) break;
        local_40 = 0;
        uStack_3e = 0;
        uStack_3c = 0;
        local_38 = 0;
        uStack_34 = 0;
        local_50 = (ulonglong)CONCAT24(uVar5,0x113e);
        local_48 = 0;
        uStack_44 = (uint)*puVar2;
        FUN_140001100(&local_50);
        if ((local_40 - 9U & 0xfffd) == 0) {
          bVar3 = true;
        }
        uVar5 = uVar5 + 1;
      } while (!bVar3);
      if (bVar3) {
        uStack_3c = 0;
        local_38 = 0;
        uStack_34 = 0;
        local_50 = CONCAT44(uVar5 - 1,0x113f);
        local_48 = 0;
        uStack_44 = (uint)*puVar2;
        local_40 = 0xb;
        uStack_3e = 0;
        FUN_140001100(&local_50);
      }
      KeReleaseInStackQueuedSpinLock(local_68);
    }
    else {
      KeReleaseInStackQueuedSpinLock(local_68);
    }
  }
  FUN_140002e40(local_30 ^ (ulonglong)auStack_88);
  return;
}

