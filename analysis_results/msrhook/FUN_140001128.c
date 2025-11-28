// Function: FUN_140001128
// Address: 140001128
// Decompiled by Ghidra


undefined8 FUN_140001128(void)

{
  undefined8 local_res8 [4];
  
  if (DAT_140005100 != 0) {
    if (DAT_1400050ee == '\0') {
      FUN_1400029c0(0);
      DAT_1400050c0 = 0;
      local_res8[0] = 0xffffffffffe17b80;
      KeDelayExecutionThread(0,0,local_res8);
    }
    else {
      FUN_1400029c0(0);
    }
    DAT_140005100 = 0;
  }
  FUN_140002960(0);
  return 1;
}

