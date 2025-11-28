// Function: FxStubDriverUnload
// Address: 140001040
// Decompiled by Ghidra


/* Library Function - Single Match
    FxStubDriverUnload
   
   Library: Visual Studio 2019 Release */

void FxStubDriverUnload(void)

{
  if ((DAT_14000b3c8 != (code *)0x0) && (DAT_14000b3c8 != FxStubDriverUnload)) {
    (*DAT_14000b3c8)();
  }
  FxStubDriverUnloadCommon();
  return;
}

