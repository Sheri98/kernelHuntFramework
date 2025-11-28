// Function: FUN_1400069d8
// Address: 1400069d8
// Decompiled by Ghidra


void FUN_1400069d8(int param_1)

{
  longlong local_res10 [3];
  
  local_res10[0] = (longlong)param_1 * -10000;
  KeDelayExecutionThread(0,0,local_res10);
  return;
}

