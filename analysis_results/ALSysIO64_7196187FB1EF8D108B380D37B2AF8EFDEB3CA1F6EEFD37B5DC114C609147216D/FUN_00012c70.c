// Function: FUN_00012c70
// Address: 00012c70
// Decompiled by Ghidra


ulonglong FUN_00012c70(ushort param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  longlong lVar10;
  undefined2 uVar11;
  int local_res18;
  
  iVar4 = FUN_00013230();
  DbgPrint("misc 25");
  if (param_1 < 2) {
    do {
      bVar3 = false;
      if (iVar4 == 0) {
        return 1;
      }
      uVar9 = FUN_00012e30();
      if (uVar9 == 0) {
        return 2;
      }
      local_res18 = (int)uVar9;
      lVar10 = MmMapIoSpace(local_res18 + 0x300,0x100,0);
      uVar1 = *(uint *)(lVar10 + 0x20);
      *(uint *)(lVar10 + 0x20) = uVar1 & 0xfffdffff;
      uVar2 = *(undefined4 *)(lVar10 + 0xe0);
      *(undefined4 *)(lVar10 + 0xe0) = 0xb;
      iVar5 = FUN_00011c90();
      if (iVar5 == 0) {
        *(undefined4 *)(lVar10 + 0x80) = 0xffffffff;
      }
      uVar11 = (undefined2)iVar4;
      uVar6 = in(uVar11);
      uVar6 = uVar6 & 0xffffff;
      do {
        uVar7 = in(uVar11);
        uVar7 = uVar7 & 0xffffff;
        if (uVar7 < uVar6) {
          uVar7 = uVar7 + 0xffffff;
        }
      } while (uVar7 - uVar6 < (uint)(0x369e99 / (ulonglong)param_2));
      uVar7 = *(uint *)(lVar10 + 0x90);
      uVar8 = in(uVar11);
      uVar8 = uVar8 & 0xffffff;
      if (uVar8 < uVar6) {
        uVar8 = uVar8 + 0xffffff;
      }
      uVar9 = (ulonglong)(*(uint *)(lVar10 + 0x90) - uVar7);
      if ((uVar7 == 0) || (*(uint *)(lVar10 + 0x90) < uVar7)) {
        bVar3 = true;
      }
      else {
        uVar9 = (ulonglong)
                ((double)uVar9 / ((double)(uVar8 - uVar6) / (double)(0x369e99 / (ulonglong)param_2))
                );
      }
      *(undefined4 *)(lVar10 + 0xe0) = uVar2;
      *(uint *)(lVar10 + 0x20) = uVar1;
      MmUnmapIoSpace(lVar10,0x100);
      if (!bVar3) {
        return uVar9 & 0xffffffff;
      }
      param_1 = param_1 + 1;
      iVar4 = FUN_00013230();
      DbgPrint("misc 25");
    } while (param_1 < 2);
  }
  return 0;
}

