// Function: FUN_000110a0
// Address: 000110a0
// Decompiled by Ghidra


undefined8
FUN_000110a0(int param_1,undefined4 *param_2,int param_3,undefined4 *param_4,uint param_5,
            uint *param_6)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if (param_1 == -0x63bf9bfc) {
    uVar4 = 2;
  }
  else {
    uVar4 = 4;
    if (param_1 != -0x63bf9bf8) {
      uVar4 = 1;
    }
  }
  if ((param_3 != 4) || (param_5 < uVar4)) {
    return 0xc000000d;
  }
  uVar2 = (undefined2)*param_2;
  if (param_1 == -0x63bf9c00) {
    uVar1 = in(uVar2);
    *(undefined1 *)param_4 = uVar1;
  }
  else {
    if (param_1 == -0x63bf9bfc) {
      uVar2 = in(uVar2);
      *(undefined2 *)param_4 = uVar2;
      *param_6 = uVar4;
      return 0;
    }
    if (param_1 == -0x63bf9bf8) {
      uVar3 = in(uVar2);
      *param_4 = uVar3;
      *param_6 = uVar4;
      return 0;
    }
  }
  *param_6 = uVar4;
  return 0;
}

