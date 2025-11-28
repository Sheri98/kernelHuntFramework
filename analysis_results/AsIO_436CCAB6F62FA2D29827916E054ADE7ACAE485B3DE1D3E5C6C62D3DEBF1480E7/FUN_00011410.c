// Function: FUN_00011410
// Address: 00011410
// Decompiled by Ghidra


undefined8 FUN_00011410(longlong param_1,longlong param_2,char param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint local_48 [2];
  undefined1 local_40;
  undefined1 uStack_3f;
  undefined2 uStack_3e;
  undefined4 uStack_3c;
  
  iVar1 = *(int *)(param_2 + 0x18);
  if (param_3 == '\0') {
    puVar3 = *(undefined4 **)(param_1 + 0x18);
    puVar4 = (undefined4 *)CONCAT44(uStack_3c,CONCAT22(uStack_3e,CONCAT11(uStack_3f,local_40)));
  }
  else {
    puVar4 = *(undefined4 **)(param_1 + 0x18);
    puVar3 = (undefined4 *)CONCAT44(uStack_3c,CONCAT22(uStack_3e,CONCAT11(uStack_3f,local_40)));
  }
  if (iVar1 == -0x5fbf5bc0) {
    local_48[0] = 1;
  }
  else if (iVar1 == -0x5fbf5bbc) {
    local_48[0] = 2;
  }
  else if (iVar1 == -0x5fbf5bb8) {
    local_48[0] = 4;
  }
  if ((ulonglong)local_48[0] + 4 <= (ulonglong)*(uint *)(param_2 + 0x10)) {
    if (param_3 == '\0') {
      uVar2 = *puVar3;
      puVar3 = puVar3 + 1;
    }
    else {
      uVar2 = *puVar4;
      puVar4 = puVar4 + 1;
    }
    local_40 = (undefined1)uVar2;
    uStack_3f = (undefined1)((uint)uVar2 >> 8);
    uStack_3e = (undefined2)((uint)uVar2 >> 0x10);
    uStack_3c = 0;
    local_48[0] = 1;
    HalTranslateBusAddress(1,0,uVar2,local_48,&local_40);
    if (local_48[0] == 1) {
      if (iVar1 == -0x5fbf5bc0) {
        if (param_3 == '\0') {
          out((short)&local_40,*(undefined1 *)puVar3);
        }
        else {
          out(CONCAT11(uStack_3f,local_40),*(undefined1 *)puVar4);
        }
      }
      else if (iVar1 == -0x5fbf5bbc) {
        if (param_3 == '\0') {
          out((short)&local_40,*(undefined2 *)puVar3);
        }
        else {
          out(CONCAT11(uStack_3f,local_40),*(undefined2 *)puVar4);
        }
      }
      else if (iVar1 == -0x5fbf5bb8) {
        if (param_3 == '\0') {
          out((short)&local_40,*puVar3);
        }
        else {
          out(CONCAT11(uStack_3f,local_40),*puVar4);
        }
      }
    }
    else if (iVar1 == -0x5fbf5bc0) {
      if (param_3 != '\0') {
        *(undefined1 *)(ulonglong)CONCAT22(uStack_3e,CONCAT11(uStack_3f,local_40)) =
             *(undefined1 *)puVar4;
      }
    }
    else if (iVar1 == -0x5fbf5bbc) {
      if (param_3 != '\0') {
        *(undefined2 *)(ulonglong)CONCAT22(uStack_3e,CONCAT11(uStack_3f,local_40)) =
             *(undefined2 *)puVar4;
      }
    }
    else if ((iVar1 == -0x5fbf5bb8) && (param_3 != '\0')) {
      *(undefined4 *)(ulonglong)CONCAT22(uStack_3e,CONCAT11(uStack_3f,local_40)) = *puVar4;
    }
    return 0;
  }
  return 0xc000000d;
}

