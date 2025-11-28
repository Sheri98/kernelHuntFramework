// Function: FUN_00017008
// Address: 00017008
// Decompiled by Ghidra


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00017008(void)

{
  if (((DAT_00015100 == 0) || (DAT_00015100 == 0x2b992ddfa232)) &&
     (DAT_00015100 = (_DAT_fffff78000000320 ^ 0x15100) & 0xffffffffffff, DAT_00015100 == 0)) {
    DAT_00015100 = 0x2b992ddfa232;
  }
  DAT_00015108 = ~DAT_00015100;
  return;
}

