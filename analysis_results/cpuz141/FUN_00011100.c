// Function: FUN_00011100
// Address: 00011100
// Decompiled by Ghidra


undefined8 FUN_00011100(longlong param_1)

{
  int local_res10 [2];
  int local_res18 [2];
  uint local_res20 [2];
  
  PsGetVersion(local_res18,local_res10,local_res20,0);
  if (local_res18[0] == 6) {
    if (local_res10[0] != 4) {
      return 0;
    }
  }
  else {
    if (local_res18[0] != 10) {
      return 0;
    }
    if (local_res10[0] != 0) {
      return 0;
    }
  }
  if (local_res20[0] < 0x37bb) {
    return 0;
  }
  return *(undefined8 *)(param_1 + 0x20);
}

