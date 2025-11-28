// Function: FUN_140002b4c
// Address: 140002b4c
// Decompiled by Ghidra


void FUN_140002b4c(longlong param_1,longlong param_2,longlong param_3)

{
  ushort uVar1;
  undefined8 uVar2;
  ushort uVar3;
  undefined1 auStack_78 [32];
  undefined1 local_58 [24];
  undefined4 local_40;
  uint local_3c;
  undefined4 local_38;
  uint local_34;
  undefined8 local_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = DAT_140005008 ^ (ulonglong)auStack_78;
  uVar3 = 1;
  DbgPrint("Entered SmartFanON");
  if ((*(int *)(param_3 + 0x10) == 0x34) && (*(int *)(param_3 + 8) == 0x34)) {
    uVar2 = *(undefined8 *)(param_1 + 0x40);
    *(undefined8 *)(param_2 + 0x38) = 0;
    uVar1 = **(ushort **)(param_2 + 0x18);
    KeAcquireInStackQueuedSpinLock(uVar2,local_58);
    for (; uVar3 < 0xb; uVar3 = uVar3 + 1) {
      local_3c = (uint)uVar3;
      local_34 = (uint)uVar1;
      local_30 = 0;
      local_28 = 0;
      local_40 = 0x113e;
      local_38 = 0;
    }
    KeReleaseInStackQueuedSpinLock(local_58);
  }
  FUN_140002e40(local_20 ^ (ulonglong)auStack_78);
  return;
}

