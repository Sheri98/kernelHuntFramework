// Function: entry
// Address: 00016010
// Decompiled by Ghidra


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(longlong param_1)

{
  if (((DAT_00014188 == 0) || (DAT_00014188 == 0x2b992ddfa232)) &&
     (DAT_00014188 = (_DAT_fffff78000000320 ^ 0x14188) & 0xffffffffffff, DAT_00014188 == 0)) {
    DAT_00014188 = 0x2b992ddfa232;
  }
  _DAT_00014180 = ~DAT_00014188;
  FUN_00012240(param_1);
  return;
}

