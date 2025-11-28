// Function: FUN_140132363
// Address: 140132363
// Decompiled by Ghidra


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0001401323ed) overlaps instruction at (ram,0x0001401323e9)
    */

void FUN_140132363(longlong param_1,uint param_2)

{
  undefined1 in_CF;
  undefined1 in_ZF;
  
  FUN_14009bdf8(param_1,param_2);
  FUN_14003609e();
  FUN_140062be5();
  if (!(bool)in_CF && !(bool)in_ZF) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (param_1 == 1) {
    FUN_14003609e();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  FUN_1400bf4a3();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

