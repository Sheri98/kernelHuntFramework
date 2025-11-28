// Function: FUN_140001088
// Address: 140001088
// Decompiled by Ghidra


undefined8 FUN_140001088(void)

{
  int iVar1;
  
  if (DAT_140005100 != 0) {
    if (DAT_1400050ee != '\0') {
      FUN_1400029c0(0);
      DAT_140005100 = 0;
    }
    if (DAT_140005100 != 0) {
      return 1;
    }
  }
  FUN_1400029c0(0);
  iVar1 = PsCreateSystemThread(&DAT_140005100,0,0,0,0,FUN_140002b90,0);
  if (iVar1 == 0) {
    DAT_1400050c0 = 1;
    return 1;
  }
  ZwClose(DAT_140005100);
  DAT_140005100 = 0;
  return 0;
}

