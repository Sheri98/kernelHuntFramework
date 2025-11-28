// Function: FUN_00012020
// Address: 00012020
// Decompiled by Ghidra


void FUN_00012020(uint *param_1,char param_2)

{
  if (param_2 != '\0') {
    param_1 = (uint *)(ulonglong)*param_1;
  }
  ZwUnmapViewOfSection(0xffffffffffffffff,param_1);
  return;
}

