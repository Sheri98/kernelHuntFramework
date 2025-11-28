// Function: FUN_1400043c0
// Address: 1400043c0
// Decompiled by Ghidra


undefined8 FUN_1400043c0(longlong param_1,undefined8 *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_1 != 0) {
    iVar1 = ObReferenceObjectByHandle
                      (param_1,2,*(undefined8 *)ExEventObjectType_exref,1,&DAT_14000a128,0);
    if ((-1 < iVar1) && (DAT_14000a128 != 0)) {
      if (DAT_14000a120 != 0) {
LAB_14000445c:
        uVar2 = MmMapLockedPages(DAT_14000a120,1);
        *param_2 = uVar2;
        return 0;
      }
      DAT_14000a130 = ExAllocatePool(0,0x440);
      if (DAT_14000a130 != 0) {
        DAT_14000a120 = IoAllocateMdl(DAT_14000a130,0x440,0,0,0);
        if (DAT_14000a120 != 0) {
          MmBuildMdlForNonPagedPool(DAT_14000a120);
          goto LAB_14000445c;
        }
      }
    }
  }
  return 0xc0000001;
}

