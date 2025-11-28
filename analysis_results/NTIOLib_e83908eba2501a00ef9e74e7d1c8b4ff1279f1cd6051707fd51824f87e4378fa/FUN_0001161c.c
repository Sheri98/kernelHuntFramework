// Function: FUN_0001161c
// Address: 0001161c
// Decompiled by Ghidra


undefined8
FUN_0001161c(undefined8 *param_1,uint param_2,undefined8 param_3,undefined8 param_4,
            undefined4 *param_5)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  undefined4 *puVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  undefined4 *puVar7;
  
  if (param_2 < 0x10) {
    return 0xc000000d;
  }
  uVar3 = *(int *)((longlong)param_1 + 0xc) * *(int *)(param_1 + 1);
  if ((ulonglong)param_2 < (ulonglong)uVar3 + 0x10) {
    return 0xc000000d;
  }
  puVar4 = (undefined4 *)MmMapIoSpace(*param_1,uVar3,0);
  iVar1 = *(int *)(param_1 + 1);
  bVar2 = false;
  if (iVar1 == 1) {
    puVar6 = param_1 + 2;
    puVar7 = puVar4;
    for (uVar5 = (ulonglong)*(uint *)((longlong)param_1 + 0xc); uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
      puVar6 = (undefined8 *)((longlong)puVar6 + 1);
      puVar7 = (undefined4 *)((longlong)puVar7 + 1);
    }
  }
  else if (iVar1 == 2) {
    puVar6 = param_1 + 2;
    puVar7 = puVar4;
    for (uVar5 = (ulonglong)*(uint *)((longlong)param_1 + 0xc); uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined2 *)puVar7 = *(undefined2 *)puVar6;
      puVar6 = (undefined8 *)((longlong)puVar6 + 2);
      puVar7 = (undefined4 *)((longlong)puVar7 + 2);
    }
  }
  else {
    if (iVar1 != 4) {
      bVar2 = true;
      goto LAB_000116ad;
    }
    puVar6 = param_1 + 2;
    puVar7 = puVar4;
    for (uVar5 = (ulonglong)*(uint *)((longlong)param_1 + 0xc); uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar7 = *(undefined4 *)puVar6;
      puVar6 = (undefined8 *)((longlong)puVar6 + 4);
      puVar7 = puVar7 + 1;
    }
  }
  LOCK();
  UNLOCK();
LAB_000116ad:
  MmUnmapIoSpace(puVar4,uVar3);
  if (bVar2) {
    return 0xc000000d;
  }
  *param_5 = 0;
  return 0;
}

