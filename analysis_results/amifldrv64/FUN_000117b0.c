// Function: FUN_000117b0
// Address: 000117b0
// Decompiled by Ghidra


/* WARNING: Type propagation algorithm not settling */

int FUN_000117b0(undefined8 *param_1)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  ulonglong uVar5;
  undefined4 local_88 [2];
  longlong local_80;
  ulonglong local_78 [2];
  ulonglong local_68;
  ulonglong local_60 [2];
  undefined4 local_50 [2];
  undefined8 local_48;
  undefined1 *local_40;
  undefined4 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined1 local_20 [24];
  
  uVar5 = (ulonglong)*(uint *)((longlong)param_1 + 0xc);
  uVar1 = *(uint *)(param_1 + 1);
  local_60[1] = 0;
  local_78[1] = 0;
  RtlInitUnicodeString(local_20,L"\\Device\\PhysicalMemory");
  local_40 = local_20;
  local_50[0] = 0x30;
  local_48 = 0;
  local_38 = 0x240;
  local_30 = 0;
  local_28 = 0;
  *param_1 = 0;
  iVar4 = ZwOpenSection(param_1,0xf001f,local_50);
  if ((-1 < iVar4) &&
     (iVar4 = ObReferenceObjectByHandle(*param_1,0xf001f,0,0,local_60 + 1,0), -1 < iVar4)) {
    local_80 = uVar5 + uVar1;
    local_88[0] = 0;
    local_78[0] = uVar5;
    cVar2 = HalTranslateBusAddress(1,0,uVar5,local_88,local_78);
    local_88[0] = 0;
    cVar3 = HalTranslateBusAddress(1,0,local_80,local_88,&local_80);
    if (cVar2 == '\0') {
      return iVar4;
    }
    if (cVar3 == '\0') {
      return iVar4;
    }
    if ((int)(local_80 - local_78[0]) == 0) {
      return iVar4;
    }
    local_68 = local_78[0];
    local_60[0] = local_80 - local_78[0] & 0xffffffff;
    iVar4 = ZwMapViewOfSection(*param_1,0xffffffffffffffff,local_78 + 1,0,local_60[0],&local_68,
                               local_60,1,0,0x204);
    if (-1 < iVar4) {
      *(int *)(param_1 + 2) = (int)local_78[1] + ((int)local_78[0] - (int)local_68);
      return iVar4;
    }
  }
  ZwClose(*param_1);
  return iVar4;
}

