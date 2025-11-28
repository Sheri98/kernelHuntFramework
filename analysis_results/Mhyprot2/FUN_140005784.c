// Function: FUN_140005784
// Address: 140005784
// Decompiled by Ghidra


ulonglong FUN_140005784(ulonglong param_1)

{
  ulonglong uVar1;
  
  if (DAT_14000a748 == 0x3d) {
    uVar1 = param_1 & 0xfffffffffffffff8;
  }
  else {
    if (DAT_14000a748 == 0x3e) {
      uVar1 = (longlong)param_1 >> 0x13;
    }
    else {
      if ((DAT_14000a748 != 0x3f) && (DAT_14000a748 != 100)) {
        return 0;
      }
      uVar1 = (longlong)param_1 >> 0x10;
    }
    uVar1 = uVar1 & 0xfffffffffffffff0;
  }
  return uVar1;
}

