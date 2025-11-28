// Function: FUN_140001aac
// Address: 140001aac
// Decompiled by Ghidra


bool FUN_140001aac(longlong param_1)

{
  char cVar1;
  bool bVar2;
  
  bVar2 = false;
  cVar1 = MmIsAddressValid();
  if (cVar1 != '\0') {
    cVar1 = MmIsAddressValid(*(undefined8 *)(param_1 + 8));
    bVar2 = cVar1 != '\0';
  }
  return bVar2;
}

