// Function: FUN_140001994
// Address: 140001994
// Decompiled by Ghidra


void FUN_140001994(longlong param_1,longlong param_2)

{
  ulonglong *puVar1;
  int iVar2;
  ulonglong uVar3;
  longlong *plVar4;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  ulonglong local_10;
  
  local_10 = DAT_140004000 ^ (ulonglong)auStack_48;
  puVar1 = *(ulonglong **)(param_1 + 0x18);
  if ((*(int *)(param_2 + 0x10) == 0x10) && (iVar2 = FUN_1400015ac((byte *)puVar1), -1 < iVar2)) {
    local_28 = 0;
    uVar3 = FUN_1400016e8(&local_28);
    if (-1 < (int)uVar3) {
      iVar2 = 0;
      local_20 = (ulonglong)
                 CONCAT13((char)local_28,
                          CONCAT12((char)((ulonglong)local_28 >> 8),
                                   CONCAT11((char)((ulonglong)local_28 >> 0x10),
                                            (char)((ulonglong)local_28 >> 0x18))));
      if ((*puVar1 == local_20) && (puVar1[1] == 0)) {
        plVar4 = &DAT_140004010;
        do {
          if (*plVar4 == 0) {
            (&DAT_140004010)[iVar2] = local_28;
            break;
          }
          iVar2 = iVar2 + 1;
          plVar4 = plVar4 + 1;
        } while ((longlong)plVar4 < 0x140004210);
      }
    }
  }
  FUN_140001e10(local_10 ^ (ulonglong)auStack_48);
  return;
}

