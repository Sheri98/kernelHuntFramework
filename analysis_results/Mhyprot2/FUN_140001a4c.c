// Function: FUN_140001a4c
// Address: 140001a4c
// Decompiled by Ghidra


undefined1 FUN_140001a4c(undefined8 *param_1,longlong param_2)

{
  undefined8 *puVar1;
  char cVar2;
  
  puVar1 = (undefined8 *)*param_1;
  while( true ) {
    if (puVar1 == param_1) {
      return 0;
    }
    cVar2 = MmIsAddressValid(puVar1);
    if (cVar2 == '\0') break;
    if (puVar1[2] == param_2) {
      return 1;
    }
    puVar1 = (undefined8 *)*puVar1;
  }
  return 0;
}

