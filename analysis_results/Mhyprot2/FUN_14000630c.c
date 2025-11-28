// Function: FUN_14000630c
// Address: 14000630c
// Decompiled by Ghidra


void FUN_14000630c(longlong param_1,undefined4 *param_2)

{
  if ((*(int *)(param_1 + 0x18) != 0) &&
     (*(ulonglong *)MmHighestUserAddress_exref <= *(ulonglong *)(param_1 + 0x10))) {
    FUN_1401324b4(&DAT_140007d30);
    return;
  }
  *param_2 = 0xffffffff;
  return;
}

