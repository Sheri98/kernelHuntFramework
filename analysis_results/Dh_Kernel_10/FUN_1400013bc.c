// Function: FUN_1400013bc
// Address: 1400013bc
// Decompiled by Ghidra


void FUN_1400013bc(undefined8 param_1,undefined8 param_2)

{
  MmUnmapLockedPages();
                    /* WARNING: Could not recover jumptable at 0x0001400013d3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IoFreeMdl(param_2);
  return;
}

