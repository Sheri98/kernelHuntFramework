// Function: FUN_00012700
// Address: 00012700
// Decompiled by Ghidra


void FUN_00012700(undefined4 *param_1,undefined4 param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined4 local_res8;
  undefined4 uStackX_c;
  longlong local_res18;
  undefined4 local_res20 [2];
  undefined8 local_28 [3];
  
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  uStackX_c = 0;
  local_res8 = param_2;
  lVar1 = MmAllocateContiguousMemory(*param_1,param_2);
  if (lVar1 != 0) {
    *(longlong *)(param_1 + 6) = lVar1;
    lVar2 = IoAllocateMdl(lVar1,*param_1,0,0,0);
    if ((lVar2 != 0) &&
       (uVar3 = FUN_00012654(1,(longlong *)local_res20,local_28,&local_res18,
                             (undefined8 *)&local_res8,lVar2), (char)uVar3 != '\0')) {
      *(longlong *)(param_1 + 6) = lVar1;
      *(longlong *)(param_1 + 4) = local_res18;
      param_1[3] = local_res20[0];
      param_1[2] = local_res8;
      return;
    }
    MmFreeContiguousMemory(lVar1);
  }
  return;
}

