// Function: FUN_1400063a8
// Address: 1400063a8
// Decompiled by Ghidra


undefined8 FUN_1400063a8(void *param_1,ulonglong param_2,uint param_3)

{
  undefined8 uVar1;
  
  if (((param_2 == 0) || (param_3 == 0)) || (param_2 < *(ulonglong *)MmHighestUserAddress_exref)) {
    uVar1 = 0xffffffff;
  }
  else {
    memset(param_1,0,(ulonglong)param_3);
    FUN_140003dd8(param_2,(longlong)param_1,param_3);
    uVar1 = 0;
  }
  return uVar1;
}

