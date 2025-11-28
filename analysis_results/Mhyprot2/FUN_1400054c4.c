// Function: FUN_1400054c4
// Address: 1400054c4
// Decompiled by Ghidra


ulonglong FUN_1400054c4(undefined4 param_1,longlong param_2,undefined4 param_3)

{
  ulonglong in_RAX;
  longlong *plVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  code *pcVar4;
  
  if (param_2 == 0) {
LAB_140005553:
    uVar3 = in_RAX & 0xffffffffffffff00;
  }
  else {
    if (DAT_14000a6d0 == 0) {
      in_RAX = FUN_140005954();
      DAT_14000a6d0 = in_RAX;
      if (in_RAX == 0) goto LAB_140005553;
    }
    plVar1 = (longlong *)ExAllocatePool(1);
    pcVar4 = FUN_140005320;
    *(undefined4 *)(plVar1 + 1) = param_1;
    *plVar1 = param_2;
    *(undefined4 *)((longlong)plVar1 + 0xc) = param_3;
    if (DAT_14000a748 != 0x3d) {
      pcVar4 = FUN_140005470;
    }
    ExEnumHandleTable(DAT_14000a6d0,pcVar4,plVar1,0);
    uVar2 = ExFreePoolWithTag(plVar1,0);
    uVar3 = CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
  }
  return uVar3;
}

