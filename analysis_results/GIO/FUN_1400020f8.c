// Function: FUN_1400020f8
// Address: 1400020f8
// Decompiled by Ghidra


undefined8 FUN_1400020f8(undefined8 param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  
  puVar3 = *(undefined4 **)(param_2 + 0x18);
  iVar1 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  uVar2 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
  DAT_140005038 = *puVar3;
  DAT_140005034 = puVar3[1];
  DAT_140005030 = puVar3[2];
  DAT_14000502c = puVar3[3];
  DAT_140005028 = puVar3[4];
  DAT_140005024 = puVar3[5];
  FUN_140001066();
  *puVar3 = DAT_140005038;
  puVar3[1] = DAT_140005034;
  puVar3[2] = DAT_140005030;
  puVar3[3] = DAT_14000502c;
  puVar3[4] = DAT_140005028;
  puVar3[5] = DAT_140005024;
  puVar3[6] = DAT_140005020;
  if ((iVar1 == 0x1c) && (0x1b < uVar2)) {
    *(undefined8 *)(param_2 + 0x38) = 0x1c;
    uVar4 = 0;
  }
  else {
    uVar4 = 0xc000000d;
  }
  return uVar4;
}

