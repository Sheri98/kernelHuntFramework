// Function: FUN_1400029f0
// Address: 1400029f0
// Decompiled by Ghidra


void FUN_1400029f0(undefined4 param_1)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(&DAT_140005180);
  DAT_140005110 = param_1;
                    /* WARNING: Could not recover jumptable at 0x000140002a19. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  KeReleaseSpinLock(&DAT_140005180,uVar1);
  return;
}

