// Function: FUN_0001242c
// Address: 0001242c
// Decompiled by Ghidra


/* WARNING: Type propagation algorithm not settling */

int FUN_0001242c(uint *param_1)

{
  uint uVar1;
  longlong lVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  uint local_res8 [2];
  uint local_res10 [2];
  uint local_res18 [2];
  undefined8 local_res20;
  longlong local_98;
  longlong local_90;
  uint local_88 [2];
  ulonglong local_80 [2];
  undefined4 local_70 [2];
  undefined8 local_68;
  undefined1 *local_60;
  undefined4 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined1 local_40 [24];
  
  local_res10[0] = param_1[4];
  uVar6 = *param_1;
  uVar1 = param_1[1];
  lVar2 = *(longlong *)(param_1 + 2);
  local_res8[0] = param_1[5];
  local_res20 = 0;
  local_80[1] = 0;
  local_res18[0] = local_res10[0];
  RtlInitUnicodeString(local_40,L"\\Device\\PhysicalMemory");
  local_60 = local_40;
  local_70[0] = 0x30;
  local_68 = 0;
  local_58 = 0x40;
  local_50 = 0;
  local_48 = 0;
  iVar5 = ZwOpenSection(&local_res20,0xf001f,local_70);
  if (iVar5 < 0) {
    return iVar5;
  }
  iVar5 = ObReferenceObjectByHandle(local_res20,0xf001f,0,0,local_80 + 1,0);
  if (-1 < iVar5) {
    local_98 = (ulonglong)local_res8[0] + lVar2;
    cVar3 = HalTranslateBusAddress(uVar6,uVar1,lVar2,local_res10,local_88);
    cVar4 = HalTranslateBusAddress(uVar6,uVar1,local_98,local_res18,&local_98);
    if ((cVar3 != '\0') && (cVar4 != '\0')) {
      local_80[0] = (ulonglong)local_88[0];
      uVar6 = (uint)(local_98 - local_80[0]);
      if (uVar6 != 0) {
        local_res8[0] = uVar6;
        if (local_res10[0] == 0) {
          local_90 = 0;
          iVar5 = ZwMapViewOfSection(local_res20,0xffffffffffffffff,&local_90,0,
                                     local_98 - local_80[0] & 0xffffffff,local_80,local_res8,1,0,
                                     0x204);
          if (iVar5 < 0) goto LAB_00012630;
          local_90 = local_90 + ((ulonglong)local_88[0] - (local_80[0] & 0xffffffff));
          *param_1 = (uint)local_90;
        }
        else {
          *param_1 = local_88[0];
        }
        iVar5 = 0;
        goto LAB_00012630;
      }
    }
    iVar5 = -0x3fffffff;
  }
LAB_00012630:
  ZwClose(local_res20);
  return iVar5;
}

