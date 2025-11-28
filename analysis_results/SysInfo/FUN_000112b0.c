// Function: FUN_000112b0
// Address: 000112b0
// Decompiled by Ghidra


undefined8
FUN_000112b0(undefined4 *param_1,uint param_2,undefined8 param_3,undefined8 param_4,
            undefined4 *param_5)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  undefined4 *puVar4;
  ulonglong uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  if (param_2 < 0xc) {
    return 0xc000000d;
  }
  uVar3 = param_1[2] * param_1[1];
  if ((ulonglong)uVar3 + 0xc <= (ulonglong)param_2) {
    puVar4 = (undefined4 *)MmMapIoSpace(*param_1,uVar3,0);
    iVar1 = param_1[1];
    bVar2 = false;
    if (iVar1 == 1) {
      puVar6 = param_1 + 3;
      puVar7 = puVar4;
      for (uVar5 = (ulonglong)(uint)param_1[2]; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
        puVar6 = (undefined4 *)((longlong)puVar6 + 1);
        puVar7 = (undefined4 *)((longlong)puVar7 + 1);
      }
      LOCK();
      UNLOCK();
    }
    else if (iVar1 == 2) {
      puVar6 = param_1 + 3;
      puVar7 = puVar4;
      for (uVar5 = (ulonglong)(uint)param_1[2]; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined2 *)puVar7 = *(undefined2 *)puVar6;
        puVar6 = (undefined4 *)((longlong)puVar6 + 2);
        puVar7 = (undefined4 *)((longlong)puVar7 + 2);
      }
      LOCK();
      UNLOCK();
    }
    else if (iVar1 == 4) {
      puVar6 = param_1 + 3;
      puVar7 = puVar4;
      for (uVar5 = (ulonglong)(uint)param_1[2]; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      LOCK();
      UNLOCK();
    }
    else {
      bVar2 = true;
    }
    MmUnmapIoSpace(puVar4,uVar3);
    if (!bVar2) {
      *param_5 = 0;
      return 0;
    }
  }
  return 0xc000000d;
}

