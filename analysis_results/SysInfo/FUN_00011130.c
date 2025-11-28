// Function: FUN_00011130
// Address: 00011130
// Decompiled by Ghidra


undefined8 FUN_00011130(int param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  undefined2 uVar2;
  
  if (param_1 == -0x63bf5bbc) {
    iVar1 = 2;
  }
  else {
    iVar1 = 4;
    if (param_1 != -0x63bf5bb8) {
      iVar1 = 1;
    }
  }
  if (param_3 < iVar1 + 4U) {
    return 0xc000000d;
  }
  uVar2 = (undefined2)*param_2;
  if (param_1 == -0x63bf5bc0) {
    out(uVar2,*(undefined1 *)(param_2 + 1));
  }
  else {
    if (param_1 == -0x63bf5bbc) {
      out(uVar2,*(undefined2 *)(param_2 + 1));
      return 0;
    }
    if (param_1 == -0x63bf5bb8) {
      out(uVar2,param_2[1]);
      return 0;
    }
  }
  return 0;
}

