// Function: FUN_1401324b4
// Address: 1401324b4
// Decompiled by Ghidra


/* WARNING: Control flow encountered bad instruction data */

void FUN_1401324b4(undefined8 param_1)

{
  longlong lVar1;
  uint uVar2;
  char cVar3;
  char *pcVar4;
  longlong unaff_RDI;
  
  cVar3 = (char)((ulonglong)param_1 >> 8);
  uVar2 = FUN_1400a7de0();
  pcVar4 = (char *)(ulonglong)uVar2;
  FUN_14005a2bc();
  cVar3 = cVar3 >> 6;
  *(int *)(unaff_RDI + -0x2ff38098) = *(int *)(unaff_RDI + -0x2ff38098) + -1;
  FUN_14009dd98();
  FUN_1400a7de0();
  lVar1 = (longlong)(int)uVar2 * 0xccfd593;
  LOCK();
  pcVar4[-0x44] = (char)((ulonglong)lVar1 >> 8);
  UNLOCK();
  *pcVar4 = (*pcVar4 - cVar3) - ((int)lVar1 != lVar1);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

