// Function: FUN_140132437
// Address: 140132437
// Decompiled by Ghidra


void FUN_140132437(undefined8 param_1,uint param_2)

{
  int *piVar1;
  longlong lVar2;
  longlong unaff_RBP;
  
  lVar2 = FUN_1400a7de0();
  LOCK();
  piVar1 = (int *)(lVar2 + -0x5515a6bf + unaff_RBP * 2);
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  lVar2 = FUN_14009bdf8(param_1,param_2);
  DAT_728be859b1a80d68 = (undefined1)lVar2;
                    /* WARNING: Could not recover jumptable at 0x000140132461. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(ulonglong)*(uint *)(lVar2 + -0x20))();
  return;
}

