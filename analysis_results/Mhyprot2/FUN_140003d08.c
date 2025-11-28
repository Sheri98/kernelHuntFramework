// Function: FUN_140003d08
// Address: 140003d08
// Decompiled by Ghidra


undefined8 FUN_140003d08(longlong param_1)

{
  char cVar1;
  undefined8 *puVar2;
  
  cVar1 = MmIsAddressValid();
  if ((cVar1 != '\0') && (DAT_14000a700 != 0)) {
    puVar2 = (undefined8 *)(param_1 + DAT_14000a700);
    cVar1 = MmIsAddressValid(puVar2);
    if (cVar1 != '\0') {
      return *puVar2;
    }
  }
  return 0;
}

