// Function: FUN_140006834
// Address: 140006834
// Decompiled by Ghidra


undefined8 FUN_140006834(undefined4 param_1)

{
  int iVar1;
  undefined8 uVar2;
  longlong local_res10 [3];
  
  local_res10[0] = 0;
  iVar1 = PsLookupThreadByThreadId(param_1,local_res10);
  if (iVar1 < 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_14000687c(local_res10[0]);
    if (local_res10[0] != 0) {
      ObfDereferenceObject();
    }
  }
  return uVar2;
}

