// Function: FUN_000114f0
// Address: 000114f0
// Decompiled by Ghidra


/* WARNING: Type propagation algorithm not settling */

int FUN_000114f0(undefined8 param_1,longlong param_2,longlong param_3,ulonglong param_4)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  longlong local_b8;
  undefined4 local_b0 [2];
  longlong local_a8;
  undefined4 local_a0 [2];
  longlong local_98;
  ulonglong local_90;
  int local_88;
  undefined4 uStack_84;
  longlong local_80 [2];
  undefined4 local_70 [2];
  undefined8 local_68;
  undefined1 *local_60;
  undefined4 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined1 local_40 [24];
  
  local_b8 = 0;
  local_80[1] = 0;
  if ((*(uint *)(param_3 + 0x10) < 0x18) || (*(uint *)(param_3 + 8) < 8)) {
    return -0x3fffff66;
  }
  puVar1 = *(undefined4 **)(param_2 + 0x18);
  local_b0[0] = puVar1[4];
  local_a0[0] = local_b0[0];
  RtlInitUnicodeString(local_40,L"\\Device\\PhysicalMemory");
  local_70[0] = 0x30;
  local_68 = 0;
  local_58 = 0x40;
  local_60 = local_40;
  local_50 = 0;
  local_48 = 0;
  iVar3 = ZwOpenSection(&local_b8,0xf001f,local_70);
  if (-1 < iVar3) {
    iVar3 = ObReferenceObjectByHandle
                      (local_b8,0xf001f,0,param_4 & 0xffffffffffffff00,local_80 + 1,0);
    if (-1 < iVar3) {
      local_a8 = (ulonglong)((puVar1[2] & 0xffff) + puVar1[5]) + *(longlong *)(puVar1 + 2);
      cVar2 = HalTranslateBusAddress
                        (*puVar1,puVar1[1],*(undefined8 *)(puVar1 + 2),local_b0,&local_88);
      if (cVar2 != '\0') {
        cVar2 = HalTranslateBusAddress(*puVar1,puVar1[1],local_a8,local_a0,&local_a8);
        if (cVar2 != '\0') {
          local_80[0] = CONCAT44(uStack_84,local_88);
          local_90 = local_a8 - local_80[0];
          if ((int)local_90 != 0) {
            local_98 = 0;
            iVar3 = ZwMapViewOfSection(local_b8,0xffffffffffffffff,&local_98,0,local_90 & 0xffffffff
                                       ,local_80,&local_90,1,0,4);
            if (-1 < iVar3) {
              local_98 = local_98 + (ulonglong)(uint)(local_88 - (int)local_80[0]) * 4;
              **(longlong **)(param_2 + 0x18) = local_98;
              iVar3 = 0;
            }
            goto LAB_00011655;
          }
        }
      }
      iVar3 = -0x3fffffff;
    }
  }
LAB_00011655:
  if (local_b8 != 0) {
    ZwClose();
  }
  return iVar3;
}

