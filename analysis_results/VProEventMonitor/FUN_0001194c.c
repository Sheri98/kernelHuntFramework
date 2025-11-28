// Function: FUN_0001194c
// Address: 0001194c
// Decompiled by Ghidra


void FUN_0001194c(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  DbgPrint("VProEventMonitor.sys: Entry UnhookVProEventMonitorApis().\n");
  if (DAT_00014182 == '\0') {
    DbgPrint("VProEventMonitor.sys: Hook for process Notification Routine not set.\n");
  }
  else {
    DbgPrint("VProEventMonitor.sys: Removing the Hook for process Notification Routine.\n");
    DAT_00014182 = '\0';
    PsSetCreateProcessNotifyRoutine(FUN_000119f8,1);
    if ((param_1 != 0) && (lVar1 = *(longlong *)(param_1 + 0x40), lVar1 != 0)) {
      ExAcquireFastMutex(&DAT_00014148);
      while (lVar2 = *(longlong *)(lVar1 + 0x10), lVar2 != 0) {
        *(undefined8 *)(lVar1 + 0x10) = *(undefined8 *)(lVar2 + 0xfe8);
        ExFreePoolWithTag(lVar2,0);
      }
      KeClearEvent(*(undefined8 *)(lVar1 + 8));
      ExReleaseFastMutex(&DAT_00014148);
    }
  }
  return;
}

