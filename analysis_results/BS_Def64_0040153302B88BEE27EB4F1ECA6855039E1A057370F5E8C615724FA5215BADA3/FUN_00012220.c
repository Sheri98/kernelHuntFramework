// Function: FUN_00012220
// Address: 00012220
// Decompiled by Ghidra


undefined1 FUN_00012220(void)

{
  ushort *puVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  longlong lVar5;
  byte bVar6;
  ulonglong uVar7;
  uint uVar8;
  undefined1 uVar9;
  char local_40 [32];
  
  builtin_strncpy(local_40,"$BKINFO$",9);
  uVar9 = 0;
  uVar8 = 0;
  lVar5 = MmMapIoSpace(-DAT_00014000,DAT_00014000 - 1,0);
  uVar4 = DAT_00014000;
  if (lVar5 == 0) {
    return 0;
  }
  if (DAT_00014000 != 0) {
    do {
      uVar7 = 0;
      while (*(char *)(uVar8 + uVar7 + lVar5) == local_40[uVar7]) {
        bVar6 = (byte)uVar7 + 1;
        uVar7 = (ulonglong)bVar6;
        if (7 < bVar6) goto LAB_000122c5;
      }
      if (7 < (byte)uVar7) {
LAB_000122c5:
        puVar1 = (ushort *)((ulonglong)uVar8 + 8 + lVar5);
        uVar2 = *puVar1;
        uVar7 = 0;
        DAT_000140d8 = uVar2;
        if (uVar2 != 0) {
          do {
            iVar3 = (int)uVar7;
            (&DAT_00018320)[uVar7 * 6] =
                 *(undefined2 *)((longlong)puVar1 + (longlong)(iVar3 * 10) + 2);
            (&DAT_00018324)[uVar7 * 3] =
                 *(undefined4 *)((longlong)puVar1 + (longlong)(iVar3 * 10) + 4);
            (&DAT_00018328)[uVar7 * 3] =
                 *(undefined4 *)((longlong)puVar1 + (longlong)(iVar3 * 10) + 8);
            bVar6 = (char)uVar7 + 1;
            uVar7 = (ulonglong)bVar6;
          } while (bVar6 < uVar2);
        }
        uVar9 = 1;
        break;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < DAT_00014000);
  }
  MmUnmapIoSpace(lVar5,uVar4 - 1);
  return uVar9;
}

