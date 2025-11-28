// Function: FUN_1400062ec
// Address: 1400062ec
// Decompiled by Ghidra


uint FUN_1400062ec(longlong param_1,int *param_2)

{
  uint uVar1;
  
  if (*param_2 != 0x88) {
    return 0xffffffff;
  }
  uVar1 = FUN_140006488(param_2[2],param_1,param_2[1]);
  return uVar1;
}

