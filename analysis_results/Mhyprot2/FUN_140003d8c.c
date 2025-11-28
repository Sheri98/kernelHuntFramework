// Function: FUN_140003d8c
// Address: 140003d8c
// Decompiled by Ghidra


undefined8 FUN_140003d8c(longlong param_1)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  uVar2 = 0;
  if (DAT_14000a708 == 0) {
    uVar2 = 0;
  }
  else {
    cVar1 = MmIsAddressValid();
    if (cVar1 == '\x01') {
      puVar3 = (undefined8 *)(param_1 + DAT_14000a708);
      cVar1 = MmIsAddressValid(puVar3);
      if (cVar1 == '\x01') {
        uVar2 = *puVar3;
      }
    }
  }
  return uVar2;
}

