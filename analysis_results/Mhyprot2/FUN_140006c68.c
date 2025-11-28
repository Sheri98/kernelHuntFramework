// Function: FUN_140006c68
// Address: 140006c68
// Decompiled by Ghidra


void FUN_140006c68(void)

{
  LOCK();
  DAT_14000a6e8 = 1;
  UNLOCK();
  KeWaitForSingleObject(DAT_14000a6f0,0,0,0,0);
                    /* WARNING: Could not recover jumptable at 0x000140006c9d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ObfDereferenceObject(DAT_14000a6f0);
  return;
}

