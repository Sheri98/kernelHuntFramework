// Function: FUN_140004df0
// Address: 140004df0
// Decompiled by Ghidra


ulonglong FUN_140004df0(short *param_1,char param_2)

{
  ushort uVar1;
  longlong *plVar2;
  short *psVar3;
  undefined4 uVar4;
  code *pcVar5;
  undefined4 extraout_var;
  ushort uVar6;
  longlong *plVar8;
  bool bVar9;
  ulonglong uVar7;
  
  pcVar5 = (code *)MmIsAddressValid();
  if ((((char)pcVar5 != '\0') &&
      (pcVar5 = (code *)MmIsAddressValid(param_1 + 0x10), (char)pcVar5 != '\0')) &&
     (pcVar5 = (code *)MmIsAddressValid(*(undefined8 *)(param_1 + 0x1c)), (char)pcVar5 != '\0')) {
    plVar2 = *(longlong **)(param_1 + 0x10);
    plVar8 = plVar2;
    do {
      psVar3 = (short *)plVar8[3];
      pcVar5 = (code *)MmIsAddressValid(psVar3);
      if ((((char)pcVar5 != '\0') &&
          (pcVar5 = (code *)ObGetFilterVersion(), *psVar3 == (short)pcVar5)) &&
         ((uVar1 = psVar3[1], uVar1 != 0 && (param_1 == psVar3)))) {
        uVar7 = 0;
        bVar9 = uVar1 != 0;
        goto LAB_140004e94;
      }
      plVar8 = (longlong *)*plVar8;
    } while (plVar8 != plVar2);
  }
LAB_140004e71:
  return (ulonglong)pcVar5 & 0xffffffffffffff00;
LAB_140004e94:
  if (!bVar9) goto LAB_140004e71;
  if (param_2 == '\0') {
    pcVar5 = FUN_140004fb0;
    if (*(code **)(psVar3 + uVar7 * 0x20 + 0x24) == FUN_140004fb0) {
      param_2 = '\0';
LAB_140004eb5:
      uVar4 = FUN_140004f44(param_2);
      return CONCAT71((int7)(CONCAT44(extraout_var,uVar4) >> 8),(char)uVar4) ^ 1;
    }
  }
  else {
    pcVar5 = FUN_1400050d0;
    if (*(code **)(psVar3 + uVar7 * 0x20 + 0x24) == FUN_1400050d0) goto LAB_140004eb5;
  }
  uVar6 = (short)uVar7 + 1;
  uVar7 = (ulonglong)uVar6;
  bVar9 = uVar6 < uVar1;
  goto LAB_140004e94;
}

