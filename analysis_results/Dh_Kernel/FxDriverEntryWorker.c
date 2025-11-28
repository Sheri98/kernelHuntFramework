// Function: FxDriverEntryWorker
// Address: 140001060
// Decompiled by Ghidra


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    FxDriverEntryWorker
   
   Library: Visual Studio 2019 Release */

ulonglong FxDriverEntryWorker(longlong param_1,longlong param_2)

{
  uint uVar1;
  ulonglong uVar2;
  
  if (param_1 == 0) {
    uVar2 = FUN_14000136c(0,param_2);
  }
  else {
    _DAT_140004d4a = 0x208;
    _DAT_140004d48 = 0;
    _DAT_140004d50 = &DAT_140004d80;
    _DAT_140004d70 = param_1;
    RtlCopyUnicodeString(&DAT_140004d48);
    uVar2 = WdfVersionBind(param_1,&DAT_140004d48,&DAT_140004020,&DAT_140004d68);
    if (-1 < (int)uVar2) {
      uVar1 = FxStubBindClasses((_WDF_BIND_INFO *)&DAT_140004020);
      if (-1 < (int)uVar1) {
        FxStubInitTypes();
        uVar1 = FUN_14000136c(param_1,param_2);
        if (-1 < (int)uVar1) {
          if (*(char *)(DAT_140004d68 + 0x30) == '\0') {
            if ((*(byte *)(DAT_140004d68 + 8) & 2) != 0) {
              _DAT_140004d60 = DAT_140004728;
              DAT_140004728 = &LAB_140001030;
            }
          }
          else {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_140004d58 = *(undefined8 *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
      }
      FxStubDriverUnloadCommon();
      uVar2 = (ulonglong)uVar1;
    }
  }
  return uVar2;
}

