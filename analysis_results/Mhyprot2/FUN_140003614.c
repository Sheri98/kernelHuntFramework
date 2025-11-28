// Function: FUN_140003614
// Address: 140003614
// Decompiled by Ghidra


ulonglong FUN_140003614(undefined4 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong local_res10;
  
  local_res10 = 0;
  iVar1 = PsLookupProcessByProcessId(param_1,&local_res10,param_3,param_4,1);
  if (local_res10 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    lVar3 = PsGetProcessWow64Process();
    uVar2 = (ulonglong)(lVar3 == 0);
    if ((local_res10 != 0) && (-1 < iVar1)) {
      ObfDereferenceObject();
    }
  }
  return uVar2;
}

