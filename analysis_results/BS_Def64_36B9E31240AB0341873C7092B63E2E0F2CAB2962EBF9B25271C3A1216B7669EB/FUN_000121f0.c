// Function: FUN_000121f0
// Address: 000121f0
// Decompiled by Ghidra


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_000121f0(void)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  byte bVar4;
  ulonglong uVar5;
  longlong lVar6;
  uint uVar7;
  undefined1 uVar8;
  char local_30 [32];
  
  builtin_strncpy(local_30,"$BKINFO$",9);
  uVar8 = 0;
  uVar7 = 0;
  lVar3 = MmMapIoSpace(-DAT_00014000,DAT_00014000 - 1,0);
  uVar2 = DAT_00014000;
  if (lVar3 == 0) {
    return 0;
  }
  if (DAT_00014000 != 0) {
    do {
      uVar5 = 0;
      while (*(char *)(uVar7 + uVar5 + lVar3) == local_30[uVar5]) {
        bVar4 = (byte)uVar5 + 1;
        uVar5 = (ulonglong)bVar4;
        if (7 < bVar4) goto LAB_00012287;
      }
      if (7 < (byte)uVar5) {
LAB_00012287:
        lVar1 = (ulonglong)uVar7 + 8 + lVar3;
        _DAT_000140d8 = 1;
        _DAT_000140dc = *(undefined2 *)(lVar1 + 2);
        uVar5 = 0;
        do {
          lVar6 = ((int)uVar5 << 3) + lVar1;
          (&DAT_00018320)[uVar5 * 2] = *(undefined4 *)(lVar6 + 4);
          (&DAT_00018324)[uVar5 * 2] = *(undefined4 *)(lVar6 + 8);
          bVar4 = (char)uVar5 + 1;
          uVar5 = (ulonglong)bVar4;
        } while (bVar4 == 0);
        uVar8 = 1;
        break;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < DAT_00014000);
  }
  MmUnmapIoSpace(lVar3,uVar2 - 1);
  return uVar8;
}

