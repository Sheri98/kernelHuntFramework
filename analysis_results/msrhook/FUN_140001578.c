// Function: FUN_140001578
// Address: 140001578
// Decompiled by Ghidra


undefined8 FUN_140001578(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  undefined8 local_res10 [3];
  
  DAT_1400050ec = 1;
  local_res10[0] = 0xfffffffffffcf2c0;
  KeDelayExecutionThread(0,0,local_res10);
  FUN_140002cbc();
  DAT_1400050ec = 0;
  if (*(uint *)(param_2 + 8) < 2) {
    DAT_1400050e8 = 0;
    uVar1 = 0xc0000023;
  }
  else {
    FUN_140002e00(*(undefined8 **)(param_1 + 0x18),(undefined8 *)&DAT_1400061c0,
                  (ulonglong)DAT_1400050e8);
    *(ulonglong *)(param_1 + 0x38) = (ulonglong)DAT_1400050e8;
    DAT_1400050e8 = 0;
    local_res10[0] = 0xfffffffffffcf2c0;
    KeDelayExecutionThread(0,0,local_res10);
    uVar1 = 0;
  }
  return uVar1;
}

