// Function: FUN_1401324eb
// Address: 1401324eb
// Decompiled by Ghidra


/* WARNING: Control flow encountered bad instruction data */

void FUN_1401324eb(undefined8 param_1)

{
  longlong lVar1;
  int unaff_ESI;
  undefined4 unaff_00000034;
  
  lVar1 = (longlong)unaff_ESI * 0xccfd593;
  LOCK();
  *(char *)(CONCAT44(unaff_00000034,unaff_ESI) + -0x44) = (char)((ulonglong)lVar1 >> 8);
  UNLOCK();
  *(char *)CONCAT44(unaff_00000034,unaff_ESI) =
       (*(char *)CONCAT44(unaff_00000034,unaff_ESI) - (char)((ulonglong)param_1 >> 8)) -
       ((int)lVar1 != lVar1);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

