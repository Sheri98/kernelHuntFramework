// Function: FUN_000113c0
// Address: 000113c0
// Decompiled by Ghidra


undefined8
FUN_000113c0(undefined4 *param_1,uint param_2,undefined8 param_3,undefined8 param_4,
            undefined4 *param_5)

{
  int iVar1;
  bool bVar2;
  undefined4 *puVar3;
  longlong lVar4;
  int iVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined4 *puVar8;
  
  if (0xf < param_2) {
    iVar5 = param_1[3] * param_1[2];
    puVar3 = (undefined4 *)MmMapIoSpace(*param_1,iVar5);
    lVar4 = MmMapIoSpace(param_1[1]);
    iVar1 = param_1[2];
    bVar2 = false;
    if (iVar1 == 1) {
      uVar7 = 0;
      puVar8 = puVar3;
      if (param_1[3] != 0) {
        do {
          *(undefined1 *)(uVar7 + lVar4) = *(undefined1 *)puVar8;
          LOCK();
          UNLOCK();
          uVar6 = (int)uVar7 + 1;
          uVar7 = (ulonglong)uVar6;
          puVar8 = (undefined4 *)((longlong)puVar8 + 1);
        } while (uVar6 < (uint)param_1[3]);
      }
    }
    else if (iVar1 == 2) {
      uVar7 = 0;
      puVar8 = puVar3;
      if (param_1[3] != 0) {
        do {
          *(undefined2 *)(lVar4 + uVar7 * 2) = *(undefined2 *)puVar8;
          LOCK();
          UNLOCK();
          uVar6 = (int)uVar7 + 1;
          uVar7 = (ulonglong)uVar6;
          puVar8 = (undefined4 *)((longlong)puVar8 + 2);
        } while (uVar6 < (uint)param_1[3]);
      }
    }
    else if (iVar1 == 4) {
      uVar7 = 0;
      puVar8 = puVar3;
      if (param_1[3] != 0) {
        do {
          *(undefined4 *)(lVar4 + uVar7 * 4) = *puVar8;
          LOCK();
          UNLOCK();
          uVar6 = (int)uVar7 + 1;
          uVar7 = (ulonglong)uVar6;
          puVar8 = puVar8 + 1;
        } while (uVar6 < (uint)param_1[3]);
      }
    }
    else {
      bVar2 = true;
    }
    MmUnmapIoSpace(lVar4,iVar5);
    MmUnmapIoSpace(puVar3,iVar5);
    if (!bVar2) {
      *param_5 = 0;
      return 0;
    }
  }
  return 0xc000000d;
}

