// Function: FUN_1400036b0
// Address: 1400036b0
// Decompiled by Ghidra


void FUN_1400036b0(int param_1)

{
  int iVar1;
  int iVar2;
  longlong local_res10;
  undefined8 local_res18;
  
  if (param_1 != 0) {
    local_res18 = 0;
    local_res10 = 0;
    iVar1 = PsLookupProcessByProcessId(param_1,&local_res10);
    if (local_res10 != 0) {
      iVar2 = ObOpenObjectByPointer(local_res10,0,0,0,0,0,&local_res18);
      if (iVar2 == 0) {
        ZwTerminateProcess(local_res18,0);
        ZwClose(local_res18);
        if ((-1 < iVar1) && (local_res10 != 0)) {
          ObfDereferenceObject();
        }
      }
      else if (-1 < iVar1) {
        ObfDereferenceObject(local_res10);
      }
    }
  }
  return;
}

