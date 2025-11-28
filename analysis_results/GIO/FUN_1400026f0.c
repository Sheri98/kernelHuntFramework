// Function: FUN_1400026f0
// Address: 1400026f0
// Decompiled by Ghidra


int FUN_1400026f0(undefined8 param_1,ulonglong *param_2)

{
  undefined4 uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  char cVar4;
  char cVar5;
  int iVar6;
  int local_res10 [2];
  ulonglong local_98;
  undefined8 local_90;
  int local_88 [2];
  longlong local_80;
  ulonglong local_78;
  ulonglong local_70;
  uint local_68 [2];
  undefined8 local_60;
  undefined1 local_58 [16];
  undefined4 local_48 [2];
  undefined8 local_40;
  undefined1 *local_38;
  undefined4 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_res10[0] = (int)param_2[2];
  uVar3 = *param_2;
  uVar1 = *(undefined4 *)((longlong)param_2 + 4);
  uVar2 = param_2[1];
  local_90 = 0;
  local_60 = 0;
  local_78 = (ulonglong)*(uint *)((longlong)param_2 + 0x14);
  local_88[0] = local_res10[0];
  RtlInitUnicodeString(local_58,L"\\Device\\PhysicalMemory");
  local_40 = 0;
  local_38 = local_58;
  local_48[0] = 0x30;
  local_30 = 0x40;
  local_28 = 0;
  uStack_20 = 0;
  iVar6 = ZwOpenSection(&local_90,0xf001f,local_48);
  if (iVar6 < 0) {
    return iVar6;
  }
  iVar6 = ObReferenceObjectByHandle(local_90,0xf001f,0,0,&local_60,0);
  if (-1 < iVar6) {
    local_80 = (local_78 & 0xffffffff) + uVar2;
    cVar4 = HalTranslateBusAddress((int)uVar3,uVar1,uVar2,local_res10,local_68);
    cVar5 = HalTranslateBusAddress((int)uVar3,uVar1,local_80,local_88,&local_80);
    if ((cVar4 != '\0') && (cVar5 != '\0')) {
      local_70 = (ulonglong)local_68[0];
      if ((int)(local_80 - local_70) != 0) {
        local_78 = local_80 - local_70 & 0xffffffff;
        if (local_res10[0] == 0) {
          local_98 = 0;
          iVar6 = ZwMapViewOfSection(local_90,0xffffffffffffffff,&local_98,0,local_78,&local_70,
                                     &local_78,1,0,0x204);
          if (iVar6 < 0) goto LAB_1400028ae;
          local_98 = local_98 + ((ulonglong)local_68[0] - (local_70 & 0xffffffff));
          DbgPrint("VirtualAddress=0x%x");
          local_70 = local_98;
        }
        *param_2 = local_70;
        iVar6 = 0;
        goto LAB_1400028ae;
      }
    }
    iVar6 = -0x3fffffff;
  }
LAB_1400028ae:
  ZwClose(local_90);
  return iVar6;
}

