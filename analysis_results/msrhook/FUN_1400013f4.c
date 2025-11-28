// Function: FUN_1400013f4
// Address: 1400013f4
// Decompiled by Ghidra


undefined8 FUN_1400013f4(longlong param_1,longlong param_2)

{
  undefined2 uVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  
  uVar3 = 0;
  uVar2 = KeAcquireSpinLockRaiseToDpc(&DAT_1400061a8);
  uVar1 = DAT_1400050e4;
  KeReleaseSpinLock(&DAT_1400061a8,uVar2);
  if (*(uint *)(param_2 + 8) < 2) {
    uVar3 = 0xc0000023;
  }
  else {
    **(undefined2 **)(param_1 + 0x18) = uVar1;
    *(undefined8 *)(param_1 + 0x38) = 2;
  }
  return uVar3;
}

