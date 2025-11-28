// Function: FUN_00011040
// Address: 00011040
// Decompiled by Ghidra


undefined8 FUN_00011040(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  undefined4 uStack_14;
  
  if ((*(int *)(param_2 + 0x10) == 4) && (3 < *(uint *)(param_2 + 8))) {
    uVar1 = rdmsr(0x2d);
    uStack_14 = (uint)((ulonglong)uVar1 >> 0x20);
    wrmsr(0x2d,(ulonglong)uStack_14 * 0x100000000 + (ulonglong)**(uint **)(param_1 + 0x18));
    **(uint **)(param_1 + 0x18) = uStack_14;
    *(undefined8 *)(param_1 + 0x38) = 4;
    return 0;
  }
  return 0xc000000d;
}

