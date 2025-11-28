// Function: FUN_00011170
// Address: 00011170
// Decompiled by Ghidra


int FUN_00011170(longlong param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 *puVar7;
  int iVar8;
  longlong lVar10;
  char cVar11;
  longlong *plVar12;
  char cVar13;
  ulonglong local_68;
  longlong local_58 [8];
  undefined1 local_18;
  undefined8 uVar9;
  
  pcVar3 = *(char **)(param_2 + 0xb8);
  plVar4 = *(longlong **)(param_1 + 0x40);
  iVar8 = 0;
  *(undefined4 *)(plVar4 + 1) = 0;
  if (*pcVar3 != '\x0e') goto LAB_000114bf;
  *plVar4 = *(longlong *)(param_2 + 0x18);
  iVar1 = *(int *)(pcVar3 + 0x10);
  *(int *)(plVar4 + 1) = iVar1;
  if (iVar1 != *(int *)(pcVar3 + 8)) goto LAB_000111b9;
  uVar2 = *(uint *)(pcVar3 + 0x18);
  if (uVar2 < 0x9b0c1f41) {
    if (uVar2 == 0x9b0c1f40) {
      cVar13 = '\x01';
LAB_000114b1:
      uVar9 = FUN_00015100(plVar4,cVar13);
      iVar8 = (int)uVar9;
    }
    else if (uVar2 == 0x9b0c1ec0) {
      uVar9 = FUN_000151d4(plVar4);
      iVar8 = (int)uVar9;
    }
    else {
      if (uVar2 == 0x9b0c1ec4) {
        cVar13 = '\x01';
      }
      else {
        if (uVar2 != 0x9b0c1ec8) {
          if (uVar2 == 0x9b0c1ecc) {
            if (iVar1 == 0x18) {
              plVar12 = (longlong *)*plVar4;
              lVar5 = *plVar12;
              local_68 = plVar12[2];
              if ((plVar4[2] == 0) || (plVar4[2] == lVar5)) {
                MmFreeContiguousMemorySpecifyCache(plVar12[1],local_68 & 0xffffffff,0);
                local_68 = local_68 & 0xffffffff00000000;
                plVar12 = (longlong *)*plVar4;
                *plVar12 = lVar5;
                plVar12[1] = 0;
                plVar12[2] = local_68;
                goto LAB_000114bf;
              }
              goto LAB_00011248;
            }
          }
          else if (uVar2 == 0x9b0c1f00) {
            if (iVar1 == 0x48) {
              memcpy(local_58,(void *)*plVar4,0x48);
              if ((plVar4[2] == 0) || (plVar4[2] == local_58[0])) {
                memcpy(plVar4 + 0xb,local_58,0x48);
                FUN_00011590(0,(longlong)plVar4);
                memcpy(local_58,plVar4 + 0xb,0x48);
LAB_000112bb:
                plVar12 = local_58;
LAB_00011256:
                memcpy((void *)*plVar4,plVar12,0x48);
                goto LAB_000114bf;
              }
              goto LAB_00011248;
            }
          }
          else if (uVar2 == 0x9b0c1f04) {
            if (iVar1 == 0x48) {
              memcpy(local_58,(void *)*plVar4,0x48);
              if ((plVar4[2] == 0) || (plVar4[2] == local_58[0])) {
                local_18 = 0;
                memcpy(plVar4 + 0xb,local_58,0x48);
                KeInsertQueueDpc(plVar4 + 3,plVar4,plVar4);
                goto LAB_000112bb;
              }
              goto LAB_00011248;
            }
          }
          else if ((uVar2 == 0x9b0c1f08) && (iVar1 == 0x48)) {
            memcpy(local_58,(void *)*plVar4,0x48);
            if ((plVar4[2] == 0) || (plVar4[2] == local_58[0])) {
              plVar12 = plVar4 + 0xb;
              goto LAB_00011256;
            }
LAB_00011248:
            iVar8 = -0x3ffffffb;
            goto LAB_000114c6;
          }
          goto LAB_000111b9;
        }
        cVar13 = '\0';
      }
      uVar9 = FUN_00015294(plVar4,cVar13);
      iVar8 = (int)uVar9;
    }
LAB_000114b9:
    if (iVar8 != 0) goto LAB_000114c6;
  }
  else {
    if (uVar2 == 0x9b0c1f44) {
      cVar13 = '\0';
      goto LAB_000114b1;
    }
    if (uVar2 == 0x9b0c1f80) {
      cVar13 = '\x01';
LAB_000114a6:
      cVar11 = '\0';
LAB_00011491:
      uVar9 = FUN_00015008(plVar4,cVar11,cVar13);
      iVar8 = (int)uVar9;
      goto LAB_000114b9;
    }
    if (uVar2 == 0x9b0c1f84) {
      cVar13 = '\0';
      goto LAB_000114a6;
    }
    if (uVar2 == 0x9b0c1f88) {
      cVar13 = '\x01';
      cVar11 = '\x01';
      goto LAB_00011491;
    }
    if (uVar2 == 0x9b0c1f8c) {
      cVar13 = '\0';
      cVar11 = '\x01';
      goto LAB_00011491;
    }
    iVar8 = 0;
    if (uVar2 == 0x9b0c1fc0) {
      if (iVar1 == 0xc) {
        puVar7 = (undefined8 *)*plVar4;
        lVar5 = plVar4[2];
        *puVar7 = 0x300000002;
        *(uint *)(puVar7 + 1) = CONCAT31((int3)((uint)*(undefined4 *)(puVar7 + 1) >> 8),lVar5 != 0);
        goto LAB_000114bf;
      }
LAB_000111b9:
      iVar8 = -0x3ffffff3;
      goto LAB_000114c6;
    }
    if ((uVar2 != 0x9b0c1fc4) || (iVar1 != 8)) goto LAB_000111b9;
    lVar5 = plVar4[2];
    lVar6 = *(longlong *)*plVar4;
    if ((lVar5 != 0) && (lVar5 != lVar6)) goto LAB_00011248;
    lVar10 = 0;
    if (lVar5 == 0) {
      lVar10 = lVar6;
    }
    plVar4[2] = lVar10;
    *(longlong *)*plVar4 = lVar6;
  }
LAB_000114bf:
  *(ulonglong *)(param_2 + 0x38) = (ulonglong)*(uint *)(plVar4 + 1);
LAB_000114c6:
  *(int *)(param_2 + 0x30) = iVar8;
  IofCompleteRequest(param_2,0);
  return iVar8;
}

