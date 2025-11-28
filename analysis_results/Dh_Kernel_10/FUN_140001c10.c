// Function: FUN_140001c10
// Address: 140001c10
// Decompiled by Ghidra


void FUN_140001c10(longlong param_1)

{
  code *pcVar1;
  
  if ((param_1 == DAT_140004010) && ((short)((ulonglong)param_1 >> 0x30) == 0)) {
    return;
  }
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

