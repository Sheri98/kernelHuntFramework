// Function: FUN_00011fe0
// Address: 00011fe0
// Decompiled by Ghidra


void FUN_00011fe0(uint *param_1,char param_2)

{
  if (param_2 != '\0') {
    param_1 = (uint *)(ulonglong)*param_1;
  }
  ZwUnmapViewOfSection(0xffffffffffffffff,param_1);
  return;
}

