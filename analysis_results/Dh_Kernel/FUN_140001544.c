// Function: FUN_140001544
// Address: 140001544
// Decompiled by Ghidra


undefined8 FUN_140001544(char *param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  
  if ((param_2 != 0) && (lVar1 = *(longlong *)(param_2 + 8), lVar2 = lVar1, lVar1 != 0)) {
    while (param_2 != lVar2) {
      iVar3 = _stricmp((char *)(lVar2 + 0x10),param_1);
      if (iVar3 == 0) {
        return 1;
      }
      lVar2 = *(longlong *)(lVar2 + 8);
      if (lVar2 == 0) {
        return 0;
      }
      if (lVar2 == lVar1) {
        return 0;
      }
    }
  }
  return 0;
}

