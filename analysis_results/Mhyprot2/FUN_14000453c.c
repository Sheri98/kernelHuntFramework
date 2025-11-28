// Function: FUN_14000453c
// Address: 14000453c
// Decompiled by Ghidra


undefined8 FUN_14000453c(longlong param_1,undefined8 *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_1 != 0) {
    iVar1 = ObReferenceObjectByHandle
                      (param_1,2,*(undefined8 *)ExEventObjectType_exref,1,&DAT_14000a3b0,0);
    if ((-1 < iVar1) && (DAT_14000a3b0 != 0)) {
      if (DAT_14000a3a8 != 0) {
LAB_1400045d7:
        uVar2 = MmMapLockedPages(DAT_14000a3a8,1);
        *param_2 = uVar2;
        return 0;
      }
      DAT_14000a3b8 = ExAllocatePool(0,8);
      if (DAT_14000a3b8 != 0) {
        DAT_14000a3a8 = IoAllocateMdl(DAT_14000a3b8,8,0,0,0);
        if (DAT_14000a3a8 != 0) {
          MmBuildMdlForNonPagedPool(DAT_14000a3a8);
          goto LAB_1400045d7;
        }
      }
    }
  }
  return 0xc0000001;
}

