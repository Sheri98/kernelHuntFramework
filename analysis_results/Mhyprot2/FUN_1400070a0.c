// Function: FUN_1400070a0
// Address: 1400070a0
// Decompiled by Ghidra


undefined4 FUN_1400070a0(void)

{
  undefined1 uVar1;
  
  uVar1 = 0;
  FUN_140007338();
  if ((DAT_14000a748 - 0x3dU < 3) || (DAT_14000a748 == 100)) {
    uVar1 = 1;
  }
  return CONCAT31((int3)(DAT_14000a748 - 0x3dU >> 8),uVar1);
}

