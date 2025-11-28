// Function: FUN_000115c0
// Address: 000115c0
// Decompiled by Ghidra


int FUN_000115c0(undefined8 param_1,longlong param_2,longlong param_3,ulonglong param_4)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  longlong lVar4;
  char cVar5;
  int *piVar6;
  int *piVar7;
  longlong local_d8;
  int local_d0 [2];
  longlong local_c8;
  longlong local_c0;
  longlong local_b8;
  longlong local_b0;
  undefined8 local_a8;
  ulonglong local_a0;
  int *local_98;
  int local_90 [2];
  undefined8 local_88;
  undefined8 local_80;
  undefined4 local_78 [2];
  undefined8 local_70;
  undefined1 *local_68;
  undefined4 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined1 local_48 [16];
  
  cVar5 = (char)param_4;
  local_b8 = 0;
  local_98 = (int *)0x0;
  local_c0 = 0;
  local_80 = 0;
  piVar1 = *(int **)(param_2 + 0x18);
  if (cVar5 == '\0') {
    if ((*(uint *)(param_3 + 0x10) < 0x18) || (*(uint *)(param_3 + 8) < 8)) {
      return -0x3fffff66;
    }
    piVar6 = (int *)0x0;
    piVar7 = piVar1;
LAB_00011666:
    local_d0[0] = piVar1[4];
    local_90[0] = local_d0[0];
    RtlInitUnicodeString(local_48,L"\\Device\\PhysicalMemory");
    local_78[0] = 0x30;
    local_70 = 0;
    local_60 = 0x240;
    local_68 = local_48;
    local_58 = 0;
    local_50 = 0;
    if (cVar5 != '\0') {
      iVar3 = ZwOpenSection(&local_c0);
      if ((-1 < iVar3) &&
         (iVar3 = ObReferenceObjectByHandle
                            (local_c0,0xf001f,0,param_4 & 0xffffffffffffff00,&local_80,0),
         -1 < iVar3)) goto LAB_00011776;
      goto LAB_00011616;
    }
    iVar3 = ZwOpenSection(&local_b8,0xf001f,local_78);
    if ((-1 < iVar3) &&
       (iVar3 = ObReferenceObjectByHandle
                          (local_b8,0xf001f,0,param_4 & 0xffffffffffffff00,&local_98,0), -1 < iVar3)
       ) {
LAB_00011776:
      local_b0 = (ulonglong)((piVar1[2] & 0xffffU) + piVar1[5]) + *(longlong *)(piVar1 + 2);
      cVar2 = HalTranslateBusAddress
                        (*piVar1,piVar1[1],*(undefined8 *)(piVar1 + 2),local_d0,&local_d8);
      if ((cVar2 == '\0') ||
         (cVar2 = HalTranslateBusAddress(*piVar1,piVar1[1],local_b0,local_90,&local_b0),
         cVar2 == '\0')) {
        local_d8 = *(longlong *)(piVar1 + 2);
      }
      local_a0 = local_b0 - local_d8;
      if ((int)local_a0 == 0) {
        iVar3 = -0x3fffffff;
      }
      else if (local_d0[0] == 0) {
        local_c8 = local_d8;
        if (cVar5 == '\0') {
          local_88 = 0;
          iVar3 = ZwMapViewOfSection(local_b8,0xffffffffffffffff,&local_88,0,local_a0 & 0xffffffff,
                                     &local_c8,&local_a0,1,0,4);
          if (iVar3 < 0) goto LAB_00011620;
          iVar3 = ((int)local_88 - (int)local_c8) + (int)local_d8;
          goto LAB_000118e7;
        }
        local_a8 = 0;
        iVar3 = ZwMapViewOfSection(local_c0,0xffffffffffffffff,&local_a8,0,local_a0 & 0xffffffff,
                                   &local_c8,&local_a0,1,0,4);
        if (-1 < iVar3) {
          iVar3 = (int)local_a8 + ((int)local_d8 - (int)local_c8);
          local_a8 = CONCAT44(local_a8._4_4_,iVar3);
          *piVar6 = iVar3;
          iVar3 = 0;
        }
      }
      else {
        iVar3 = (int)local_d8;
        if (cVar5 == '\0') {
LAB_000118e7:
          *piVar7 = iVar3;
          iVar3 = 0;
        }
        else {
          *piVar6 = (int)local_d8;
          iVar3 = 0;
        }
      }
      goto LAB_00011616;
    }
  }
  else {
    if ((0x17 < *(uint *)(param_3 + 0x10)) &&
       (piVar6 = piVar1, piVar7 = local_98, 3 < *(uint *)(param_3 + 8))) goto LAB_00011666;
    iVar3 = -0x3fffff66;
LAB_00011616:
    lVar4 = local_c0;
    if (cVar5 != '\0') goto LAB_00011625;
  }
LAB_00011620:
  lVar4 = local_b8;
LAB_00011625:
  if (lVar4 != 0) {
    ZwClose();
  }
  return iVar3;
}

