// Function: FUN_00012c00
// Address: 00012c00
// Decompiled by Ghidra


undefined8 FUN_00012c00(undefined8 param_1,void *param_2,ulonglong param_3)

{
  void *_Src;
  ulonglong _Size;
  
  _Size = param_3 & 0xffffffff;
  _Src = (void *)MmMapIoSpace(param_1,_Size,0);
  memcpy(param_2,_Src,_Size);
  MmUnmapIoSpace(_Src,_Size);
  return 0;
}

