// Function: FUN_140001338
// Address: 140001338
// Decompiled by Ghidra


void FUN_140001338(longlong param_1,longlong param_2,longlong param_3)

{
  undefined8 uVar1;
  ushort *puVar2;
  undefined1 auStack_78 [32];
  undefined1 local_58 [24];
  undefined4 local_40;
  uint local_3c;
  int iStack_38;
  ulonglong local_34;
  undefined8 local_2c;
  undefined4 local_24;
  ulonglong local_20;
  
  local_20 = DAT_140005008 ^ (ulonglong)auStack_78;
  DbgPrint("Entered CPUTempPwmWrite");
  if ((*(int *)(param_3 + 0x10) == 0x34) && (*(int *)(param_3 + 8) == 0x34)) {
    uVar1 = *(undefined8 *)(param_1 + 0x40);
    puVar2 = *(ushort **)(param_2 + 0x18);
    *(undefined8 *)(param_2 + 0x38) = 0;
    KeAcquireInStackQueuedSpinLock(uVar1,local_58);
    local_2c = 0;
    local_24 = 0;
    local_40 = 0x113f;
    _local_3c = CONCAT44((uint)puVar2[9] + (uint)puVar2[8],(uint)puVar2[0xb]);
    local_34 = (ulonglong)CONCAT24(puVar2[10],(uint)*puVar2);
    FUN_140001100((undefined8 *)&local_40);
    KeReleaseInStackQueuedSpinLock(local_58);
  }
  FUN_140002e40(local_20 ^ (ulonglong)auStack_78);
  return;
}

