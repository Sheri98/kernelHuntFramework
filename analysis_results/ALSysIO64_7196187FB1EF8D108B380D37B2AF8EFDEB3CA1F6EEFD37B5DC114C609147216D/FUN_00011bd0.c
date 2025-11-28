// Function: FUN_00011bd0
// Address: 00011bd0
// Decompiled by Ghidra


void FUN_00011bd0(void)

{
  undefined1 auStack_168 [32];
  undefined1 local_148 [16];
  undefined1 local_138 [288];
  ulonglong local_18;
  
  local_18 = DAT_00016100 ^ (ulonglong)auStack_168;
  DbgPrint("io 538");
  if (DAT_00016170 != (code *)0x0) {
    (*DAT_00016170)(local_138);
    FUN_00013640(local_18 ^ (ulonglong)auStack_168);
    return;
  }
  if (DAT_00016178 != (code *)0x0) {
    (*DAT_00016178)(local_148,0,0,0);
    FUN_00013640(local_18 ^ (ulonglong)auStack_168);
    return;
  }
  FUN_00013640(local_18 ^ (ulonglong)auStack_168);
  return;
}

