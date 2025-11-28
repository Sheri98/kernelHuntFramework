// Function: FUN_1401325e7
// Address: 1401325e7
// Decompiled by Ghidra


void FUN_1401325e7(void)

{
  int iVar1;
  undefined2 unaff_BP;
  undefined6 unaff_0000002a;
  uint unaff_ESI;
  uint unaff_EDI;
  undefined8 unaff_R12;
  undefined8 *unaff_R14;
  undefined8 in_stack_00000028;
  
  *unaff_R14 = 0;
  *(undefined4 *)(CONCAT62(unaff_0000002a,unaff_BP) + 0x1f8) = 0;
  iVar1 = 0;
  if (unaff_EDI != 0) {
    for (; (unaff_EDI >> iVar1 & 1) == 0; iVar1 = iVar1 + 1) {
    }
  }
  **(undefined4 **)(CONCAT62(unaff_0000002a,unaff_BP) + 0x200) = 0;
  FUN_140132567(unaff_R12,(ulonglong)unaff_ESI,(ulonglong)&stack0x00000030,
                CONCAT62(unaff_0000002a,unaff_BP) + 0x1f8,in_stack_00000028,(uint *)0x0);
  return;
}

