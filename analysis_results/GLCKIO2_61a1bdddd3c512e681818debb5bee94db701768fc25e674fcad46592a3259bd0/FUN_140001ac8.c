// Function: FUN_140001ac8
// Address: 140001ac8
// Decompiled by Ghidra


undefined4 FUN_140001ac8(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  undefined4 uVar1;
  
  uVar1 = ZwUnmapViewOfSection(0xffffffffffffffff);
  if (param_3 != 0) {
    ObfDereferenceObject(param_3);
  }
  ZwClose(param_1);
  return uVar1;
}

