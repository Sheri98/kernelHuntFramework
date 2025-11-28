// Function: FUN_00011574
// Address: 00011574
// Decompiled by Ghidra


ulonglong FUN_00011574(ulonglong param_1)

{
  return (longlong)(int)(param_1 >> 0x20) << 0x20 ^ param_1 & 0xffffffff;
}

