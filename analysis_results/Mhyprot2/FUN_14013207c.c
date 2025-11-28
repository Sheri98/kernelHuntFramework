// Function: FUN_14013207c
// Address: 14013207c
// Decompiled by Ghidra


void FUN_14013207c(void)

{
  ulonglong *puVar1;
  int unaff_EBP;
  uint *unaff_RSI;
  undefined2 unaff_R14W;
  undefined6 unaff_000000b2;
  undefined2 unaff_R15W;
  undefined6 unaff_000000ba;
  longlong local_res20;
  longlong *in_stack_00000090;
  
  *unaff_RSI = 0;
  if (((int)in_stack_00000090[4] != 0) && (*(int *)((longlong)in_stack_00000090 + 0xc) != 0)) {
    *unaff_RSI = unaff_EBP - 8U;
    puVar1 = (ulonglong *)ExAllocatePool(0,unaff_EBP - 8U);
    *(ulonglong **)CONCAT62(unaff_000000ba,unaff_R15W) = puVar1;
    in_stack_00000090[2] = *(longlong *)CONCAT62(unaff_000000b2,unaff_R14W);
    *(undefined4 *)(in_stack_00000090 + 1) = 0;
    local_res20 = *in_stack_00000090;
    FUN_140002088((undefined8 *)(CONCAT62(unaff_000000b2,unaff_R14W) + 8),*unaff_RSI,puVar1,
                  &local_res20);
  }
  FUN_1400021d0();
  return;
}

