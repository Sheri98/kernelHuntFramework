// Function: FUN_140002990
// Address: 140002990
// Decompiled by Ghidra


void FUN_140002990(undefined4 param_1)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(&DAT_140005178);
  DAT_140005114 = param_1;
                    /* WARNING: Could not recover jumptable at 0x0001400029b9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  KeReleaseSpinLock(&DAT_140005178,uVar1);
  return;
}

