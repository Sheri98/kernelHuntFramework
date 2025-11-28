// Function: FUN_00013230
// Address: 00013230
// Decompiled by Ghidra


void FUN_00013230(void)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  void *pvVar5;
  int iVar6;
  undefined1 auStack_98 [32];
  longlong local_78;
  undefined1 local_70 [4];
  uint local_6c;
  void *local_48;
  int local_40;
  undefined8 local_38;
  byte local_29;
  int local_28;
  int local_24;
  longlong local_20;
  ulonglong local_10;
  int iVar7;
  
  local_10 = DAT_00016100 ^ (ulonglong)auStack_98;
  iVar6 = 0;
  iVar7 = 0;
  DbgPrint("misc 287");
  local_78 = 0xe0000;
  iVar2 = DAT_00016140;
  if (DAT_00016114 != 0) {
    DAT_00016114 = 0;
    DbgPrint("misc 215");
    uVar3 = FUN_00012ff0(&local_38);
    iVar2 = iVar6;
    if (((int)uVar3 != 0) && (iVar2 = iVar7, local_24 != 0)) {
      local_78 = CONCAT44(local_78._4_4_,local_28);
      iVar2 = iVar6;
      if ((local_28 != 0) &&
         (uVar4 = FUN_00012eb0(local_78,local_70,0x24), uVar1 = local_6c, iVar2 = iVar7,
         (int)uVar4 == 0)) {
        local_40 = (int)((ulonglong)local_6c - 0x24 >> 2);
        if (local_40 != 0) {
          pvVar5 = (void *)ExAllocatePoolWithTag(0,(ulonglong)local_6c - 0x24,0x72736474);
          local_78 = CONCAT44(local_78._4_4_,local_28 + 0x24);
          local_48 = pvVar5;
          uVar4 = FUN_00012eb0(local_78,pvVar5,(ulonglong)(uVar1 - 0x24));
          iVar2 = iVar6;
          if ((int)uVar4 == 0) {
            iVar2 = FUN_00013430((longlong)local_70);
            pvVar5 = local_48;
          }
          ExFreePoolWithTag(pvVar5,0x72736474);
        }
      }
      local_78 = local_20;
      if ((((iVar2 == 0) && (1 < local_29)) && (local_20 != 0)) &&
         (uVar4 = FUN_00012eb0(local_20,local_70,0x24), (int)uVar4 == 0)) {
        local_40 = (int)((ulonglong)local_6c - 0x24 >> 3);
        if (local_40 != 0) {
          pvVar5 = (void *)ExAllocatePoolWithTag(0,(ulonglong)local_6c - 0x24,0x78736474);
          local_78 = CONCAT44(local_78._4_4_,(int)local_20 + 0x24);
          local_48 = pvVar5;
          uVar4 = FUN_00012eb0(local_78,pvVar5,(ulonglong)(local_6c - 0x24));
          if ((int)uVar4 == 0) {
            iVar2 = FUN_00013550((longlong)local_70);
            pvVar5 = local_48;
          }
          ExFreePoolWithTag(pvVar5,0x78736474);
        }
      }
    }
  }
  DAT_00016140 = iVar2;
  FUN_00013640(local_10 ^ (ulonglong)auStack_98);
  return;
}

