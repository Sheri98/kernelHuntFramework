// Function: FUN_1400016d8
// Address: 1400016d8
// Decompiled by Ghidra


void FUN_1400016d8(undefined8 param_1,undefined8 param_2)

{
  MmUnmapLockedPages();
                    /* WARNING: Could not recover jumptable at 0x0001400016ef. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IoFreeMdl(param_2);
  return;
}

