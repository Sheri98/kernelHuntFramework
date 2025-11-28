// Function: FUN_1400023b8
// Address: 1400023b8
// Decompiled by Ghidra


undefined4 FUN_1400023b8(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  
  if ((-1 < *(int *)(param_2 + 0x30)) && (param_1 != DAT_1400075c0)) {
    FUN_140001bf4(param_2);
  }
  DAT_140005118 = DAT_140005118 + -1;
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  return *(undefined4 *)(param_2 + 0x30);
}

