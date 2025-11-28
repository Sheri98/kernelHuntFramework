// Function: FUN_00011130
// Address: 00011130
// Decompiled by Ghidra


void FUN_00011130(int param_1)

{
  longlong local_18 [3];
  
  local_18[0] = (longlong)(param_1 * -10000);
  KeDelayExecutionThread((ulonglong)(uint3)((uint)(param_1 * -10000) >> 8) << 8,0,local_18);
  return;
}

