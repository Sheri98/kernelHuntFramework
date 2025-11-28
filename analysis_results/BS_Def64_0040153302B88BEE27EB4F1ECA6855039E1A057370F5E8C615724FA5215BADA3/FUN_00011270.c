// Function: FUN_00011270
// Address: 00011270
// Decompiled by Ghidra


ulonglong FUN_00011270(void)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  ulonglong in_RAX;
  ulonglong uVar4;
  ushort uVar5;
  uint uVar6;
  longlong lVar7;
  int iVar8;
  ushort *puVar9;
  ushort uVar10;
  char cVar11;
  
  cVar11 = '\0';
  if (DAT_00014040 == 0) {
    uVar4 = in_RAX & 0xffffffffffffff00;
  }
  else {
    iVar8 = -DAT_00014000;
    lVar7 = (ulonglong)DAT_00014050 + DAT_00014040;
    puVar9 = (ushort *)((ulonglong)DAT_00014054 + 0x10000 + DAT_00014040);
    uVar1 = *puVar9;
    uVar10 = 0;
    if (uVar1 != 0) {
      do {
        if (cVar11 != '\0') break;
        if (DAT_00014000 < 0x100001) {
          iVar3 = *(int *)(puVar9 + 2) + -0x100000;
        }
        else {
          iVar3 = iVar8 + *(int *)(puVar9 + 2);
        }
        *(int *)(lVar7 + 4) = iVar3;
        puVar9 = puVar9 + 4;
        *(undefined4 *)(lVar7 + 8) = *(undefined4 *)puVar9;
        uVar2 = *(uint *)(lVar7 + 4);
        uVar6 = -(DAT_00014058 + DAT_0001405c);
        if (DAT_00014060 == '\0') {
          if (uVar2 < uVar6) {
LAB_0001134c:
            if (uVar2 <= uVar6) goto LAB_00011350;
            goto LAB_0001136a;
          }
        }
        else if (uVar2 < uVar6) {
LAB_00011350:
          if (*(int *)(lVar7 + 8) + -1 + uVar2 == -1 - DAT_0001405c) {
            *(int *)(lVar7 + 8) = *(int *)(lVar7 + 8) - DAT_00014058;
          }
LAB_0001136a:
          if ((DAT_000140d4 != '\0') && (uVar4 = 0, DAT_000140d8 != 0)) {
            do {
              if (((uint)((&DAT_00018324)[uVar4 * 3] + iVar8) <= *(uint *)(lVar7 + 4)) &&
                 (*(uint *)(lVar7 + 4) <
                  (uint)((&DAT_00018328)[uVar4 * 3] + (&DAT_00018324)[uVar4 * 3] + iVar8)))
              goto LAB_000113c9;
              uVar5 = (short)uVar4 + 1;
              uVar4 = (ulonglong)uVar5;
            } while (uVar5 < DAT_000140d8);
          }
          out(DAT_0001404c,0x22);
          cVar11 = *(char *)(lVar7 + 0x10);
LAB_000113c9:
          FUN_00011240(0x32);
        }
        else if (-DAT_0001405c - 1U < uVar2) goto LAB_0001134c;
        uVar10 = uVar10 + 1;
      } while (uVar10 < uVar1);
    }
    uVar4 = (ulonglong)(cVar11 == '\0');
  }
  return uVar4;
}

