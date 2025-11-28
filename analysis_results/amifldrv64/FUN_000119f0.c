// Function: FUN_000119f0
// Address: 000119f0
// Decompiled by Ghidra


undefined8 FUN_000119f0(undefined4 *param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  uint local_18;
  int local_14 [3];
  
  local_18 = 0;
  local_14[0] = 0;
  if (param_1 == (undefined4 *)0x0) {
    return 0xc0000001;
  }
  local_14[2] = 0;
  local_14[1] = 0x1fffffff;
  lVar4 = MmAllocateContiguousMemory(*param_1,0x1fffffff);
  if ((lVar4 != 0) && (cVar1 = MmIsAddressValid(lVar4), cVar1 != '\0')) {
    uVar2 = MmGetPhysicalAddress(lVar4);
    param_1[2] = uVar2;
    *param_2 = uVar2;
    uVar6 = 0;
    lVar5 = IoAllocateMdl(lVar4,*param_1,0,0,0);
    if (lVar5 != 0) {
      MmBuildMdlForNonPagedPool(lVar5);
      PsGetVersion(&local_18,local_14,0,0);
      if ((local_18 < 6) || (local_14[0] == 0)) {
        iVar3 = MmMapLockedPages(lVar5,1);
      }
      else {
        iVar3 = MmMapLockedPagesSpecifyCache(lVar5,1,1,0,uVar6 & 0xffffffff00000000,0x10);
      }
      if (iVar3 != 0) {
        param_1[1] = iVar3;
        param_1[4] = (int)lVar5;
        param_1[3] = (int)lVar4;
        *(longlong *)(param_2 + 6) = lVar5;
        *(longlong *)(param_2 + 4) = lVar4;
        *(longlong *)(param_2 + 2) = (longlong)iVar3;
        return 0;
      }
      IoFreeMdl(lVar5);
    }
    MmFreeContiguousMemory(lVar4);
  }
  return 0xc0000001;
}

