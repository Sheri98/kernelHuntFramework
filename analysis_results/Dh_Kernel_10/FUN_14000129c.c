// Function: FUN_14000129c
// Address: 14000129c
// Decompiled by Ghidra


void FUN_14000129c(undefined8 param_1)

{
  int iVar1;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  longlong local_20;
  ulonglong local_18;
  
  local_18 = DAT_140004010 ^ (ulonglong)auStack_48;
  iVar1 = PsLookupProcessByProcessId(param_1,&local_20);
  if ((iVar1 == 0) && (local_20 != 0)) {
    KeAttachProcess();
    local_28 = PsGetProcessSectionBaseAddress(local_20);
    KeDetachProcess();
    ObfDereferenceObject(local_20);
  }
  FUN_140001c10(local_18 ^ (ulonglong)auStack_48);
  return;
}

