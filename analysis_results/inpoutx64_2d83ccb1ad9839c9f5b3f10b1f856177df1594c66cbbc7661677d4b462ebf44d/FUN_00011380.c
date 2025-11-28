// Function: FUN_00011380
// Address: 00011380
// Decompiled by Ghidra


/* WARNING: Type propagation algorithm not settling */

int FUN_00011380(longlong param_1,longlong param_2,longlong *param_3,undefined8 *param_4)

{
  char cVar1;
  char cVar2;
  int iVar3;
  longlong local_res10 [2];
  undefined4 local_res20 [2];
  longlong local_88;
  longlong local_80;
  longlong local_78;
  longlong local_70 [2];
  undefined4 local_60 [2];
  undefined8 local_58;
  undefined1 *local_50;
  undefined4 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined1 local_30 [24];
  
  local_70[1] = 0;
  local_78 = 0;
  local_res10[0] = param_2;
  RtlInitUnicodeString(local_30,L"\\Device\\PhysicalMemory");
  local_58 = 0;
  local_40 = 0;
  local_38 = 0;
  *param_4 = 0;
  local_50 = local_30;
  local_60[0] = 0x30;
  local_48 = 0x40;
  iVar3 = ZwOpenSection(param_4,0xf001f,local_60);
  if ((-1 < iVar3) &&
     (iVar3 = ObReferenceObjectByHandle(*param_4,0xf001f,0,0,local_70 + 1,0), -1 < iVar3)) {
    local_res20[0] = 0;
    local_88 = param_1 + local_res10[0];
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
    if ((int)local_res10[0] == 0) {
      return iVar3;
    }
    local_70[0] = local_80;
    iVar3 = ZwMapViewOfSection(*param_4,0xffffffffffffffff,&local_78,0,local_res10[0],local_70,
                               local_res10,1,0,0x204);
    if (-1 < iVar3) {
      *param_3 = (ulonglong)(uint)((int)local_80 - (int)local_70[0]) + local_78;
      return iVar3;
    }
  }
  ZwClose(*param_4);
  return iVar3;
}

