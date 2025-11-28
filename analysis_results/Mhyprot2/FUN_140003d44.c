// Function: FUN_140003d44
// Address: 140003d44
// Decompiled by Ghidra


undefined8 FUN_140003d44(undefined4 param_1)

{
  int iVar1;
  undefined8 uVar2;
  longlong local_res10 [3];
  
  local_res10[0] = 0;
  iVar1 = PsLookupProcessByProcessId(param_1,local_res10);
  if (iVar1 < 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_140003d8c(local_res10[0]);
    if (local_res10[0] != 0) {
      ObfDereferenceObject();
    }
  }
  return uVar2;
}

