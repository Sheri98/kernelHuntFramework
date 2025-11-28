// Function: FUN_1400073f0
// Address: 1400073f0
// Decompiled by Ghidra


ulonglong FUN_1400073f0(int *param_1,uint param_2,ulonglong param_3,uint param_4)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  ulonglong uVar4;
  
  if ((((param_1 != (int *)0x0) && (param_2 != 0)) && (param_3 != 0)) && (param_4 != 0)) {
    uVar4 = param_4 + param_3;
    for (; param_3 < uVar4; param_3 = param_3 + 1) {
      uVar2 = 0;
      piVar3 = param_1;
      if (param_2 == 0) {
        return param_3;
      }
      while ((cVar1 = MmIsAddressValid((longlong)*piVar3 + param_3), cVar1 != '\0' &&
             (*(char *)((longlong)*piVar3 + param_3) == (char)piVar3[1]))) {
        uVar2 = uVar2 + 1;
        piVar3 = piVar3 + 2;
        if (param_2 <= uVar2) {
          return param_3;
        }
      }
    }
  }
  return 0;
}

