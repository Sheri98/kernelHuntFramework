// Function: FUN_000119a0
// Address: 000119a0
// Decompiled by Ghidra


int FUN_000119a0(undefined8 param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  undefined8 *puVar3;
  byte bVar4;
  int iVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  char *pcVar8;
  char *pcVar9;
  undefined8 local_38;
  
  bVar4 = IoIs32bitProcess(param_2);
  param_2[0x38] = '\0';
  param_2[0x39] = '\0';
  param_2[0x3a] = '\0';
  param_2[0x3b] = '\0';
  param_2[0x3c] = '\0';
  param_2[0x3d] = '\0';
  param_2[0x3e] = '\0';
  param_2[0x3f] = '\0';
  pcVar9 = *(char **)(param_2 + 0xb8);
  iVar5 = -0x3ffffffe;
  cVar1 = *pcVar9;
  if ((cVar1 == '\0') || (cVar1 == '\x02')) goto switchD_00011af5_caseD_a040a48c;
  if (cVar1 != '\x0e') goto switchD_00011af5_caseD_a040a449;
  uVar2 = *(uint *)(pcVar9 + 0x18);
  if (uVar2 < 0xa040a445) {
    if (uVar2 != 0xa040a444) {
      if (uVar2 < 0xa0406405) {
        if (uVar2 != 0xa0406404) {
          if (uVar2 == 0xa040244c) goto switchD_00011af5_caseD_a040a480;
          if (uVar2 == 0xa0402450) {
            if (bVar4 == 0) {
              if (*(uint *)(pcVar9 + 0x10) < 8) goto LAB_00011a70;
              pcVar9 = (char *)**(undefined8 **)(param_2 + 0x18);
            }
            else {
              if (*(uint *)(pcVar9 + 0x10) < 4) {
LAB_00011a70:
                iVar5 = -0x3fffff66;
                goto switchD_00011af5_caseD_a040a449;
              }
              pcVar9 = (char *)(ulonglong)**(uint **)(param_2 + 0x18);
            }
            iVar5 = ZwUnmapViewOfSection(0xffffffffffffffff,pcVar9);
            goto switchD_00011af5_caseD_a040a449;
          }
          if (uVar2 != 0xa0406400) goto switchD_00011af5_caseD_a040a449;
        }
      }
      else if (uVar2 != 0xa0406408) {
        if (uVar2 == 0xa0406458) {
          uVar7 = FUN_00011000((longlong)param_2);
          iVar5 = (int)uVar7;
          if (-1 < iVar5) {
            param_2[0x38] = '\b';
            param_2[0x39] = '\0';
            param_2[0x3a] = '\0';
            param_2[0x3b] = '\0';
            param_2[0x3c] = '\0';
            param_2[0x3d] = '\0';
            param_2[0x3e] = '\0';
            param_2[0x3f] = '\0';
          }
          goto switchD_00011af5_caseD_a040a449;
        }
        if (uVar2 != 0xa040a440) goto switchD_00011af5_caseD_a040a449;
        goto switchD_00011af5_caseD_a040a448;
      }
      uVar7 = FUN_00011260((longlong)param_2,(longlong)pcVar9);
      iVar5 = (int)uVar7;
      goto switchD_00011af5_caseD_a040a449;
    }
switchD_00011af5_caseD_a040a448:
    uVar7 = FUN_00011410((longlong)param_2,(longlong)pcVar9,bVar4);
    iVar5 = (int)uVar7;
  }
  else {
    switch(uVar2) {
    case 0xa040a448:
      goto switchD_00011af5_caseD_a040a448;
    case 0xa040a45c:
      uVar7 = FUN_000110b0((longlong)param_2,(longlong)pcVar9);
      iVar5 = (int)uVar7;
      if (-1 < iVar5) {
        param_2[0x38] = '\b';
        param_2[0x39] = '\0';
        param_2[0x3a] = '\0';
        param_2[0x3b] = '\0';
        param_2[0x3c] = '\0';
        param_2[0x3d] = '\0';
        param_2[0x3e] = '\0';
        param_2[0x3f] = '\0';
      }
      break;
    case 0xa040a460:
      uVar7 = FUN_00011040((longlong)param_2,(longlong)pcVar9);
      iVar5 = (int)uVar7;
      if (-1 < iVar5) {
        param_2[0x38] = '\b';
        param_2[0x39] = '\0';
        param_2[0x3a] = '\0';
        param_2[0x3b] = '\0';
        param_2[0x3c] = '\0';
        param_2[0x3d] = '\0';
        param_2[0x3e] = '\0';
        param_2[0x3f] = '\0';
      }
      break;
    case 0xa040a464:
      uVar7 = FUN_00011160((longlong)param_2,(longlong)pcVar9);
      iVar5 = (int)uVar7;
      if (-1 < iVar5) {
        param_2[0x38] = '\x04';
        param_2[0x39] = '\0';
        param_2[0x3a] = '\0';
        param_2[0x3b] = '\0';
        param_2[0x3c] = '\0';
        param_2[0x3d] = '\0';
        param_2[0x3e] = '\0';
        param_2[0x3f] = '\0';
      }
      break;
    case 0xa040a480:
switchD_00011af5_caseD_a040a480:
      pcVar8 = param_2;
      iVar5 = FUN_000115c0(param_1,(longlong)param_2,(longlong)pcVar9,(ulonglong)bVar4);
      pcVar9 = pcVar8;
      if (iVar5 < 0) {
        param_2[0x30] = '\r';
        param_2[0x31] = '\0';
        param_2[0x32] = '\0';
        param_2[0x33] = -0x40;
      }
      else {
        uVar7 = 8;
        if (bVar4 != 0) {
          uVar7 = 4;
        }
        *(undefined8 *)(param_2 + 0x38) = uVar7;
      }
      break;
    case 0xa040a488:
      puVar3 = *(undefined8 **)(param_2 + 0x18);
      pcVar9 = (char *)0xffffffff;
      uVar7 = MmAllocateContiguousMemory(*(undefined4 *)puVar3,0xffffffff);
      uVar6 = MmGetPhysicalAddress(uVar7);
      local_38 = CONCAT44((int)uVar7,uVar6);
      *puVar3 = local_38;
      param_2[0x38] = '\b';
      param_2[0x39] = '\0';
      param_2[0x3a] = '\0';
      param_2[0x3b] = '\0';
      param_2[0x3c] = '\0';
      param_2[0x3d] = '\0';
      param_2[0x3e] = '\0';
      param_2[0x3f] = '\0';
    case 0xa040a48c:
switchD_00011af5_caseD_a040a48c:
      iVar5 = 0;
    }
  }
switchD_00011af5_caseD_a040a449:
  *(int *)(param_2 + 0x30) = iVar5;
  IofCompleteRequest(param_2,(ulonglong)pcVar9 & 0xffffffffffffff00);
  return iVar5;
}

