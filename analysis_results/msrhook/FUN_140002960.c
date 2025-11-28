// Function: FUN_140002960
// Address: 140002960
// Decompiled by Ghidra


void FUN_140002960(undefined4 param_1)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(&DAT_140005188);
  DAT_14000510c = param_1;
                    /* WARNING: Could not recover jumptable at 0x000140002989. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  KeReleaseSpinLock(&DAT_140005188,uVar1);
  return;
}

