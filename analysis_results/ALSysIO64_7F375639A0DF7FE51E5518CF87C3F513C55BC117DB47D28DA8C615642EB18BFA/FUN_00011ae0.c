// Function: FUN_00011ae0
// Address: 00011ae0
// Decompiled by Ghidra


void FUN_00011ae0(void)

{
  undefined1 auStack_168 [32];
  undefined1 local_148 [16];
  undefined1 local_138 [288];
  ulonglong local_18;
  
  local_18 = DAT_00015100 ^ (ulonglong)auStack_168;
  if (DAT_00015170 != (code *)0x0) {
    (*DAT_00015170)(local_138);
    FUN_000133b0(local_18 ^ (ulonglong)auStack_168);
    return;
  }
  if (DAT_00015178 != (code *)0x0) {
    (*DAT_00015178)(local_148,0,0,0);
    FUN_000133b0(local_18 ^ (ulonglong)auStack_168);
    return;
  }
  FUN_000133b0(local_18 ^ (ulonglong)auStack_168);
  return;
}

