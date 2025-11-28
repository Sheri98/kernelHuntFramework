// Function: FUN_140001a2c
// Address: 140001a2c
// Decompiled by Ghidra


void FUN_140001a2c(undefined8 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 *puVar3;
  longlong lVar4;
  undefined1 auStack_88 [32];
  undefined8 *local_68;
  undefined8 *local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined1 local_48 [48];
  ulonglong local_18;
  
  local_18 = DAT_140004010 ^ (ulonglong)auStack_88;
  uVar1 = *(undefined4 *)((longlong)param_1 + 0x1c);
  local_60 = param_1;
  iVar2 = PsLookupProcessByProcessId(*(undefined4 *)(param_1 + 4),&local_58);
  if (-1 < iVar2) {
    iVar2 = PsLookupProcessByProcessId(uVar1,&local_50);
    if (iVar2 < 0) {
      ObfDereferenceObject(local_58);
    }
    else {
      puVar3 = (undefined8 *)
               ExAllocatePoolWithTag(0,*(undefined8 *)((longlong)param_1 + 0x14),0x574431);
      local_68 = puVar3;
      if (puVar3 == (undefined8 *)0x0) {
        ObfDereferenceObject(local_58);
        ObfDereferenceObject(local_50);
      }
      else {
        KeStackAttachProcess(local_50,local_48);
        ProbeForRead(*(undefined8 *)((longlong)param_1 + 4),
                     *(undefined8 *)((longlong)param_1 + 0x14),1);
        FUN_140002180(puVar3,*(undefined8 **)((longlong)param_1 + 4),
                      *(ulonglong *)((longlong)param_1 + 0x14));
        KeUnstackDetachProcess(local_48);
        KeStackAttachProcess(local_58,local_48);
        local_60 = (undefined8 *)0x0;
        lVar4 = FUN_140001320(*(longlong *)((longlong)param_1 + 0xc),&local_60,
                              *(longlong *)((longlong)param_1 + 0x14));
        if ((lVar4 != 0) && (local_60 != (undefined8 *)0x0)) {
          FUN_140002180(local_60,puVar3,*(ulonglong *)((longlong)param_1 + 0x14));
          FUN_1400013bc(local_60,lVar4);
        }
        KeUnstackDetachProcess(local_48);
        ObfDereferenceObject(local_58);
        ObfDereferenceObject(local_50);
        ExFreePoolWithTag(puVar3,0x574431);
      }
    }
  }
  FUN_140001c10(local_18 ^ (ulonglong)auStack_88);
  return;
}

