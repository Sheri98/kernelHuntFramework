// Function: FUN_140001820
// Address: 140001820
// Decompiled by Ghidra


undefined8 FUN_140001820(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  
  piVar1 = *(int **)(param_2 + 0x18);
  uVar4 = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  uVar2 = *(undefined8 *)piVar1;
  DbgPrint("Default VA=%x",uVar2);
  uVar3 = FUN_14000297c(uVar2);
  if ((int)uVar3 == 0) {
    uVar4 = 0xc000000d;
  }
  else {
    DbgPrint("Physical Address=%x",uVar3 & 0xffffffff);
    *piVar1 = (int)uVar3;
    *(undefined8 *)(param_2 + 0x38) = 4;
  }
  return uVar4;
}

