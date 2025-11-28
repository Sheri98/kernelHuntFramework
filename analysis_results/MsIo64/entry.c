// Function: entry
// Address: 00015010
// Decompiled by Ghidra


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(longlong param_1)

{
  if (((DAT_00013108 == 0) || (DAT_00013108 == 0x2b992ddfa232)) &&
     (DAT_00013108 = (_DAT_fffff78000000320 ^ 0x13108) & 0xffffffffffff, DAT_00013108 == 0)) {
    DAT_00013108 = 0x2b992ddfa232;
  }
  _DAT_00013100 = ~DAT_00013108;
  FUN_000116c0(param_1);
  return;
}

