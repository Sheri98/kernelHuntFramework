// Function: FUN_14006f13d
// Address: 14006f13d
// Decompiled by Ghidra


void FUN_14006f13d(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  int iVar1;
  int in_R11D;
  
  iVar1 = 0x1f;
  if ((uint)param_3 != 0) {
    for (; (uint)param_3 >> iVar1 == 0; iVar1 = iVar1 + -1) {
    }
  }
  FUN_1400b0373(param_1,param_2,(undefined *)(param_3 + (in_R11D + 1)));
  return;
}

