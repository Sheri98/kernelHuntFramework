// Function: FxStubDriverUnloadCommon
// Address: 140001030
// Decompiled by Ghidra


void __cdecl FxStubDriverUnloadCommon(void)

{
  FxStubUnbindClasses((_WDF_BIND_INFO *)&DAT_14000a020);
  WdfVersionUnbind(&DAT_14000b3b8,&DAT_14000a020,DAT_14000b3d8);
  return;
}

