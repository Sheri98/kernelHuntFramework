// Function: FUN_140007338
// Address: 140007338
// Decompiled by Ghidra


undefined8 FUN_140007338(void)

{
  ulonglong in_RAX;
  uint local_res8 [2];
  uint local_res10 [6];
  
  if (DAT_14000a748 == 0) {
    local_res10[0] = 0;
    local_res8[0] = 0;
    PsGetVersion(local_res10,local_res8,0,0);
    in_RAX = (ulonglong)local_res10[0];
    if (local_res10[0] == 5) {
      if (local_res8[0] != 1) {
LAB_1400073df:
        DAT_14000a748 = 0;
        return in_RAX & 0xffffffffffffff00;
      }
      DAT_14000a748 = 0x33;
    }
    else if (local_res10[0] == 6) {
      in_RAX = (ulonglong)local_res8[0];
      if (local_res8[0] == 1) {
        DAT_14000a748 = 0x3d;
      }
      else if (local_res8[0] == 2) {
        DAT_14000a748 = 0x3e;
      }
      else {
        if (local_res8[0] != 3) goto LAB_1400073df;
        DAT_14000a748 = 0x3f;
      }
    }
    else {
      if ((local_res10[0] != 10) || (local_res8[0] != 0)) goto LAB_1400073df;
      DAT_14000a748 = 100;
    }
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}

