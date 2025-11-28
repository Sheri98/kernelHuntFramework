// Function: FUN_14000da80
// Address: 14000da80
// Decompiled by Ghidra


/* WARNING: Control flow encountered bad instruction data */

void FUN_14000da80(undefined8 param_1,undefined2 param_2)

{
  undefined1 *puVar1;
  undefined4 *unaff_RSI;
  
  puVar1 = &LAB_14000db40;
  FUN_14009dd98();
  while (puVar1 != (undefined1 *)0x0) {
    puVar1 = puVar1 + -1;
    out(*unaff_RSI,param_2);
    unaff_RSI = unaff_RSI + 1;
  }
  FUN_14005a2bc();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

