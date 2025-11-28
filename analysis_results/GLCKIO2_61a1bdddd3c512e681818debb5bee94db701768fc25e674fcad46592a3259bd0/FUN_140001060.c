// Function: FUN_140001060
// Address: 140001060
// Decompiled by Ghidra


void FUN_140001060(byte *param_1,longlong param_2)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte bVar4;
  longlong lVar5;
  longlong lVar6;
  
  FUN_140001018(10,param_1,param_2);
  bVar4 = 9;
  do {
    bVar1 = param_1[0xd];
    lVar6 = 4;
    param_1[0xd] = param_1[9];
    param_1[9] = param_1[5];
    param_1[5] = param_1[1];
    param_1[1] = bVar1;
    bVar1 = param_1[2];
    param_1[2] = param_1[10];
    param_1[10] = bVar1;
    bVar1 = param_1[6];
    param_1[6] = param_1[0xe];
    param_1[0xe] = bVar1;
    bVar1 = param_1[3];
    param_1[3] = param_1[7];
    param_1[7] = param_1[0xb];
    param_1[0xb] = param_1[0xf];
    param_1[0xf] = bVar1;
    pbVar3 = param_1;
    do {
      lVar5 = 4;
      pbVar2 = pbVar3;
      do {
        *pbVar2 = (&DAT_1400031a0)[*pbVar2];
        pbVar2 = pbVar2 + 4;
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
      pbVar3 = pbVar3 + 1;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
    FUN_140001018(bVar4,param_1,param_2);
    FUN_1400011c0((longlong)param_1);
    bVar4 = bVar4 - 1;
  } while (bVar4 != 0);
  bVar4 = param_1[0xd];
  lVar6 = 4;
  param_1[0xd] = param_1[9];
  param_1[9] = param_1[5];
  param_1[5] = param_1[1];
  param_1[1] = bVar4;
  bVar4 = param_1[2];
  param_1[2] = param_1[10];
  param_1[10] = bVar4;
  bVar4 = param_1[6];
  param_1[6] = param_1[0xe];
  param_1[0xe] = bVar4;
  bVar4 = param_1[3];
  param_1[3] = param_1[7];
  param_1[7] = param_1[0xb];
  param_1[0xb] = param_1[0xf];
  param_1[0xf] = bVar4;
  pbVar3 = param_1;
  do {
    lVar5 = 4;
    pbVar2 = pbVar3;
    do {
      *pbVar2 = (&DAT_1400031a0)[*pbVar2];
      pbVar2 = pbVar2 + 4;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
    pbVar3 = pbVar3 + 1;
    lVar6 = lVar6 + -1;
  } while (lVar6 != 0);
  FUN_140001018(0,param_1,param_2);
  return;
}

