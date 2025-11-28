// Function: FUN_1400026d0
// Address: 1400026d0
// Decompiled by Ghidra


int FUN_1400026d0(undefined4 param_1,longlong param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  longlong local_res20;
  
  local_res20 = 0;
  iVar1 = PsLookupProcessByProcessId(param_1,&local_res20);
  if (local_res20 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_1400027d4(local_res20,param_2,param_3);
    if ((local_res20 != 0) && (-1 < iVar1)) {
      ObfDereferenceObject();
    }
  }
  return iVar2;
}

