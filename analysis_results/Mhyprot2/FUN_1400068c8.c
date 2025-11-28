// Function: FUN_1400068c8
// Address: 1400068c8
// Decompiled by Ghidra


longlong FUN_1400068c8(longlong param_1)

{
  char cVar1;
  int iVar2;
  longlong *plVar3;
  undefined8 local_res10;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  local_res10 = 0;
  iVar2 = ObOpenObjectByPointer
                    (param_1,0,0,0x1fffff,*(undefined8 *)PsThreadType_exref,0,&local_res10);
  if (iVar2 == 0) {
    NtQueryInformationThread(local_res10,9,local_res18,8,0);
    ZwClose(local_res10);
  }
  if ((local_res18[0] == 0) && (DAT_14000a730 != 0)) {
    plVar3 = (longlong *)(param_1 + DAT_14000a730);
    cVar1 = MmIsAddressValid(plVar3);
    if (cVar1 == '\x01') {
      local_res18[0] = *plVar3;
    }
  }
  return local_res18[0];
}

