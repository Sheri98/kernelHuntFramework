// Function: FUN_14000301c
// Address: 14000301c
// Decompiled by Ghidra


void FUN_14000301c(longlong *param_1,undefined8 param_2)

{
  ulonglong uVar1;
  void *_Dst;
  longlong lVar2;
  
  if (param_1 != (longlong *)0x0) {
    *param_1 = 0;
    param_1[1] = 0;
    _Dst = (void *)ExAllocatePool(0);
    *param_1 = (longlong)_Dst;
    memset(_Dst,0,0x9c0);
    *(undefined4 *)((longlong)param_1 + 0xc) = 1;
    *(undefined8 *)*param_1 = param_2;
    *(undefined4 *)(param_1 + 1) = 1;
    do {
      lVar2 = (longlong)(int)param_1[1];
      uVar1 = *(ulonglong *)(*param_1 + -8 + lVar2 * 8);
      *(ulonglong *)(*param_1 + lVar2 * 8) = (uVar1 >> 0x3e ^ uVar1) * 0x5851f42d4c957f2d + lVar2;
      *(int *)(param_1 + 1) = (int)param_1[1] + 1;
    } while ((int)param_1[1] < 0x138);
  }
  return;
}

