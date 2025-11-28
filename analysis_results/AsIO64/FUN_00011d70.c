// Function: FUN_00011d70
// Address: 00011d70
// Decompiled by Ghidra


int FUN_00011d70(undefined8 param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  undefined8 uVar5;
  char *pcVar6;
  char *pcVar7;
  
  bVar3 = IoIs32bitProcess(param_2);
  param_2[0x38] = '\0';
  param_2[0x39] = '\0';
  param_2[0x3a] = '\0';
  param_2[0x3b] = '\0';
  param_2[0x3c] = '\0';
  param_2[0x3d] = '\0';
  param_2[0x3e] = '\0';
  param_2[0x3f] = '\0';
  pcVar6 = *(char **)(param_2 + 0xb8);
  iVar4 = -0x3ffffffe;
  cVar1 = *pcVar6;
  if ((cVar1 == '\0') || (cVar1 == '\x02')) {
    iVar4 = 0;
    goto LAB_00011f3e;
  }
  if (cVar1 != '\x0e') goto LAB_00011f3e;
  uVar2 = *(uint *)(pcVar6 + 0x18);
  if (uVar2 < 0xa040a441) {
    if (uVar2 != 0xa040a440) {
      if (uVar2 < 0xa0406405) {
        if (uVar2 != 0xa0406404) {
          if (uVar2 == 0xa040244c) {
            pcVar7 = param_2;
            iVar4 = FUN_00011820(param_1,(longlong)param_2,(longlong)pcVar6,(ulonglong)bVar3);
            pcVar6 = pcVar7;
            if (iVar4 < 0) {
              param_2[0x30] = '\r';
              param_2[0x31] = '\0';
              param_2[0x32] = '\0';
              param_2[0x33] = -0x40;
            }
            else {
              uVar5 = 8;
              if (bVar3 != 0) {
                uVar5 = 4;
              }
              *(undefined8 *)(param_2 + 0x38) = uVar5;
            }
            goto LAB_00011f3e;
          }
          if (uVar2 == 0xa0402450) {
            if (bVar3 == 0) {
              if (*(uint *)(pcVar6 + 0x10) < 8) goto LAB_00011e40;
              pcVar6 = (char *)**(undefined8 **)(param_2 + 0x18);
            }
            else {
              if (*(uint *)(pcVar6 + 0x10) < 4) {
LAB_00011e40:
                iVar4 = -0x3fffff66;
                goto LAB_00011f3e;
              }
              pcVar6 = (char *)(ulonglong)**(uint **)(param_2 + 0x18);
            }
            iVar4 = ZwUnmapViewOfSection(0xffffffffffffffff,pcVar6);
            goto LAB_00011f3e;
          }
          if (uVar2 != 0xa0406400) goto LAB_00011f3e;
        }
      }
      else if (uVar2 != 0xa0406408) {
        if (uVar2 == 0xa0406458) {
          uVar5 = FUN_00011000((longlong)param_2);
          iVar4 = (int)uVar5;
          if (-1 < iVar4) {
            param_2[0x38] = '\b';
            param_2[0x39] = '\0';
            param_2[0x3a] = '\0';
            param_2[0x3b] = '\0';
            param_2[0x3c] = '\0';
            param_2[0x3d] = '\0';
            param_2[0x3e] = '\0';
            param_2[0x3f] = '\0';
          }
        }
        goto LAB_00011f3e;
      }
      uVar5 = FUN_000114a0((longlong)param_2,(longlong)pcVar6);
      iVar4 = (int)uVar5;
      goto LAB_00011f3e;
    }
  }
  else if ((uVar2 != 0xa040a444) && (uVar2 != 0xa040a448)) {
    if (uVar2 == 0xa040a45c) {
      uVar5 = FUN_00011120((longlong)param_2,(longlong)pcVar6);
      iVar4 = (int)uVar5;
      if (-1 < iVar4) {
        param_2[0x38] = '\b';
        param_2[0x39] = '\0';
        param_2[0x3a] = '\0';
        param_2[0x3b] = '\0';
        param_2[0x3c] = '\0';
        param_2[0x3d] = '\0';
        param_2[0x3e] = '\0';
        param_2[0x3f] = '\0';
      }
    }
    else if (uVar2 == 0xa040a460) {
      uVar5 = FUN_00011040((longlong)param_2,(longlong)pcVar6);
      iVar4 = (int)uVar5;
      if (-1 < iVar4) {
        param_2[0x38] = '\b';
        param_2[0x39] = '\0';
        param_2[0x3a] = '\0';
        param_2[0x3b] = '\0';
        param_2[0x3c] = '\0';
        param_2[0x3d] = '\0';
        param_2[0x3e] = '\0';
        param_2[0x3f] = '\0';
      }
    }
    else if (uVar2 == 0xa040a464) {
      uVar5 = FUN_00011220((longlong)param_2,(longlong)pcVar6);
      iVar4 = (int)uVar5;
      if (-1 < iVar4) {
        param_2[0x38] = '\x04';
        param_2[0x39] = '\0';
        param_2[0x3a] = '\0';
        param_2[0x3b] = '\0';
        param_2[0x3c] = '\0';
        param_2[0x3d] = '\0';
        param_2[0x3e] = '\0';
        param_2[0x3f] = '\0';
      }
    }
    goto LAB_00011f3e;
  }
  uVar5 = FUN_00011620((longlong)param_2,(longlong)pcVar6,bVar3);
  iVar4 = (int)uVar5;
LAB_00011f3e:
  *(int *)(param_2 + 0x30) = iVar4;
  IofCompleteRequest(param_2,(ulonglong)pcVar6 & 0xffffffffffffff00);
  return iVar4;
}

