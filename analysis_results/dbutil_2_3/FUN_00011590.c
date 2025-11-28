// Function: FUN_00011590
// Address: 00011590
// Decompiled by Ghidra


void FUN_00011590(undefined8 param_1,longlong param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = 0x1f;
  uVar2 = KeSetPriorityThread(SystemReserved1[0xf]);
  if (*(int *)(param_2 + 0x94) == 1) {
    FUN_000116ec(param_2 + 0x60,uVar3);
  }
  else {
    iVar1 = *(int *)(param_2 + 0x90);
    if (iVar1 == 1) {
      FUN_00011630(param_2 + 0x60,uVar3);
    }
    else if (iVar1 == 2) {
      FUN_00011657(param_2 + 0x60,uVar3);
    }
    else if (iVar1 == 4) {
      FUN_0001167f(param_2 + 0x60,uVar3);
    }
  }
  KeSetPriorityThread(SystemReserved1[0xf],uVar2);
  *(undefined1 *)(param_2 + 0x98) = 1;
  return;
}

