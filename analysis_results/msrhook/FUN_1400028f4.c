// Function: FUN_1400028f4
// Address: 1400028f4
// Decompiled by Ghidra


undefined8 FUN_1400028f4(longlong param_1)

{
  longlong *plVar1;
  int iVar2;
  
  iVar2 = 0;
  plVar1 = &DAT_140005120;
  do {
    if (*plVar1 == 0) {
      plVar1 = (longlong *)(longlong)iVar2;
      (&DAT_140005120)[(longlong)plVar1] = param_1;
      break;
    }
    if (*plVar1 == param_1) break;
    plVar1 = plVar1 + 1;
    iVar2 = iVar2 + 1;
  } while ((longlong)plVar1 < 0x140005170);
  return CONCAT71((int7)((ulonglong)plVar1 >> 8),iVar2 < 10);
}

