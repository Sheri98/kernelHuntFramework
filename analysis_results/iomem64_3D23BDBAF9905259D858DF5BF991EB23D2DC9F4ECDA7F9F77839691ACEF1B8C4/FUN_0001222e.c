// Function: FUN_0001222e
// Address: 0001222e
// Decompiled by Ghidra


undefined8 FUN_0001222e(int param_1)

{
  undefined8 uVar1;
  undefined8 in_RAX;
  
  uVar1 = rdtsc();
  *(int *)(longlong)param_1 = (int)uVar1;
  *(int *)(longlong)(param_1 + 4) = (int)((ulonglong)uVar1 >> 0x20);
  return in_RAX;
}

