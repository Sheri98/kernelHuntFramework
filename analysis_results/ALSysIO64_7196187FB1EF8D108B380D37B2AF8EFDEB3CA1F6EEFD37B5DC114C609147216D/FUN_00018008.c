// Function: FUN_00018008
// Address: 00018008
// Decompiled by Ghidra


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00018008(void)

{
  if (((DAT_00016100 == 0) || (DAT_00016100 == 0x2b992ddfa232)) &&
     (DAT_00016100 = (_DAT_fffff78000000320 ^ 0x16100) & 0xffffffffffff, DAT_00016100 == 0)) {
    DAT_00016100 = 0x2b992ddfa232;
  }
  DAT_00016108 = ~DAT_00016100;
  return;
}

