// Function: FUN_140009000
// Address: 140009000
// Decompiled by Ghidra


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140009000(void)

{
  code *pcVar1;
  
  if ((DAT_1400050c8 != 0) && (DAT_1400050c8 != 0x2b992ddfa232)) {
    _DAT_1400050d0 = ~DAT_1400050c8;
    return;
  }
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(6);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

