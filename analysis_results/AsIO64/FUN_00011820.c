// Function: FUN_00011820
// Address: 00011820
// Decompiled by Ghidra


int FUN_00011820(undefined8 param_1,longlong param_2,longlong param_3,ulonglong param_4)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  int *piVar4;
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
  if (cVar5 == '\0') {
    DbgPrint("[MapMemMapTheMemory] In\n");
    piVar4 = *(int **)(param_2 + 0x18);
    if ((0x17 < *(uint *)(param_3 + 0x10)) &&
       (piVar6 = local_98, piVar7 = piVar4, 7 < *(uint *)(param_3 + 8))) goto LAB_000118c6;
    iVar2 = -0x3fffff66;
    DbgPrint("[MapMemMapTheMemory] STATUS_INSUFFICIENT_RESOURCES\n");
LAB_00011bb2:
    lVar3 = local_b8;
    if (local_b8 == 0) goto LAB_00011bc2;
  }
  else {
    piVar4 = *(int **)(param_2 + 0x18);
    if ((*(uint *)(param_3 + 0x10) < 0x18) ||
       (piVar6 = piVar4, piVar7 = local_98, *(uint *)(param_3 + 8) < 4)) {
      iVar2 = -0x3fffff66;
      goto LAB_0001187a;
    }
LAB_000118c6:
    local_d0[0] = piVar4[4];
    local_90[0] = local_d0[0];
    RtlInitUnicodeString(local_50,L"\\Device\\PhysicalMemory");
    local_80[0] = 0x30;
    local_78 = 0;
    local_68 = 0x40;
    local_70 = local_50;
    local_60 = 0;
    local_58 = 0;
    if (cVar5 == '\0') {
      DbgPrint("[MapMemMapTheMemory] ZwOpenSection\n");
      iVar2 = ZwOpenSection(&local_b8,0xf001f,local_80);
      if ((iVar2 < 0) ||
         (iVar2 = ObReferenceObjectByHandle
                            (local_b8,0xf001f,0,param_4 & 0xffffffffffffff00,&local_98,0), iVar2 < 0
         )) goto LAB_00011bb2;
    }
    else {
      iVar2 = ZwOpenSection(&local_d8,0xf001f,local_80);
      if ((iVar2 < 0) ||
         (iVar2 = ObReferenceObjectByHandle
                            ((longlong)local_d8,0xf001f,0,param_4 & 0xffffffffffffff00,local_a0,0),
         iVar2 < 0)) goto LAB_0001187a;
    }
    local_a8 = (ulonglong)((piVar4[2] & 0xffffU) + piVar4[5]) + *(longlong *)(piVar4 + 2);
    cVar1 = HalTranslateBusAddress(*piVar4,piVar4[1],*(undefined8 *)(piVar4 + 2),local_d0,&local_c8)
    ;
    if ((cVar1 == '\0') ||
       (cVar1 = HalTranslateBusAddress(*piVar4,piVar4[1],local_a8,local_90,&local_a8), cVar1 == '\0'
       )) {
LAB_00011a71:
      iVar2 = -0x3fffffff;
    }
    else {
      local_c0 = CONCAT44(uStack_c4,local_c8);
      local_b0 = local_a8 - local_c0;
      if ((int)local_b0 == 0) goto LAB_00011a71;
      if (local_d0[0] == 0) {
        if (cVar5 == '\0') {
          local_88 = 0;
          iVar2 = ZwMapViewOfSection(local_b8,0xffffffffffffffff,&local_88,0,local_b0 & 0xffffffff,
                                     &local_c0,&local_b0,1,0,0x204);
          if (iVar2 < 0) goto LAB_00011bb2;
          local_c8 = ((int)local_88 - (int)local_c0) + local_c8;
          goto LAB_00011b8a;
        }
        local_d4 = 0;
        iVar2 = ZwMapViewOfSection((longlong)local_d8,0xffffffffffffffff,&local_d4,0,
                                   local_b0 & 0xffffffff,&local_c0,&local_b0,1,0,0x204);
        if (-1 < iVar2) {
          local_d4 = local_d4 + (local_c8 - (int)local_c0);
          *piVar6 = local_d4;
          DbgPrint("[MapMemMapTheMemory] STATUS_SUCCESS\n");
          iVar2 = 0;
        }
      }
      else if (cVar5 == '\0') {
LAB_00011b8a:
        *piVar7 = local_c8;
        DbgPrint("[MapMemMapTheMemory] STATUS_SUCCESS\n");
        iVar2 = 0;
      }
      else {
        *piVar6 = local_c8;
        DbgPrint("[MapMemMapTheMemory] STATUS_SUCCESS\n");
        iVar2 = 0;
      }
    }
LAB_0001187a:
    if (cVar5 == '\0') goto LAB_00011bb2;
    if (local_d8 == 0) goto LAB_00011bc2;
    lVar3 = (longlong)local_d8;
  }
  ZwClose(lVar3);
LAB_00011bc2:
  DbgPrint("[MapMemMapTheMemory] Out\n");
  return iVar2;
}

