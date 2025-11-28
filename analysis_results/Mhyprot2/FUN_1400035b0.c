// Function: FUN_1400035b0
// Address: 1400035b0
// Decompiled by Ghidra


bool FUN_1400035b0(uint param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong local_res10 [3];
  
  local_res10[0] = 0;
  iVar1 = PsLookupProcessByProcessId(param_1,local_res10,param_3,param_4,0xffffffff);
  if (iVar1 < 0) {
    local_res10[0] = FUN_1400034a8(param_1);
  }
  else {
    ObfDereferenceObject(local_res10[0]);
  }
  return local_res10[0] != 0;
}

