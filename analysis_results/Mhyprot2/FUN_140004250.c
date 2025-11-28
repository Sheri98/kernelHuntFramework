// Function: FUN_140004250
// Address: 140004250
// Decompiled by Ghidra


undefined8 FUN_140004250(longlong param_1,undefined8 *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_1 != 0) {
    iVar1 = ObReferenceObjectByHandle
                      (param_1,2,*(undefined8 *)ExEventObjectType_exref,1,&DAT_14000a380,0);
    if ((-1 < iVar1) && (DAT_14000a380 != 0)) {
      if (DAT_14000a378 != 0) {
LAB_1400042ec:
        uVar2 = MmMapLockedPages(DAT_14000a378,1);
        *param_2 = uVar2;
        return 0;
      }
      DAT_14000a388 = ExAllocatePool(0,0x20c);
      if (DAT_14000a388 != 0) {
        DAT_14000a378 = IoAllocateMdl(DAT_14000a388,0x20c,0,0,0);
        if (DAT_14000a378 != 0) {
          MmBuildMdlForNonPagedPool(DAT_14000a378);
          goto LAB_1400042ec;
        }
      }
    }
  }
  return 0xc0000001;
}

