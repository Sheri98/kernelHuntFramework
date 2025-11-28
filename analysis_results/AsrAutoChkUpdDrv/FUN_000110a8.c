// Function: FUN_000110a8
// Address: 000110a8
// Decompiled by Ghidra


int FUN_000110a8(longlong param_1,longlong param_2)

{
  ushort uVar1;
  int iVar2;
  ulonglong *puVar3;
  longlong lVar4;
  undefined4 uVar5;
  undefined1 uVar6;
  undefined2 uVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 *puVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  byte *pbVar15;
  int iVar16;
  uint uVar17;
  longlong lVar18;
  short sVar19;
  ulonglong in_CR0;
  ulonglong in_CR2;
  ulonglong in_CR3;
  ulonglong in_CR4;
  ulonglong in_CR8;
  
  puVar3 = *(ulonglong **)(param_2 + 0x18);
  iVar9 = 0;
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  if (**(char **)(param_2 + 0xb8) != '\x0e') goto LAB_0001197a;
  uVar17 = *(uint *)(*(char **)(param_2 + 0xb8) + 0x18);
  if (uVar17 < 0x222859) {
    if (uVar17 == 0x222858) {
      uVar11 = FUN_00011b1c((short *)puVar3);
      *(int *)(param_2 + 0x30) = (int)uVar11;
      if (-1 < (int)uVar11) {
        *(undefined8 *)(param_2 + 0x38) = 0x204;
      }
      goto LAB_0001197a;
    }
    if (uVar17 < 0x222831) {
      if (uVar17 != 0x222830) {
        if (uVar17 != 0x222808) {
          if (uVar17 == 0x22280c) {
            puVar10 = (undefined4 *)MmMapIoSpace(*puVar3,(int)puVar3[1],0);
            if (puVar10 == (undefined4 *)0x0) {
              iVar9 = -0x3fffffff;
            }
            else {
              puVar14 = (undefined4 *)puVar3[2];
              iVar16 = (int)puVar3[1];
              puVar13 = puVar10;
              while (iVar16 != 0) {
                iVar2 = *(int *)((longlong)puVar3 + 0xc);
                if (iVar2 == 0) {
                  uVar6 = *(undefined1 *)puVar14;
                  puVar14 = (undefined4 *)((longlong)puVar14 + 1);
                  *(undefined1 *)puVar13 = uVar6;
                  puVar13 = (undefined4 *)((longlong)puVar13 + 1);
                  iVar16 = iVar16 + -1;
                }
                else if (iVar2 == 1) {
                  uVar7 = *(undefined2 *)puVar14;
                  puVar14 = (undefined4 *)((longlong)puVar14 + 2);
                  *(undefined2 *)puVar13 = uVar7;
                  puVar13 = (undefined4 *)((longlong)puVar13 + 2);
                  iVar16 = iVar16 + -2;
                }
                else if (iVar2 == 2) {
                  uVar8 = *puVar14;
                  puVar14 = puVar14 + 1;
                  *puVar13 = uVar8;
                  puVar13 = puVar13 + 1;
                  iVar16 = iVar16 + -4;
                }
              }
              MmUnmapIoSpace(puVar10,(int)puVar3[1]);
            }
            goto LAB_00011220;
          }
          if (uVar17 == 0x222810) {
            uVar6 = in((short)*puVar3);
            *(undefined1 *)((longlong)puVar3 + 4) = uVar6;
          }
          else {
            if (uVar17 == 0x222814) {
              out((short)*puVar3,*(undefined1 *)((longlong)puVar3 + 4));
              goto LAB_0001197a;
            }
            if (uVar17 == 0x222818) {
              uVar7 = in((short)*puVar3);
              *(undefined2 *)((longlong)puVar3 + 4) = uVar7;
            }
            else {
              if (uVar17 == 0x22281c) {
                out((short)*puVar3,*(undefined2 *)((longlong)puVar3 + 4));
                goto LAB_0001197a;
              }
              if (uVar17 != 0x222820) {
                if (uVar17 == 0x222824) {
                  out((short)*puVar3,*(undefined4 *)((longlong)puVar3 + 4));
                  goto LAB_0001197a;
                }
                goto LAB_00011894;
              }
              uVar8 = in((short)*puVar3);
              *(undefined4 *)((longlong)puVar3 + 4) = uVar8;
            }
          }
          goto LAB_0001118f;
        }
        puVar10 = (undefined4 *)MmMapIoSpace(*puVar3,(int)puVar3[1],0);
        if (puVar10 == (undefined4 *)0x0) {
          iVar9 = -0x3fffffff;
        }
        else {
          puVar14 = (undefined4 *)puVar3[2];
          iVar16 = (int)puVar3[1];
          puVar13 = puVar10;
          while (iVar16 != 0) {
            iVar2 = *(int *)((longlong)puVar3 + 0xc);
            if (iVar2 == 0) {
              uVar6 = *(undefined1 *)puVar13;
              puVar13 = (undefined4 *)((longlong)puVar13 + 1);
              *(undefined1 *)puVar14 = uVar6;
              puVar14 = (undefined4 *)((longlong)puVar14 + 1);
              iVar16 = iVar16 + -1;
            }
            else if (iVar2 == 1) {
              uVar7 = *(undefined2 *)puVar13;
              puVar13 = (undefined4 *)((longlong)puVar13 + 2);
              *(undefined2 *)puVar14 = uVar7;
              puVar14 = (undefined4 *)((longlong)puVar14 + 2);
              iVar16 = iVar16 + -2;
            }
            else if (iVar2 == 2) {
              uVar8 = *puVar13;
              puVar13 = puVar13 + 1;
              *puVar14 = uVar8;
              puVar14 = puVar14 + 1;
              iVar16 = iVar16 + -4;
            }
          }
          MmUnmapIoSpace(puVar10,(int)puVar3[1]);
        }
        *(int *)(param_2 + 0x30) = iVar9;
        if (iVar9 < 0) goto LAB_0001197a;
LAB_000112b8:
        *(undefined8 *)(param_2 + 0x38) = 0x18;
        goto LAB_0001197a;
      }
      uVar1 = *(ushort *)((longlong)puVar3 + 4);
      out(0xcf8,((uint)*(byte *)((longlong)puVar3 + 2) +
                ((((uVar1 >> 8 & 0xf) + 0x80) * 0x100 + (uint)(byte)*puVar3) * 0x20 +
                (uint)*(byte *)((longlong)puVar3 + 1)) * 8) * 0x100 + (uVar1 & 0xfc));
      uVar6 = in((uVar1 & 3) + 0xcfc);
      *(undefined1 *)(puVar3 + 1) = uVar6;
    }
    else {
      if (uVar17 == 0x222834) {
        uVar1 = *(ushort *)((longlong)puVar3 + 4);
        out(0xcf8,((uint)*(byte *)((longlong)puVar3 + 2) +
                  ((((uVar1 >> 8 & 0xf) + 0x80) * 0x100 + (uint)(byte)*puVar3) * 0x20 +
                  (uint)*(byte *)((longlong)puVar3 + 1)) * 8) * 0x100 + (uVar1 & 0xfc));
        out((uVar1 & 3) + 0xcfc,(char)puVar3[1]);
        goto LAB_0001197a;
      }
      if (uVar17 == 0x222838) {
        uVar1 = *(ushort *)((longlong)puVar3 + 4);
        out(0xcf8,((uint)*(byte *)((longlong)puVar3 + 2) +
                  ((((uVar1 >> 8 & 0xf) + 0x80) * 0x100 + (uint)(byte)*puVar3) * 0x20 +
                  (uint)*(byte *)((longlong)puVar3 + 1)) * 8) * 0x100 + (uVar1 & 0xfc));
        uVar7 = in((uVar1 & 3) + 0xcfc);
        *(undefined2 *)(puVar3 + 1) = uVar7;
      }
      else {
        if (uVar17 == 0x22283c) {
          uVar1 = *(ushort *)((longlong)puVar3 + 4);
          out(0xcf8,((uint)*(byte *)((longlong)puVar3 + 2) +
                    ((((uVar1 >> 8 & 0xf) + 0x80) * 0x100 + (uint)(byte)*puVar3) * 0x20 +
                    (uint)*(byte *)((longlong)puVar3 + 1)) * 8) * 0x100 + (uVar1 & 0xfc));
          out((uVar1 & 3) + 0xcfc,(short)puVar3[1]);
          goto LAB_0001197a;
        }
        if (uVar17 != 0x222840) {
          if (uVar17 == 0x222844) {
            uVar1 = *(ushort *)((longlong)puVar3 + 4);
            out(0xcf8,((uint)*(byte *)((longlong)puVar3 + 2) +
                      ((((uVar1 >> 8 & 0xf) + 0x80) * 0x100 + (uint)(byte)*puVar3) * 0x20 +
                      (uint)*(byte *)((longlong)puVar3 + 1)) * 8) * 0x100 + (uVar1 & 0xfc));
            out((uVar1 & 3) + 0xcfc,(int)puVar3[1]);
            goto LAB_0001197a;
          }
          if (uVar17 == 0x222848) {
            uVar12 = rdmsr((int)puVar3[1]);
            *(int *)puVar3 = (int)uVar12;
            *(int *)((longlong)puVar3 + 0xc) = (int)((ulonglong)uVar12 >> 0x20);
          }
          else {
            if (uVar17 == 0x22284c) {
              wrmsr((int)puVar3[1],CONCAT44(*(undefined4 *)((longlong)puVar3 + 0xc),(int)*puVar3));
              goto LAB_0001197a;
            }
            if (uVar17 != 0x222850) goto LAB_00011894;
            DAT_00014100 = (undefined4)*puVar3;
            DAT_00014104 = *(undefined4 *)((longlong)puVar3 + 4);
            DAT_00014108 = (undefined4)puVar3[1];
            DAT_0001410c = *(undefined4 *)((longlong)puVar3 + 0xc);
            FUN_00012650();
            uVar8 = DAT_00014100;
            *(undefined4 *)((longlong)puVar3 + 4) = DAT_00014104;
            *(undefined4 *)(puVar3 + 1) = DAT_00014108;
            uVar5 = DAT_0001410c;
            *(undefined4 *)puVar3 = uVar8;
            *(undefined4 *)((longlong)puVar3 + 0xc) = uVar5;
            *(undefined4 *)(param_2 + 0x30) = 0;
          }
          goto LAB_00011972;
        }
        uVar1 = *(ushort *)((longlong)puVar3 + 4);
        out(0xcf8,((uint)*(byte *)((longlong)puVar3 + 2) +
                  ((((uVar1 >> 8 & 0xf) + 0x80) * 0x100 + (uint)(byte)*puVar3) * 0x20 +
                  (uint)*(byte *)((longlong)puVar3 + 1)) * 8) * 0x100 + (uVar1 & 0xfc));
        uVar8 = in((uVar1 & 3) + 0xcfc);
        *(undefined4 *)(puVar3 + 1) = uVar8;
      }
    }
    *(undefined8 *)(param_2 + 0x38) = 0xc;
    goto LAB_0001197a;
  }
  if (uVar17 < 0x22287d) {
    if (uVar17 == 0x22287c) {
      uVar12 = FUN_00011f7c((longlong)puVar3);
      iVar9 = (int)uVar12;
      goto LAB_000118c9;
    }
    if (uVar17 != 0x22285c) {
      if (uVar17 == 0x222860) {
        uVar11 = FUN_000120d4((uint *)puVar3);
        *(int *)(param_2 + 0x30) = (int)uVar11;
        if (-1 < (int)uVar11) {
          *(undefined8 *)(param_2 + 0x38) = 0x208;
        }
        goto LAB_0001197a;
      }
      if (uVar17 == 0x222864) {
        uVar11 = rdtsc();
        *puVar3 = uVar11;
      }
      else {
        if (uVar17 == 0x222868) {
          uVar11 = rdpmc((int)*puVar3);
          puVar3[1] = uVar11;
          goto LAB_00011972;
        }
        if (uVar17 == 0x22286c) {
          *(undefined8 *)(param_2 + 0x38) = 0x10;
          iVar9 = (int)*puVar3;
          if ((((iVar9 == 0) || (in_CR0 = in_CR2, iVar9 == 2)) || (in_CR0 = in_CR3, iVar9 == 3)) ||
             ((in_CR0 = in_CR4, iVar9 == 4 || (in_CR0 = in_CR8, iVar9 == 8)))) {
            puVar3[1] = in_CR0;
          }
          else {
            *(undefined8 *)(param_2 + 0x38) = 0;
            *(undefined4 *)(param_2 + 0x30) = 0xc0000001;
          }
          goto LAB_0001197a;
        }
        if (uVar17 == 0x222870) {
          iVar9 = (int)*puVar3;
          if (((iVar9 != 0) && (iVar9 != 3)) && ((iVar9 != 4 && (iVar9 != 8)))) {
            *(undefined4 *)(param_2 + 0x30) = 0xc0000001;
          }
          goto LAB_0001197a;
        }
        if (uVar17 != 0x222874) {
          if (uVar17 != 0x222878) goto LAB_00011894;
          uVar12 = FUN_00011e9c((longlong)puVar3);
          iVar9 = (int)uVar12;
          goto LAB_000118c9;
        }
        lVar18 = 2;
        pbVar15 = (byte *)((longlong)puVar3 + 1);
        do {
          uVar1 = *(ushort *)(pbVar15 + 3);
          sVar19 = (uVar1 & 3) + 0xcfc;
          iVar9 = ((uint)pbVar15[1] +
                  ((((uVar1 >> 8 & 0xf) + 0x80) * 0x100 + (uint)pbVar15[-1]) * 0x20 + (uint)*pbVar15
                  ) * 8) * 0x100 + (uVar1 & 0xfc);
          if (pbVar15[2] == 1) {
            out(0xcf8,iVar9);
            uVar8 = in(sVar19);
            *(undefined4 *)(pbVar15 + 7) = uVar8;
          }
          else if (pbVar15[2] == 2) {
            out(0xcf8,iVar9);
            out(sVar19,*(undefined4 *)(pbVar15 + 7));
          }
          pbVar15 = pbVar15 + 0xc;
          lVar18 = lVar18 + -1;
        } while (lVar18 != 0);
      }
LAB_0001118f:
      *(undefined8 *)(param_2 + 0x38) = 8;
      goto LAB_0001197a;
    }
    iVar9 = in((short)puVar3[2]);
    lVar18 = rdmsr((int)*puVar3);
    KeStallExecutionProcessor(*(undefined4 *)((longlong)puVar3 + 4));
    iVar16 = in((short)puVar3[2]);
    uVar17 = iVar16 - iVar9;
    lVar4 = rdmsr((int)*puVar3);
    if (*(short *)((longlong)puVar3 + 0x12) == 0) {
      uVar17 = uVar17 & 0xffffff;
    }
    *(uint *)((longlong)puVar3 + 4) = uVar17;
    *(int *)((longlong)puVar3 + 0xc) = (int)(lVar4 - lVar18);
    *(int *)(puVar3 + 1) = (int)((ulonglong)(lVar4 - lVar18) >> 0x20);
    *(undefined4 *)(param_2 + 0x30) = 0;
  }
  else {
    if (uVar17 == 0x222880) {
      uVar12 = FUN_00012060((undefined4 *)puVar3);
      *(int *)(param_2 + 0x30) = (int)uVar12;
      if ((int)uVar12 < 0) goto LAB_0001197a;
LAB_00011972:
      *(undefined8 *)(param_2 + 0x38) = 0x10;
      goto LAB_0001197a;
    }
    if (uVar17 == 0x222884) {
      MmFreeContiguousMemorySpecifyCache(puVar3[1],(int)*puVar3,0);
      goto LAB_0001197a;
    }
    if (uVar17 == 0x222888) {
      DAT_00014100 = (undefined4)*puVar3;
      DAT_00014104 = *(undefined4 *)((longlong)puVar3 + 4);
      DAT_00014108 = (undefined4)puVar3[1];
      DAT_0001410c = *(undefined4 *)((longlong)puVar3 + 0xc);
      DAT_00014110 = (undefined4)puVar3[2];
      DAT_00014114 = *(undefined4 *)((longlong)puVar3 + 0x14);
      uVar8 = FUN_00012620();
      *(undefined4 *)puVar3 = uVar8;
      goto LAB_000112b8;
    }
    if ((uVar17 == 0x22288c) || (uVar17 == 0x222890)) {
      uVar12 = FUN_000123cc(*(longlong *)(param_1 + 0x40),(int *)puVar3,uVar17,param_2);
      iVar9 = (int)uVar12;
LAB_00011220:
      *(int *)(param_2 + 0x30) = iVar9;
      goto LAB_0001197a;
    }
    if (uVar17 == 0x222894) {
      iVar9 = FUN_000119b4((longlong *)puVar3);
      *(int *)(param_2 + 0x30) = iVar9;
      if (-1 < iVar9) {
        *(undefined8 *)(param_2 + 0x38) = 0x30;
      }
      goto LAB_0001197a;
    }
    if (uVar17 != 0x222898) {
      if (uVar17 == 0x2228a4) {
        uVar12 = FUN_00011db4((int *)puVar3);
        *(int *)(param_2 + 0x30) = (int)uVar12;
        if (-1 < (int)uVar12) {
          *(undefined8 *)(param_2 + 0x38) = 0x14;
        }
        goto LAB_0001197a;
      }
LAB_00011894:
      *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
      goto LAB_0001197a;
    }
    uVar12 = FUN_000124a0(puVar3);
    iVar9 = (int)uVar12;
LAB_000118c9:
    *(int *)(param_2 + 0x30) = iVar9;
    if (iVar9 < 0) goto LAB_0001197a;
  }
  *(undefined8 *)(param_2 + 0x38) = 0x20;
LAB_0001197a:
  iVar9 = *(int *)(param_2 + 0x30);
  if (iVar9 != 0x103) {
    IofCompleteRequest(param_2,0);
  }
  return iVar9;
}

