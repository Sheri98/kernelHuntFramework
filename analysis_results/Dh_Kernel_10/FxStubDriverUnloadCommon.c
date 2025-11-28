// Function: FxStubDriverUnloadCommon
// Address: 140001d58
// Decompiled by Ghidra


/* Library Function - Single Match
    void __cdecl FxStubDriverUnloadCommon(void)
   
   Library: Visual Studio 2019 Release */

void __cdecl FxStubDriverUnloadCommon(void)

{
  FxStubUnbindClasses((_WDF_BIND_INFO *)&DAT_140004020);
  WdfVersionUnbind(&DAT_1400040e0,&DAT_140004020,DAT_1400040f8);
  return;
}

