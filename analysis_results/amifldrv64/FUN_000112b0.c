// Function: FUN_000112b0
// Address: 000112b0
// Decompiled by Ghidra


uint FUN_000112b0(uint *param_1)

{
  uint uVar1;
  char cVar2;
  undefined4 uVar3;
  uint local_res8 [2];
  uint *local_28;
  uint local_20;
  undefined4 uStack_1c;
  uint local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 uStack_c;
  
  uVar1 = param_1[2];
  local_res8[0] = param_1[1];
  if (uVar1 == 0) {
    local_18 = *param_1;
    uVar3 = 1;
    uStack_14 = 0;
    cVar2 = HalTranslateBusAddress(1,0,local_18,local_res8,&local_10);
    if (cVar2 == '\0') {
      return 0xc000002e;
    }
    if (local_res8[0] == 0) {
      local_28 = (uint *)MmMapIoSpace(CONCAT44(uStack_c,local_10),1,0);
    }
    else {
      local_28 = (uint *)CONCAT44(local_28._4_4_,local_10);
    }
    if (local_res8[0] == 0) {
      *(char *)local_28 = (char)param_1[3];
      LOCK();
      UNLOCK();
    }
    else {
      out(local_28._0_2_,(char)param_1[3]);
    }
  }
  else if (uVar1 == 1) {
    local_20 = *param_1;
    uVar3 = 2;
    uStack_1c = 0;
    cVar2 = HalTranslateBusAddress(1,0,local_20,local_res8,&local_18);
    if (cVar2 == '\0') {
      return 0xc000002e;
    }
    if (local_res8[0] == 0) {
      local_28 = (uint *)MmMapIoSpace(CONCAT44(uStack_14,local_18),2,0);
    }
    else {
      local_28 = (uint *)CONCAT44(local_28._4_4_,local_18);
    }
    if (local_res8[0] == 0) {
      *(short *)local_28 = (short)param_1[3];
      LOCK();
      UNLOCK();
    }
    else {
      out(local_28._0_2_,(short)param_1[3]);
    }
  }
  else if (uVar1 == 2) {
    uVar3 = 4;
    cVar2 = HalTranslateBusAddress(1,0,*param_1,local_res8,&local_20);
    if (cVar2 == '\0') {
      return 0xc000002e;
    }
    if (local_res8[0] == 0) {
      local_28 = (uint *)MmMapIoSpace(CONCAT44(uStack_1c,local_20),4,0);
    }
    else {
      local_28 = (uint *)(ulonglong)local_20;
    }
    if (local_res8[0] == 0) {
      *local_28 = param_1[3];
      LOCK();
      UNLOCK();
    }
    else {
      out(local_28._0_2_,param_1[3]);
    }
  }
  else {
    if (local_res8[0] != 0) {
      return local_res8[0];
    }
    uVar3 = 0;
  }
  if (local_res8[0] == 0) {
    MmUnmapIoSpace(local_28,uVar3);
  }
  return 0;
}

