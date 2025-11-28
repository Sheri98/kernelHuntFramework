// Function: FUN_00011500
// Address: 00011500
// Decompiled by Ghidra


undefined8 FUN_00011500(longlong param_1)

{
  int iVar1;
  
  iVar1 = FUN_00011170(param_1,(longlong *)(param_1 + 8));
  if (-1 < iVar1) {
    *(code **)(param_1 + 0x70) = FUN_00011010;
    *(code **)(param_1 + 0x80) = FUN_00011010;
    *(code **)(param_1 + 0xe0) = FUN_00011460;
    *(code **)(param_1 + 0x68) = FUN_000113d0;
    return 0;
  }
  return 0xc000000e;
}

