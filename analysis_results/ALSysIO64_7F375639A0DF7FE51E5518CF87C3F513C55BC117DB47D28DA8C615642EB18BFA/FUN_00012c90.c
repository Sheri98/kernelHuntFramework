// Function: FUN_00012c90
// Address: 00012c90
// Decompiled by Ghidra


undefined8 FUN_00012c90(undefined8 param_1,void *param_2,ulonglong param_3)

{
  void *_Dst;
  ulonglong _Size;
  
  _Size = param_3 & 0xffffffff;
  _Dst = (void *)MmMapIoSpace(param_1,_Size,0);
  memcpy(_Dst,param_2,_Size);
  MmUnmapIoSpace(_Dst,_Size);
  return 0;
}

