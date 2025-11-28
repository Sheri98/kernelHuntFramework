// Function: FUN_140001db4
// Address: 140001db4
// Decompiled by Ghidra


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_140001db4(longlong param_1,longlong param_2)

{
  uint uVar1;
  ulonglong uVar2;
  
  if (param_1 == 0) {
    uVar2 = FUN_14000104c(0,param_2);
  }
  else {
    _DAT_1400040e8 = &DAT_140004120;
    _DAT_1400040e0 = 0x2080000;
    _DAT_140004108 = param_1;
    RtlCopyUnicodeString(&DAT_1400040e0);
    uVar2 = WdfVersionBind(param_1,&DAT_1400040e0,&DAT_140004020,&DAT_1400040f8);
    if (-1 < (int)uVar2) {
      _DAT_140004110 = *(undefined1 **)(DAT_140004100 + 0x648);
      uVar1 = FxStubBindClasses((_WDF_BIND_INFO *)&DAT_140004020);
      if (((-1 < (int)uVar1) && (uVar1 = FxStubInitTypes(), -1 < (int)uVar1)) &&
         (uVar1 = FUN_14000104c(param_1,param_2), -1 < (int)uVar1)) {
        if (*(char *)(DAT_1400040f8 + 0x30) == '\0') {
          if ((*(uint *)(DAT_1400040f8 + 8) & 2) != 0) {
            _DAT_140004110 = &LAB_140001edc;
          }
        }
        else {
          if (*(longlong *)(param_1 + 0x68) != 0) {
            DAT_1400040f0 = *(longlong *)(param_1 + 0x68);
          }
          *(code **)(param_1 + 0x68) = FxStubDriverUnload;
        }
        return 0;
      }
      FxStubDriverUnloadCommon();
      uVar2 = (ulonglong)uVar1;
    }
  }
  return uVar2;
}

