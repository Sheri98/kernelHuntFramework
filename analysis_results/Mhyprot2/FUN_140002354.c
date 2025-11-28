// Function: FUN_140002354
// Address: 140002354
// Decompiled by Ghidra


undefined8 FUN_140002354(undefined4 param_1)

{
  int iVar1;
  undefined8 local_res10 [3];
  
  local_res10[0] = 0;
  iVar1 = PsLookupProcessByProcessId(param_1,local_res10);
  if (-1 < iVar1) {
    ObfDereferenceObject(local_res10[0]);
  }
  return local_res10[0];
}

