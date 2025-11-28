// Function: FUN_000110a0
// Address: 000110a0
// Decompiled by Ghidra


uint FUN_000110a0(uint *param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint local_res8 [2];
  uint *local_28;
  uint local_20;
  undefined4 uStack_1c;
  uint local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 uStack_c;
  
  local_res8[0] = param_1[1];
  uVar4 = param_1[2];
  if (uVar4 == 0) {
    local_18 = *param_1;
    uVar5 = 1;
    uStack_14 = 0;
    cVar1 = HalTranslateBusAddress(1,0,local_18,local_res8,&local_10);
    if (cVar1 == '\0') {
      return 0xc000002e;
    }
    if (local_res8[0] == 0) {
      local_28 = (uint *)MmMapIoSpace(CONCAT44(uStack_c,local_10),1,0);
    }
    else {
      local_28 = (uint *)CONCAT44(local_28._4_4_,local_10);
    }
    *(undefined1 *)(param_1 + 3) = 0;
    if (local_res8[0] == 0) {
      *(char *)(param_1 + 3) = (char)*local_28;
    }
    else {
      uVar2 = in(local_28._0_2_);
      *(undefined1 *)(param_1 + 3) = uVar2;
    }
  }
  else if (uVar4 == 1) {
    local_20 = *param_1;
    uVar5 = 2;
    uStack_1c = 0;
    cVar1 = HalTranslateBusAddress(1,0,local_20,local_res8,&local_18);
    if (cVar1 == '\0') {
      return 0xc000002e;
    }
    if (local_res8[0] == 0) {
      local_28 = (uint *)MmMapIoSpace(CONCAT44(uStack_14,local_18),2,0);
    }
    else {
      local_28 = (uint *)CONCAT44(local_28._4_4_,local_18);
    }
    *(undefined2 *)(param_1 + 3) = 0;
    if (local_res8[0] == 0) {
      *(short *)(param_1 + 3) = (short)*local_28;
    }
    else {
      uVar3 = in(local_28._0_2_);
      *(undefined2 *)(param_1 + 3) = uVar3;
    }
  }
  else if (uVar4 == 2) {
    uVar5 = 4;
    cVar1 = HalTranslateBusAddress(1,0,*param_1,local_res8,&local_20);
    if (cVar1 == '\0') {
      return 0xc000002e;
    }
    if (local_res8[0] == 0) {
      local_28 = (uint *)MmMapIoSpace(CONCAT44(uStack_1c,local_20),4,0);
    }
    else {
      local_28 = (uint *)(ulonglong)local_20;
    }
    param_1[3] = 0;
    if (local_res8[0] == 0) {
      param_1[3] = *local_28;
    }
    else {
      uVar4 = in(local_28._0_2_);
      param_1[3] = uVar4;
    }
  }
  else {
    if (local_res8[0] != 0) {
      return local_res8[0];
    }
    uVar5 = 0;
  }
  if (local_res8[0] == 0) {
    MmUnmapIoSpace(local_28,uVar5);
  }
  return 0;
}

