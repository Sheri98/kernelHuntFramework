// Function: FUN_000114c0
// Address: 000114c0
// Decompiled by Ghidra


uint FUN_000114c0(uint *param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint uVar5;
  uint local_28 [2];
  undefined1 *local_20;
  uint local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 uStack_c;
  
  uVar4 = param_1[1];
  local_28[0] = uVar4;
  if (param_1[2] == 0) {
    local_18 = *param_1;
    uVar4 = 0;
    uVar5 = 1;
    uStack_14 = 0;
    cVar1 = HalTranslateBusAddress(1,0,local_18,local_28,&local_10);
    if (cVar1 == '\0') {
      return 0xc000002e;
    }
    if (local_28[0] == 0) {
      local_20 = (undefined1 *)MmMapIoSpace(CONCAT44(uStack_c,local_10),1,0);
    }
    else {
      local_20 = (undefined1 *)CONCAT44(local_20._4_4_,local_10);
    }
    puVar3 = local_20;
    if (local_28[0] == 0) {
      *local_20 = (char)param_1[3];
      LOCK();
      UNLOCK();
    }
    else {
      uVar2 = FUN_00011010((ulonglong)param_1[4],(short)local_20,(uint)(byte)param_1[3]);
      *(short *)(param_1 + 5) = (short)uVar2;
    }
  }
  else {
    puVar3 = local_20;
    uVar5 = uVar4;
    if (param_1[2] == 3) {
      uVar4 = 0;
      local_20 = (undefined1 *)(ulonglong)*param_1;
      cVar1 = HalTranslateBusAddress(1,0,local_20,local_28,&local_18);
      if (cVar1 == '\0') {
        puVar3 = local_20;
        uVar4 = 0xc000002e;
      }
      else if (local_28[0] == 0) {
        puVar3 = (undefined1 *)MmMapIoSpace(CONCAT44(uStack_14,local_18),1,0);
      }
      else {
        local_20 = (undefined1 *)CONCAT44(local_20._4_4_,local_18);
        puVar3 = local_20;
        uVar4 = 0;
      }
      if (local_28[0] == 0) {
        return 1;
      }
      FUN_00011070((ulonglong)param_1[4],(short)puVar3,(char)(short)param_1[3]);
      *(undefined2 *)(param_1 + 5) = 0;
      uVar5 = 1;
    }
    if (uVar4 != 0) {
      return uVar4;
    }
  }
  if (local_28[0] == 0) {
    MmUnmapIoSpace(puVar3,uVar5);
  }
  return uVar4;
}

