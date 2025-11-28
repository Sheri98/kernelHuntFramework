// Function: FUN_140132567
// Address: 140132567
// Decompiled by Ghidra


/* WARNING: Variable defined which should be unmapped: param_6 */

void FUN_140132567(undefined8 param_1,undefined8 param_2,ulonglong param_3,undefined8 param_4,
                  undefined8 param_5,uint *param_6)

{
  int iVar1;
  longlong unaff_RBP;
  undefined4 unaff_ESI;
  uint *unaff_R12;
  
  iVar1 = FUN_140002134();
  if (((iVar1 == 0) || (param_6 == (uint *)0x0)) || (*(int *)(unaff_RBP + 0x1f8) == 0)) {
    *(undefined4 *)(unaff_RBP + 0x1f8) = unaff_ESI;
    param_6 = unaff_R12;
  }
  FUN_14000d0a3(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}

