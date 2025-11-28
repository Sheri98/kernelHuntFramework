// Function: FUN_140132061
// Address: 140132061
// Decompiled by Ghidra


/* WARNING: Control flow encountered bad instruction data */

void FUN_140132061(undefined8 param_1,undefined2 param_2)

{
  byte bVar1;
  uint in_EAX;
  longlong lVar2;
  
  bVar1 = ((byte)in_EAX | 0x4b) ^ 0x41;
  if ('\0' < (char)bVar1) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  out(param_2,(in_EAX | 0x4b) ^ 0x41);
  out(param_2,bVar1);
  lVar2 = FUN_140002314();
  DAT_14000a0d8._0_4_ = (undefined4)lVar2;
  FUN_14000150f();
  return;
}

