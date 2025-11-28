// Function: FUN_000114f8
// Address: 000114f8
// Decompiled by Ghidra


uint FUN_000114f8(undefined2 param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  
  if (param_2 == 4) {
    uVar3 = in(param_1);
    return uVar3;
  }
  if (param_2 == 2) {
    uVar2 = in(param_1);
    return (uint)uVar2;
  }
  if (param_2 == 1) {
    bVar1 = in(param_1);
    return (uint)bVar1;
  }
  return 0;
}

