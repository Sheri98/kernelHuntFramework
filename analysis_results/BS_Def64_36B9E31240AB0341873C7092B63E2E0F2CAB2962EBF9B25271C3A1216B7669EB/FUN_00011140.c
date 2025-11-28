// Function: FUN_00011140
// Address: 00011140
// Decompiled by Ghidra


void FUN_00011140(void)

{
  if ((DAT_00014030 != 0) && (DAT_00014028 != 0)) {
    MmUnmapLockedPages();
    DAT_00014028 = 0;
    IoFreeMdl(DAT_00014030);
    DAT_00014030 = 0;
  }
  if (DAT_00014020 != 0) {
    MmFreeContiguousMemory();
    DAT_00014020 = 0;
  }
  DAT_00014038 = 0;
  return;
}

