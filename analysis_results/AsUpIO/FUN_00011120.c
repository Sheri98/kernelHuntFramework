// Function: FUN_00011120
// Address: 00011120
// Decompiled by Ghidra


undefined8 FUN_00011120(longlong param_1,longlong param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 local_18;
  undefined4 uStack_14;
  
  if ((*(int *)(param_2 + 0x10) == 0xc) && (7 < *(uint *)(param_2 + 8))) {
    uVar1 = **(undefined4 **)(param_1 + 0x18);
    wrmsr(uVar1,(ulonglong)(uint)(*(undefined4 **)(param_1 + 0x18))[1]);
    uVar3 = rdmsr(uVar1);
    puVar2 = *(undefined4 **)(param_1 + 0x18);
    uStack_14 = (undefined4)((ulonglong)uVar3 >> 0x20);
    *puVar2 = uStack_14;
    local_18 = (undefined4)uVar3;
    puVar2[1] = local_18;
    *(undefined8 *)(param_1 + 0x38) = 8;
    return 0;
  }
  return 0xc000000d;
}

