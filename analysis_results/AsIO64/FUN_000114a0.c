// Function: FUN_000114a0
// Address: 000114a0
// Decompiled by Ghidra


undefined8 FUN_000114a0(longlong param_1,longlong param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined1 uVar5;
  undefined2 uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint local_68 [2];
  uint local_60 [2];
  undefined4 local_58;
  undefined4 uStack_54;
  
  iVar1 = *(int *)(param_2 + 0x18);
  iVar2 = *(int *)(param_2 + 0x10);
  uVar3 = *(uint *)(param_2 + 8);
  puVar4 = *(undefined4 **)(param_1 + 0x18);
  DbgPrint("[GpdIoctlReadPort] In\n");
  if (iVar1 == -0x5fbf9c00) {
    uVar8 = 1;
  }
  else if (iVar1 == -0x5fbf9bfc) {
    uVar8 = 2;
  }
  else {
    uVar8 = local_68[0];
    if (iVar1 == -0x5fbf9bf8) {
      uVar8 = 4;
    }
  }
  if ((iVar2 != 4) || (uVar3 < uVar8)) {
    return 0xc000000d;
  }
  local_58 = *puVar4;
  uStack_54 = 0;
  local_68[0] = 1;
  HalTranslateBusAddress(1,0,local_58,local_68,local_60);
  if (local_68[0] == 1) {
    uVar6 = (undefined2)local_60[0];
    if (iVar1 != -0x5fbf9c00) {
      if (iVar1 == -0x5fbf9bfc) {
        uVar6 = in(uVar6);
        *(undefined2 *)puVar4 = uVar6;
      }
      else if (iVar1 == -0x5fbf9bf8) {
        uVar7 = in(uVar6);
        *puVar4 = uVar7;
      }
      goto LAB_000115b1;
    }
    uVar5 = in(uVar6);
  }
  else {
    if (iVar1 != -0x5fbf9c00) {
      if (iVar1 == -0x5fbf9bfc) {
        *(undefined2 *)puVar4 = *(undefined2 *)(ulonglong)local_60[0];
      }
      else if (iVar1 == -0x5fbf9bf8) {
        *puVar4 = *(undefined4 *)(ulonglong)local_60[0];
      }
      goto LAB_000115b1;
    }
    uVar5 = *(undefined1 *)(ulonglong)local_60[0];
  }
  *(undefined1 *)puVar4 = uVar5;
LAB_000115b1:
  *(ulonglong *)(param_1 + 0x38) = (ulonglong)uVar8;
  DbgPrint("[GpdIoctlReadPort] Out\n");
  return 0;
}

