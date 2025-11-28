// Function: FUN_1400023f8
// Address: 1400023f8
// Decompiled by Ghidra


void FUN_1400023f8(longlong param_1)

{
  longlong lVar1;
  undefined8 local_res8 [4];
  
  local_res8[0] = 0xfffffffffff0bdc0;
  KeSetPriorityThread(SystemReserved1[0xf],0x10);
  for (lVar1 = *(longlong *)(param_1 + 8); lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x10)) {
    FUN_140002068(lVar1);
  }
  while (DAT_140005118 != 0) {
    KeDelayExecutionThread(0,0,local_res8);
  }
  return;
}

