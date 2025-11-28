// Function: FUN_000113d0
// Address: 000113d0
// Decompiled by Ghidra


ulonglong FUN_000113d0(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  undefined4 *puVar3;
  uint uVar4;
  longlong lVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  longlong lVar8;
  
  uVar4 = (*(uint *)(param_1 + 4) - (*(uint *)(param_1 + 4) & 0xfff)) - DAT_00014000;
  uVar1 = -(DAT_00014058 + DAT_0001405c);
  uVar2 = (ulonglong)uVar1;
  if (DAT_00014060 == '\0') {
    if (uVar1 <= uVar4) goto LAB_00011414;
  }
  else if ((uVar1 <= uVar4) &&
          (uVar2 = (ulonglong)(-DAT_0001405c - 1U), uVar4 <= -DAT_0001405c - 1U)) goto LAB_00011414;
  puVar6 = (undefined1 *)(param_1 + 8);
  puVar7 = (undefined1 *)((ulonglong)(*(ushort *)(param_1 + 4) & 0xfff) + DAT_00014028);
  for (uVar2 = (ulonglong)*(ushort *)(param_1 + 2); uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  uVar1 = (uint)*(ushort *)(param_1 + 2) + *(int *)(param_1 + 4) & 0xfff;
  uVar2 = (ulonglong)uVar1;
  if (uVar1 == 0) {
    uVar2 = DAT_00014040;
    if (DAT_00014040 != 0) {
      puVar3 = (undefined4 *)(DAT_00014050 + DAT_00014040);
      *puVar3 = DAT_00014038;
      puVar3[1] = uVar4;
      puVar3[2] = 0x1000;
      lVar5 = 0;
      puVar3[3] = 0;
      lVar8 = 0x400;
      do {
        puVar3[3] = puVar3[3] + *(int *)(lVar5 + DAT_00014028);
        lVar5 = lVar5 + 4;
        lVar8 = lVar8 + -1;
      } while (lVar8 != 0);
      uVar1 = puVar3[3];
      puVar3[3] = ~uVar1;
      uVar2 = CONCAT62((uint6)(ushort)(~uVar1 >> 0x10),0x23);
      out(DAT_0001404c,0x23);
      if (*(char *)(puVar3 + 4) == '\0') goto LAB_00011414;
    }
    return uVar2 & 0xffffffffffffff00;
  }
LAB_00011414:
  return CONCAT71((int7)(uVar2 >> 8),1);
}

