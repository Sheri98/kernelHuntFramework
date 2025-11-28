// Function: FUN_140001320
// Address: 140001320
// Decompiled by Ghidra


longlong FUN_140001320(longlong param_1,undefined8 *param_2,longlong param_3)

{
  char cVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  if ((((param_3 != 0) && (param_1 != 0)) && (param_2 != (undefined8 *)0x0)) &&
     ((cVar1 = MmIsAddressValid(param_2), cVar1 != '\0' &&
      (lVar2 = MmCreateMdl(0,param_1,param_3), lVar2 != 0)))) {
    MmBuildMdlForNonPagedPool(lVar2);
    if ((*(ushort *)(lVar2 + 10) & 1) == 0) {
      *(ushort *)(lVar2 + 10) = *(ushort *)(lVar2 + 10) | 1;
    }
    MmProbeAndLockPages(lVar2,0);
    uVar3 = MmMapLockedPages(lVar2,0);
    *param_2 = uVar3;
    return lVar2;
  }
  return 0;
}

