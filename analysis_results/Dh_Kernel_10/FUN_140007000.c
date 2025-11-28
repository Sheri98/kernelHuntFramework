// Function: FUN_140007000
// Address: 140007000
// Decompiled by Ghidra


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140007000(void)

{
  code *pcVar1;
  
  if ((DAT_140004010 != 0) && (DAT_140004010 != 0x2b992ddfa232)) {
    _DAT_140004018 = ~DAT_140004010;
    return;
  }
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(6);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

