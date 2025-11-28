// Function: FUN_1401321b1
// Address: 1401321b1
// Decompiled by Ghidra


void FUN_1401321b1(void)

{
  longlong lVar1;
  ulonglong *puVar2;
  ulonglong uVar3;
  uint unaff_EBP;
  undefined4 unaff_0000002c;
  undefined4 unaff_ESI;
  undefined4 unaff_00000034;
  undefined2 unaff_R14W;
  undefined6 unaff_000000b2;
  undefined8 *unaff_R15;
  longlong *in_stack_00000060;
  
  *(undefined4 *)CONCAT44(unaff_00000034,unaff_ESI) = 0;
  if (((int)in_stack_00000060[4] != 0) && (*(int *)((longlong)in_stack_00000060 + 0xc) != 0)) {
    *(uint *)CONCAT44(unaff_00000034,unaff_ESI) = unaff_EBP + 8;
    puVar2 = (ulonglong *)ExAllocatePool(0,CONCAT44(unaff_0000002c,unaff_EBP) + 8);
    *(ulonglong **)CONCAT62(unaff_000000b2,unaff_R14W) = puVar2;
    rdtsc();
    uVar3 = rdtsc();
    lVar1 = 0x3f;
    if (in_stack_00000060 != (longlong *)0x0) {
      for (; (ulonglong)in_stack_00000060 >> lVar1 == 0; lVar1 = lVar1 + -1) {
      }
    }
    uVar3 = CONCAT44((int)((ulonglong)puVar2 >> 0x10),(int)uVar3) | uVar3 & 0xffffffff00000000;
    *puVar2 = uVar3;
    *(undefined4 *)(in_stack_00000060 + 1) = 0;
    in_stack_00000060[2] = uVar3;
    FUN_140002088(unaff_R15,unaff_EBP,puVar2 + 1,in_stack_00000060);
  }
  FUN_1400022f9();
  return;
}

