// Function: FUN_00011090
// Address: 00011090
// Decompiled by Ghidra


undefined8 FUN_00011090(undefined8 *param_1)

{
  int local_res10 [2];
  int local_res18 [2];
  uint local_res20 [2];
  
  PsGetVersion(local_res18,local_res10,local_res20,0);
  if (local_res18[0] == 6) {
    if (local_res10[0] != 4) goto LAB_000110c3;
  }
  else if ((local_res18[0] != 10) || (local_res10[0] != 0)) goto LAB_000110c3;
  if (0x37ba < local_res20[0]) {
    return *param_1;
  }
LAB_000110c3:
  return param_1[1];
}

