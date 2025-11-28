// Function: FUN_140005954
// Address: 140005954
// Decompiled by Ghidra


longlong FUN_140005954(void)

{
  char cVar1;
  longlong *plVar2;
  longlong lVar3;
  
  plVar2 = (longlong *)FUN_140005998();
  if ((((plVar2 == (longlong *)0x0) || (cVar1 = MmIsAddressValid(plVar2), cVar1 == '\0')) ||
      (lVar3 = *plVar2, lVar3 == 0)) || (cVar1 = MmIsAddressValid(lVar3), cVar1 == '\0')) {
    lVar3 = 0;
  }
  return lVar3;
}

