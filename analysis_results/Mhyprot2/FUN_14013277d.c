// Function: FUN_14013277d
// Address: 14013277d
// Decompiled by Ghidra


/* WARNING: Control flow encountered bad instruction data */

void FUN_14013277d(longlong param_1)

{
  undefined8 in_RAX;
  
  *(char *)(param_1 + 0x67) = (char)((ulonglong)in_RAX >> 8);
  out(0x44,(int)(short)in_RAX);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

