// Function: FUN_14000161c
// Address: 14000161c
// Decompiled by Ghidra


undefined8 FUN_14000161c(longlong param_1,longlong param_2)

{
  byte bVar1;
  
  if (*(int *)(param_2 + 0x10) == 0) {
    return 0xc000000d;
  }
  bVar1 = **(byte **)(param_1 + 0x18);
  FUN_140002990(0);
  FUN_1400029f0(0);
  FUN_140002960((uint)bVar1);
  if (bVar1 == 1) {
    *(undefined8 *)(param_1 + 0x38) = 1;
  }
  else {
    if (bVar1 != 3) {
      *(undefined8 *)(param_1 + 0x38) = 0;
      FUN_140001128();
      return 0;
    }
    *(undefined8 *)(param_1 + 0x38) = 3;
  }
  FUN_140001088();
  return 0;
}

