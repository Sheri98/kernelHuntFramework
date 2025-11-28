// Function: FxStubUnbindClasses
// Address: 1400011b0
// Decompiled by Ghidra


/* Library Function - Single Match
    void __cdecl FxStubUnbindClasses(struct _WDF_BIND_INFO * __ptr64)
   
   Library: Visual Studio 2019 Release */

void __cdecl FxStubUnbindClasses(_WDF_BIND_INFO *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = &DAT_140004060;
  if ((PTR_DAT_140004068 != &DAT_140004050) && ((undefined *)0x14000405f < PTR_DAT_140004068)) {
    do {
      if (*(code **)(puVar1 + 0x10) == (code *)0x0) {
        WdfVersionUnbindClass(param_1,DAT_140004d68,puVar1);
      }
      else {
        (**(code **)(puVar1 + 0x10))(WdfVersionUnbindClass,param_1,DAT_140004d68,puVar1);
      }
      puVar1 = puVar1 + 0x14;
    } while (puVar1 <= PTR_DAT_140004068);
  }
  return;
}

