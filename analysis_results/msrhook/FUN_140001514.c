// Function: FUN_140001514
// Address: 140001514
// Decompiled by Ghidra


undefined8 FUN_140001514(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (*(uint *)(param_2 + 8) < 2) {
    uVar1 = 0xc0000023;
  }
  else {
    **(undefined2 **)(param_1 + 0x18) = DAT_1400050f0;
    *(undefined8 *)(param_1 + 0x38) = 2;
  }
  return uVar1;
}

