// Function: FUN_00011b34
// Address: 00011b34
// Decompiled by Ghidra


int FUN_00011b34(ulonglong *param_1,longlong param_2,longlong param_3)

{
  ulonglong *puVar1;
  int iVar2;
  ulonglong *puVar3;
  ulonglong *local_res10;
  
  iVar2 = 0;
  if (*(ulonglong **)(param_2 + 0xa8) != (ulonglong *)0x0) {
    puVar1 = *(ulonglong **)(param_2 + 0xa8);
    do {
      puVar3 = puVar1;
      if (((int)puVar3[1] == (int)param_1[1]) &&
         (*(int *)((longlong)puVar3 + 0x14) == *(int *)((longlong)param_1 + 0x14)))
      goto LAB_00011bd7;
      puVar1 = (ulonglong *)puVar3[4];
      local_res10 = puVar3;
    } while ((ulonglong *)puVar3[4] != (ulonglong *)0x0);
  }
  puVar3 = (ulonglong *)ExAllocatePool(0);
  FUN_00012860(puVar3,0,0x28);
  if (*(int *)(param_2 + 0xa0) == 0) {
    *(ulonglong **)(param_2 + 0xa8) = puVar3;
  }
  else {
    local_res10[4] = (ulonglong)puVar3;
  }
  *(int *)(param_2 + 0xa0) = *(int *)(param_2 + 0xa0) + 1;
  *(int *)puVar3 = (int)*param_1;
  *(undefined4 *)((longlong)puVar3 + 4) = *(undefined4 *)((longlong)param_1 + 4);
  puVar3[1] = param_1[1];
  *(int *)(puVar3 + 2) = (int)param_1[2];
  *(undefined4 *)((longlong)puVar3 + 0x14) = *(undefined4 *)((longlong)param_1 + 0x14);
LAB_00011bd7:
  if (puVar3[3] == 0) {
    iVar2 = FUN_0001242c((uint *)param_1);
  }
  else {
    *param_1 = puVar3[3];
  }
  *(undefined8 *)(param_3 + 0x38) = 4;
  return iVar2;
}

