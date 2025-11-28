// Function: FUN_140001024
// Address: 140001024
// Decompiled by Ghidra


longlong FUN_140001024(undefined2 *param_1,undefined1 param_2)

{
  ushort uVar1;
  
  if (0x200 < DAT_1400050fc) {
    return (ulonglong)(byte)(DAT_1400050fc >> 8) << 8;
  }
  *(undefined2 *)(&DAT_1400051a0 + (ulonglong)DAT_1400050fc * 8) = *param_1;
  *(undefined2 *)(&DAT_1400051a2 + (ulonglong)DAT_1400050fc * 8) = param_1[1];
  *(undefined2 *)(&DAT_1400051a4 + (ulonglong)DAT_1400050fc * 8) = param_1[2];
  uVar1 = DAT_1400050fc;
  (&DAT_1400051a6)[(ulonglong)DAT_1400050fc * 8] = param_2;
  DAT_1400050fc = DAT_1400050fc + 1;
  return CONCAT71((uint7)(byte)(uVar1 >> 8),1);
}

