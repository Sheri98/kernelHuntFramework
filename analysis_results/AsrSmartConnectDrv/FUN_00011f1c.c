// Function: FUN_00011f1c
// Address: 00011f1c
// Decompiled by Ghidra


ulonglong FUN_00011f1c(uint *param_1)

{
  uint *puVar1;
  short sVar2;
  undefined4 uVar3;
  uint uVar4;
  longlong lVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  longlong lVar9;
  int iVar10;
  int iVar11;
  bool bVar12;
  undefined4 local_38;
  int local_34;
  ulonglong *local_30;
  
  uVar4 = *param_1;
  uVar7 = 0;
  lVar5 = MmMapIoSpace(uVar4,0x1000,1);
  if (lVar5 == 0) {
    uVar8 = (ulonglong)uVar4;
  }
  else {
    lVar9 = (longlong)(int)((uint)(byte)param_1[1] << 7);
    if (((byte)*(undefined4 *)(lVar9 + 0x128 + lVar5) & 0xf) == 3) {
      local_38 = 0xe00;
      uVar6 = FUN_00011ea8(&local_38);
      uVar8 = uVar6 & 0xffffffff;
      if (-1 < (int)uVar6) {
        FUN_00012500(local_30,0,0xe00);
        sVar2 = *(short *)(lVar9 + 0x126 + lVar5);
        if ((-1 < *(int *)(lVar5 + 4)) || ((sVar2 != -0x14ec && (sVar2 != 0)))) {
          *(undefined4 *)(lVar5 + 4) = 1;
          KeStallExecutionProcessor(200000);
          *(undefined4 *)(lVar5 + 4) = 0x80000000;
        }
        *(undefined4 *)(lVar9 + 0x104 + lVar5) = 0;
        *(undefined4 *)(lVar9 + 0x10c + lVar5) = 0;
        *(int *)(lVar9 + 0x100 + lVar5) = local_34;
        *(int *)(lVar9 + 0x108 + lVar5) = local_34 + 0x400;
        *(undefined4 *)local_30 = 0x10005;
        *(undefined4 *)((longlong)local_30 + 4) = 0x200;
        *(int *)(local_30 + 1) = local_34 + 0x500;
        uVar3 = 0xec8027;
        if (sVar2 == -0x14ec) {
          uVar3 = 0xa18027;
        }
        *(undefined4 *)(local_30 + 0xa0) = uVar3;
        *(undefined4 *)((longlong)local_30 + 0x58c) = 0x1ff;
        *(int *)(local_30 + 0xb0) = local_34 + 0x600;
        puVar1 = (uint *)(lVar9 + 0x118 + lVar5);
        *puVar1 = *puVar1 | 0x11;
        uVar4 = *(uint *)(lVar9 + 0x118 + lVar5);
        if ((uVar4 >> 0x1a & 1) != 0) {
          uVar4 = uVar4 & 0xfffffff | 0x10000000;
        }
        puVar1 = (uint *)(lVar9 + 0x138 + lVar5);
        *puVar1 = *puVar1 | 1;
        *(undefined4 *)(lVar9 + 0x134 + lVar5) = 0;
        iVar10 = 3000;
        *(uint *)(lVar9 + 0x118 + lVar5) = uVar4 | 1;
        iVar11 = 3000;
        do {
          KeStallExecutionProcessor(1000);
          if ((char)local_30[0x84] == '_') {
            if ((*(byte *)((longlong)local_30 + 0x422) & 8) != 0) {
              bVar12 = (*(byte *)((longlong)local_30 + 0x421) & 0x20) == 0;
              goto LAB_000120dc;
            }
            break;
          }
          iVar11 = iVar11 + -1;
        } while (iVar11 != 0);
LAB_000120fd:
        uVar7 = 0xc0000001;
LAB_00012104:
        if ((int)uVar7 != -0x3fffffff) {
          memcpy((void *)((longlong)param_1 + 5),local_30 + 0xc0,0x200);
        }
        MmFreeContiguousMemorySpecifyCache(local_30,local_38,0);
        uVar8 = uVar7;
      }
    }
    else {
      uVar8 = 0xc0000001;
    }
    MmUnmapIoSpace(lVar5,0x1000);
  }
  return uVar8;
LAB_000120dc:
  if (bVar12) goto LAB_000120fd;
  if ((*(byte *)(lVar9 + 0x120 + lVar5) & 0x88) == 0) {
    if ((*(uint *)(lVar9 + 0x130 + lVar5) & 0x3ea0f03) != 0) {
      uVar7 = 0xc0000001;
    }
    goto LAB_00012104;
  }
  iVar10 = iVar10 + -1;
  bVar12 = iVar10 == 0;
  goto LAB_000120dc;
}

