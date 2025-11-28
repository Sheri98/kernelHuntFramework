// Function: FUN_00011c90
// Address: 00011c90
// Decompiled by Ghidra


void FUN_00011c90(void)

{
  undefined1 auStack_168 [32];
  uint local_148;
  uint local_144 [3];
  undefined1 local_138 [4];
  uint local_134;
  uint local_130;
  ulonglong local_18;
  
  local_18 = DAT_00016100 ^ (ulonglong)auStack_168;
  DbgPrint("io 564");
  if (DAT_00016170 == (code *)0x0) {
    if (DAT_00016178 != (code *)0x0) {
      (*DAT_00016178)(local_144,&local_148,0,0);
      if ((6 < local_144[0]) || ((local_144[0] == 6 && (1 < local_148)))) {
        FUN_00013640(local_18 ^ (ulonglong)auStack_168);
        return;
      }
    }
  }
  else {
    (*DAT_00016170)(local_138);
    if ((6 < local_134) || ((local_134 == 6 && (1 < local_130)))) {
      FUN_00013640(local_18 ^ (ulonglong)auStack_168);
      return;
    }
  }
  FUN_00013640(local_18 ^ (ulonglong)auStack_168);
  return;
}

