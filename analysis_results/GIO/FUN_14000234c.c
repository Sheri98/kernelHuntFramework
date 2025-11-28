// Function: FUN_14000234c
// Address: 14000234c
// Decompiled by Ghidra


undefined8 FUN_14000234c(undefined8 param_1,longlong param_2,longlong param_3)

{
  int *piVar1;
  undefined8 uVar2;
  
  piVar1 = *(int **)(param_2 + 0x18);
  if ((*(int *)(param_3 + 0x10) == *(int *)(param_3 + 8)) && (*(int *)(param_3 + 8) == 0x10)) {
    *(undefined8 *)(param_2 + 0x38) = 0;
    DAT_140005044 = piVar1[1];
    DAT_14000503c = 0;
    DAT_140005040 = 0;
    if (*piVar1 == 0) {
      DAT_140005040 = piVar1[2];
      DAT_14000503c = piVar1[3];
      FUN_1400010e3();
    }
    else {
      if (*piVar1 != 1) goto LAB_1400023ce;
      FUN_1400010c6();
      piVar1[2] = DAT_140005040;
      piVar1[3] = DAT_14000503c;
    }
    *(undefined8 *)(param_2 + 0x38) = 0x10;
    uVar2 = 0;
  }
  else {
LAB_1400023ce:
    uVar2 = 0xc000000d;
  }
  return uVar2;
}

