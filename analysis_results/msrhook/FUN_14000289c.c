// Function: FUN_14000289c
// Address: 14000289c
// Decompiled by Ghidra


void FUN_14000289c(void)

{
  undefined1 uVar1;
  
  FUN_140002960(0);
  FUN_140002990(0);
  FUN_1400029f0(0);
  uVar1 = KeAcquireSpinLockRaiseToDpc(&DAT_1400061a8);
  DAT_140005108 = 0;
  DAT_1400050e8 = 0;
  DAT_1400050e4 = 0;
  DAT_1400050fc = 0;
                    /* WARNING: Could not recover jumptable at 0x0001400028ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  KeReleaseSpinLock(&DAT_1400061a8,uVar1);
  return;
}

