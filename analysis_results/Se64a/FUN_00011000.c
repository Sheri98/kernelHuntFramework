// Function: FUN_00011000
// Address: 00011000
// Decompiled by Ghidra


/* WARNING: Type propagation algorithm not settling */

ulonglong FUN_00011000(undefined8 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  char cVar4;
  char cVar5;
  uint uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  uint local_c8;
  int local_c4;
  longlong local_c0;
  undefined8 local_b8;
  longlong local_b0;
  uint local_a8;
  undefined4 uStack_a4;
  int local_a0 [2];
  ulonglong local_98 [3];
  undefined4 local_80 [2];
  undefined8 local_78;
  undefined1 *local_70;
  undefined4 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined1 local_50 [32];
  
  uVar8 = 0;
  local_b8 = 0;
  local_98[1] = 0;
  param_2[6] = 0x44;
  uVar1 = *param_2;
  uVar2 = param_2[1];
  uVar3 = *(ulonglong *)(param_2 + 2);
  local_c4 = param_2[4];
  local_c8 = param_2[5];
  uVar9 = uVar3;
  local_a0[0] = local_c4;
  DbgPrint("HW_MapTheMemory Entry it=%d busn=%d busaddr=%x IoSpace=%d len=%d\n",uVar1,uVar2,uVar3,
           local_c4,local_c8);
  RtlInitUnicodeString(local_50,L"\\Device\\PhysicalMemory");
  local_80[0] = 0x30;
  local_78 = 0;
  local_68 = 0x40;
  local_70 = local_50;
  local_60 = 0;
  local_58 = 0;
  uVar7 = ZwOpenSection(&local_b8,0xf001f,local_80);
  if ((int)uVar7 < 0) {
    param_2[6] = 0x48;
    return uVar7;
  }
  uVar6 = ObReferenceObjectByHandle(local_b8,0xf001f,0,uVar9 & 0xffffffffffffff00,local_98 + 1,0);
  if ((int)uVar6 < 0) {
    param_2[6] = 0x49;
    uVar8 = (ulonglong)uVar6;
  }
  else {
    local_b0 = local_c8 + uVar3;
    cVar4 = HalTranslateBusAddress(uVar1,uVar2,uVar3,&local_c4,&local_a8);
    cVar5 = HalTranslateBusAddress(uVar1,uVar2,local_b0,local_a0,&local_b0);
    if ((cVar4 == '\0') || (cVar5 == '\0')) {
      param_2[6] = 0x4a;
    }
    else {
      local_98[0] = CONCAT44(uStack_a4,local_a8);
      local_98[2] = local_b0 - local_98[0];
      uVar6 = (uint)local_98[2];
      if (uVar6 != 0) {
        local_c8 = uVar6;
        if (local_c4 == 0) {
          local_c0 = 0;
          uVar6 = ZwMapViewOfSection(local_b8,0xffffffffffffffff,&local_c0,0,
                                     local_98[2] & 0xffffffff,local_98,&local_c8,1,0,0x204);
          uVar8 = (ulonglong)uVar6;
          if ((int)uVar6 < 0) {
            param_2[6] = 0x4c;
          }
          else {
            local_c0 = local_c0 + ((ulonglong)local_a8 - (local_98[0] & 0xffffffff));
            param_2[6] = (undefined4)local_c0;
            uVar8 = 0;
          }
        }
        else {
          param_2[6] = local_a8;
        }
        goto LAB_00011257;
      }
      param_2[6] = 0x4b;
    }
    uVar8 = 0xc0000001;
  }
LAB_00011257:
  ZwClose(local_b8);
  return uVar8;
}

