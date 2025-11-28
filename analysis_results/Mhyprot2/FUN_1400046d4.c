// Function: FUN_1400046d4
// Address: 1400046d4
// Decompiled by Ghidra


undefined8 FUN_1400046d4(void)

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
  pcVar5 = DAT_14000a658;
  uVar9 = uVar6;
  uVar10 = uVar6;
  if ((DAT_14000a658 != (char *)0x0) ||
     (pcVar5 = FUN_140006cb8(), DAT_14000a658 = pcVar5, pcVar5 != (char *)0x0)) {
    do {
      puVar1 = (ulonglong *)(pcVar5 + uVar10);
      pcVar3 = pcVar5;
      if (((puVar1 != (ulonglong *)0x0) &&
          (((cVar4 = MmIsAddressValid(puVar1), pcVar3 = DAT_14000a658, cVar4 != '\0' &&
            (uVar2 = *puVar1, uVar2 != 0)) &&
           (pcVar5 = (char *)MmIsAddressValid(uVar2), pcVar3 = DAT_14000a658, (char)pcVar5 != '\0'))
          )) && (uVar7 = uVar6, *(code **)((uVar2 & 0xfffffffffffffff0) + 8) == FUN_140004480))
      goto LAB_140004783;
      pcVar5 = pcVar3;
      uVar8 = (int)uVar9 + 1;
      uVar9 = (ulonglong)uVar8;
      uVar10 = uVar10 + 8;
    } while (uVar8 < 0x40);
LAB_140004763:
    return (ulonglong)pcVar5 & 0xffffffffffffff00;
  }
LAB_14000479e:
  return CONCAT71((int7)((ulonglong)pcVar5 >> 8),1);
  while( true ) {
    uVar8 = (int)uVar7 + 1;
    uVar6 = uVar6 + 4;
    uVar7 = (ulonglong)uVar8;
    if (7 < uVar8) break;
LAB_140004783:
    if (*(int *)((longlong)&DAT_14000a5f8 + uVar6) != *(int *)(FUN_140004480 + uVar6))
    goto LAB_140004763;
  }
  goto LAB_14000479e;
}

