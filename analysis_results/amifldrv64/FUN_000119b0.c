// Function: FUN_000119b0
// Address: 000119b0
// Decompiled by Ghidra


undefined4 FUN_000119b0(undefined8 param_1)

{
  undefined4 uVar1;
  
  uVar1 = ZwUnmapViewOfSection(0xffffffffffffffff);
  ZwClose(param_1);
  return uVar1;
}

