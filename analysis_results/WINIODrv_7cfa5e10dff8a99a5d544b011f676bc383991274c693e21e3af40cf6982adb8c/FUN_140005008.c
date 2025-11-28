// Function: FUN_140005008
// Address: 140005008
// Decompiled by Ghidra


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140005008(void)

{
  code *pcVar1;
  
  if ((DAT_140003100 != 0) && (DAT_140003100 != 0x2b992ddfa232)) {
    _DAT_140003108 = ~DAT_140003100;
    return;
  }
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(6);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

