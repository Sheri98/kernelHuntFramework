// Function: FUN_00011454
// Address: 00011454
// Decompiled by Ghidra


/* WARNING: Type propagation algorithm not settling */

int FUN_00011454(longlong param_1,uint param_2,longlong *param_3,undefined8 *param_4)

{
  char cVar1;
  char cVar2;
  int iVar3;
  ulonglong uVar4;
  undefined4 local_res20 [2];
  longlong local_88;
  longlong local_80;
  longlong local_78;
  longlong local_70;
  ulonglong local_68 [2];
  undefined4 local_58 [2];
  undefined8 local_50;
  undefined1 *local_48;
  undefined4 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined1 local_28 [16];
  
  local_68[1] = 0;
  local_78 = 0;
  uVar4 = (ulonglong)param_2;
  RtlInitUnicodeString(local_28,L"\\Device\\PhysicalMemoryToLinear");
  local_50 = 0;
  local_38 = 0;
  local_30 = 0;
  *param_4 = 0;
  local_48 = local_28;
  local_58[0] = 0x30;
  local_40 = 0x40;
  iVar3 = ZwOpenSection(param_4,0xf001f,local_58);
  if ((-1 < iVar3) &&
     (iVar3 = ObReferenceObjectByHandle(*param_4,0xf001f,0,0,local_68 + 1,0), -1 < iVar3)) {
    local_res20[0] = 0;
    local_88 = param_1 + uVar4;
    local_80 = param_1;
    cVar1 = HalTranslateBusAddress(1,0,param_1,local_res20,&local_80);
    local_res20[0] = 0;
    cVar2 = HalTranslateBusAddress(1,0,local_88,local_res20,&local_88);
    if (cVar1 == '\0') {
      return iVar3;
    }
    if (cVar2 == '\0') {
      return iVar3;
    }
    if ((int)local_88 == (int)local_80) {
      return iVar3;
    }
    local_70 = local_80;
    local_68[0] = uVar4;
    iVar3 = ZwMapViewOfSection(*param_4,0xffffffffffffffff,&local_78,0,uVar4,&local_70,local_68,1,0,
                               0x204);
    if (-1 < iVar3) {
      *param_3 = (ulonglong)(uint)((int)local_80 - (int)local_70) + local_78;
      return iVar3;
    }
  }
  ZwClose(*param_4);
  return iVar3;
}

