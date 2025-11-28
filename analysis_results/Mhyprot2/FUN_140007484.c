// Function: FUN_140007484
// Address: 140007484
// Decompiled by Ghidra


ulonglong FUN_140007484(ulonglong param_1,int *param_2,uint param_3,uint param_4)

{
  char cVar1;
  int *piVar2;
  ulonglong uVar3;
  
  piVar2 = (int *)FUN_1400073f0(param_2,param_3,param_1,param_4);
  cVar1 = MmIsAddressValid(piVar2);
  if (cVar1 == '\0') {
    uVar3 = 0;
  }
  else {
    uVar3 = (longlong)piVar2 + (longlong)*piVar2 + 4;
    cVar1 = MmIsAddressValid(uVar3);
    uVar3 = -(ulonglong)(cVar1 != '\0') & uVar3;
  }
  return uVar3;
}

