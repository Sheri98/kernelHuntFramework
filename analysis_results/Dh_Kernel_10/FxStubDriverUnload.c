// Function: FxStubDriverUnload
// Address: 140001ee4
// Decompiled by Ghidra


/* Library Function - Single Match
    FxStubDriverUnload
   
   Library: Visual Studio 2019 Release */

void FxStubDriverUnload(void)

{
  if ((DAT_1400040f0 != (code *)0x0) && (DAT_1400040f0 != FxStubDriverUnload)) {
    (*DAT_1400040f0)();
  }
  FxStubDriverUnloadCommon();
  return;
}

