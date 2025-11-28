// Function: FUN_140005d58
// Address: 140005d58
// Decompiled by Ghidra


void FUN_140005d58(undefined8 *param_1)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  char cVar4;
  
  puVar3 = (undefined8 *)*param_1;
  while (((puVar3 != param_1 && (cVar4 = MmIsAddressValid(puVar3), cVar4 != '\0')) &&
         (cVar4 = MmIsAddressValid(puVar3), cVar4 != '\0'))) {
    uVar1 = puVar3[2];
    cVar4 = MmIsAddressValid(uVar1);
    if (cVar4 == '\0') {
      return;
    }
    puVar2 = (undefined8 *)*puVar3;
    ExFreePoolWithTag(uVar1,0);
    ExFreePoolWithTag(puVar3);
    puVar3 = puVar2;
  }
  return;
}

