// Function: FUN_1401324a4
// Address: 1401324a4
// Decompiled by Ghidra


/* WARNING: Control flow encountered bad instruction data */

void FUN_1401324a4(void)

{
  longlong lVar1;
  int in_EAX;
  longlong unaff_RBX;
  bool in_ZF;
  
  lVar1 = (longlong)in_EAX * (longlong)*(int *)(unaff_RBX + 0x33);
  if ((int)lVar1 != lVar1 || in_ZF) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  out((short)((ulonglong)lVar1 >> 0x20),(char)lVar1);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

