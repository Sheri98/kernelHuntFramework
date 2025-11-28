// Function: FUN_000110e0
// Address: 000110e0
// Decompiled by Ghidra


/* WARNING: Type propagation algorithm not settling */

ulonglong FUN_000110e0(longlong param_1,longlong param_2,longlong *param_3,undefined8 *param_4)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong local_res10 [2];
  undefined4 local_res20 [2];
  longlong local_98;
  longlong local_90;
  longlong local_88;
  longlong local_80 [2];
  undefined4 local_70 [2];
  undefined8 local_68;
  undefined1 *local_60;
  undefined4 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined1 local_40 [24];
  
  local_80[1] = 0;
  local_88 = 0;
  local_res10[0] = param_2;
  RtlInitUnicodeString(local_40,L"\\Device\\PhysicalMemory");
  local_60 = local_40;
  local_70[0] = 0x30;
  local_68 = 0;
  local_58 = 0x40;
  local_50 = 0;
  local_48 = 0;
  *param_4 = 0;
  uVar3 = ZwOpenSection(param_4,0xf001f,local_70);
  uVar5 = (ulonglong)uVar3;
  if (-1 < (int)uVar3) {
    uVar3 = ObReferenceObjectByHandle(*param_4,0xf001f,0,0,local_80 + 1,0);
    uVar5 = (ulonglong)uVar3;
    if (-1 < (int)uVar3) {
      local_98 = param_1 + local_res10[0];
      local_res20[0] = 0;
      local_90 = param_1;
      cVar1 = HalTranslateBusAddress(1,0,param_1,local_res20,&local_90);
      local_res20[0] = 0;
      cVar2 = HalTranslateBusAddress(1,0,local_98,local_res20,&local_98);
      if (cVar1 == '\0') {
        return uVar5;
      }
      if (cVar2 == '\0') {
        return uVar5;
      }
      local_res10[0] = local_98 - local_90;
      if ((int)local_res10[0] == 0) {
        return uVar5;
      }
      local_80[0] = local_90;
      uVar4 = ZwMapViewOfSection(*param_4,0xffffffffffffffff,&local_88,0,local_res10[0],local_80,
                                 local_res10,1,0,0x204);
      uVar5 = uVar4 & 0xffffffff;
      if (-1 < (int)uVar4) {
        *param_3 = (ulonglong)(uint)((int)local_90 - (int)local_80[0]) + local_88;
        return uVar4;
      }
    }
  }
  ZwClose(*param_4);
  return uVar5;
}

