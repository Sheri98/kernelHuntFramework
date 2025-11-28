// Function: FUN_1400029c0
// Address: 1400029c0
// Decompiled by Ghidra


void FUN_1400029c0(undefined1 param_1)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(&DAT_140005170);
  DAT_1400050ee = param_1;
                    /* WARNING: Could not recover jumptable at 0x0001400029e9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  KeReleaseSpinLock(&DAT_140005170,uVar1);
  return;
}

