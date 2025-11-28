// Function: entry
// Address: 00012d60
// Decompiled by Ghidra


void entry(longlong param_1)

{
  ulonglong uVar1;
  longlong local_18 [3];
  
  *(code **)(param_1 + 0x70) = FUN_00012c70;
  *(code **)(param_1 + 0x80) = FUN_00011a60;
  *(code **)(param_1 + 0xe0) = FUN_00012440;
  *(code **)(param_1 + 0x68) = FUN_00011b10;
  uVar1 = FUN_00011970(param_1,local_18);
  if (-1 < (int)uVar1) {
    **(longlong **)(local_18[0] + 0x40) = local_18[0];
  }
  return;
}

