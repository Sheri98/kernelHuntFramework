// Function: FUN_00011008
// Address: 00011008
// Decompiled by Ghidra


int FUN_00011008(short *param_1,ulonglong param_2,longlong param_3,ulonglong param_4)

{
  short sVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  int iVar6;
  
  uVar3 = param_2 >> 1;
  iVar6 = 0;
  iVar2 = -0x3ffffff3;
  if ((uVar3 == 0) || (0x7fffffff < uVar3)) {
    iVar6 = -0x3ffffff3;
  }
  if (iVar6 < 0) {
    return iVar6;
  }
  if (param_4 >> 1 < 0x7fffffff) {
    iVar2 = 0;
    if (uVar3 != 0) {
      lVar5 = (param_4 >> 1) - uVar3;
      lVar4 = param_3 - (longlong)param_1;
      do {
        if ((lVar5 + uVar3 == 0) || (sVar1 = *(short *)(lVar4 + (longlong)param_1), sVar1 == 0))
        break;
        *param_1 = sVar1;
        param_1 = param_1 + 1;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
      if (uVar3 != 0) goto LAB_00011077;
    }
    param_1 = param_1 + -1;
    iVar2 = -0x7ffffffb;
  }
LAB_00011077:
  *param_1 = 0;
  return iVar2;
}

