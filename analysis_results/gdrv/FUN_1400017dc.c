// Function: FUN_1400017dc
// Address: 1400017dc
// Decompiled by Ghidra


uint FUN_1400017dc(undefined8 param_1,longlong param_2,longlong param_3)

{
  bool bVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_3 + 0x10);
  *(undefined8 *)(param_2 + 0x38) = 0;
  if (uVar2 < 4) {
    DbgPrint("(FREE_PHYS_MEM) Insufficient input or output buffer\n");
    uVar2 = 0xc000009a;
  }
  else {
    bVar1 = FUN_14000293c(**(undefined8 **)(param_2 + 0x18));
    uVar2 = ~-(uint)bVar1 & 0xc000000d;
  }
  return uVar2;
}

