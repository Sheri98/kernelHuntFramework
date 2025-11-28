// Function: FUN_140002e2c
// Address: 140002e2c
// Decompiled by Ghidra


uint FUN_140002e2c(short *param_1,short *param_2)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  longlong lVar4;
  
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  uVar2 = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  if (param_2 != (short *)0x0) {
    lVar4 = 0x7fff;
    psVar3 = param_2;
    do {
      if (*psVar3 == 0) break;
      psVar3 = psVar3 + 1;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    uVar2 = ~-(uint)(lVar4 != 0) & 0xc000000d;
    if (lVar4 != 0) {
      if (param_1 == (short *)0x0) {
        uVar2 = 0xc000000d;
      }
      else {
        sVar1 = (0x7fff - (short)lVar4) * 2;
        *(short **)(param_1 + 4) = param_2;
        *param_1 = sVar1;
        param_1[1] = sVar1 + 2;
      }
    }
  }
  return uVar2;
}

