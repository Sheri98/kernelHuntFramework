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
  int local_d8;
  int local_d4;
  int local_d0 [2];
  int local_c8;
  undefined4 uStack_c4;
  longlong local_c0;
  longlong local_b8;
  ulonglong local_b0;
  longlong local_a8;
  undefined4 local_a0 [2];
  int *local_98;
  int local_90 [2];
  undefined8 local_88;
  undefined4 local_80 [2];
  undefined8 local_78;
  undefined1 *local_70;
  undefined4 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined1 local_50 [24];
  
  cVar5 = (char)param_4;
  local_b8 = 0;
  local_98 = (int *)0x0;
  local_d8 = 0;
  local_a0[0] = 0;
  piVar1 = *(int **)(param_2 + 0x18);
  if (cVar5 == '\0') {
    if ((*(uint *)(param_3 + 0x10) < 0x18) || (*(uint *)(param_3 + 8) < 8)) {
      return -0x3fffff66;
    }
    piVar6 = (int *)0x0;
    piVar7 = piVar1;
LAB_00011654:
    local_d0[0] = piVar1[4];
    local_90[0] = local_d0[0];
    RtlInitUnicodeString(local_50,L"\\Device\\PhysicalMemory");
    local_80[0] = 0x30;
    local_78 = 0;
    local_68 = 0x240;
    local_70 = local_50;
    local_60 = 0;
    local_58 = 0;
    if (cVar5 != '\0') {
      iVar3 = ZwOpenSection(&local_d8);
      if ((-1 < iVar3) &&
         (iVar3 = ObReferenceObjectByHandle
                            ((longlong)local_d8,0xf001f,0,param_4 & 0xffffffffffffff00,local_a0,0),
         -1 < iVar3)) goto LAB_00011764;
      goto LAB_00011616;
    }
    iVar3 = ZwOpenSection(&local_b8,0xf001f,local_80);
    if ((-1 < iVar3) &&
       (iVar3 = ObReferenceObjectByHandle
                          (local_b8,0xf001f,0,param_4 & 0xffffffffffffff00,&local_98,0), -1 < iVar3)
       ) {
LAB_00011764:
      local_a8 = (ulonglong)((piVar1[2] & 0xffffU) + piVar1[5]) + *(longlong *)(piVar1 + 2);
      cVar2 = HalTranslateBusAddress
                        (*piVar1,piVar1[1],*(undefined8 *)(piVar1 + 2),local_d0,&local_c8);
      if ((cVar2 != '\0') &&
         (cVar2 = HalTranslateBusAddress(*piVar1,piVar1[1],local_a8,local_90,&local_a8),
         cVar2 != '\0')) {
        local_c0 = CONCAT44(uStack_c4,local_c8);
        local_b0 = local_a8 - local_c0;
        if ((int)local_b0 != 0) {
          if (local_d0[0] == 0) {
            if (cVar5 == '\0') {
              local_88 = 0;
              iVar3 = ZwMapViewOfSection(local_b8,0xffffffffffffffff,&local_88,0,
                                         local_b0 & 0xffffffff,&local_c0,&local_b0,1,0,0x204);
              if (iVar3 < 0) goto LAB_000118f5;
              local_c8 = ((int)local_88 - (int)local_c0) + local_c8;
              goto LAB_000118e3;
            }
            local_d4 = 0;
            iVar3 = ZwMapViewOfSection((longlong)local_d8,0xffffffffffffffff,&local_d4,0,
                                       local_b0 & 0xffffffff,&local_c0,&local_b0,1,0,0x204);
            if (-1 < iVar3) {
              local_d4 = local_d4 + (local_c8 - (int)local_c0);
              *piVar6 = local_d4;
              iVar3 = 0;
            }
          }
          else if (cVar5 == '\0') {
LAB_000118e3:
            *piVar7 = local_c8;
            iVar3 = 0;
          }
          else {
            *piVar6 = local_c8;
            iVar3 = 0;
          }
          goto LAB_00011616;
        }
      }
      iVar3 = -0x3fffffff;
      goto LAB_00011616;
    }
  }
  else {
    if ((0x17 < *(uint *)(param_3 + 0x10)) &&
       (piVar6 = piVar1, piVar7 = local_98, 3 < *(uint *)(param_3 + 8))) goto LAB_00011654;
    iVar3 = -0x3fffff66;
LAB_00011616:
    if (cVar5 != '\0') {
      if (local_d8 == 0) {
        return iVar3;
      }
      lVar4 = (longlong)local_d8;
      goto LAB_000118ff;
    }
  }
LAB_000118f5:
  lVar4 = local_b8;
  if (local_b8 == 0) {
    return iVar3;
  }
LAB_000118ff:
  ZwClose(lVar4);
  return iVar3;
}

