// Function: FUN_140002a20
// Address: 140002a20
// Decompiled by Ghidra


void FUN_140002a20(char param_1)

{
  undefined1 uVar1;
  byte bVar2;
  ulonglong uVar3;
  ushort uVar4;
  uint uVar5;
  ushort uVar6;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(&DAT_1400061a8);
  uVar6 = DAT_1400050fc;
  uVar4 = DAT_1400050e4;
  if (DAT_1400050fc != 0) {
    uVar5 = (uint)DAT_1400050e4;
    if (DAT_1400050fc + uVar5 < 0x201) {
      FUN_140002e00((undefined8 *)(&DAT_1400065c0 + (byte)((char)DAT_1400050e4 << 3)),
                    (undefined8 *)&DAT_1400051a0,(ulonglong)(byte)((char)DAT_1400050fc << 3));
      if ((param_1 != '\0') && (uVar3 = 0, uVar6 != 0)) {
        do {
          bVar2 = (char)uVar3 + 1;
          (&DAT_1400065c6)[(uVar5 + uVar3) * 8] = (&DAT_1400065c6)[(uVar5 + uVar3) * 8] + 'd';
          uVar5 = (uint)DAT_1400050e4;
          uVar3 = (ulonglong)bVar2;
          uVar4 = DAT_1400050e4;
          uVar6 = DAT_1400050fc;
        } while (bVar2 < DAT_1400050fc);
      }
      DAT_1400050e4 = uVar4 + uVar6;
      DAT_1400050fc = 0;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x000140002b07. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  KeReleaseSpinLock(&DAT_1400061a8,uVar1);
  return;
}

