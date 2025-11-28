// Function: FUN_000113f0
// Address: 000113f0
// Decompiled by Ghidra


undefined8 FUN_000113f0(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint local_38 [2];
  undefined2 local_30;
  undefined2 uStack_2e;
  undefined4 uStack_2c;
  
  iVar1 = *(int *)(param_2 + 0x18);
  if (iVar1 == -0x5fbf5bc0) {
    local_38[0] = 1;
  }
  else if (iVar1 == -0x5fbf5bbc) {
    local_38[0] = 2;
  }
  else if (iVar1 == -0x5fbf5bb8) {
    local_38[0] = 4;
  }
  if ((ulonglong)local_38[0] + 4 <= (ulonglong)*(uint *)(param_2 + 0x10)) {
    uVar2 = **(undefined4 **)(param_1 + 0x18);
    local_30 = (undefined2)uVar2;
    uStack_2e = (undefined2)((uint)uVar2 >> 0x10);
    puVar3 = *(undefined4 **)(param_1 + 0x18) + 1;
    uStack_2c = 0;
    local_38[0] = 1;
    HalTranslateBusAddress(1,0,uVar2,local_38,&local_30);
    if (local_38[0] == 1) {
      if (iVar1 != -0x5fbf5bc0) {
        if (iVar1 == -0x5fbf5bbc) {
          out(local_30,*(undefined2 *)puVar3);
        }
        else if (iVar1 != -0x5fbf5bb8) {
          return 0;
        }
        out(local_30,*puVar3);
        return 0;
      }
      out(local_30,*(undefined1 *)puVar3);
    }
    return 0;
  }
  return 0xc000000d;
}

