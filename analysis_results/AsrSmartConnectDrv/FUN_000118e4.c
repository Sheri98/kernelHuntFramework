// Function: FUN_000118e4
// Address: 000118e4
// Decompiled by Ghidra


int FUN_000118e4(longlong *param_1)

{
  int iVar1;
  ulonglong *_Src;
  void *_Src_00;
  ulonglong uVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  uint uVar6;
  
  iVar3 = -0x3fffffff;
  _Src = (ulonglong *)ExAllocatePoolWithTag(0,0x2000,0x6d656d66);
  if (_Src != (ulonglong *)0x0) {
    FUN_00012500(_Src,0,0x1000);
    if (*(char *)((longlong)param_1 + 0x24) != '\0') {
      *param_1 = *param_1 + -0x1000;
    }
    if (*(int *)((longlong)param_1 + 0xc) == 0) {
      *(undefined4 *)((longlong)param_1 + 0xc) = 1;
    }
    while ((int)param_1[1] != 0) {
      uVar6 = *(uint *)(param_1 + 1);
      if (uVar6 < 0x1001) {
        *(undefined4 *)(param_1 + 1) = 0;
      }
      else {
        iVar1 = uVar6 - 0x1000;
        uVar6 = 0x1000;
        *(int *)(param_1 + 1) = iVar1;
      }
      _Src_00 = (void *)MmMapIoSpace(*param_1,0x1000,0);
      if (_Src_00 != (void *)0x0) {
        memcpy(_Src + 0x200,_Src,0x1000);
        memcpy(_Src,_Src_00,0x1000);
        uVar5 = 0;
        if (uVar6 != 0) {
          do {
            uVar4 = *(uint *)(param_1 + 4);
            uVar2 = RtlCompareMemory(uVar5 + (longlong)_Src,param_1[3]);
            if (uVar2 == uVar4) {
              if ((int)param_1[2] == 0) {
                iVar3 = 0;
                param_1[5] = uVar5 + *param_1;
                break;
              }
              *(int *)(param_1 + 2) = (int)param_1[2] + -1;
            }
            uVar4 = (int)uVar5 + *(int *)((longlong)param_1 + 0xc);
            uVar5 = (ulonglong)uVar4;
          } while (uVar4 < uVar6);
        }
        MmUnmapIoSpace(_Src_00,0x1000);
      }
      if (iVar3 == 0) break;
      if (*(char *)((longlong)param_1 + 0x24) == '\0') {
        *param_1 = *param_1 + 0x1000;
      }
      else {
        *param_1 = *param_1 + -0x1000;
      }
    }
    ExFreePoolWithTag(_Src,0);
  }
  return iVar3;
}

