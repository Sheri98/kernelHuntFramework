// Function: FxStubDriverUnload
// Address: 140001038
// Decompiled by Ghidra


/* Library Function - Single Match
    FxStubDriverUnload
   
   Library: Visual Studio 2019 Release */

void FxStubDriverUnload(void)

{
  if ((DAT_140004d58 != (code *)0x0) && (DAT_140004d58 != FxStubDriverUnload)) {
    (*DAT_140004d58)();
  }
  FxStubDriverUnloadCommon();
  return;
}

