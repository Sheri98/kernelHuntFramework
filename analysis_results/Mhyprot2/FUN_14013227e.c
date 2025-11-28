// Function: FUN_14013227e
// Address: 14013227e
// Decompiled by Ghidra


/* WARNING: Control flow encountered bad instruction data */

void FUN_14013227e(undefined8 param_1,undefined2 param_2)

{
  int *piVar1;
  code *pcVar2;
  char unaff_BL;
  undefined7 unaff_00000019;
  undefined4 *unaff_RSI;
  
  out(*unaff_RSI,param_2);
  if ((char)(unaff_BL - *(char *)(CONCAT71(unaff_00000019,unaff_BL) + -0x56191573)) < '\0') {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  piVar1 = (int *)(CONCAT71(unaff_00000019,unaff_BL) + -0x13);
  *piVar1 = *piVar1 + -1;
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}

