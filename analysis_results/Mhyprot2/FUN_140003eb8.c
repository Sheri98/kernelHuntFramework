// Function: FUN_140003eb8
// Address: 140003eb8
// Decompiled by Ghidra


void FUN_140003eb8(undefined8 param_1,int *param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  if (*param_2 == 1) {
    uVar1 = IoGetCurrentProcess();
    uVar2 = param_1;
    param_1 = uVar1;
  }
  else {
    uVar2 = IoGetCurrentProcess();
  }
  MmCopyVirtualMemory(param_1,*(undefined8 *)(param_2 + 6),uVar2,*(undefined8 *)(param_2 + 4),
                      param_2[8],0,param_3);
  return;
}

