// Function: FUN_1400050d0
// Address: 1400050d0
// Decompiled by Ghidra


undefined8 FUN_1400050d0(undefined8 param_1,int *param_2)

{
  int iVar1;
  longlong lVar2;
  char *_Str1;
  uint *puVar3;
  longlong local_res10 [3];
  
  if ((((*(longlong *)(param_2 + 4) == *(longlong *)PsThreadType_exref) && ((param_2[1] & 1U) == 0))
      && (DAT_14000a688 != 0)) && (*param_2 == 1)) {
    lVar2 = IoThreadToProcess(*(undefined8 *)(param_2 + 2));
    local_res10[0] = 0;
    iVar1 = PsLookupProcessByProcessId(DAT_14000a688,local_res10);
    if (-1 < iVar1) {
      ObfDereferenceObject(local_res10[0]);
    }
    if ((local_res10[0] != 0) && (lVar2 == local_res10[0])) {
      puVar3 = *(uint **)(param_2 + 8);
      if ((puVar3[1] & 1) != 0) {
        *puVar3 = *puVar3 & 0xfffffffe;
        puVar3 = *(uint **)(param_2 + 8);
      }
      if ((puVar3[1] & 2) != 0) {
        lVar2 = IoGetCurrentProcess();
        if (local_res10[0] != lVar2) {
          _Str1 = (char *)PsGetProcessImageFileName(lVar2);
          iVar1 = strcmp(_Str1,"csrss.exe");
          if (iVar1 != 0) {
            **(uint **)(param_2 + 8) = **(uint **)(param_2 + 8) & 0xfffffffd;
          }
        }
      }
    }
  }
  return 0;
}

