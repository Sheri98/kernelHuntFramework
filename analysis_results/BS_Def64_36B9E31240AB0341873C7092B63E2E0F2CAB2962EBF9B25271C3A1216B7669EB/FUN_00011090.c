// Function: FUN_00011090
// Address: 00011090
// Decompiled by Ghidra


undefined8 FUN_00011090(uint param_1)

{
  ulonglong uVar1;
  
  uVar1 = MmAllocateContiguousMemory(param_1,0xffffffffffffffff);
  DAT_00014020 = uVar1;
  if (uVar1 != 0) {
    DAT_00014038 = MmGetPhysicalAddress(uVar1);
    uVar1 = (ulonglong)param_1;
    DAT_00014030 = IoAllocateMdl(DAT_00014020,uVar1,0,0,0);
    if (DAT_00014030 != 0) {
      MmBuildMdlForNonPagedPool(DAT_00014030);
      DAT_00014028 = MmMapLockedPages(DAT_00014030,uVar1 & 0xffffffffffffff00);
      return CONCAT71((int7)((ulonglong)DAT_00014028 >> 8),1);
    }
    uVar1 = MmFreeContiguousMemory(DAT_00014020);
    DAT_00014020 = 0;
  }
  return uVar1 & 0xffffffffffffff00;
}

