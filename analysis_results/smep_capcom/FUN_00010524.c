// Function: FUN_00010524
// Address: 00010524
// Decompiled by Ghidra


bool FUN_00010524(undefined *param_1)

{
  undefined *puVar1;
  ulonglong local_28;
  code *local_20;
  code *local_18;
  
  puVar1 = *(undefined **)(param_1 + -8);
  if (puVar1 == param_1) {
    local_18 = MmGetSystemRoutineAddress_exref;
    local_28 = 0;
    local_20 = (code *)param_1;
    FUN_00010788(&local_28);
    (*local_20)(local_18);
    FUN_000107a0(&local_28);
  }
  return puVar1 == param_1;
}

