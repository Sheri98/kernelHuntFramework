// Function: FUN_140005eb0
// Address: 140005eb0
// Decompiled by Ghidra


undefined8 FUN_140005eb0(undefined8 param_1,uint param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined8 uVar1;
  
  uVar1 = FUN_140005dd8(param_1,param_2);
  if ((char)uVar1 == '\0') {
    *param_4 = 0xffffffff;
  }
  else {
    *param_4 = 0;
    *(undefined8 *)(param_4 + 2) = 0;
    *(undefined8 *)(param_4 + 4) = 0;
    uVar1 = 1;
    param_4[1] = param_3;
    *(undefined8 *)(param_4 + 6) = param_1;
  }
  return uVar1;
}

