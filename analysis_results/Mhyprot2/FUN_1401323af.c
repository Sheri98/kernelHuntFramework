// Function: FUN_1401323af
// Address: 1401323af
// Decompiled by Ghidra


/* WARNING: Control flow encountered bad instruction data */

void FUN_1401323af(undefined8 param_1,undefined2 param_2)

{
  int *piVar1;
  undefined1 in_AL;
  undefined7 in_register_00000001;
  char in_SF;
  char in_OF;
  
  if (in_OF != in_SF) {
    out(param_2,in_AL);
    return;
  }
  LOCK();
  piVar1 = (int *)(CONCAT71(in_register_00000001,in_AL) + 0x68);
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  LOCK();
  piVar1 = (int *)(CONCAT71(in_register_00000001,in_AL) + -0x2f);
  *piVar1 = *piVar1 + 1;
  UNLOCK();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

