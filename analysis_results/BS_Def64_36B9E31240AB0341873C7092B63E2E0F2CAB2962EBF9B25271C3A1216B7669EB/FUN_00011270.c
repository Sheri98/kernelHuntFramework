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
  uint uVar5;
  longlong lVar6;
  ushort uVar7;
  ushort *puVar8;
  int iVar9;
  char cVar10;
  
  cVar10 = '\0';
  if (DAT_00014040 == 0) {
    uVar4 = in_RAX & 0xffffffffffffff00;
  }
  else {
    iVar9 = -DAT_00014000;
    lVar6 = (ulonglong)DAT_00014050 + DAT_00014040;
    puVar8 = (ushort *)((ulonglong)DAT_00014054 + 0x10000 + DAT_00014040);
    uVar1 = *puVar8;
    uVar7 = 0;
    if (uVar1 != 0) {
      do {
        if (cVar10 != '\0') break;
        if (DAT_00014000 < 0x100001) {
          iVar3 = *(int *)(puVar8 + 2) + -0x100000;
        }
        else {
          iVar3 = iVar9 + *(int *)(puVar8 + 2);
        }
        *(int *)(lVar6 + 4) = iVar3;
        puVar8 = puVar8 + 4;
        *(undefined4 *)(lVar6 + 8) = *(undefined4 *)puVar8;
        uVar2 = *(uint *)(lVar6 + 4);
        uVar5 = -(DAT_00014058 + DAT_0001405c);
        if (DAT_00014060 == '\0') {
          if (uVar2 < uVar5) {
LAB_00011344:
            if (uVar2 <= uVar5) goto LAB_00011349;
            goto LAB_00011360;
          }
        }
        else if (uVar2 < uVar5) {
LAB_00011349:
          if (*(int *)(lVar6 + 8) + -1 + uVar2 == -1 - DAT_0001405c) {
            *(int *)(lVar6 + 8) = *(int *)(lVar6 + 8) - DAT_00014058;
          }
LAB_00011360:
          if (((DAT_000140d4 == '\0') || (*(uint *)(lVar6 + 4) < (uint)(DAT_00018320 + iVar9))) ||
             ((uint)(DAT_00018324 + DAT_00018320 + iVar9) <= *(uint *)(lVar6 + 4))) {
            out(DAT_0001404c,0x22);
            cVar10 = *(char *)(lVar6 + 0x10);
            FUN_00011240(0x32);
          }
        }
        else if (-DAT_0001405c - 1U < uVar2) goto LAB_00011344;
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar1);
    }
    uVar4 = (ulonglong)(cVar10 == '\0');
  }
  return uVar4;
}

