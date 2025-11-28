// Function: FUN_000129c0
// Address: 000129c0
// Decompiled by Ghidra


ulonglong FUN_000129c0(ushort param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined2 uVar10;
  int local_res18;
  
  while( true ) {
    bVar3 = false;
    if ((DAT_00015118 != 0) && (DAT_00015140 == 0)) {
      FUN_00013040();
    }
    iVar4 = DAT_00015140;
    DAT_00015118 = 0;
    if (1 < param_1) {
      DAT_00015118 = 0;
      return 0;
    }
    if (DAT_00015140 == 0) {
      DAT_00015118 = 0;
      return 1;
    }
    uVar8 = FUN_00012b90();
    if (uVar8 == 0) break;
    local_res18 = (int)uVar8;
    lVar9 = MmMapIoSpace(local_res18 + 0x300,0x100,0);
    uVar1 = *(uint *)(lVar9 + 0x20);
    uVar2 = *(undefined4 *)(lVar9 + 0xe0);
    *(uint *)(lVar9 + 0x20) = uVar1 & 0xfffdffff;
    *(undefined4 *)(lVar9 + 0xe0) = 0xb;
    *(undefined4 *)(lVar9 + 0x80) = 0xffffffff;
    uVar10 = (undefined2)iVar4;
    uVar5 = in(uVar10);
    uVar5 = uVar5 & 0xffffff;
    do {
      uVar6 = in(uVar10);
      uVar6 = uVar6 & 0xffffff;
      if (uVar6 < uVar5) {
        uVar6 = uVar6 + 0xffffff;
      }
    } while (uVar6 - uVar5 < (uint)(0x369e99 / (ulonglong)param_2));
    uVar6 = *(uint *)(lVar9 + 0x90);
    uVar7 = in(uVar10);
    uVar7 = uVar7 & 0xffffff;
    if (uVar7 < uVar5) {
      uVar7 = uVar7 + 0xffffff;
    }
    uVar8 = (ulonglong)(*(uint *)(lVar9 + 0x90) - uVar6);
    if ((uVar6 == 0) || (*(uint *)(lVar9 + 0x90) < uVar6)) {
      bVar3 = true;
    }
    else {
      uVar8 = (ulonglong)
              ((double)uVar8 / ((double)(uVar7 - uVar5) / (double)(0x369e99 / (ulonglong)param_2)));
    }
    *(undefined4 *)(lVar9 + 0xe0) = uVar2;
    *(uint *)(lVar9 + 0x20) = uVar1;
    *(undefined4 *)(lVar9 + 0x80) = *(undefined4 *)(lVar9 + 0x90);
    MmUnmapIoSpace(lVar9,0x100);
    if (!bVar3) {
      return uVar8 & 0xffffffff;
    }
    param_1 = param_1 + 1;
  }
  return 2;
}

