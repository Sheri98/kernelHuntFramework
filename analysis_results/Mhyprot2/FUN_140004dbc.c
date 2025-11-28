// Function: FUN_140004dbc
// Address: 140004dbc
// Decompiled by Ghidra


void FUN_140004dbc(void)

{
  PsSetCreateProcessNotifyRoutineEx(FUN_140004480,1);
  PsRemoveLoadImageNotifyRoutine(FUN_1400049e0);
                    /* WARNING: Could not recover jumptable at 0x000140004de7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  PsRemoveCreateThreadNotifyRoutine(FUN_140004600);
  return;
}

