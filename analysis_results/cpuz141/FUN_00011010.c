// Function: FUN_00011010
// Address: 00011010
// Decompiled by Ghidra


undefined4 FUN_00011010(longlong param_1)

{
  int local_res10 [2];
  int local_res18 [2];
  uint local_res20 [2];
  
  PsGetVersion(local_res18,local_res10,local_res20,0);
  if (local_res18[0] == 5) {
    if (local_res10[0] == 0) {
      return *(undefined4 *)(param_1 + 0x24);
    }
  }
  else {
    if (local_res18[0] == 6) {
      if (local_res10[0] != 4) goto LAB_00011059;
    }
    else if ((local_res18[0] != 10) || (local_res10[0] != 0)) goto LAB_00011059;
    if (0x37ba < local_res20[0]) {
      return *(undefined4 *)(param_1 + 0x28);
    }
  }
LAB_00011059:
  return *(undefined4 *)(param_1 + 0x20);
}

