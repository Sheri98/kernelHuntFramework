// Function: FUN_000121e0
// Address: 000121e0
// Decompiled by Ghidra


ulonglong FUN_000121e0(undefined4 param_1)

{
  ulonglong uVar1;
  
  uVar1 = rdmsr(param_1);
  return uVar1 & 0xffffffff;
}

