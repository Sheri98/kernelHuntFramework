// Function: FUN_140001bf4
// Address: 140001bf4
// Decompiled by Ghidra


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140001bf4(longlong param_1)

{
  longlong lVar1;
  undefined1 auVar2 [16];
  char cVar3;
  undefined1 uVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  short *psVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  
  if (DAT_1400050ec != 1) {
    lVar1 = *(longlong *)(param_1 + 0x18);
    uVar11 = CONCAT44(0,*(uint *)(param_1 + 0x38));
    auVar2._8_8_ = 0;
    auVar2._0_8_ = uVar11;
    uVar7 = SUB168(ZEXT816(0xaaaaaaaaaaaaaaab) * auVar2,8);
    uVar11 = uVar11 / 0xc;
    lVar5 = FUN_140001bb4();
    uVar10 = 0;
    if (800 < lVar5 - _DAT_1400061a0) {
      FUN_140002930(0);
      DAT_1400050f4 = 0;
      DAT_1400050f8 = 0;
      DAT_1400050e4 = 0;
      DAT_1400050fc = 0;
      DAT_140005108 = 0;
      DAT_140005110 = 0;
      DAT_140005114 = 0;
    }
    _DAT_1400061a0 = FUN_140001bb4();
    if (uVar11 != 0) {
      psVar9 = (short *)(lVar1 + 2);
      do {
        if (DAT_1400050ec == 1) {
LAB_140001dae:
          FUN_140002930(0);
          DAT_1400050e4 = 0;
          DAT_1400050f4 = 0;
          DAT_1400050f8 = 0;
          DAT_1400050fc = 0;
          DAT_140005108 = 0;
          DAT_140005110 = 0;
          DAT_140005114 = 0;
          return;
        }
        uVar4 = KeAcquireSpinLockRaiseToDpc(&DAT_1400061a8);
        uVar7 = CONCAT71((int7)((ulonglong)uVar7 >> 8),uVar4);
        KeReleaseSpinLock();
        if ((*psVar9 == 0x3a) && (psVar9[1] == 0)) {
          DAT_1400050e6 = DAT_1400050e6 == '\0';
        }
        else {
          uVar6 = FUN_140002458(psVar9 + -1,uVar7);
          if ((int)uVar6 == 0) {
            if (DAT_1400050ec == 1) goto LAB_140001dae;
            if (DAT_1400050e7 != '\0') {
              uVar4 = KeAcquireSpinLockRaiseToDpc(&DAT_1400061a8);
              cVar3 = DAT_1400050e6;
              uVar8 = (ulonglong)(uint)DAT_1400050e4;
              if (DAT_1400050e4 + 1 < 0x200) {
                uVar8 = (ulonglong)DAT_1400050e4;
                *(short *)(&DAT_1400065c0 + uVar8 * 8) = psVar9[-1];
                (&DAT_1400065c2)[(ulonglong)DAT_1400050e4 * 4] = *psVar9;
                (&DAT_1400065c4)[(ulonglong)DAT_1400050e4 * 4] = psVar9[1];
                (&DAT_1400065c6)[(ulonglong)DAT_1400050e4 * 8] = cVar3;
                DAT_1400050e4 = DAT_1400050e4 + 1;
              }
              uVar7 = CONCAT71((int7)(uVar8 >> 8),uVar4);
              KeReleaseSpinLock(&DAT_1400061a8,uVar7);
              *psVar9 = 0;
            }
          }
        }
        uVar10 = uVar10 + 1;
        psVar9 = psVar9 + 6;
      } while (uVar10 < uVar11);
    }
  }
  return;
}

