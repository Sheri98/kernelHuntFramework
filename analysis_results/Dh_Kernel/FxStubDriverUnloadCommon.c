// Function: FxStubDriverUnloadCommon
// Address: 140001000
// Decompiled by Ghidra


/* Library Function - Single Match
    void __cdecl FxStubDriverUnloadCommon(void)
   
   Library: Visual Studio 2019 Release */

void __cdecl FxStubDriverUnloadCommon(void)

{
  FxStubUnbindClasses((_WDF_BIND_INFO *)&DAT_140004020);
  WdfVersionUnbind(&DAT_140004d48,&DAT_140004020,DAT_140004d68);
  return;
}

