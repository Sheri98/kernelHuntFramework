// Function: FUN_000116a0
// Address: 000116a0
// Decompiled by Ghidra


undefined8 FUN_000116a0(undefined4 *param_1)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  int local_18 [2];
  undefined4 local_10;
  undefined4 uStack_c;
  
  local_10 = *param_1;
  uStack_c = 0;
  local_18[0] = 1;
  cVar1 = HalTranslateBusAddress(1,0,local_10,local_18,&local_10);
  if (cVar1 == '\0') {
    return 0xc000002e;
  }
  if (local_18[0] == 0) {
    uVar2 = MmMapIoSpace(CONCAT44(uStack_c,local_10),1);
  }
  else {
    uVar2 = CONCAT44(uStack_c,local_10);
  }
  uVar3 = FUN_00011039((short)uVar2,(ulonglong)*(byte *)(param_1 + 1));
  if (local_18[0] == 0) {
    MmUnmapIoSpace(uVar2,1);
  }
  *(short *)(param_1 + 2) = (short)uVar3;
  return 0;
}

