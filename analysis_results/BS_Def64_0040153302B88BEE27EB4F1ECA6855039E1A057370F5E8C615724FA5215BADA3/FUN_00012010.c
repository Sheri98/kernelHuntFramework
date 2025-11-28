// Function: FUN_00012010
// Address: 00012010
// Decompiled by Ghidra


void FUN_00012010(uint *param_1,char param_2)

{
  if (param_2 != '\0') {
    param_1 = (uint *)(ulonglong)*param_1;
  }
  ZwUnmapViewOfSection(0xffffffffffffffff,param_1);
  return;
}

