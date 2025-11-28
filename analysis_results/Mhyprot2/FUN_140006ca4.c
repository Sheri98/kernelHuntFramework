// Function: FUN_140006ca4
// Address: 140006ca4
// Decompiled by Ghidra


int FUN_140006ca4(undefined8 *param_1)

{
  int iVar1;
  undefined8 *puVar2;
  
  iVar1 = 0;
  for (puVar2 = (undefined8 *)*param_1; puVar2 != param_1; puVar2 = (undefined8 *)*puVar2) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}

