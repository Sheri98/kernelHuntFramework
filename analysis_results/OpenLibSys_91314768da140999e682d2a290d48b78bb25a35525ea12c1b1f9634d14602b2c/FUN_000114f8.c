// Function: FUN_000114f8
// Address: 000114f8
// Decompiled by Ghidra


undefined8
FUN_000114f8(undefined8 *param_1,int param_2,undefined4 *param_3,uint param_4,uint *param_5)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  undefined4 *puVar4;
  ulonglong uVar5;
  undefined4 *puVar6;
  
  if ((param_2 == 0x10) &&
     (uVar3 = *(int *)(param_1 + 1) * *(int *)((longlong)param_1 + 0xc), uVar3 <= param_4)) {
    puVar4 = (undefined4 *)MmMapIoSpace(*param_1,uVar3,0);
    iVar1 = *(int *)(param_1 + 1);
    bVar2 = false;
    if (iVar1 == 1) {
      puVar6 = puVar4;
      for (uVar5 = (ulonglong)*(uint *)((longlong)param_1 + 0xc); uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined1 *)param_3 = *(undefined1 *)puVar6;
        puVar6 = (undefined4 *)((longlong)puVar6 + 1);
        param_3 = (undefined4 *)((longlong)param_3 + 1);
      }
    }
    else if (iVar1 == 2) {
      puVar6 = puVar4;
      for (uVar5 = (ulonglong)*(uint *)((longlong)param_1 + 0xc); uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined2 *)param_3 = *(undefined2 *)puVar6;
        puVar6 = (undefined4 *)((longlong)puVar6 + 2);
        param_3 = (undefined4 *)((longlong)param_3 + 2);
      }
    }
    else if (iVar1 == 4) {
      puVar6 = puVar4;
      for (uVar5 = (ulonglong)*(uint *)((longlong)param_1 + 0xc); uVar5 != 0; uVar5 = uVar5 - 1) {
        *param_3 = *puVar6;
        puVar6 = puVar6 + 1;
        param_3 = param_3 + 1;
      }
    }
    else {
      bVar2 = true;
    }
    MmUnmapIoSpace(puVar4,uVar3);
    if (!bVar2) {
      *param_5 = param_4;
      return 0;
    }
  }
  return 0xc000000d;
}

