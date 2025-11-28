// Function: FUN_14000204c
// Address: 14000204c
// Decompiled by Ghidra


undefined8 FUN_14000204c(longlong param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  undefined2 *puVar3;
  undefined8 uVar4;
  
  puVar3 = *(undefined2 **)(param_1 + 0x18);
  iVar1 = *(int *)(param_2 + 0x10);
  uVar2 = *(uint *)(param_2 + 8);
  DAT_140005052 = *puVar3;
  DAT_140005050 = puVar3[1];
  DAT_14000504e = puVar3[2];
  DAT_14000504c = puVar3[3];
  FUN_140001000();
  *puVar3 = DAT_140005052;
  puVar3[1] = DAT_140005050;
  puVar3[2] = DAT_14000504e;
  puVar3[3] = DAT_14000504c;
  if ((iVar1 == 8) && (7 < uVar2)) {
    *(undefined8 *)(param_1 + 0x38) = 8;
    uVar4 = 0;
  }
  else {
    uVar4 = 0xc000000d;
  }
  return uVar4;
}

