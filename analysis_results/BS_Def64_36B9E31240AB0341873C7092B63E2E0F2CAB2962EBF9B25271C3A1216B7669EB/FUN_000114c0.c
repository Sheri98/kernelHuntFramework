// Function: FUN_000114c0
// Address: 000114c0
// Decompiled by Ghidra


ulonglong FUN_000114c0(longlong param_1,longlong param_2)

{
  undefined4 uVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined1 *puVar4;
  ulonglong uVar5;
  undefined1 *puVar6;
  int iVar7;
  
  iVar7 = *(uint *)(param_1 + 4) - DAT_00014000;
  uVar5 = (ulonglong)*(ushort *)(param_1 + 2);
  if ((*(uint *)(param_1 + 4) & 0xfff) == 0) {
    uVar3 = DAT_00014040;
    if (DAT_00014040 != 0) {
      puVar4 = (undefined1 *)(DAT_00014050 + DAT_00014040);
      *puVar4 = 1;
      uVar1 = DAT_00014038;
      *(undefined4 *)(puVar4 + 1) = DAT_00014038;
      *(int *)(puVar4 + 5) = iVar7;
      *(undefined4 *)(puVar4 + 9) = 0x1000;
      out(DAT_0001404c,0x7f);
      uVar3 = CONCAT62((uint6)(ushort)((uint)uVar1 >> 0x10),0x7f) & 0xffffffffffffff00;
      out(0xe1,0);
      if (puVar4[0x11] == '\0') goto LAB_00011530;
    }
    return uVar3 & 0xffffffffffffff00;
  }
LAB_00011530:
  uVar2 = *(ushort *)(param_1 + 4) & 0xfff;
  puVar4 = (undefined1 *)((ulonglong)uVar2 + DAT_00014028);
  puVar6 = (undefined1 *)(param_2 + 8);
  for (; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
  }
  return CONCAT71((uint7)(uint3)(uVar2 >> 8),1);
}

