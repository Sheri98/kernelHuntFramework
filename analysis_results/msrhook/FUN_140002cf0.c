// Function: FUN_140002cf0
// Address: 140002cf0
// Decompiled by Ghidra


ulonglong FUN_140002cf0(void)

{
  undefined1 uVar1;
  char cVar2;
  uint uVar3;
  ulonglong uVar4;
  byte bVar5;
  
  FUN_140002d74();
  uVar4 = 0;
  if (DAT_1400050e8 != 0) {
    do {
      bVar5 = 0;
      uVar1 = (&DAT_1400061c0)[uVar4];
      while( true ) {
        cVar2 = FUN_140002b50();
        if (cVar2 == '\0') {
          DAT_1400050e8 = 0;
          return uVar4;
        }
        FUN_140001012(uVar1);
        cVar2 = FUN_140002b10();
        if (cVar2 == '\0') {
          DAT_1400050e8 = 0;
          return uVar4;
        }
        cVar2 = FUN_140001006();
        if (cVar2 == -6) break;
        bVar5 = bVar5 + 1;
        if (cVar2 != -2) {
          DAT_1400050e8 = 0;
          return uVar4;
        }
        if (2 < bVar5) {
          DAT_1400050e8 = 0;
          return uVar4;
        }
      }
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar3;
    } while (uVar3 < DAT_1400050e8);
  }
  DAT_1400050e8 = 0;
  return uVar4;
}

