// Function: FUN_00011070
// Address: 00011070
// Decompiled by Ghidra


undefined8 FUN_00011070(longlong param_1)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  undefined4 uStack_14;
  
  puVar1 = *(undefined4 **)(param_1 + 0x18);
  uVar2 = rdmsr(*puVar1);
  *puVar1 = (int)uVar2;
  uStack_14 = (undefined4)((ulonglong)uVar2 >> 0x20);
  puVar1[1] = uStack_14;
  *(undefined8 *)(param_1 + 0x38) = 8;
  return 0;
}

