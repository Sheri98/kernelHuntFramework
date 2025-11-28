// Function: FUN_140002314
// Address: 140002314
// Decompiled by Ghidra


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong FUN_140002314(void)

{
  uint uVar1;
  
  uVar1 = KeQueryTimeIncrement();
  return (longlong)(_DAT_fffff78000000320 * (ulonglong)uVar1) / 10000;
}

