// Function: FUN_140006408
// Address: 140006408
// Decompiled by Ghidra


undefined8 FUN_140006408(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  char *pcVar1;
  undefined8 uVar2;
  undefined *puVar3;
  longlong unaff_RBP;
  undefined4 uVar4;
  undefined4 in_register_00000084;
  undefined8 in_R9;
  uint *unaff_R12;
  char cVar5;
  undefined8 in_stack_ffffffffffffffe8;
  uint *in_stack_fffffffffffffff0;
  
  cVar5 = &stack0x00000000 == (undefined1 *)0x28;
  puVar3 = &DAT_140007c90;
  uVar4 = param_3;
  FUN_140108673();
  FUN_1400896ed(puVar3,param_2,CONCAT44(in_register_00000084,uVar4));
  pcVar1 = (char *)FUN_14003609e();
  if (puVar3 + -1 == (undefined *)0x0 || cVar5 == '\0') {
    return 0xe859b14d;
  }
  *pcVar1 = *pcVar1 + (char)pcVar1;
  if (*pcVar1 == '\0') {
    *(undefined4 *)(unaff_RBP + 0x1f8) = param_3;
    in_stack_fffffffffffffff0 = unaff_R12;
  }
  uVar2 = FUN_14000d0a3(puVar3 + -1,param_2,CONCAT44(in_register_00000084,uVar4),in_R9,
                        in_stack_ffffffffffffffe8,in_stack_fffffffffffffff0);
  return uVar2;
}

