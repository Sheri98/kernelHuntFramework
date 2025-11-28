// Function: FUN_14013246d
// Address: 14013246d
// Decompiled by Ghidra


/* WARNING: Control flow encountered bad instruction data */

void FUN_14013246d(longlong param_1,uint param_2)

{
  int *piVar1;
  ulonglong uVar2;
  ulonglong in_RAX;
  char cVar4;
  longlong lVar3;
  char *pcVar5;
  int unaff_EDI;
  undefined4 unaff_0000003c;
  char in_ZF;
  
  lVar3 = param_1 + -1;
  if (lVar3 == 0 || in_ZF != '\0') {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uVar2 = (longlong)((ulonglong)param_2 << 0x20 | in_RAX & 0xffffffff) / (longlong)unaff_EDI;
  pcVar5 = (char *)(uVar2 & 0xffffffff);
  FUN_14005a2bc();
  cVar4 = (char)((ulonglong)lVar3 >> 8) >> 6;
  piVar1 = (int *)(CONCAT44(unaff_0000003c,unaff_EDI) + -0x2ff38098);
  *piVar1 = *piVar1 + -1;
  FUN_14009dd98();
  FUN_1400a7de0();
  lVar3 = (longlong)(int)uVar2 * 0xccfd593;
  LOCK();
  pcVar5[-0x44] = (char)((ulonglong)lVar3 >> 8);
  UNLOCK();
  *pcVar5 = (*pcVar5 - cVar4) - ((int)lVar3 != lVar3);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

