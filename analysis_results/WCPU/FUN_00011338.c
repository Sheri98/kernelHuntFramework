// Function: FUN_00011338
// Address: 00011338
// Decompiled by Ghidra


undefined8 FUN_00011338(undefined8 param_1,longlong param_2,longlong param_3,int param_4)

{
  uint *puVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  uint uVar4;
  uint uVar5;
  uint local_res10 [4];
  uint local_res20 [2];
  
  puVar1 = *(uint **)(param_2 + 0x18);
  if (param_4 == -0x2927d994) {
    uVar5 = 1;
  }
  else if (param_4 == -0x2927d990) {
    uVar5 = 2;
  }
  else {
    uVar5 = local_res20[0];
    if (param_4 == -0x2927d98c) {
      uVar5 = 4;
    }
  }
  if ((*(int *)(param_3 + 0x10) != 4) || (*(uint *)(param_3 + 8) < uVar5)) {
    return 0xc000000d;
  }
  local_res10[0] = *puVar1;
  local_res10[1] = 0;
  local_res20[0] = 1;
  HalTranslateBusAddress(1,0,local_res10[0],local_res20,local_res10);
  if (local_res20[0] == 1) {
    uVar3 = (undefined2)local_res10[0];
    if (param_4 == -0x2927d994) {
      uVar2 = in(uVar3);
LAB_00011430:
      *(undefined1 *)puVar1 = uVar2;
      goto LAB_00011432;
    }
    if (param_4 == -0x2927d990) {
      uVar3 = in(uVar3);
LAB_00011425:
      *(undefined2 *)puVar1 = uVar3;
      goto LAB_00011432;
    }
    if (param_4 != -0x2927d98c) goto LAB_00011432;
    uVar4 = in(uVar3);
  }
  else {
    if (param_4 == -0x2927d994) {
      uVar2 = *(undefined1 *)(ulonglong)local_res10[0];
      goto LAB_00011430;
    }
    if (param_4 == -0x2927d990) {
      uVar3 = *(undefined2 *)(ulonglong)local_res10[0];
      goto LAB_00011425;
    }
    if (param_4 != -0x2927d98c) goto LAB_00011432;
    uVar4 = *(uint *)(ulonglong)local_res10[0];
  }
  *puVar1 = uVar4;
LAB_00011432:
  *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar5;
  return 0;
}

