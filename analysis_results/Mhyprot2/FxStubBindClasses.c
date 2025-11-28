// Function: FxStubBindClasses
// Address: 140001250
// Decompiled by Ghidra


/* Library Function - Single Match
    long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64)
   
   Library: Visual Studio 2019 Release */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = &DAT_14000a070;
  while( true ) {
    if ((int *)0x14000a06f < piVar2) {
      return iVar1;
    }
    if (*piVar2 != 0x50) break;
    PTR_DAT_14000a078 = (undefined *)piVar2;
    if (*(code **)(piVar2 + 0xe) == (code *)0x0) {
      iVar1 = WdfVersionBindClass(param_1,DAT_14000b3d8,piVar2);
    }
    else {
      iVar1 = (**(code **)(piVar2 + 0xe))(WdfVersionBindClass,param_1,DAT_14000b3d8,piVar2);
    }
    if (iVar1 < 0) {
      return iVar1;
    }
    piVar2 = piVar2 + 0x14;
  }
  return -0x3ffffffc;
}

