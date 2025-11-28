// Function: FUN_140004904
// Address: 140004904
// Decompiled by Ghidra


undefined8 FUN_140004904(void)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  char *pcVar3;
  char cVar4;
  char *pcVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  uint uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  
  uVar6 = 0;
  pcVar5 = DAT_14000a668;
  uVar9 = uVar6;
  uVar10 = uVar6;
  if ((DAT_14000a668 != (char *)0x0) ||
     (pcVar5 = FUN_140006d94(), DAT_14000a668 = pcVar5, pcVar5 != (char *)0x0)) {
    do {
      puVar1 = (ulonglong *)(pcVar5 + uVar10);
      pcVar3 = pcVar5;
      if (((puVar1 != (ulonglong *)0x0) &&
          (((cVar4 = MmIsAddressValid(puVar1), pcVar3 = DAT_14000a668, cVar4 != '\0' &&
            (uVar2 = *puVar1, uVar2 != 0)) &&
           (pcVar5 = (char *)MmIsAddressValid(uVar2), pcVar3 = DAT_14000a668, (char)pcVar5 != '\0'))
          )) && (uVar7 = uVar6, *(code **)((uVar2 & 0xfffffffffffffff0) + 8) == FUN_140004600))
      goto LAB_1400049b3;
      pcVar5 = pcVar3;
      uVar8 = (int)uVar9 + 1;
      uVar9 = (ulonglong)uVar8;
      uVar10 = uVar10 + 8;
    } while (uVar8 < 0x40);
LAB_140004993:
    return (ulonglong)pcVar5 & 0xffffffffffffff00;
  }
LAB_1400049ce:
  return CONCAT71((int7)((ulonglong)pcVar5 >> 8),1);
  while( true ) {
    uVar8 = (int)uVar7 + 1;
    uVar6 = uVar6 + 4;
    uVar7 = (ulonglong)uVar8;
    if (7 < uVar8) break;
LAB_1400049b3:
    if (*(int *)((longlong)&DAT_14000a618 + uVar6) != *(int *)(FUN_140004600 + uVar6))
    goto LAB_140004993;
  }
  goto LAB_1400049ce;
}

