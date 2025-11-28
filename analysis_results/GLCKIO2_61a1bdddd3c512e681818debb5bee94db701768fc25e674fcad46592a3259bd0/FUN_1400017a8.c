// Function: FUN_1400017a8
// Address: 1400017a8
// Decompiled by Ghidra


int FUN_1400017a8(longlong param_1,longlong param_2,longlong *param_3,undefined8 *param_4,
                 undefined8 *param_5)

{
  char cVar1;
  char cVar2;
  int iVar3;
  longlong local_res10 [2];
  undefined4 local_res20 [2];
  longlong local_88;
  longlong local_80;
  longlong local_78;
  longlong local_70;
  undefined1 local_68 [16];
  undefined4 local_58 [2];
  undefined8 local_50;
  undefined1 *local_48;
  undefined4 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_70 = 0;
  local_res10[0] = param_2;
  RtlInitUnicodeString(local_68,L"\\Device\\PhysicalMemory");
  *param_4 = 0;
  local_48 = local_68;
  local_50 = 0;
  local_58[0] = 0x30;
  local_40 = 0x40;
  *param_5 = 0;
  local_38 = 0;
  uStack_30 = 0;
  iVar3 = ZwOpenSection(param_4,0xf001f,local_58);
  if ((-1 < iVar3) &&
     (iVar3 = ObReferenceObjectByHandle(*param_4,0xf001f,0,0,param_5,0), -1 < iVar3)) {
    local_res20[0] = 0;
    local_88 = local_res10[0] + param_1;
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
    local_res10[0] = local_88 - local_80;
    local_78 = local_80;
    iVar3 = ZwMapViewOfSection(*param_4,0xffffffffffffffff,&local_70,0,local_res10[0],&local_78,
                               local_res10,1,0,0x204);
    if (iVar3 == -0x3fffffe8) {
      iVar3 = ZwMapViewOfSection(*param_4,0xffffffffffffffff,&local_70,0,local_res10[0],&local_78,
                                 local_res10,1,0,4);
    }
    if (-1 < iVar3) {
      *param_3 = (local_80 - local_78) + local_70;
      return iVar3;
    }
  }
  ZwClose(*param_4);
  return iVar3;
}

