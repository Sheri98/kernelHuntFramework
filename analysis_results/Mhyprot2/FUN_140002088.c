// Function: FUN_140002088
// Address: 140002088
// Decompiled by Ghidra


void FUN_140002088(undefined8 *param_1,uint param_2,ulonglong *param_3,longlong *param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  int iVar5;
  
  FUN_1400075c0(param_3,param_1,(ulonglong)param_2);
  iVar3 = 0;
  if ((ulonglong)(param_2 >> 3) != 0) {
    iVar5 = 0;
    lVar4 = (longlong)param_1 - (longlong)param_3;
    do {
      uVar1 = FUN_140002eb0(param_4);
      lVar2 = (longlong)iVar5;
      iVar3 = iVar3 + 1;
      iVar5 = iVar5 + 0x10;
      *param_3 = *(ulonglong *)(lVar4 + (longlong)param_3) ^ uVar1 ^ lVar2 + param_4[2];
      param_3 = param_3 + 1;
      *(int *)(param_4 + 1) = (int)param_4[1] % 0x138;
    } while ((ulonglong)(longlong)iVar3 < (ulonglong)(param_2 >> 3));
  }
  return;
}

