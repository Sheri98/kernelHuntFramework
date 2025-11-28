// Function: FUN_1400067f4
// Address: 1400067f4
// Decompiled by Ghidra


byte FUN_1400067f4(longlong param_1)

{
  char cVar1;
  byte *pbVar2;
  
  cVar1 = MmIsAddressValid();
  if ((cVar1 != '\0') && (DAT_14000a738 != 0)) {
    pbVar2 = (byte *)(param_1 + DAT_14000a738);
    cVar1 = MmIsAddressValid(pbVar2);
    if (cVar1 != '\0') {
      return *pbVar2 & 1;
    }
  }
  return 1;
}

