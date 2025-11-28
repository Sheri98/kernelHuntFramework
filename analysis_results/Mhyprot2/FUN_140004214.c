// Function: FUN_140004214
// Address: 140004214
// Decompiled by Ghidra


bool FUN_140004214(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined8 local_res18 [2];
  
  local_res18[0] = 0;
  iVar1 = FUN_140003f2c(param_1,local_res18);
  *param_2 = (undefined4)local_res18[0];
  return iVar1 == 0;
}

