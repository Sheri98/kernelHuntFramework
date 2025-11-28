// Function: FUN_140002868
// Address: 140002868
// Decompiled by Ghidra


undefined8 FUN_140002868(longlong param_1)

{
  longlong *plVar1;
  int iVar2;
  
  iVar2 = 0;
  plVar1 = &DAT_140005120;
  do {
    if (*plVar1 == param_1) {
      plVar1 = (longlong *)(longlong)iVar2;
      (&DAT_140005120)[(longlong)plVar1] = 0;
      break;
    }
    plVar1 = plVar1 + 1;
    iVar2 = iVar2 + 1;
  } while ((longlong)plVar1 < 0x140005170);
  return CONCAT71((int7)((ulonglong)plVar1 >> 8),iVar2 < 10);
}

