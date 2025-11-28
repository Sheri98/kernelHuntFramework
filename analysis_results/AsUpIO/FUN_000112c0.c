// Function: FUN_000112c0
// Address: 000112c0
// Decompiled by Ghidra


undefined8 FUN_000112c0(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint local_48 [2];
  undefined4 local_40;
  undefined4 uStack_3c;
  
  iVar1 = *(int *)(param_2 + 0x18);
  puVar2 = *(undefined4 **)(param_1 + 0x18);
  if (iVar1 == -0x5fbf9c00) {
    uVar6 = 1;
  }
  else if (iVar1 == -0x5fbf9bfc) {
    uVar6 = 2;
  }
  else {
    uVar6 = local_48[0];
    if (iVar1 == -0x5fbf9bf8) {
      uVar6 = 4;
    }
  }
  if ((*(int *)(param_2 + 0x10) != 4) || (*(uint *)(param_2 + 8) < uVar6)) {
    return 0xc000000d;
  }
  local_40 = *puVar2;
  uStack_3c = 0;
  local_48[0] = 1;
  HalTranslateBusAddress(1,0,local_40,local_48,&local_40);
  if (local_48[0] == 1) {
    uVar4 = (undefined2)local_40;
    if (iVar1 == -0x5fbf9c00) {
      uVar3 = in(uVar4);
      *(undefined1 *)puVar2 = uVar3;
    }
    else {
      if (iVar1 == -0x5fbf9bfc) {
        uVar4 = in(uVar4);
        *(undefined2 *)puVar2 = uVar4;
        *(ulonglong *)(param_1 + 0x38) = (ulonglong)uVar6;
        return 0;
      }
      if (iVar1 == -0x5fbf9bf8) {
        uVar5 = in(uVar4);
        *puVar2 = uVar5;
        *(ulonglong *)(param_1 + 0x38) = (ulonglong)uVar6;
        return 0;
      }
    }
  }
  *(ulonglong *)(param_1 + 0x38) = (ulonglong)uVar6;
  return 0;
}

