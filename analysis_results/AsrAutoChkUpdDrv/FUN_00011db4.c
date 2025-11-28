// Function: FUN_00011db4
// Address: 00011db4
// Decompiled by Ghidra


undefined8 FUN_00011db4(int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  undefined8 uVar8;
  longlong lVar9;
  uint uVar10;
  
  uVar10 = 0;
  lVar7 = MmMapIoSpace(*param_1 + 0x300,0x100,0);
  if (lVar7 == 0) {
    uVar8 = 0xc0000001;
  }
  else {
    uVar1 = *(uint *)(lVar7 + 0x20);
    uVar2 = *(undefined4 *)(lVar7 + 0xe0);
    uVar3 = *(undefined4 *)(lVar7 + 0x80);
    *(undefined4 *)(lVar7 + 0x80) = 0xffffffff;
    iVar4 = *(int *)(lVar7 + 0x90);
    *(undefined4 *)(lVar7 + 0xe0) = 2;
    *(uint *)(lVar7 + 0x20) = uVar1 & 0xfffdffff;
    iVar5 = in((short)param_1[4]);
    if (param_1[1] != 0) {
      do {
        iVar6 = in((short)param_1[4]);
        uVar10 = iVar6 - iVar5 & 0xffffff;
      } while (uVar10 < (uint)param_1[1]);
    }
    iVar5 = *(int *)(lVar7 + 0x90);
    param_1[1] = uVar10;
    lVar9 = (ulonglong)(uint)(iVar4 - iVar5) << 3;
    param_1[3] = (int)lVar9;
    param_1[2] = (int)((ulonglong)lVar9 >> 0x20);
    *(uint *)(lVar7 + 0x20) = uVar1;
    *(undefined4 *)(lVar7 + 0xe0) = uVar2;
    *(undefined4 *)(lVar7 + 0x80) = uVar3;
    MmUnmapIoSpace(lVar7,0x100);
    uVar8 = 0;
  }
  return uVar8;
}

