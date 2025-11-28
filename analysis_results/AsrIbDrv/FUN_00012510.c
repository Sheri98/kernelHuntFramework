// Function: FUN_00012510
// Address: 00012510
// Decompiled by Ghidra


void FUN_00012510(ulonglong *param_1,ulonglong param_2,ulonglong param_3)

{
  uint uVar1;
  ulonglong *puVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  uVar3 = param_3;
  if (7 < param_3) {
    param_2 = (param_2 & 0xff) * 0x101010101010101;
    if (0x3f < param_3) {
      uVar1 = -(int)param_1 & 7;
      if (uVar1 != 0) {
        uVar3 = param_3 - uVar1;
        *param_1 = param_2;
      }
      param_1 = (ulonglong *)((ulonglong)uVar1 + (longlong)param_1);
      param_3 = uVar3 & 0x3f;
      uVar3 = uVar3 >> 6;
      if (uVar3 != 0) {
        puVar2 = param_1;
        if (uVar3 < 0x1c00) {
          do {
            *puVar2 = param_2;
            puVar2[1] = param_2;
            puVar2[2] = param_2;
            param_1 = puVar2 + 8;
            puVar2[3] = param_2;
            puVar2[4] = param_2;
            uVar3 = uVar3 - 1;
            puVar2[5] = param_2;
            puVar2[6] = param_2;
            puVar2[7] = param_2;
            puVar2 = param_1;
          } while (uVar3 != 0);
        }
        else {
          do {
            *puVar2 = param_2;
            puVar2[1] = param_2;
            puVar2[2] = param_2;
            param_1 = puVar2 + 8;
            puVar2[3] = param_2;
            puVar2[4] = param_2;
            uVar3 = uVar3 - 1;
            puVar2[5] = param_2;
            puVar2[6] = param_2;
            puVar2[7] = param_2;
            puVar2 = param_1;
          } while (uVar3 != 0);
          LOCK();
          UNLOCK();
        }
      }
    }
    uVar3 = param_3 & 7;
    for (uVar4 = param_3 >> 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *param_1 = param_2;
      param_1 = param_1 + 1;
    }
  }
  for (; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(char *)param_1 = (char)param_2;
    param_1 = (ulonglong *)((longlong)param_1 + 1);
  }
  return;
}

