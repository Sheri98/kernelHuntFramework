// Function: entry
// Address: 00016008
// Decompiled by Ghidra


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(longlong param_1)

{
  if (((DAT_00014100 == 0) || (DAT_00014100 == 0x2b992ddfa232)) &&
     (DAT_00014100 = (_DAT_fffff78000000320 ^ 0x14100) & 0xffffffffffff, DAT_00014100 == 0)) {
    DAT_00014100 = 0x2b992ddfa232;
  }
  DAT_00014108 = ~DAT_00014100;
  FUN_00011008(param_1);
  return;
}

