// Function: FUN_140132170
// Address: 140132170
// Decompiled by Ghidra


/* WARNING: Control flow encountered bad instruction data */

void FUN_140132170(undefined4 param_1)

{
  longlong unaff_RDI;
  
  *(uint *)(unaff_RDI + -0x17) =
       *(uint *)(unaff_RDI + -0x17) & CONCAT31((int3)((uint)param_1 >> 8),0x7d);
  FUN_14005a2bc();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

