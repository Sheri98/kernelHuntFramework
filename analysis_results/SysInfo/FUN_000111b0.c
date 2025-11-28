// Function: FUN_000111b0
// Address: 000111b0
// Decompiled by Ghidra


undefined8
FUN_000111b0(undefined4 *param_1,int param_2,undefined4 *param_3,uint param_4,uint *param_5)

{
  int iVar1;
  bool bVar2;
  undefined4 *puVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined4 *puVar6;
  
  if ((param_2 == 0xc) && (uVar4 = param_1[2] * param_1[1], uVar4 <= param_4)) {
    puVar3 = (undefined4 *)MmMapIoSpace(*param_1,uVar4,0);
    iVar1 = param_1[1];
    bVar2 = false;
    if (iVar1 == 1) {
      puVar6 = puVar3;
      for (uVar5 = (ulonglong)(uint)param_1[2]; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined1 *)param_3 = *(undefined1 *)puVar6;
        puVar6 = (undefined4 *)((longlong)puVar6 + 1);
        param_3 = (undefined4 *)((longlong)param_3 + 1);
      }
    }
    else if (iVar1 == 2) {
      puVar6 = puVar3;
      for (uVar5 = (ulonglong)(uint)param_1[2]; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined2 *)param_3 = *(undefined2 *)puVar6;
        puVar6 = (undefined4 *)((longlong)puVar6 + 2);
        param_3 = (undefined4 *)((longlong)param_3 + 2);
      }
    }
    else if (iVar1 == 4) {
      puVar6 = puVar3;
      for (uVar5 = (ulonglong)(uint)param_1[2]; uVar5 != 0; uVar5 = uVar5 - 1) {
        *param_3 = *puVar6;
        puVar6 = puVar6 + 1;
        param_3 = param_3 + 1;
      }
    }
    else {
      bVar2 = true;
    }
    MmUnmapIoSpace(puVar3,uVar4);
    if (!bVar2) {
      *param_5 = param_4;
      return 0;
    }
  }
  return 0xc000000d;
}

