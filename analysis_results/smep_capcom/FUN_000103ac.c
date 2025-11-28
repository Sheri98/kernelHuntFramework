// Function: FUN_000103ac
// Address: 000103ac
// Decompiled by Ghidra


short * FUN_000103ac(short *param_1,short *param_2)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  longlong lVar4;
  ushort *puVar5;
  char cVar6;
  short *psVar7;
  short *psVar8;
  byte bVar9;
  ushort local_48 [32];
  
  puVar5 = local_48;
  lVar4 = (longlong)local_48 - (longlong)param_2;
  do {
    sVar1 = *param_2;
    *(short *)(lVar4 + (longlong)param_2) = sVar1;
    param_2 = param_2 + 1;
  } while (sVar1 != 0);
  cVar6 = '\0';
  bVar9 = 0x55;
  while (local_48[0] != 0) {
    bVar9 = bVar9 * '\x04' + cVar6;
    uVar3 = *puVar5 >> 6;
    if (2 < uVar3 - 1) break;
    uVar2 = 0;
    uVar3 = (byte)((((byte)*puVar5 ^ bVar9) - cVar6) - (char)uVar3) & 0x3f;
    if (uVar3 < 10) {
      uVar2 = uVar3 + 0x30;
LAB_0001041d:
      if (0x23 < uVar3) goto LAB_00010423;
    }
    else {
      if (uVar3 < 0x24) {
        uVar2 = uVar3 + 0x37;
        goto LAB_0001041d;
      }
LAB_00010423:
      if (uVar3 < 0x3e) {
        uVar2 = uVar3 + 0x3d;
      }
    }
    if (uVar3 == 0x3e) {
      uVar2 = 0x2e;
    }
    if (uVar2 == 0) break;
    *puVar5 = uVar2;
    puVar5 = puVar5 + 1;
    cVar6 = cVar6 + '\x01';
    local_48[0] = *puVar5;
  }
  lVar4 = 0;
  psVar7 = param_1;
  do {
    lVar4 = lVar4 + -1;
    psVar8 = psVar7;
    if (lVar4 == 0) break;
    psVar8 = psVar7 + 1;
    sVar1 = *psVar7;
    psVar7 = psVar8;
  } while (sVar1 != 0);
  lVar4 = 0;
  do {
    sVar1 = *(short *)((longlong)local_48 + lVar4);
    *(short *)((longlong)psVar8 + lVar4 + -2) = sVar1;
    lVar4 = lVar4 + 2;
  } while (sVar1 != 0);
  return param_1;
}

