// Function: FUN_140003fa8
// Address: 140003fa8
// Decompiled by Ghidra


undefined4 FUN_140003fa8(undefined8 param_1,undefined8 param_2,uint param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined8 *_Dst;
  undefined4 uVar4;
  bool bVar5;
  bool bVar6;
  ulonglong uVar7;
  undefined1 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  
  uVar4 = 0xc0000001;
  uVar9 = 0;
  uVar10 = 0;
  bVar5 = false;
  bVar6 = false;
  uVar8 = 0;
  uVar11 = 0;
  uVar7 = 0;
  lVar1 = IoAllocateMdl(param_1,param_3,0,0,0);
  if (lVar1 != 0) {
    lVar3 = lVar1;
    MmBuildMdlForNonPagedPool(lVar1);
    if ((*(byte *)(lVar1 + 10) & 5) == 0) {
      puVar2 = (undefined8 *)
               MmMapLockedPagesSpecifyCache
                         (lVar1,0,1,0,uVar7 & 0xffffffff00000000,0x10,uVar8,uVar9,uVar10,uVar11,
                          lVar3);
      bVar5 = puVar2 != (undefined8 *)0x0;
    }
    else {
      puVar2 = *(undefined8 **)(lVar1 + 0x18);
    }
    if (puVar2 != (undefined8 *)0x0) {
      uVar7 = 0;
      lVar3 = IoAllocateMdl(param_2,param_3,0,0,0);
      if (lVar3 != 0) {
        MmProbeAndLockPages(lVar3,0,1);
        if ((*(byte *)(lVar3 + 10) & 5) == 0) {
          _Dst = (undefined8 *)
                 MmMapLockedPagesSpecifyCache(lVar3,0,1,0,uVar7 & 0xffffffff00000000,0x10,1);
          bVar6 = _Dst != (undefined8 *)0x0;
        }
        else {
          _Dst = *(undefined8 **)(lVar3 + 0x18);
        }
        if (_Dst != (undefined8 *)0x0) {
          memset(_Dst,0,(ulonglong)param_3);
          FUN_1400075c0(_Dst,puVar2,(ulonglong)param_3);
          uVar4 = 0;
        }
        if (bVar5) {
          MmUnmapLockedPages(puVar2,lVar1);
        }
        if (bVar6) {
          MmUnmapLockedPages(_Dst,lVar3);
        }
        MmUnlockPages(lVar3);
        IoFreeMdl(lVar3);
      }
    }
    IoFreeMdl(lVar1);
  }
  return uVar4;
}

