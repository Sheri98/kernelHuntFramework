// Function: FUN_140002cbc
// Address: 140002cbc
// Decompiled by Ghidra


ulonglong FUN_140002cbc(void)

{
  undefined1 uVar1;
  char cVar2;
  ulonglong uVar3;
  
  uVar3 = 0;
  while( true ) {
    cVar2 = FUN_140002b10();
    if (cVar2 == '\0') break;
    uVar1 = FUN_140001006();
    (&DAT_1400061c0)[uVar3] = uVar1;
    uVar3 = (ulonglong)((int)uVar3 + 1);
  }
  DAT_1400050e8 = (int)uVar3;
  return uVar3;
}

