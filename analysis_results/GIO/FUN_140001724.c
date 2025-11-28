// Function: FUN_140001724
// Address: 140001724
// Decompiled by Ghidra


void FUN_140001724(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong local_res18 [2];
  
  uVar2 = FUN_14000197c(L"\\Device\\GIO",50000,param_1,local_res18);
  if (-1 < (int)uVar2) {
    lVar1 = *(longlong *)(local_res18[0] + 0x40);
    *(undefined8 *)(lVar1 + 0x18) = 0;
    *(longlong *)(lVar1 + 0x10) = local_res18[0];
    *(code **)(param_1 + 0x70) = FUN_140001a20;
    *(code **)(param_1 + 0x80) = FUN_140001a20;
    *(code **)(param_1 + 0xe0) = FUN_140001a20;
    *(code **)(param_1 + 0x68) = FUN_1400022c4;
  }
  return;
}

