// Function: FUN_00011dd0
// Address: 00011dd0
// Decompiled by Ghidra


/* WARNING: Type propagation algorithm not settling */

int FUN_00011dd0(undefined4 *param_1,ulonglong *param_2,undefined8 param_3,ulonglong param_4)

{
  char cVar1;
  int iVar2;
  int local_b8 [2];
  longlong local_b0;
  longlong local_a8;
  undefined4 local_a0 [2];
  uint local_98;
  undefined4 uStack_94;
  undefined4 local_90;
  undefined4 uStack_8c;
  longlong local_88;
  undefined8 local_80;
  ulonglong local_78 [2];
  undefined4 local_68 [2];
  undefined8 local_60;
  undefined1 *local_58;
  undefined4 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined1 local_38 [16];
  
  local_b0 = 0;
  local_78[1] = 0;
  local_b8[0] = 0;
  local_a0[0] = 0;
  local_90 = *param_1;
  uStack_8c = 0;
  RtlInitUnicodeString(local_38,L"\\Device\\PhysicalMemory");
  local_68[0] = 0x30;
  local_60 = 0;
  local_50 = 0x40;
  local_58 = local_38;
  local_48 = 0;
  local_40 = 0;
  iVar2 = ZwOpenSection(&local_b0,0xf001f,local_68);
  if (-1 < iVar2) {
    iVar2 = ObReferenceObjectByHandle
                      (local_b0,0xf001f,0,param_4 & 0xffffffffffffff00,local_78 + 1,0);
    if (-1 < iVar2) {
      local_a8 = (ulonglong)(uint)param_1[1] + CONCAT44(uStack_8c,local_90);
      cVar1 = HalTranslateBusAddress(1,0,CONCAT44(uStack_8c,local_90),local_b8,&local_98);
      if (cVar1 != '\0') {
        cVar1 = HalTranslateBusAddress(1,0,local_a8,local_a0,&local_a8);
        if (cVar1 != '\0') {
          local_88 = CONCAT44(uStack_94,local_98);
          local_78[0] = local_a8 - local_88;
          if ((int)local_78[0] != 0) {
            if (local_b8[0] == 0) {
              local_80 = 0;
              iVar2 = ZwMapViewOfSection(local_b0,0xffffffffffffffff,&local_80,0,
                                         local_78[0] & 0xffffffff,&local_88,local_78,1,0,0x204);
              if (-1 < iVar2) {
                *param_2 = (ulonglong)(((int)local_80 - (int)local_88) + local_98);
                iVar2 = 0;
              }
            }
            else {
              *param_2 = (ulonglong)local_98;
              iVar2 = 0;
            }
            goto LAB_00011fc8;
          }
        }
      }
      iVar2 = -0x3fffffff;
    }
  }
LAB_00011fc8:
  if (local_b0 != 0) {
    ZwClose();
  }
  return iVar2;
}

