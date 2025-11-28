// Function: FUN_000110b0
// Address: 000110b0
// Decompiled by Ghidra


undefined8 FUN_000110b0(longlong param_1,longlong param_2)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  undefined4 local_18;
  undefined4 uStack_14;
  
  puVar1 = *(undefined4 **)(param_1 + 0x18);
  if ((*(int *)(param_2 + 0x10) == 0xc) && (7 < *(uint *)(param_2 + 8))) {
    wrmsr(*puVar1,(ulonglong)(uint)puVar1[2] * 0x100000000 + (ulonglong)(uint)puVar1[1]);
    uVar2 = rdmsr(*puVar1);
    puVar1 = *(undefined4 **)(param_1 + 0x18);
    local_18 = (undefined4)uVar2;
    *puVar1 = local_18;
    uStack_14 = (undefined4)((ulonglong)uVar2 >> 0x20);
    puVar1[1] = uStack_14;
    *(undefined8 *)(param_1 + 0x38) = 8;
    return 0;
  }
  return 0xc000000d;
}

