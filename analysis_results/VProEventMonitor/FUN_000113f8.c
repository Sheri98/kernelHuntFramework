// Function: FUN_000113f8
// Address: 000113f8
// Decompiled by Ghidra


int FUN_000113f8(undefined8 param_1)

{
  short sVar1;
  longlong lVar2;
  ulonglong *puVar3;
  short *psVar4;
  longlong lVar5;
  ulonglong uVar6;
  int iVar7;
  ulonglong *puVar8;
  longlong lVar9;
  longlong lVar10;
  uint uVar11;
  ulonglong *puVar12;
  ulonglong *in_stack_00000030;
  uint in_stack_00000038;
  int in_stack_00000040;
  int *in_stack_00000048;
  longlong in_stack_00000050;
  
  lVar2 = *(longlong *)(in_stack_00000050 + 0x40);
  iVar7 = 0;
  *in_stack_00000048 = 0;
  in_stack_00000048[2] = 0;
  in_stack_00000048[3] = 0;
  if (in_stack_00000040 == -0x5445d800) {
    DbgPrint("VProEventMonitor.sys: Stop event monitoring.\n");
    FUN_0001194c(in_stack_00000050);
    goto LAB_00011917;
  }
  if (in_stack_00000040 == -0x5445d7fc) {
    DbgPrint("VProEventMonitor.sys: Start event monitoring.\n");
    if (DAT_00014182 == '\0') {
      DAT_00014182 = '\x01';
      PsSetCreateProcessNotifyRoutine(FUN_000119f8,0);
    }
    goto LAB_00011917;
  }
  if (in_stack_00000040 == -0x5445d7f8) {
    DbgPrint("VProEventMonitor.sys: Get Statistics.\n");
    uVar6 = 0x218;
    if (in_stack_00000038 < 0x218) {
LAB_000116df:
      iVar7 = -0x3ffffdfa;
      goto LAB_00011917;
    }
    ExAcquireFastMutex(&DAT_00014148);
    puVar8 = *(ulonglong **)(lVar2 + 0x10);
    iVar7 = 0;
    if (puVar8 == (ulonglong *)0x0) {
      KeClearEvent(*(undefined8 *)(lVar2 + 8));
      uVar11 = in_stack_00000038 - 0x218;
LAB_000116b9:
      if (uVar11 < 8) {
        FUN_000120c0(in_stack_00000030,0,uVar6);
      }
      else {
        in_stack_00000048[2] = 0;
        in_stack_00000048[3] = 0;
      }
      iVar7 = 0;
    }
    else {
      puVar12 = puVar8 + 4;
      lVar9 = 0x80;
      lVar5 = 0x80;
      if (in_stack_00000038 - 0x218 < 8) {
        psVar4 = (short *)((longlong)in_stack_00000030 + 10);
        *(int *)in_stack_00000030 = (int)*puVar8;
        lVar10 = (longlong)puVar12 - (longlong)psVar4;
        *(int *)((longlong)in_stack_00000030 + 4) = (int)puVar8[1];
        *(char *)(in_stack_00000030 + 1) = (char)puVar8[2];
        in_stack_00000030[0x42] = puVar8[3];
        do {
          if ((lVar5 == -0x372) || (sVar1 = *(short *)(lVar10 + (longlong)psVar4), sVar1 == 0))
          break;
          *psVar4 = sVar1;
          psVar4 = psVar4 + 1;
          lVar5 = lVar5 + -1;
        } while (lVar5 != 0);
        if (lVar5 == 0) {
          psVar4 = psVar4 + -1;
          iVar7 = -0x7ffffffb;
        }
        *psVar4 = 0;
        if (iVar7 == -0x7ffffffb) {
          iVar7 = 0;
        }
        if (-1 < iVar7) {
          psVar4 = (short *)((longlong)in_stack_00000030 + 0x10a);
          do {
            if ((lVar9 == -0x372) ||
               (sVar1 = *(short *)((longlong)puVar8 +
                                   (0x804 - ((longlong)in_stack_00000030 + 0x10a)) +
                                  (longlong)psVar4), sVar1 == 0)) break;
            *psVar4 = sVar1;
            psVar4 = psVar4 + 1;
            lVar9 = lVar9 + -1;
          } while (lVar9 != 0);
LAB_000117f0:
          iVar7 = 0;
          if (lVar9 == 0) {
            psVar4 = psVar4 + -1;
            iVar7 = -0x7ffffffb;
          }
          *psVar4 = 0;
          if (iVar7 == -0x7ffffffb) {
            iVar7 = 0;
          }
LAB_000115a3:
          if (-1 < iVar7) {
            DbgPrint("VProEventMonitor.sys: Get Statistics().\n");
            DbgPrint("VProEventMonitor.sys: ProcName[%s], ProcID[%x], ParentID[%x].\n",puVar12,
                     puVar8[1],*puVar8);
            *(ulonglong *)(lVar2 + 0x10) = puVar8[0x1fd];
            ExFreePoolWithTag(puVar8,0);
            iVar7 = 0;
            if (*(longlong *)(lVar2 + 0x10) == 0) {
              KeClearEvent(*(undefined8 *)(lVar2 + 8));
            }
            *(ulonglong *)(in_stack_00000048 + 2) = (ulonglong)in_stack_00000038;
          }
        }
      }
      else {
        psVar4 = (short *)((longlong)in_stack_00000030 + 0x12);
        *in_stack_00000030 = *puVar8;
        lVar10 = (longlong)puVar12 - (longlong)psVar4;
        in_stack_00000030[1] = puVar8[1];
        *(char *)(in_stack_00000030 + 2) = (char)puVar8[2];
        in_stack_00000030[0x43] = puVar8[3];
        do {
          if ((lVar5 == -0x372) || (sVar1 = *(short *)(lVar10 + (longlong)psVar4), sVar1 == 0))
          break;
          *psVar4 = sVar1;
          psVar4 = psVar4 + 1;
          lVar5 = lVar5 + -1;
        } while (lVar5 != 0);
        if (lVar5 == 0) {
          psVar4 = psVar4 + -1;
          iVar7 = -0x7ffffffb;
        }
        *psVar4 = 0;
        if (iVar7 == -0x7ffffffb) {
          iVar7 = 0;
        }
        if (-1 < iVar7) {
          psVar4 = (short *)((longlong)in_stack_00000030 + 0x112);
          do {
            if ((lVar9 == -0x372) ||
               (sVar1 = *(short *)((longlong)puVar8 +
                                   (0x804 - ((longlong)in_stack_00000030 + 0x112)) +
                                  (longlong)psVar4), sVar1 == 0)) break;
            *psVar4 = sVar1;
            psVar4 = psVar4 + 1;
            lVar9 = lVar9 + -1;
          } while (lVar9 != 0);
          goto LAB_000117f0;
        }
      }
    }
  }
  else {
    if (in_stack_00000040 != -0x5445d7e8) {
      DbgPrint("VProEventMonitor.sys: unknown IRP_MJ_DEVICE_CONTROL.\n");
      iVar7 = -0x3ffffff0;
      goto LAB_00011917;
    }
    DbgPrint("VProEventMonitor.sys: Get Statistics.\n");
    uVar6 = 0xfe0;
    if (in_stack_00000038 < 0xfe0) goto LAB_000116df;
    ExAcquireFastMutex(&DAT_00014148);
    puVar8 = *(ulonglong **)(lVar2 + 0x10);
    iVar7 = 0;
    if (puVar8 == (ulonglong *)0x0) {
      KeClearEvent(*(undefined8 *)(lVar2 + 8));
      uVar11 = in_stack_00000038 - 0xfe0;
      goto LAB_000116b9;
    }
    puVar12 = puVar8 + 4;
    lVar9 = 0x3f2;
    lVar5 = 0x3f2;
    if (in_stack_00000038 - 0xfe0 < 8) {
      *(int *)in_stack_00000030 = (int)*puVar8;
      *(int *)((longlong)in_stack_00000030 + 4) = (int)puVar8[1];
      *(char *)(in_stack_00000030 + 1) = (char)puVar8[2];
      in_stack_00000030[2] = puVar8[3];
      puVar3 = in_stack_00000030 + 3;
      lVar10 = (longlong)puVar12 - (longlong)puVar3;
      do {
        if (lVar5 == 0) goto LAB_00011534;
        sVar1 = *(short *)(lVar10 + (longlong)puVar3);
        if (sVar1 == 0) break;
        *(short *)puVar3 = sVar1;
        puVar3 = (ulonglong *)((longlong)puVar3 + 2);
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
      if (lVar5 == 0) {
LAB_00011534:
        puVar3 = (ulonglong *)((longlong)puVar3 + -2);
        iVar7 = -0x7ffffffb;
      }
      *(short *)puVar3 = 0;
      if (iVar7 == -0x7ffffffb) {
        iVar7 = 0;
      }
      if (-1 < iVar7) {
        psVar4 = (short *)((longlong)in_stack_00000030 + 0x7fc);
        do {
          if (lVar9 == 0) goto LAB_00011590;
          sVar1 = *(short *)((longlong)puVar8 + (0x804 - ((longlong)in_stack_00000030 + 0x7fc)) +
                            (longlong)psVar4);
          if (sVar1 == 0) break;
          *psVar4 = sVar1;
          psVar4 = psVar4 + 1;
          lVar9 = lVar9 + -1;
        } while (lVar9 != 0);
LAB_0001158b:
        iVar7 = 0;
        if (lVar9 == 0) {
LAB_00011590:
          psVar4 = psVar4 + -1;
          iVar7 = -0x7ffffffb;
        }
        *psVar4 = 0;
        if (iVar7 == -0x7ffffffb) {
          iVar7 = 0;
        }
        goto LAB_000115a3;
      }
    }
    else {
      *in_stack_00000030 = *puVar8;
      in_stack_00000030[1] = puVar8[1];
      *(char *)(in_stack_00000030 + 2) = (char)puVar8[2];
      in_stack_00000030[3] = puVar8[3];
      puVar3 = in_stack_00000030 + 4;
      lVar10 = (longlong)puVar12 - (longlong)puVar3;
      do {
        if (lVar5 == 0) goto LAB_0001164d;
        sVar1 = *(short *)(lVar10 + (longlong)puVar3);
        if (sVar1 == 0) break;
        *(short *)puVar3 = sVar1;
        puVar3 = (ulonglong *)((longlong)puVar3 + 2);
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
      if (lVar5 == 0) {
LAB_0001164d:
        puVar3 = (ulonglong *)((longlong)puVar3 + -2);
        iVar7 = -0x7ffffffb;
      }
      *(short *)puVar3 = 0;
      if (iVar7 == -0x7ffffffb) {
        iVar7 = 0;
      }
      if (-1 < iVar7) {
        psVar4 = (short *)((longlong)in_stack_00000030 + 0x804);
        do {
          if (lVar9 == 0) goto LAB_00011590;
          sVar1 = *(short *)((longlong)puVar8 + (0x804 - ((longlong)in_stack_00000030 + 0x804)) +
                            (longlong)psVar4);
          if (sVar1 == 0) break;
          *psVar4 = sVar1;
          psVar4 = psVar4 + 1;
          lVar9 = lVar9 + -1;
        } while (lVar9 != 0);
        goto LAB_0001158b;
      }
    }
  }
  ExReleaseFastMutex(&DAT_00014148);
LAB_00011917:
  *in_stack_00000048 = iVar7;
  IofCompleteRequest(param_1,0);
  return iVar7;
}

