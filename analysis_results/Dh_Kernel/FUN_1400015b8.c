// Function: FUN_1400015b8
// Address: 1400015b8
// Decompiled by Ghidra


void FUN_1400015b8(undefined8 param_1)

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
  FUN_140001f20(local_18 ^ (ulonglong)auStack_48);
  return;
}

