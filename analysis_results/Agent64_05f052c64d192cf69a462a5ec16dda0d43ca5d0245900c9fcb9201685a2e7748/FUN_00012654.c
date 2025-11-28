// Function: FUN_00012654
// Address: 00012654
// Decompiled by Ghidra


undefined8
FUN_00012654(int param_1,longlong *param_2,undefined8 *param_3,longlong *param_4,undefined8 *param_5
            ,longlong param_6)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  
  MmBuildMdlForNonPagedPool(param_6);
  if (param_1 != 0) {
    lVar1 = MmMapLockedPagesSpecifyCache(param_6,1,1,0,0,0x10);
    if (lVar1 == 0) {
      uVar2 = IoFreeMdl(param_6);
      return uVar2 & 0xffffffffffffff00;
    }
    *param_2 = lVar1;
  }
  if ((*(byte *)(param_6 + 10) & 5) == 0) {
    uVar3 = MmMapLockedPages(param_6,0);
  }
  else {
    uVar3 = *(undefined8 *)(param_6 + 0x18);
  }
  *param_3 = uVar3;
  uVar3 = MmGetPhysicalAddress(uVar3);
  *param_4 = param_6;
  *param_5 = uVar3;
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
}

