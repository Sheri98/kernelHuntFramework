// Function: thunk_FUN_14000145c
// Address: 140001010
// Decompiled by Ghidra


void thunk_FUN_14000145c(longlong param_1,longlong param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  uint uVar9;
  ulonglong uVar10;
  byte bVar11;
  
  uVar5 = 4;
  uVar9 = 0;
  do {
    uVar4 = uVar9 + 1;
    uVar9 = uVar9 * 4;
    *(undefined1 *)((ulonglong)uVar9 + param_1) = *(undefined1 *)((ulonglong)uVar9 + param_2);
    *(undefined1 *)((ulonglong)(uVar9 + 1) + param_1) =
         *(undefined1 *)((ulonglong)(uVar9 + 1) + param_2);
    *(undefined1 *)((ulonglong)(uVar9 + 2) + param_1) =
         *(undefined1 *)((ulonglong)(uVar9 + 2) + param_2);
    *(undefined1 *)((ulonglong)(uVar9 + 3) + param_1) =
         *(undefined1 *)((ulonglong)(uVar9 + 3) + param_2);
    uVar10 = uVar5;
    uVar9 = uVar4;
  } while (uVar4 < 4);
  do {
    iVar3 = (int)uVar10;
    iVar2 = iVar3 * 4;
    bVar8 = *(byte *)((ulonglong)(iVar2 - 4) + param_1);
    bVar1 = *(byte *)((ulonglong)(iVar2 - 3) + param_1);
    bVar7 = *(byte *)((ulonglong)(iVar2 - 2) + param_1);
    bVar6 = *(byte *)((ulonglong)(iVar2 - 1) + param_1);
    bVar11 = bVar1;
    if ((uVar10 & 3) == 0) {
      bVar11 = (&UNK_1400030a0)[bVar7];
      bVar7 = (&UNK_1400030a0)[bVar6];
      bVar6 = (&UNK_1400030a0)[bVar8];
      bVar8 = (&UNK_1400032a0)[uVar5 >> 2] ^ (&UNK_1400030a0)[bVar1];
    }
    iVar2 = iVar3 * 4;
    uVar9 = iVar3 * 4;
    uVar5 = uVar5 + 1;
    *(byte *)((ulonglong)uVar9 + param_1) = *(byte *)((ulonglong)(iVar2 - 0x10) + param_1) ^ bVar8;
    *(byte *)((ulonglong)(uVar9 + 1) + param_1) =
         *(byte *)((ulonglong)(iVar2 - 0xf) + param_1) ^ bVar11;
    *(byte *)((ulonglong)(uVar9 + 2) + param_1) =
         *(byte *)((ulonglong)(iVar2 - 0xe) + param_1) ^ bVar7;
    *(byte *)((ulonglong)(uVar9 + 3) + param_1) =
         *(byte *)((ulonglong)(iVar2 - 0xd) + param_1) ^ bVar6;
    uVar10 = (ulonglong)(iVar3 + 1U);
  } while (iVar3 + 1U < 0x2c);
  return;
}

