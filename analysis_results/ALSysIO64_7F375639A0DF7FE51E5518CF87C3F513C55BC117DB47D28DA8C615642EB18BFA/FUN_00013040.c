// Function: FUN_00013040
// Address: 00013040
// Decompiled by Ghidra


void FUN_00013040(void)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined4 *puVar4;
  void *pvVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint uVar8;
  ulonglong uVar9;
  undefined1 auStack_98 [32];
  ulonglong local_78;
  undefined8 local_70;
  byte local_61;
  int local_60;
  int local_5c;
  ulonglong local_58;
  undefined1 local_48 [4];
  uint local_44;
  ulonglong local_18;
  
  local_18 = DAT_00015100 ^ (ulonglong)auStack_98;
  uVar9 = 0;
  local_78 = 0xe0000;
  uVar2 = FUN_00012e10(&local_70);
  if (((int)uVar2 != 0) && (local_5c != 0)) {
    local_78 = CONCAT44(local_78._4_4_,local_60);
    if ((local_60 != 0) &&
       (uVar3 = FUN_00012c00(local_78,local_48,0x24), uVar6 = local_44, (int)uVar3 == 0)) {
      uVar8 = (uint)((ulonglong)local_44 - 0x24 >> 2);
      if (uVar8 != 0) {
        puVar4 = (undefined4 *)ExAllocatePoolWithTag(0,(ulonglong)local_44 - 0x24,0x72736474);
        local_78 = CONCAT44(local_78._4_4_,local_60 + 0x24);
        uVar3 = FUN_00012c00(local_78,puVar4,(ulonglong)(uVar6 - 0x24));
        if (((int)uVar3 == 0) &&
           (local_78 = local_78 & 0xffffffff, uVar2 = uVar9, puVar7 = puVar4, uVar8 != 0)) {
          do {
            local_78 = CONCAT44(local_78._4_4_,*puVar7);
            iVar1 = FUN_00013250(local_78);
            if (iVar1 != 0) break;
            uVar6 = (int)uVar2 + 1;
            uVar2 = (ulonglong)uVar6;
            puVar7 = puVar7 + 1;
          } while (uVar6 < uVar8);
        }
        ExFreePoolWithTag(puVar4,0x72736474);
      }
    }
    if ((((DAT_00015188 == 0) && (DAT_00015180 == 0)) && (local_78 = local_58, 1 < local_61)) &&
       ((local_58 != 0 && (uVar3 = FUN_00012c00(local_58,local_48,0x24), (int)uVar3 == 0)))) {
      uVar6 = (uint)((ulonglong)local_44 - 0x24 >> 3);
      if (uVar6 != 0) {
        pvVar5 = (void *)ExAllocatePoolWithTag(0,(ulonglong)local_44 - 0x24,0x78736474);
        local_78 = CONCAT44(local_78._4_4_,(int)local_58 + 0x24);
        uVar3 = FUN_00012c00(local_78,pvVar5,(ulonglong)(local_44 - 0x24));
        if (((int)uVar3 == 0) && (uVar6 != 0)) {
          do {
            iVar1 = FUN_00013250(*(undefined8 *)((longlong)pvVar5 + uVar9 * 8));
            if (iVar1 != 0) break;
            uVar8 = (int)uVar9 + 1;
            uVar9 = (ulonglong)uVar8;
          } while (uVar8 < uVar6);
        }
        ExFreePoolWithTag(pvVar5,0x78736474);
      }
    }
  }
  FUN_000133b0(local_18 ^ (ulonglong)auStack_98);
  return;
}

