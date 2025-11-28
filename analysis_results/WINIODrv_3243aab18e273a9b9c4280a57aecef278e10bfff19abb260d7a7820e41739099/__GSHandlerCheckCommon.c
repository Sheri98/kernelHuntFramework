// Function: __GSHandlerCheckCommon
// Address: 1400015a8
// Decompiled by Ghidra


/* Library Function - Single Match
    __GSHandlerCheckCommon
   
   Library: Visual Studio 2019 Release */

void __GSHandlerCheckCommon(ulonglong param_1,longlong param_2,uint *param_3)

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
    param_1 = param_1 + (longlong)(int)(bVar1 & 0xfffffff0);
  }
  FUN_140001570(param_1 ^ *(ulonglong *)((longlong)(int)(*param_3 & 0xfffffff8) + uVar2));
  return;
}

