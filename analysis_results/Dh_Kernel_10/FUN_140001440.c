// Function: FUN_140001440
// Address: 140001440
// Decompiled by Ghidra


void FUN_140001440(longlong param_1)

{
  int iVar1;
  undefined1 auStack_78 [32];
  undefined4 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined1 local_40 [48];
  ulonglong local_10;
  
  local_10 = DAT_140004010 ^ (ulonglong)auStack_78;
  if ((*(int *)(param_1 + 0x1c) != 0) &&
     (iVar1 = PsLookupProcessByProcessId(*(int *)(param_1 + 0x1c),&local_48), -1 < iVar1)) {
    local_50 = FUN_14000129c((ulonglong)*(uint *)(param_1 + 0x20));
    KeStackAttachProcess(local_48,local_40);
    ProbeForRead(*(undefined8 *)(param_1 + 4),*(undefined8 *)(param_1 + 0x14),1);
    FUN_140002180(*(undefined8 **)(param_1 + 4),&local_50,*(ulonglong *)(param_1 + 0x14));
    KeUnstackDetachProcess(local_40);
    local_58 = 0;
    ObfDereferenceObject(local_48);
  }
  FUN_140001c10(local_10 ^ (ulonglong)auStack_78);
  return;
}

