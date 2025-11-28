// Function: thunk_FUN_1400036b0
// Address: 1400036a8
// Decompiled by Ghidra


void thunk_FUN_1400036b0(int param_1)

{
  int iVar1;
  int iVar2;
  longlong lStackX_10;
  undefined8 uStackX_18;
  
  if (param_1 != 0) {
    uStackX_18 = 0;
    lStackX_10 = 0;
    iVar1 = PsLookupProcessByProcessId(param_1,&lStackX_10);
    if (lStackX_10 != 0) {
      iVar2 = ObOpenObjectByPointer(lStackX_10,0,0,0,0,0,&uStackX_18);
      if (iVar2 == 0) {
        ZwTerminateProcess(uStackX_18,0);
        ZwClose(uStackX_18);
        if ((-1 < iVar1) && (lStackX_10 != 0)) {
          ObfDereferenceObject();
        }
      }
      else if (-1 < iVar1) {
        ObfDereferenceObject(lStackX_10);
      }
    }
  }
  return;
}

