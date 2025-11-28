// Function: FUN_140001000
// Address: 140001000
// Decompiled by Ghidra


undefined4 FUN_140001000(undefined8 param_1,longlong param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(int *)(*(longlong *)(param_2 + 0xb8) + 0x18) == 0x2220c0) {
    uVar1 = FUN_1400013dc(*(undefined8 **)(param_2 + 0x18));
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = uVar1;
  IofCompleteRequest(param_2,0);
  return uVar1;
}

