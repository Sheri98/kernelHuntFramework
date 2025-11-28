// Function: FUN_140001da0
// Address: 140001da0
// Decompiled by Ghidra


undefined8 FUN_140001da0(longlong param_1,longlong param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  
  if ((*(int *)(param_2 + 0x10) == 0xc) && (7 < *(uint *)(param_2 + 8))) {
    uVar1 = **(undefined4 **)(param_1 + 0x18);
    wrmsr(uVar1,*(undefined8 *)(*(undefined4 **)(param_1 + 0x18) + 1));
    uVar3 = rdmsr(uVar1);
    puVar2 = *(undefined4 **)(param_1 + 0x18);
    *puVar2 = (int)uVar3;
    puVar2[1] = (int)((ulonglong)uVar3 >> 0x20);
    *(undefined8 *)(param_1 + 0x38) = 8;
    return 0;
  }
  return 0xc000000d;
}

