// Function: FUN_140001768
// Address: 140001768
// Decompiled by Ghidra


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140001768(longlong param_1)

{
  longlong lVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)(param_1 + 0x70);
  for (lVar1 = 0x1b; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = FUN_14000213c;
    puVar2 = puVar2 + 1;
  }
  *(code **)(param_1 + 0xe0) = FUN_1400019e4;
  *(code **)(param_1 + 0x100) = FUN_1400019e4;
  *(code **)(param_1 + 0x80) = FUN_1400019e4;
  *(code **)(param_1 + 0x70) = FUN_1400019e4;
  _DAT_1400075e8 = 0;
  _DAT_1400075f0 = 0;
  _DAT_1400075e0 = 1;
  KeInitializeEvent(&DAT_1400075f8,1,0);
  KeInitializeSpinLock(&DAT_1400061a8);
  KeInitializeSpinLock(&DAT_140005188);
  KeInitializeSpinLock(&DAT_140005180);
  KeInitializeSpinLock(&DAT_140005178);
  *(code **)(param_1 + 0x88) = FUN_140002188;
  *(code **)(param_1 + 0x120) = FUN_140002354;
  *(code **)(param_1 + 0x148) = FUN_140002234;
  *(code **)(param_1 + 0x68) = FUN_1400023f8;
  FUN_140001e04(param_1);
  return;
}

