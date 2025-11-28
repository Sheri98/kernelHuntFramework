// Function: FUN_1400028d8
// Address: 1400028d8
// Decompiled by Ghidra


longlong FUN_1400028d8(int param_1,longlong *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = 0;
  if (param_2 != (longlong *)0x0) {
    lVar1 = MmAllocateContiguousMemory(param_1 + 0xfffU & 0xfffff000,0xffffff);
    param_2[1] = lVar1;
    if (lVar1 != 0) {
      *param_2 = lVar1;
      uVar2 = DbgPrint("ptPageAddr->dwHandle VA=%x,sizeof(dwHandle)=%d",lVar1,8);
      lVar1 = CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
    }
  }
  return lVar1;
}

