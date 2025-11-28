// Function: FUN_140002930
// Address: 140002930
// Decompiled by Ghidra


void FUN_140002930(undefined1 param_1)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(&DAT_1400061a8);
  DAT_1400050e7 = param_1;
                    /* WARNING: Could not recover jumptable at 0x000140002959. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  KeReleaseSpinLock(&DAT_1400061a8,uVar1);
  return;
}

