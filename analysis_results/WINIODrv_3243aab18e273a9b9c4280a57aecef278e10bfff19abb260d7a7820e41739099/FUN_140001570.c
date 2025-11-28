// Function: FUN_140001570
// Address: 140001570
// Decompiled by Ghidra


void FUN_140001570(longlong param_1)

{
  code *pcVar1;
  
  if ((param_1 == DAT_140003100) && ((short)((ulonglong)param_1 >> 0x30) == 0)) {
    return;
  }
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

