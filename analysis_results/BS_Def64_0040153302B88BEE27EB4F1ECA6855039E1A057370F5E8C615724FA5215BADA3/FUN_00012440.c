// Function: FUN_00012440
// Address: 00012440
// Decompiled by Ghidra


int FUN_00012440(undefined8 param_1,ulonglong *param_2,undefined8 param_3,ulonglong param_4)

{
  ushort uVar1;
  char *pcVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  longlong lVar8;
  ulonglong *puVar9;
  undefined1 *puVar10;
  undefined4 *puVar11;
  undefined1 *puVar12;
  uint uVar13;
  bool bVar14;
  undefined4 local_38;
  undefined4 uStack_34;
  
  pcVar2 = (char *)param_2[0x17];
  uVar6 = *(undefined4 *)(pcVar2 + 0x18);
  iVar5 = -0x3ffffffe;
  cVar3 = IoIs32bitProcess(param_2);
  puVar9 = (ulonglong *)0x0;
  cVar4 = *pcVar2;
  uVar13 = (uint)DAT_00014048;
  if ((cVar4 == '\x0e') && (DAT_00014048 == 0)) goto switchD_000124d0_caseD_222401;
  if ((cVar4 == '\0') || (cVar4 == '\x02')) goto switchD_000124d0_caseD_222400;
  if (cVar4 != '\x0e') goto switchD_000124d0_caseD_222401;
  switch(uVar6) {
  case 0x222400:
  case 0x222404:
    break;
  default:
    goto switchD_000124d0_caseD_222401;
  case 0x222408:
    KeEnterCriticalRegion();
    puVar9 = param_2;
    uVar7 = FUN_00011000(param_1,(longlong)param_2);
    iVar5 = (int)uVar7;
    KeLeaveCriticalRegion();
    goto switchD_000124d0_caseD_222401;
  case 0x22240c:
    KeEnterCriticalRegion();
    puVar9 = param_2;
    uVar7 = FUN_000117b0(param_1,(longlong)param_2);
    iVar5 = (int)uVar7;
    KeLeaveCriticalRegion();
    goto switchD_000124d0_caseD_222401;
  case 0x222410:
    KeEnterCriticalRegion();
    puVar9 = param_2;
    uVar7 = FUN_00011860(param_1,(longlong)param_2);
    iVar5 = (int)uVar7;
    KeLeaveCriticalRegion();
    goto switchD_000124d0_caseD_222401;
  case 0x222414:
    KeEnterCriticalRegion();
    puVar9 = param_2;
    uVar7 = FUN_000118e0(param_1,(longlong)param_2);
    iVar5 = (int)uVar7;
    KeLeaveCriticalRegion();
    goto switchD_000124d0_caseD_222401;
  case 0x222440:
    if (7 < *(uint *)(pcVar2 + 0x10)) {
      if (cVar3 == '\0') {
        bVar14 = *(uint *)(pcVar2 + 8) < 8;
      }
      else {
        bVar14 = *(uint *)(pcVar2 + 8) < 4;
      }
      if (!bVar14) {
        if (cVar3 == '\0') {
          puVar9 = (ulonglong *)&local_38;
          iVar5 = FUN_00011dc0((undefined4 *)param_2[3],puVar9,(ulonglong)uVar13,param_4);
          if (-1 < iVar5) {
            *(ulonglong *)param_2[3] = CONCAT44(uStack_34,local_38);
            param_2[7] = 8;
          }
        }
        else {
          puVar9 = (ulonglong *)&local_38;
          iVar5 = FUN_00011b80((undefined4 *)param_2[3],(int *)puVar9,(ulonglong)uVar13,param_4);
          if (-1 < iVar5) {
            *(undefined4 *)param_2[3] = local_38;
            param_2[7] = 4;
          }
        }
        goto switchD_000124d0_caseD_222401;
      }
    }
    goto LAB_000125cd;
  case 0x222444:
    if (cVar3 == '\0') {
      if (7 < *(uint *)(pcVar2 + 0x10)) {
LAB_000125d9:
        iVar5 = FUN_00012010(*(uint **)param_2[3],cVar3);
        goto switchD_000124d0_caseD_222401;
      }
    }
    else if (3 < *(uint *)(pcVar2 + 0x10)) goto LAB_000125d9;
    goto LAB_000125cd;
  case 0x222454:
    if ((*(uint *)(pcVar2 + 0x10) < 4) || (*(uint *)(pcVar2 + 8) < 4)) goto LAB_000125cd;
    uVar1 = *(ushort *)param_2[3];
    puVar9 = (ulonglong *)(ulonglong)uVar1;
    uVar6 = in(uVar1);
    *(undefined4 *)param_2[3] = uVar6;
LAB_000125fc:
    param_2[7] = 4;
    break;
  case 0x222458:
    if (*(uint *)(pcVar2 + 0x10) < 8) goto LAB_000125cd;
    uVar1 = *(ushort *)param_2[3];
    puVar9 = (ulonglong *)(ulonglong)uVar1;
    out(uVar1,*(undefined4 *)((ushort *)param_2[3] + 2));
    param_2[7] = 0;
    break;
  case 0x222480:
    out(0x70,0x2f);
    cVar4 = in(0x71);
    out(0x70,0x2f);
    puVar9 = (ulonglong *)0x0;
    out(0x71,cVar4 + '\x01');
    if ((DAT_00014048 == 2) || (DAT_00014048 == 5)) {
      out(0x70,0x10);
      out(0x71,0xdd);
      out(0x70,0x11);
      out(0x71,0xcc);
      out(0x70,0x12);
      puVar9 = (ulonglong *)0x0;
      out(0x71,0xbb);
    }
    break;
  case 0x2224c4:
    puVar10 = (undefined1 *)param_2[3];
    puVar12 = &DAT_000140e0;
    for (lVar8 = 0x204; lVar8 != 0; lVar8 = lVar8 + -1) {
      *puVar12 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar12 = puVar12 + 1;
    }
    param_2[7] = 0x204;
    break;
  case 0x2224c8:
    if (*(uint *)(pcVar2 + 8) < 0x4004) goto LAB_000126f0;
    puVar11 = &DAT_00014300;
    puVar10 = (undefined1 *)param_2[3];
    for (lVar8 = 0x4004; lVar8 != 0; lVar8 = lVar8 + -1) {
      *puVar10 = *(undefined1 *)puVar11;
      puVar11 = (undefined4 *)((longlong)puVar11 + 1);
      puVar10 = puVar10 + 1;
    }
    param_2[7] = 0x4004;
    break;
  case 0x2224d0:
    DAT_00014060 = ((byte)*(undefined4 *)param_2[3] & 1) == 1;
LAB_000126f0:
    param_2[7] = 0;
    break;
  case 0x2224d4:
    if (3 < *(uint *)(pcVar2 + 8)) {
      *(uint *)param_2[3] = uVar13;
      goto LAB_000125fc;
    }
LAB_000125cd:
    iVar5 = -0x3ffffff3;
    goto switchD_000124d0_caseD_222401;
  case 0x2224d8:
    if (*(int *)param_2[3] == 1) {
      DAT_000140d4 = 1;
    }
    goto switchD_000124d0_caseD_222401;
  }
switchD_000124d0_caseD_222400:
  iVar5 = 0;
switchD_000124d0_caseD_222401:
  *(int *)(param_2 + 6) = iVar5;
  IofCompleteRequest(param_2,(ulonglong)puVar9 & 0xffffffffffffff00);
  return iVar5;
}

