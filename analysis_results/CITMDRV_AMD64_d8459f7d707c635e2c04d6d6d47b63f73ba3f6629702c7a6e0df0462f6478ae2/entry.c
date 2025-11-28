// Function: entry
// Address: 00016010
// Decompiled by Ghidra


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(longlong param_1)

{
  if (((DAT_00014108 == 0) || (DAT_00014108 == 0x2b992ddfa232)) &&
     (DAT_00014108 = (_DAT_fffff78000000320 ^ 0x14108) & 0xffffffffffff, DAT_00014108 == 0)) {
    DAT_00014108 = 0x2b992ddfa232;
  }
  DAT_00014100 = ~DAT_00014108;
  FUN_00011c80(param_1);
  return;
}

