// Function: FUN_0001106c
// Address: 0001106c
// Decompiled by Ghidra


int FUN_0001106c(longlong param_1,longlong param_2)

{
  ushort uVar1;
  int iVar2;
  ulonglong *puVar3;
  longlong lVar4;
  undefined1 uVar5;
  undefined2 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  ulonglong uVar10;
  undefined8 uVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  byte *pbVar14;
  int iVar15;
  uint uVar16;
  longlong lVar17;
  short sVar18;
  ulonglong in_CR0;
  ulonglong in_CR2;
  ulonglong in_CR3;
  ulonglong in_CR4;
  ulonglong in_CR8;
  
  puVar3 = *(ulonglong **)(param_2 + 0x18);
  iVar8 = 0;
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  if (**(char **)(param_2 + 0xb8) != '\x0e') goto LAB_000118a9;
  uVar16 = *(uint *)(*(char **)(param_2 + 0xb8) + 0x18);
  if (uVar16 < 0x222859) {
    if (uVar16 == 0x222858) {
      uVar10 = FUN_00011a4c((short *)puVar3);
      *(int *)(param_2 + 0x30) = (int)uVar10;
      if (-1 < (int)uVar10) {
        *(undefined8 *)(param_2 + 0x38) = 0x204;
      }
      goto LAB_000118a9;
    }
    if (uVar16 < 0x222831) {
      if (uVar16 != 0x222830) {
        if (uVar16 != 0x222808) {
          if (uVar16 == 0x22280c) {
            puVar9 = (undefined4 *)MmMapIoSpace(*puVar3,(int)puVar3[1],0);
            if (puVar9 == (undefined4 *)0x0) {
              iVar8 = -0x3fffffff;
            }
            else {
              puVar13 = (undefined4 *)puVar3[2];
              iVar15 = (int)puVar3[1];
              puVar12 = puVar9;
              while (iVar15 != 0) {
                iVar2 = *(int *)((longlong)puVar3 + 0xc);
                if (iVar2 == 0) {
                  uVar5 = *(undefined1 *)puVar13;
                  puVar13 = (undefined4 *)((longlong)puVar13 + 1);
                  *(undefined1 *)puVar12 = uVar5;
                  puVar12 = (undefined4 *)((longlong)puVar12 + 1);
                  iVar15 = iVar15 + -1;
                }
                else if (iVar2 == 1) {
                  uVar6 = *(undefined2 *)puVar13;
                  puVar13 = (undefined4 *)((longlong)puVar13 + 2);
                  *(undefined2 *)puVar12 = uVar6;
                  puVar12 = (undefined4 *)((longlong)puVar12 + 2);
                  iVar15 = iVar15 + -2;
                }
                else if (iVar2 == 2) {
                  uVar7 = *puVar13;
                  puVar13 = puVar13 + 1;
                  *puVar12 = uVar7;
                  puVar12 = puVar12 + 1;
                  iVar15 = iVar15 + -4;
                }
              }
              MmUnmapIoSpace(puVar9,(int)puVar3[1]);
            }
            goto LAB_000111e4;
          }
          if (uVar16 == 0x222810) {
            uVar5 = in((short)*puVar3);
            *(undefined1 *)((longlong)puVar3 + 4) = uVar5;
          }
          else {
            if (uVar16 == 0x222814) {
              out((short)*puVar3,*(undefined1 *)((longlong)puVar3 + 4));
              goto LAB_000118a9;
            }
            if (uVar16 == 0x222818) {
              uVar6 = in((short)*puVar3);
              *(undefined2 *)((longlong)puVar3 + 4) = uVar6;
            }
            else {
              if (uVar16 == 0x22281c) {
                out((short)*puVar3,*(undefined2 *)((longlong)puVar3 + 4));
                goto LAB_000118a9;
              }
              if (uVar16 != 0x222820) {
                if (uVar16 == 0x222824) {
                  out((short)*puVar3,*(undefined4 *)((longlong)puVar3 + 4));
                  goto LAB_000118a9;
                }
                goto LAB_000117e4;
              }
              uVar7 = in((short)*puVar3);
              *(undefined4 *)((longlong)puVar3 + 4) = uVar7;
            }
          }
          goto LAB_00011153;
        }
        puVar9 = (undefined4 *)MmMapIoSpace(*puVar3,(int)puVar3[1],0);
        if (puVar9 == (undefined4 *)0x0) {
          iVar8 = -0x3fffffff;
        }
        else {
          puVar13 = (undefined4 *)puVar3[2];
          iVar15 = (int)puVar3[1];
          puVar12 = puVar9;
          while (iVar15 != 0) {
            iVar2 = *(int *)((longlong)puVar3 + 0xc);
            if (iVar2 == 0) {
              uVar5 = *(undefined1 *)puVar12;
              puVar12 = (undefined4 *)((longlong)puVar12 + 1);
              *(undefined1 *)puVar13 = uVar5;
              puVar13 = (undefined4 *)((longlong)puVar13 + 1);
              iVar15 = iVar15 + -1;
            }
            else if (iVar2 == 1) {
              uVar6 = *(undefined2 *)puVar12;
              puVar12 = (undefined4 *)((longlong)puVar12 + 2);
              *(undefined2 *)puVar13 = uVar6;
              puVar13 = (undefined4 *)((longlong)puVar13 + 2);
              iVar15 = iVar15 + -2;
            }
            else if (iVar2 == 2) {
              uVar7 = *puVar12;
              puVar12 = puVar12 + 1;
              *puVar13 = uVar7;
              puVar13 = puVar13 + 1;
              iVar15 = iVar15 + -4;
            }
          }
          MmUnmapIoSpace(puVar9,(int)puVar3[1]);
        }
        *(int *)(param_2 + 0x30) = iVar8;
        if (iVar8 < 0) goto LAB_000118a9;
LAB_0001127c:
        *(undefined8 *)(param_2 + 0x38) = 0x18;
        goto LAB_000118a9;
      }
      uVar1 = *(ushort *)((longlong)puVar3 + 4);
      out(0xcf8,((uint)*(byte *)((longlong)puVar3 + 2) +
                ((((uVar1 >> 8 & 0xf) + 0x80) * 0x100 + (uint)(byte)*puVar3) * 0x20 +
                (uint)*(byte *)((longlong)puVar3 + 1)) * 8) * 0x100 + (uVar1 & 0xfc));
      uVar5 = in((uVar1 & 3) + 0xcfc);
      *(undefined1 *)(puVar3 + 1) = uVar5;
    }
    else {
      if (uVar16 == 0x222834) {
        uVar1 = *(ushort *)((longlong)puVar3 + 4);
        out(0xcf8,((uint)*(byte *)((longlong)puVar3 + 2) +
                  ((((uVar1 >> 8 & 0xf) + 0x80) * 0x100 + (uint)(byte)*puVar3) * 0x20 +
                  (uint)*(byte *)((longlong)puVar3 + 1)) * 8) * 0x100 + (uVar1 & 0xfc));
        out((uVar1 & 3) + 0xcfc,(char)puVar3[1]);
        goto LAB_000118a9;
      }
      if (uVar16 == 0x222838) {
        uVar1 = *(ushort *)((longlong)puVar3 + 4);
        out(0xcf8,((uint)*(byte *)((longlong)puVar3 + 2) +
                  ((((uVar1 >> 8 & 0xf) + 0x80) * 0x100 + (uint)(byte)*puVar3) * 0x20 +
                  (uint)*(byte *)((longlong)puVar3 + 1)) * 8) * 0x100 + (uVar1 & 0xfc));
        uVar6 = in((uVar1 & 3) + 0xcfc);
        *(undefined2 *)(puVar3 + 1) = uVar6;
      }
      else {
        if (uVar16 == 0x22283c) {
          uVar1 = *(ushort *)((longlong)puVar3 + 4);
          out(0xcf8,((uint)*(byte *)((longlong)puVar3 + 2) +
                    ((((uVar1 >> 8 & 0xf) + 0x80) * 0x100 + (uint)(byte)*puVar3) * 0x20 +
                    (uint)*(byte *)((longlong)puVar3 + 1)) * 8) * 0x100 + (uVar1 & 0xfc));
          out((uVar1 & 3) + 0xcfc,(short)puVar3[1]);
          goto LAB_000118a9;
        }
        if (uVar16 != 0x222840) {
          if (uVar16 == 0x222844) {
            uVar1 = *(ushort *)((longlong)puVar3 + 4);
            out(0xcf8,((uint)*(byte *)((longlong)puVar3 + 2) +
                      ((((uVar1 >> 8 & 0xf) + 0x80) * 0x100 + (uint)(byte)*puVar3) * 0x20 +
                      (uint)*(byte *)((longlong)puVar3 + 1)) * 8) * 0x100 + (uVar1 & 0xfc));
            out((uVar1 & 3) + 0xcfc,(int)puVar3[1]);
            goto LAB_000118a9;
          }
          if (uVar16 != 0x222848) {
            if (uVar16 == 0x22284c) {
              wrmsr((int)puVar3[1],CONCAT44(*(undefined4 *)((longlong)puVar3 + 0xc),(int)*puVar3));
              goto LAB_000118a9;
            }
LAB_000117e4:
            *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
            goto LAB_000118a9;
          }
          uVar11 = rdmsr((int)puVar3[1]);
          *(int *)puVar3 = (int)uVar11;
          *(int *)((longlong)puVar3 + 0xc) = (int)((ulonglong)uVar11 >> 0x20);
          goto LAB_000118a1;
        }
        uVar1 = *(ushort *)((longlong)puVar3 + 4);
        out(0xcf8,((uint)*(byte *)((longlong)puVar3 + 2) +
                  ((((uVar1 >> 8 & 0xf) + 0x80) * 0x100 + (uint)(byte)*puVar3) * 0x20 +
                  (uint)*(byte *)((longlong)puVar3 + 1)) * 8) * 0x100 + (uVar1 & 0xfc));
        uVar7 = in((uVar1 & 3) + 0xcfc);
        *(undefined4 *)(puVar3 + 1) = uVar7;
      }
    }
    *(undefined8 *)(param_2 + 0x38) = 0xc;
    goto LAB_000118a9;
  }
  if (uVar16 < 0x22287d) {
    if (uVar16 == 0x22287c) {
      uVar11 = FUN_00011dc4((longlong)puVar3);
      iVar8 = (int)uVar11;
      goto LAB_000117f8;
    }
    if (uVar16 != 0x22285c) {
      if (uVar16 == 0x222860) {
        uVar10 = FUN_00011f1c((uint *)puVar3);
        *(int *)(param_2 + 0x30) = (int)uVar10;
        if (-1 < (int)uVar10) {
          *(undefined8 *)(param_2 + 0x38) = 0x208;
        }
        goto LAB_000118a9;
      }
      if (uVar16 == 0x222864) {
        uVar10 = rdtsc();
        *puVar3 = uVar10;
      }
      else {
        if (uVar16 == 0x222868) {
          uVar10 = rdpmc((int)*puVar3);
          puVar3[1] = uVar10;
          goto LAB_000118a1;
        }
        if (uVar16 == 0x22286c) {
          *(undefined8 *)(param_2 + 0x38) = 0x10;
          iVar8 = (int)*puVar3;
          if ((((iVar8 == 0) || (in_CR0 = in_CR2, iVar8 == 2)) || (in_CR0 = in_CR3, iVar8 == 3)) ||
             ((in_CR0 = in_CR4, iVar8 == 4 || (in_CR0 = in_CR8, iVar8 == 8)))) {
            puVar3[1] = in_CR0;
          }
          else {
            *(undefined8 *)(param_2 + 0x38) = 0;
            *(undefined4 *)(param_2 + 0x30) = 0xc0000001;
          }
          goto LAB_000118a9;
        }
        if (uVar16 == 0x222870) {
          iVar8 = (int)*puVar3;
          if (((iVar8 != 0) && (iVar8 != 3)) && ((iVar8 != 4 && (iVar8 != 8)))) {
            *(undefined4 *)(param_2 + 0x30) = 0xc0000001;
          }
          goto LAB_000118a9;
        }
        if (uVar16 != 0x222874) {
          if (uVar16 != 0x222878) goto LAB_000117e4;
          uVar11 = FUN_00011ce4((longlong)puVar3);
          iVar8 = (int)uVar11;
          goto LAB_000117f8;
        }
        lVar17 = 2;
        pbVar14 = (byte *)((longlong)puVar3 + 1);
        do {
          uVar1 = *(ushort *)(pbVar14 + 3);
          sVar18 = (uVar1 & 3) + 0xcfc;
          iVar8 = ((uint)pbVar14[1] +
                  ((((uVar1 >> 8 & 0xf) + 0x80) * 0x100 + (uint)pbVar14[-1]) * 0x20 + (uint)*pbVar14
                  ) * 8) * 0x100 + (uVar1 & 0xfc);
          if (pbVar14[2] == 1) {
            out(0xcf8,iVar8);
            uVar7 = in(sVar18);
            *(undefined4 *)(pbVar14 + 7) = uVar7;
          }
          else if (pbVar14[2] == 2) {
            out(0xcf8,iVar8);
            out(sVar18,*(undefined4 *)(pbVar14 + 7));
          }
          pbVar14 = pbVar14 + 0xc;
          lVar17 = lVar17 + -1;
        } while (lVar17 != 0);
      }
LAB_00011153:
      *(undefined8 *)(param_2 + 0x38) = 8;
      goto LAB_000118a9;
    }
    iVar8 = in((short)puVar3[2]);
    lVar17 = rdmsr((int)*puVar3);
    KeStallExecutionProcessor(*(undefined4 *)((longlong)puVar3 + 4));
    iVar15 = in((short)puVar3[2]);
    uVar16 = iVar15 - iVar8;
    lVar4 = rdmsr((int)*puVar3);
    if (*(short *)((longlong)puVar3 + 0x12) == 0) {
      uVar16 = uVar16 & 0xffffff;
    }
    *(uint *)((longlong)puVar3 + 4) = uVar16;
    *(int *)((longlong)puVar3 + 0xc) = (int)(lVar4 - lVar17);
    *(int *)(puVar3 + 1) = (int)((ulonglong)(lVar4 - lVar17) >> 0x20);
    *(undefined4 *)(param_2 + 0x30) = 0;
  }
  else {
    if (uVar16 == 0x222880) {
      uVar11 = FUN_00011ea8((undefined4 *)puVar3);
      *(int *)(param_2 + 0x30) = (int)uVar11;
      if ((int)uVar11 < 0) goto LAB_000118a9;
LAB_000118a1:
      *(undefined8 *)(param_2 + 0x38) = 0x10;
      goto LAB_000118a9;
    }
    if (uVar16 == 0x222884) {
      MmFreeContiguousMemorySpecifyCache(puVar3[1],(int)*puVar3,0);
      goto LAB_000118a9;
    }
    if (uVar16 == 0x222888) {
      DAT_00014100 = (undefined4)*puVar3;
      DAT_00014104 = *(undefined4 *)((longlong)puVar3 + 4);
      DAT_00014108 = (undefined4)puVar3[1];
      DAT_0001410c = *(undefined4 *)((longlong)puVar3 + 0xc);
      DAT_00014110 = (undefined4)puVar3[2];
      DAT_00014114 = *(undefined4 *)((longlong)puVar3 + 0x14);
      uVar7 = FUN_00012460();
      *(undefined4 *)puVar3 = uVar7;
      goto LAB_0001127c;
    }
    if ((uVar16 == 0x22288c) || (uVar16 == 0x222890)) {
      uVar11 = FUN_00012214(*(longlong *)(param_1 + 0x40),(int *)puVar3,uVar16,param_2);
      iVar8 = (int)uVar11;
LAB_000111e4:
      *(int *)(param_2 + 0x30) = iVar8;
      goto LAB_000118a9;
    }
    if (uVar16 == 0x222894) {
      iVar8 = FUN_000118e4((longlong *)puVar3);
      *(int *)(param_2 + 0x30) = iVar8;
      if (-1 < iVar8) {
        *(undefined8 *)(param_2 + 0x38) = 0x30;
      }
      goto LAB_000118a9;
    }
    if (uVar16 != 0x222898) goto LAB_000117e4;
    uVar11 = FUN_000122e8(puVar3);
    iVar8 = (int)uVar11;
LAB_000117f8:
    *(int *)(param_2 + 0x30) = iVar8;
    if (iVar8 < 0) goto LAB_000118a9;
  }
  *(undefined8 *)(param_2 + 0x38) = 0x20;
LAB_000118a9:
  iVar8 = *(int *)(param_2 + 0x30);
  if (iVar8 != 0x103) {
    IofCompleteRequest(param_2,0);
  }
  return iVar8;
}

