// Function: FUN_140001bb4
// Address: 140001bb4
// Decompiled by Ghidra


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong FUN_140001bb4(void)

{
  uint uVar1;
  
  uVar1 = KeQueryTimeIncrement();
  return (longlong)((ulonglong)uVar1 * _DAT_fffff78000000320) / 10000;
}

