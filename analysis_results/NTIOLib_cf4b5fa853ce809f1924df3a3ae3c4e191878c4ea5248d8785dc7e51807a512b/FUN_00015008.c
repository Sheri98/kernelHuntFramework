// Function: FUN_00015008
// Address: 00015008
// Decompiled by Ghidra


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00015008(void)

{
  if (((DAT_00013100 == 0) || (DAT_00013100 == 0x2b992ddfa232)) &&
     (DAT_00013100 = (_DAT_fffff78000000320 ^ 0x13100) & 0xffffffffffff, DAT_00013100 == 0)) {
    DAT_00013100 = 0x2b992ddfa232;
  }
  DAT_00013108 = ~DAT_00013100;
  return;
}

