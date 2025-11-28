// Function: FUN_00011ad4
// Address: 00011ad4
// Decompiled by Ghidra


void FUN_00011ad4(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  
  puVar1 = *(undefined8 **)(param_1 + 0x40);
  FUN_00012960(*(undefined8 **)(param_2 + 0xb8) + -9,*(undefined8 **)(param_2 + 0xb8),0x48);
  lVar2 = *(longlong *)(param_2 + 0xb8);
  *(undefined1 **)(lVar2 + -0x10) = &LAB_00011a7c;
  *(longlong *)(lVar2 + -8) = param_1;
  *(undefined1 *)(lVar2 + -0x45) = 0xe0;
                    /* WARNING: Could not recover jumptable at 0x00011b24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IofCallDriver(*puVar1,param_2);
  return;
}

