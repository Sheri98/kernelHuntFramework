// Function: FUN_140002eb0
// Address: 140002eb0
// Decompiled by Ghidra


void FUN_140002eb0(ulonglong param_1,longlong param_2,uint *param_3)

{
  byte bVar1;
  ulonglong uVar2;
  
  uVar2 = param_1;
  if ((*param_3 & 4) != 0) {
    uVar2 = (longlong)(int)param_3[1] + param_1 & (longlong)(int)-param_3[2];
  }
  bVar1 = *(byte *)((ulonglong)*(uint *)(*(longlong *)(param_2 + 0x10) + 8) +
                    *(longlong *)(param_2 + 8) + 3);
  if ((bVar1 & 0xf) != 0) {
    param_1 = param_1 + (bVar1 & 0xfffffff0);
  }
  FUN_140002e40(param_1 ^ *(ulonglong *)((longlong)(int)(*param_3 & 0xfffffff8) + uVar2));
  return;
}

