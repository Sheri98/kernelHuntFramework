// Function: FUN_140132713
// Address: 140132713
// Decompiled by Ghidra


/* WARNING: Control flow encountered bad instruction data */

void FUN_140132713(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined2 uVar2;
  undefined4 *unaff_RSI;
  
  uVar2 = (undefined2)param_2;
  lVar1 = CONCAT71((int7)((ulonglong)param_1 >> 8),*(undefined1 *)(param_2 + 0x41354344));
  FUN_14009dd98();
  while (lVar1 != 0) {
    lVar1 = lVar1 + -1;
    out(*unaff_RSI,uVar2);
    unaff_RSI = unaff_RSI + 1;
  }
  FUN_14005a2bc();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

