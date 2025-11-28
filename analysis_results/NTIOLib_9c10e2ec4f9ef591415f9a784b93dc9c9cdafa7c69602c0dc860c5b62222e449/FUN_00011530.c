// Function: FUN_00011530
// Address: 00011530
// Decompiled by Ghidra


undefined8
FUN_00011530(longlong *param_1,int param_2,undefined4 *param_3,uint param_4,uint *param_5)

{
  int iVar1;
  longlong lVar2;
  bool bVar3;
  uint uVar4;
  undefined4 *puVar5;
  ulonglong uVar6;
  undefined4 *puVar7;
  
  if (param_2 == 0x10) {
    uVar4 = *(int *)((longlong)param_1 + 0xc) * (int)param_1[1];
    if (((uVar4 <= param_4) && (lVar2 = *param_1, 0xbffff < lVar2)) &&
       ((longlong)(lVar2 + -1 + (ulonglong)uVar4) < 0x100000)) {
      puVar5 = (undefined4 *)MmMapIoSpace(lVar2,uVar4,0);
      iVar1 = (int)param_1[1];
      bVar3 = false;
      if (iVar1 == 1) {
        puVar7 = puVar5;
        for (uVar6 = (ulonglong)*(uint *)((longlong)param_1 + 0xc); uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined1 *)param_3 = *(undefined1 *)puVar7;
          puVar7 = (undefined4 *)((longlong)puVar7 + 1);
          param_3 = (undefined4 *)((longlong)param_3 + 1);
        }
      }
      else if (iVar1 == 2) {
        puVar7 = puVar5;
        for (uVar6 = (ulonglong)*(uint *)((longlong)param_1 + 0xc); uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined2 *)param_3 = *(undefined2 *)puVar7;
          puVar7 = (undefined4 *)((longlong)puVar7 + 2);
          param_3 = (undefined4 *)((longlong)param_3 + 2);
        }
      }
      else if (iVar1 == 4) {
        puVar7 = puVar5;
        for (uVar6 = (ulonglong)*(uint *)((longlong)param_1 + 0xc); uVar6 != 0; uVar6 = uVar6 - 1) {
          *param_3 = *puVar7;
          puVar7 = puVar7 + 1;
          param_3 = param_3 + 1;
        }
      }
      else {
        bVar3 = true;
      }
      MmUnmapIoSpace(puVar5,uVar4);
      if (!bVar3) {
        *param_5 = param_4;
        return 0;
      }
    }
  }
  return 0xc000000d;
}

