// Function: FUN_140003468
// Address: 140003468
// Decompiled by Ghidra


undefined8 FUN_140003468(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 local_res10 [3];
  
  uVar2 = 0;
  local_res10[0] = 0;
  iVar1 = PsLookupProcessByProcessId(param_1,local_res10);
  if (-1 < iVar1) {
    uVar2 = PsGetProcessImageFileName(local_res10[0]);
    ObfDereferenceObject(local_res10[0]);
  }
  return uVar2;
}

