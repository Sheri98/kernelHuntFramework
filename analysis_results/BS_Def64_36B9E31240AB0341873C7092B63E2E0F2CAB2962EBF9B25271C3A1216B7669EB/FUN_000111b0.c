// Function: FUN_000111b0
// Address: 000111b0
// Decompiled by Ghidra


ulonglong FUN_000111b0(longlong param_1,longlong param_2)

{
  undefined4 uVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined4 *puVar4;
  ulonglong uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  int iVar8;
  
  uVar1 = DAT_00014038;
  iVar8 = *(uint *)(param_1 + 4) - DAT_00014000;
  uVar5 = (ulonglong)*(ushort *)(param_1 + 2);
  if ((*(uint *)(param_1 + 4) & 0xfff) == 0) {
    uVar3 = DAT_00014040;
    if (DAT_00014040 != 0) {
      puVar4 = (undefined4 *)(DAT_00014050 + DAT_00014040);
      *puVar4 = DAT_00014038;
      puVar4[1] = iVar8;
      puVar4[2] = 0x1000;
      uVar3 = CONCAT62((uint6)(ushort)((uint)uVar1 >> 0x10),0x21);
      out(DAT_0001404c,0x21);
      if (*(char *)(puVar4 + 4) == '\0') goto LAB_00011216;
    }
    return uVar3 & 0xffffffffffffff00;
  }
LAB_00011216:
  uVar2 = *(ushort *)(param_1 + 4) & 0xfff;
  puVar6 = (undefined1 *)((ulonglong)uVar2 + DAT_00014028);
  puVar7 = (undefined1 *)(param_2 + 8);
  for (; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  return CONCAT71((uint7)(uint3)(uVar2 >> 8),1);
}

