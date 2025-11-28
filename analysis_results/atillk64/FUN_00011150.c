// Function: FUN_00011150
// Address: 00011150
// Decompiled by Ghidra


undefined8 FUN_00011150(undefined8 param_1,longlong param_2,longlong param_3,uint param_4)

{
  undefined2 uVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 uVar8;
  uint *puVar9;
  uint *puVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  uint uVar13;
  bool bVar14;
  uint local_res20 [2];
  undefined8 in_stack_ffffffffffffffd8;
  undefined4 uVar15;
  undefined4 uVar16;
  
  puVar10 = *(uint **)(param_2 + 0x18);
  iVar4 = *(int *)(param_3 + 0x10);
  uVar12 = (ulonglong)*(uint *)(param_3 + 8);
  if (param_4 < 0x9c402551) {
    if (param_4 == 0x9c402550) {
      if (iVar4 == 4) {
        uVar8 = rdmsr(*puVar10);
        *puVar10 = (uint)uVar8;
        puVar10[1] = (uint)((ulonglong)uVar8 >> 0x20);
        goto LAB_0001161b;
      }
    }
    else if (param_4 == 0x9c40252c) {
      if (iVar4 == 8) {
        uVar1 = (undefined2)*puVar10;
        if (puVar10[1] != 1) {
          if (puVar10[1] != 2) {
            uVar12 = 4;
            if (puVar10[1] != 4) {
              return 0xc000000d;
            }
            uVar5 = in(uVar1);
            *puVar10 = uVar5;
            goto LAB_00011569;
          }
          uVar3 = in(uVar1);
          uVar5 = (uint)uVar3;
LAB_000115db:
          *puVar10 = uVar5;
LAB_0001154b:
          *(undefined8 *)(param_2 + 0x38) = 2;
          return 0;
        }
        bVar2 = in(uVar1);
        uVar5 = (uint)bVar2;
LAB_000115c9:
        *puVar10 = uVar5;
LAB_0001152b:
        *(undefined8 *)(param_2 + 0x38) = 1;
        return 0;
      }
    }
    else if (param_4 == 0x9c402530) {
      if (iVar4 == 0xc) {
        uVar1 = (undefined2)*puVar10;
        if (puVar10[1] == 1) {
          out(uVar1,(byte)puVar10[2]);
        }
        else if (puVar10[1] == 2) {
          out(uVar1,(short)puVar10[2]);
        }
        else {
          if (puVar10[1] != 4) {
            return 0xc000000d;
          }
          out(uVar1,puVar10[2]);
        }
        goto LAB_00011890;
      }
    }
    else if (param_4 == 0x9c402534) {
      if (iVar4 == 0x10) {
        uVar5 = puVar10[2];
        uVar12 = 4;
        puVar9 = (uint *)MmMapIoSpace(*(undefined8 *)puVar10,4,0);
        if (uVar5 == 1) {
          *puVar10 = (uint)(byte)*puVar9;
          MmUnmapIoSpace(puVar9,4);
          goto LAB_0001152b;
        }
        if (uVar5 == 2) {
          *puVar10 = (uint)(ushort)*puVar9;
          MmUnmapIoSpace(puVar9,4);
          goto LAB_0001154b;
        }
        if (uVar5 != 4) {
          return 0xc000000d;
        }
        *puVar10 = *puVar9;
LAB_00011560:
        MmUnmapIoSpace(puVar9,uVar12);
LAB_00011569:
        *(ulonglong *)(param_2 + 0x38) = uVar12;
        return 0;
      }
    }
    else if (param_4 == 0x9c402538) {
      if (iVar4 == 0x18) {
        uVar5 = puVar10[2];
        uVar12 = 4;
        puVar9 = (uint *)MmMapIoSpace(*(undefined8 *)puVar10,4,0);
        if (uVar5 == 1) {
          *(byte *)puVar9 = (byte)puVar10[4];
        }
        else if (uVar5 == 2) {
          *(short *)puVar9 = (short)puVar10[4];
        }
        else {
          if (uVar5 != 4) {
            return 0xc000000d;
          }
          *puVar9 = puVar10[4];
        }
        goto LAB_000112bf;
      }
    }
    else {
      uVar15 = (undefined4)((ulonglong)in_stack_ffffffffffffffd8 >> 0x20);
      if (param_4 == 0x9c40253c) {
        if (iVar4 == 8) {
          uVar5 = *puVar10;
          uVar13 = puVar10[1];
          uVar12 = 4;
          iVar4 = HalGetBusDataByOffset
                            (4,*(byte *)((longlong)puVar10 + 2),
                             (uVar5 >> 8 & 0xf8 | uVar5 & 0x700) >> 3,local_res20,
                             CONCAT44(uVar15,uVar5) & 0xffffffff000000fc,4);
          if (iVar4 == 0) {
            local_res20[0] = 0xffffffff;
          }
          if (uVar13 == 1) {
            uVar5 = local_res20[0] >> (sbyte)((*puVar10 & 3) << 3) & 0xff;
            goto LAB_000115c9;
          }
          if (uVar13 == 2) {
            uVar5 = *puVar10 & 3;
            if ((uVar5 == 0) || (uVar5 == 2)) {
              uVar5 = local_res20[0] >> (sbyte)(uVar5 << 3) & 0xffff;
              goto LAB_000115db;
            }
          }
          else {
            if (uVar13 != 4) {
              return 0xc000000d;
            }
            if ((*puVar10 & 3) == 0) {
              *puVar10 = local_res20[0];
              goto LAB_00011569;
            }
          }
        }
      }
      else if (param_4 == 0x9c402540) {
        if (iVar4 == 0xc) {
          if (puVar10[1] == 1) {
            uVar5 = *puVar10;
            uVar16 = 1;
            uVar13 = uVar5 >> 8 & 0xf8 | uVar5 & 0x700;
LAB_00011355:
            HalSetBusDataByOffset
                      (4,*(byte *)((longlong)puVar10 + 2),uVar13 >> 3,puVar10 + 2,
                       CONCAT44(uVar15,uVar5) & 0xffffffff000000fc,uVar16);
            goto LAB_00011890;
          }
          if (puVar10[1] == 2) {
            uVar5 = *puVar10;
            if (((uVar5 & 3) == 0) || ((uVar5 & 3) == 2)) {
              uVar16 = 2;
              uVar13 = uVar5 >> 8 & 0xf8 | uVar5 & 0x700;
              goto LAB_00011355;
            }
          }
          else {
            if (puVar10[1] != 4) {
              return 0xc000000d;
            }
            uVar5 = *puVar10;
            if ((uVar5 & 3) == 0) {
              uVar16 = 4;
              uVar13 = uVar5 >> 8 & 0xf8 | uVar5 & 0x700;
              goto LAB_00011355;
            }
          }
        }
      }
      else if (param_4 == 0x9c402544) {
        if ((iVar4 == 0x10) && (*(ulonglong *)(puVar10 + 2) == uVar12)) {
          uVar5 = puVar10[2];
          uVar12 = (ulonglong)uVar5;
          puVar9 = (uint *)MmMapIoSpace(*(undefined8 *)puVar10,uVar12,0);
          if (uVar5 != 0) {
            lVar6 = (longlong)puVar9 - (longlong)puVar10;
            uVar11 = uVar12;
            do {
              *(byte *)puVar10 = *(byte *)(lVar6 + (longlong)puVar10);
              puVar10 = (uint *)((longlong)puVar10 + 1);
              uVar11 = uVar11 - 1;
            } while (uVar11 != 0);
          }
          goto LAB_00011560;
        }
      }
      else if (param_4 == 0x9c402548) {
        if (iVar4 == 0x18) {
          uVar5 = puVar10[2];
          uVar12 = (ulonglong)uVar5;
          puVar9 = (uint *)MmMapIoSpace(*(undefined8 *)puVar10,uVar12,0);
          lVar6 = *(longlong *)(puVar10 + 4);
          if (uVar5 != 0) {
            puVar10 = puVar9;
            uVar11 = uVar12;
            do {
              *(byte *)puVar10 = *(byte *)((lVar6 - (longlong)puVar9) + (longlong)puVar10);
              puVar10 = (uint *)((longlong)puVar10 + 1);
              uVar11 = uVar11 - 1;
            } while (uVar11 != 0);
          }
          goto LAB_000112bf;
        }
      }
      else {
        if (param_4 != 0x9c40254c) {
          return 0xc000000d;
        }
        if (iVar4 == 0x10) {
          lVar6 = MmMapIoSpace(*(undefined8 *)puVar10,puVar10[2],0);
          if (lVar6 == 0) {
            return 0xc000009a;
          }
          lVar7 = IoAllocateMdl(lVar6,puVar10[2],0,0,0);
          if (lVar7 == 0) {
            uVar12 = *(ulonglong *)(puVar10 + 2);
            goto LAB_00011802;
          }
          goto LAB_00011247;
        }
      }
    }
  }
  else if (param_4 == 0x9c402554) {
    if (iVar4 == 0xc) {
      wrmsr(*puVar10,*(undefined8 *)(puVar10 + 1));
LAB_00011890:
      uVar8 = 0;
      goto LAB_00011892;
    }
  }
  else if (param_4 == 0x9c402558) {
    if (iVar4 == 0x10) {
      bVar14 = false;
LAB_000117cb:
      lVar6 = MmMapIoSpace(*(undefined8 *)puVar10,puVar10[2],bVar14);
      if (lVar6 == 0) {
        return 0xc000009a;
      }
      lVar7 = IoAllocateMdl(lVar6,puVar10[2],0,0,0);
      if (lVar7 != 0) {
        MmBuildMdlForNonPagedPool(lVar7);
        uVar8 = MmMapLockedPages(lVar7,1);
        *(longlong *)(puVar10 + 2) = lVar7;
        *(undefined8 *)puVar10 = uVar8;
        *(undefined8 *)(param_2 + 0x38) = 0x10;
        return 0;
      }
LAB_000117ff:
      uVar12 = (ulonglong)puVar10[2];
LAB_00011802:
      MmUnmapIoSpace(lVar6,uVar12);
      return 0xc000009a;
    }
  }
  else if (param_4 == 0x9c40255c) {
    if (iVar4 == 0x18) {
      puVar9 = *(uint **)puVar10;
      IoFreeMdl(*(undefined8 *)(puVar10 + 4));
      uVar12 = (ulonglong)puVar10[2];
LAB_000112bf:
      MmUnmapIoSpace(puVar9,uVar12);
      goto LAB_00011890;
    }
  }
  else if (param_4 == 0x9c402560) {
    if (iVar4 == 0x18) {
      bVar14 = *(longlong *)(puVar10 + 4) != 0;
      goto LAB_000117cb;
    }
  }
  else if (param_4 == 0x9c402564) {
    if (iVar4 == 0x18) {
      lVar6 = MmMapIoSpace(*(undefined8 *)puVar10,puVar10[2],*(longlong *)(puVar10 + 4) != 0);
      if (lVar6 == 0) {
        return 0xc000009a;
      }
      lVar7 = IoAllocateMdl(lVar6,puVar10[2],0,0,0);
      if (lVar7 != 0) {
LAB_00011247:
        MmBuildMdlForNonPagedPool(lVar7);
        uVar8 = MmMapLockedPages(lVar7,1);
        IoFreeMdl(lVar7);
        MmUnmapIoSpace(lVar6,puVar10[2]);
        *(undefined8 *)puVar10 = uVar8;
LAB_0001161b:
        *(undefined8 *)(param_2 + 0x38) = 8;
        return 0;
      }
      goto LAB_000117ff;
    }
  }
  else if (param_4 == 0x9c402568) {
    if ((iVar4 == 0x18) && (*(ulonglong *)(puVar10 + 2) == uVar12)) {
      uVar5 = puVar10[2];
      uVar12 = (ulonglong)uVar5;
      puVar9 = (uint *)MmMapIoSpace(*(undefined8 *)puVar10,uVar12,*(longlong *)(puVar10 + 4) != 0);
      if (uVar5 != 0) {
        lVar6 = (longlong)puVar9 - (longlong)puVar10;
        uVar11 = uVar12;
        do {
          *(byte *)puVar10 = *(byte *)((longlong)puVar10 + lVar6);
          puVar10 = (uint *)((longlong)puVar10 + 1);
          uVar11 = uVar11 - 1;
        } while (uVar11 != 0);
      }
      goto LAB_00011560;
    }
  }
  else if (param_4 == 0x9c40256c) {
    if (iVar4 == 0x20) {
      uVar5 = puVar10[2];
      uVar12 = (ulonglong)uVar5;
      puVar9 = (uint *)MmMapIoSpace(*(undefined8 *)puVar10,uVar12,*(longlong *)(puVar10 + 6) != 0);
      lVar6 = *(longlong *)(puVar10 + 4);
      if (uVar5 != 0) {
        puVar10 = puVar9;
        uVar11 = uVar12;
        do {
          *(byte *)puVar10 = *(byte *)((longlong)puVar10 + (lVar6 - (longlong)puVar9));
          puVar10 = (uint *)((longlong)puVar10 + 1);
          uVar11 = uVar11 - 1;
        } while (uVar11 != 0);
      }
      goto LAB_000112bf;
    }
  }
  else {
    if (param_4 != 0x9c402570) {
      return 0xc000000d;
    }
    if ((iVar4 == 0x10) && (*(ulonglong *)(puVar10 + 2) == uVar12)) {
      uVar5 = puVar10[2];
      if (uVar5 != 0) {
        lVar6 = *(longlong *)puVar10 - (longlong)puVar10;
        uVar12 = (ulonglong)uVar5;
        do {
          *(byte *)puVar10 = *(byte *)((longlong)puVar10 + lVar6);
          puVar10 = (uint *)((longlong)puVar10 + 1);
          uVar12 = uVar12 - 1;
        } while (uVar12 != 0);
      }
      *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar5;
      return 0;
    }
  }
  uVar8 = 0xc000000d;
LAB_00011892:
  *(undefined8 *)(param_2 + 0x38) = 0;
  return uVar8;
}

