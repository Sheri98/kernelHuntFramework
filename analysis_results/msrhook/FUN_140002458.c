// Function: FUN_140002458
// Address: 140002458
// Decompiled by Ghidra


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140002458(undefined2 *param_1,undefined8 param_2)

{
  short sVar1;
  ushort uVar2;
  undefined1 uVar3;
  undefined8 uVar4;
  undefined7 uVar5;
  short sVar6;
  short sVar7;
  char cVar8;
  
  uVar5 = (undefined7)((ulonglong)param_2 >> 8);
  sVar1 = param_1[1];
  uVar2 = param_1[2];
  sVar6 = 0xb;
  cVar8 = '\0';
  sVar7 = 3;
  if ((DAT_1400050e7 != '\0') && (sVar1 == 0x45)) {
    return 1;
  }
  if (DAT_14000510c == 0) {
    uVar4 = FUN_14000275c(sVar1,uVar2);
    return uVar4;
  }
  if ((DAT_14000510c - 1U & 0xfffffffd) != 0) {
    return 0;
  }
  if (DAT_1400050e7 != '\0') {
    if (DAT_1400050e4 != 0x1ff) {
      return 0;
    }
    uVar3 = KeAcquireSpinLockRaiseToDpc(&DAT_1400061a8);
    DAT_1400050e4 = 0;
    KeReleaseSpinLock(&DAT_1400061a8,CONCAT71(uVar5,uVar3));
    return 0;
  }
  if (DAT_140005108 == 0) {
LAB_140002557:
    if (DAT_14000510c == 3) {
      sVar6 = 7;
      sVar7 = 0xb;
    }
    if ((sVar1 == sVar6) && (cVar8 = uVar2 == 0, uVar2 == 1)) {
      cVar8 = '\x02';
    }
    if (sVar1 == sVar7) {
      if (uVar2 == 0) {
        cVar8 = '\x03';
      }
      if (uVar2 == 1) {
        cVar8 = '\x04';
      }
    }
    if (cVar8 == '\x01') {
      DAT_1400050f8 = *(int *)(&DAT_140005080 + (longlong)DAT_1400050f8 * 4);
    }
    else if (cVar8 == '\x02') {
      DAT_1400050f8 = *(int *)(&DAT_140005090 + (longlong)DAT_1400050f8 * 4);
    }
    else if (cVar8 == '\x03') {
      DAT_1400050f8 = *(int *)(&DAT_1400050a0 + (longlong)DAT_1400050f8 * 4);
    }
    else if (cVar8 == '\x04') {
      DAT_1400050f8 = *(int *)(&DAT_1400050b0 + (longlong)DAT_1400050f8 * 4);
    }
    else {
      DAT_1400050f8 = 0;
    }
    if (DAT_140005108 == 0) {
      if (DAT_1400050f8 != 0) {
        if (DAT_1400050f8 == 4) {
          DAT_140005108 = 1;
        }
        else if (DAT_1400050f8 == 2) {
          FUN_1400029f0(1);
        }
        goto LAB_140002535;
      }
    }
    else {
      if (0x1ff < DAT_1400050fc + 1) {
        FUN_1400029f0(0);
        uVar3 = KeAcquireSpinLockRaiseToDpc(&DAT_1400061a8);
        DAT_1400050fc = 0;
        KeReleaseSpinLock(&DAT_1400061a8,uVar3);
        DAT_140005108 = 0;
        return 0;
      }
      FUN_140001024(param_1,DAT_1400050e6);
      param_1[1] = 0;
      if (DAT_140005108 == 10) {
        if ((sVar1 == 9) && (uVar2 == 0)) {
          return 0;
        }
      }
      else {
        if (DAT_140005108 != 0xb) {
          if (DAT_140005108 != 0xc) {
            return 0;
          }
LAB_1400026e1:
          FUN_1400029f0(0);
          FUN_140002a20('\0');
          FUN_140002930(1);
          _DAT_1400061a0 = FUN_140001bb4();
          return 1;
        }
        if ((sVar1 == 9) && (uVar2 == 1)) {
          DAT_140005108 = 0xc;
          goto LAB_1400026e1;
        }
      }
      DAT_140005108 = 0;
    }
    FUN_1400029f0(0);
    FUN_140002a20('\x01');
  }
  else {
    if (sVar1 != 0x2a) {
      DAT_140005108 = DAT_140005108 + 1;
      goto LAB_140002557;
    }
LAB_140002535:
    FUN_140001024(param_1,DAT_1400050e6);
    param_1[1] = 0;
  }
  return 0;
}

