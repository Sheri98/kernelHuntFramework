// Function: FUN_140001b8c
// Address: 140001b8c
// Decompiled by Ghidra


undefined8 FUN_140001b8c(longlong param_1)

{
  longlong *plVar1;
  int iVar2;
  
  iVar2 = 0;
  plVar1 = &DAT_140005120;
  do {
    if (*plVar1 == param_1) break;
    plVar1 = plVar1 + 1;
    iVar2 = iVar2 + 1;
  } while ((longlong)plVar1 < 0x140005170);
  return CONCAT71((int7)((ulonglong)plVar1 >> 8),iVar2 < 10);
}

