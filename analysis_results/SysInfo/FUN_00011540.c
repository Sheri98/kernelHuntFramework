// Function: FUN_00011540
// Address: 00011540
// Decompiled by Ghidra


undefined8
FUN_00011540(undefined4 *param_1,uint param_2,undefined8 param_3,undefined8 param_4,
            undefined4 *param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  longlong lVar5;
  uint uVar6;
  ulonglong uVar7;
  
  if (0xf < param_2) {
    iVar1 = param_1[3];
    iVar2 = param_1[2];
    lVar5 = MmMapIoSpace(*param_1);
    bVar4 = false;
    iVar3 = param_1[2];
    if (iVar3 == 1) {
      uVar7 = 0;
      if (param_1[3] != 0) {
        do {
          *(undefined1 *)(uVar7 + lVar5) = *(undefined1 *)(param_1 + 1);
          LOCK();
          UNLOCK();
          uVar6 = (int)uVar7 + 1;
          uVar7 = (ulonglong)uVar6;
        } while (uVar6 < (uint)param_1[3]);
      }
    }
    else if (iVar3 == 2) {
      uVar7 = 0;
      if (param_1[3] != 0) {
        do {
          *(undefined2 *)(lVar5 + uVar7 * 2) = *(undefined2 *)(param_1 + 1);
          LOCK();
          UNLOCK();
          uVar6 = (int)uVar7 + 1;
          uVar7 = (ulonglong)uVar6;
        } while (uVar6 < (uint)param_1[3]);
      }
    }
    else if (iVar3 == 4) {
      uVar7 = 0;
      if (param_1[3] != 0) {
        do {
          *(undefined4 *)(lVar5 + uVar7 * 4) = param_1[1];
          LOCK();
          UNLOCK();
          uVar6 = (int)uVar7 + 1;
          uVar7 = (ulonglong)uVar6;
        } while (uVar6 < (uint)param_1[3]);
      }
    }
    else {
      bVar4 = true;
    }
    MmUnmapIoSpace(lVar5,iVar1 * iVar2);
    if (!bVar4) {
      *param_5 = 0;
      return 0;
    }
  }
  return 0xc000000d;
}

