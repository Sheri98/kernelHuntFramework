// Function: FUN_00011b80
// Address: 00011b80
// Decompiled by Ghidra


int FUN_00011b80(undefined4 *param_1,int *param_2,undefined8 param_3,ulonglong param_4)

{
  char cVar1;
  int iVar2;
  int local_a8;
  int local_a4;
  int local_a0 [2];
  longlong local_98;
  undefined4 local_90;
  undefined4 local_8c;
  int local_88;
  undefined4 uStack_84;
  undefined4 local_80;
  undefined4 uStack_7c;
  longlong local_78;
  ulonglong local_70;
  undefined4 local_68 [2];
  undefined8 local_60;
  undefined1 *local_58;
  undefined4 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined1 local_38 [16];
  
  local_a8 = 0;
  local_90 = 0;
  local_a0[0] = 0;
  local_8c = 0;
  local_80 = *param_1;
  uStack_7c = 0;
  RtlInitUnicodeString(local_38,L"\\Device\\PhysicalMemory");
  local_68[0] = 0x30;
  local_60 = 0;
  local_50 = 0x40;
  local_58 = local_38;
  local_48 = 0;
  local_40 = 0;
  iVar2 = ZwOpenSection(&local_a8,0xf001f,local_68);
  if (-1 < iVar2) {
    iVar2 = ObReferenceObjectByHandle
                      ((longlong)local_a8,0xf001f,0,param_4 & 0xffffffffffffff00,&local_90,0);
    if (-1 < iVar2) {
      local_98 = (ulonglong)(uint)param_1[1] + CONCAT44(uStack_7c,local_80);
      cVar1 = HalTranslateBusAddress(1,0,CONCAT44(uStack_7c,local_80),local_a0,&local_88);
      if (cVar1 != '\0') {
        cVar1 = HalTranslateBusAddress(1,0,local_98,&local_8c,&local_98);
        if (cVar1 != '\0') {
          local_78 = CONCAT44(uStack_84,local_88);
          local_70 = local_98 - local_78;
          if ((int)local_70 != 0) {
            if (local_a0[0] == 0) {
              local_a4 = 0;
              iVar2 = ZwMapViewOfSection((longlong)local_a8,0xffffffffffffffff,&local_a4,0,
                                         local_70 & 0xffffffff,&local_78,&local_70,1,0,0x204);
              if (-1 < iVar2) {
                local_a4 = local_a4 + (local_88 - (int)local_78);
                *param_2 = local_a4;
                iVar2 = 0;
              }
            }
            else {
              *param_2 = local_88;
              iVar2 = 0;
            }
            goto LAB_00011d6d;
          }
        }
      }
      iVar2 = -0x3fffffff;
    }
  }
LAB_00011d6d:
  if (local_a8 != 0) {
    ZwClose((longlong)local_a8);
  }
  return iVar2;
}

