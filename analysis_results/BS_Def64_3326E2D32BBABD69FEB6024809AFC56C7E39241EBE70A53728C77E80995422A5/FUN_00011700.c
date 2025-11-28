// Function: FUN_00011700
// Address: 00011700
// Decompiled by Ghidra


ulonglong FUN_00011700(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  undefined1 *puVar3;
  longlong lVar4;
  undefined1 *puVar5;
  int iVar6;
  longlong lVar7;
  
  uVar1 = *(uint *)(param_1 + 4) & 0xfff;
  iVar6 = (*(uint *)(param_1 + 4) - uVar1) - DAT_00014000;
  puVar3 = (undefined1 *)(param_1 + 8);
  puVar5 = (undefined1 *)((ulonglong)uVar1 + DAT_00014028);
  for (uVar2 = (ulonglong)*(ushort *)(param_1 + 2); uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  uVar1 = (uint)*(ushort *)(param_1 + 2) + *(int *)(param_1 + 4) & 0xfff;
  uVar2 = (ulonglong)uVar1;
  if (uVar1 == 0) {
    uVar2 = DAT_00014040;
    if (DAT_00014040 != 0) {
      puVar3 = (undefined1 *)(DAT_00014050 + DAT_00014040);
      *puVar3 = 3;
      *(undefined4 *)(puVar3 + 1) = DAT_00014038;
      *(int *)(puVar3 + 5) = iVar6;
      *(undefined4 *)(puVar3 + 9) = 0x1000;
      lVar4 = 0;
      *(undefined4 *)(puVar3 + 0xd) = 0;
      lVar7 = 0x400;
      do {
        *(int *)(puVar3 + 0xd) = *(int *)(puVar3 + 0xd) + *(int *)(lVar4 + DAT_00014028);
        lVar4 = lVar4 + 4;
        lVar7 = lVar7 + -1;
      } while (lVar7 != 0);
      uVar1 = *(uint *)(puVar3 + 0xd);
      *(uint *)(puVar3 + 0xd) = ~uVar1;
      out(DAT_0001404c,0x7f);
      uVar2 = CONCAT62((uint6)(ushort)(~uVar1 >> 0x10),0x7f) & 0xffffffffffffff00;
      out(0xe1,0);
      if (puVar3[0x11] == '\0') goto LAB_000117b3;
    }
    return uVar2 & 0xffffffffffffff00;
  }
LAB_000117b3:
  return CONCAT71((int7)(uVar2 >> 8),1);
}

