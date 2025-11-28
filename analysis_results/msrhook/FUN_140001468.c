// Function: FUN_140001468
// Address: 140001468
// Decompiled by Ghidra


undefined8 FUN_140001468(longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  
  uVar3 = 0;
  uVar2 = KeAcquireSpinLockRaiseToDpc(&DAT_1400061a8);
  if (DAT_1400050e4 == 0) {
    KeReleaseSpinLock(&DAT_1400061a8,uVar2);
    *(undefined8 *)(param_1 + 0x38) = 0;
    uVar3 = 0;
  }
  else {
    if ((uint)DAT_1400050e4 << 3 < *(uint *)(param_2 + 8)) {
      uVar1 = (ulonglong)DAT_1400050e4;
      FUN_140002e00(*(undefined8 **)(param_1 + 0x18),(undefined8 *)&DAT_1400065c0,
                    (ulonglong)DAT_1400050e4 << 3);
      *(ulonglong *)(param_1 + 0x38) = uVar1 << 3;
      DAT_1400050e4 = 0;
    }
    else {
      uVar3 = 0xc0000023;
    }
    KeReleaseSpinLock(&DAT_1400061a8,uVar2);
  }
  return uVar3;
}

