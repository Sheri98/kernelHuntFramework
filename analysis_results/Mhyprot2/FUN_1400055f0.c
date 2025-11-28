// Function: FUN_1400055f0
// Address: 1400055f0
// Decompiled by Ghidra


undefined1 FUN_1400055f0(undefined8 *param_1,longlong param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  char cVar3;
  
  puVar1 = (undefined8 *)*param_1;
  while( true ) {
    if (puVar1 == param_1) {
      return 0;
    }
    cVar3 = MmIsAddressValid(puVar1);
    if (cVar3 == '\0') {
      return 0;
    }
    cVar3 = MmIsAddressValid(puVar1);
    if (cVar3 == '\0') {
      return 0;
    }
    lVar2 = puVar1[2];
    cVar3 = MmIsAddressValid(lVar2);
    if (cVar3 == '\0') break;
    if (*(longlong *)(lVar2 + 0x210) == param_2) {
      return 1;
    }
    puVar1 = (undefined8 *)*puVar1;
  }
  return 0;
}

