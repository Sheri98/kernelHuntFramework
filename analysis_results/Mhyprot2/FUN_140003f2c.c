// Function: FUN_140003f2c
// Address: 140003f2c
// Decompiled by Ghidra


undefined4 FUN_140003f2c(int *param_1,undefined8 param_2)

{
  int iVar1;
  undefined4 uVar2;
  longlong local_res8;
  
  local_res8 = 0;
  iVar1 = PsLookupProcessByProcessId(param_1[2],&local_res8);
  if (local_res8 == 0) {
    uVar2 = 0xc0000001;
  }
  else {
    uVar2 = FUN_140003eb8(local_res8,param_1,param_2);
    if (-1 < iVar1) {
      ObfDereferenceObject(local_res8);
    }
  }
  return uVar2;
}

