// Function: FUN_00015008
// Address: 00015008
// Decompiled by Ghidra


undefined8 FUN_00015008(longlong *param_1,char param_2,char param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  int local_20;
  undefined2 uStack_1c;
  undefined2 uStack_1a;
  undefined8 local_18;
  
  if ((int)param_1[1] == 0x18) {
    plVar1 = (longlong *)*param_1;
    lVar2 = *plVar1;
    lVar3 = plVar1[1];
    lVar4 = plVar1[2];
    if ((param_1[2] == 0) || (param_1[2] == lVar2)) {
      uVar5 = KeSetPriorityThread(SystemReserved1[0xf],0x1f);
      local_20 = (int)lVar3;
      uVar7 = (ulonglong)uVar5;
      local_18._0_4_ = (undefined4)lVar4;
      if (param_2 != '\0') {
        uStack_1c = (undefined2)((ulonglong)lVar3 >> 0x20);
        FUN_00011528(uStack_1c,(undefined4)local_18,local_20);
      }
      uStack_1a = (undefined2)((ulonglong)lVar3 >> 0x30);
      if (param_3 == '\0') {
        local_18._4_4_ = (undefined4)((ulonglong)lVar4 >> 0x20);
        FUN_00011528(uStack_1a,local_18._4_4_,local_20);
        local_18 = lVar4;
      }
      else {
        uVar5 = FUN_000114f8(uStack_1a,local_20);
        local_18 = CONCAT44(uVar5,(undefined4)local_18);
      }
      KeSetPriorityThread(SystemReserved1[0xf],uVar7 & 0xffffffff);
      plVar1 = (longlong *)*param_1;
      *plVar1 = lVar2;
      plVar1[1] = lVar3;
      plVar1[2] = local_18;
      uVar6 = 0;
    }
    else {
      uVar6 = 0xc0000005;
    }
  }
  else {
    uVar6 = 0xc000000d;
  }
  return uVar6;
}

