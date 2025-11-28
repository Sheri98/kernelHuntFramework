// Function: FUN_000119f8
// Address: 000119f8
// Decompiled by Ghidra


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000119f8(ulonglong param_1,ulonglong param_2,char param_3)

{
  short sVar1;
  bool bVar2;
  ulonglong uVar3;
  ulonglong *puVar4;
  ulonglong *puVar5;
  longlong lVar6;
  longlong lVar7;
  short *psVar8;
  longlong lVar9;
  longlong lVar10;
  undefined1 auStack_1a8 [32];
  uint local_188 [2];
  ushort local_180;
  ushort local_17e;
  ulonglong *local_178;
  ushort local_170;
  ushort local_16e;
  ulonglong *local_168;
  int local_160 [2];
  longlong local_158;
  longlong local_150;
  short local_148 [64];
  short local_c8 [64];
  ulonglong local_48;
  
  local_48 = DAT_00014100 ^ (ulonglong)auStack_1a8;
  bVar2 = false;
  RtlInitUnicodeString(&local_180,&LAB_00012590);
  RtlInitUnicodeString(&local_170,&LAB_00012590);
  lVar10 = 0;
  DbgPrint("VProEventMonitor.sys: Entry - ProcessNotifyRoutine().\n");
  if (DAT_00014188 == 0) {
    DbgPrint("VProEventMonitor.sys: ProcessNotifyRoutine(): Global device object is NULL.\n");
  }
  else {
    DbgPrint("VProEventMonitor.sys: ProcessNotifyRoutine(): Global device object has some value.\n")
    ;
    lVar10 = *(longlong *)(DAT_00014188 + 0x40);
  }
  DbgPrint("VProEventMonitor.sys: Entry - VProEventMonitorGetTimeStamp().\n");
  KeQueryPerformanceCounter(0);
  uVar3 = _DAT_fffff78000000014;
  if (param_3 == '\0') goto LAB_00011d9b;
  DbgPrint("VProEventMonitor.sys: ProcessNotifyRoutine(): Called for Create Operation.\n");
  PsGetVersion(local_188,local_160,0,0);
  if ((local_188[0] < 5) || ((local_160[0] == 0 && (local_188[0] < 6)))) {
LAB_00011b79:
    PsLookupProcessByProcessId(param_2,&local_150);
    ObfDereferenceObject(local_150);
    if (bVar2) {
      FUN_00011e84(param_2,&local_180);
    }
    else {
      FUN_00011dcc(local_150,local_148);
    }
    PsLookupProcessByProcessId(param_1,&local_158);
    ObfDereferenceObject(local_158);
    if (bVar2) {
      FUN_00011e84(param_1,&local_170);
    }
    else {
      FUN_00011dcc(local_158,local_c8);
    }
    if (lVar10 != 0) {
      DbgPrint(
              "VProEventMonitor.sys: ProcessNotifyRoutine(): Filling up the callback info into DevExt.\n"
              );
      ExAcquireFastMutex(&DAT_00014148);
      lVar6 = *(longlong *)(lVar10 + 0x10);
      puVar4 = (ulonglong *)ExAllocatePoolWithTag(0,0xff0,0x63506556);
      if (puVar4 != (ulonglong *)0x0) {
        FUN_000120c0(puVar4,0,0xff0);
        if (lVar6 == 0) {
          *(ulonglong **)(lVar10 + 0x10) = puVar4;
        }
        else {
          for (; *(longlong *)(lVar6 + 0xfe8) != 0; lVar6 = *(longlong *)(lVar6 + 0xfe8)) {
          }
          *(ulonglong **)(lVar6 + 0xfe8) = puVar4;
        }
        puVar5 = puVar4 + 4;
        if (bVar2) {
          FUN_00011008((short *)puVar5,0x7e4,(longlong)local_178,(ulonglong)local_180);
          FUN_00011008((short *)((longlong)puVar4 + 0x804),0x7e4,(longlong)local_168,
                       (ulonglong)local_170);
        }
        else {
          lVar9 = 0x3f2;
          lVar7 = (longlong)local_148 - (longlong)puVar5;
          lVar6 = 0x3f2;
          do {
            if ((lVar6 == 0x3b2) || (sVar1 = *(short *)(lVar7 + (longlong)puVar5), sVar1 == 0))
            break;
            *(short *)puVar5 = sVar1;
            puVar5 = (ulonglong *)((longlong)puVar5 + 2);
            lVar6 = lVar6 + -1;
          } while (lVar6 != 0);
          if (lVar6 == 0) {
            puVar5 = (ulonglong *)((longlong)puVar5 + -2);
          }
          *(short *)puVar5 = 0;
          psVar8 = (short *)((longlong)puVar4 + 0x804);
          lVar6 = (longlong)local_c8 - (longlong)psVar8;
          do {
            if ((lVar9 == 0x3b2) || (sVar1 = *(short *)(lVar6 + (longlong)psVar8), sVar1 == 0))
            break;
            *psVar8 = sVar1;
            psVar8 = psVar8 + 1;
            lVar9 = lVar9 + -1;
          } while (lVar9 != 0);
          if (lVar9 == 0) {
            psVar8 = psVar8 + -1;
          }
          *psVar8 = 0;
        }
        *(char *)(puVar4 + 2) = param_3;
        *puVar4 = param_1;
        puVar4[1] = param_2;
        puVar4[3] = uVar3;
        DbgPrint("VProEventMonitor.sys: ProcessNotifyRoutine(): Process Details [Process ID - %x].\n"
                 ,param_2);
        DbgPrint(
                "VProEventMonitor.sys: ProcessNotifyRoutine(): Setting the event for Process creation.\n"
                );
        KeSetEvent(*(undefined8 *)(lVar10 + 8),0,0);
      }
      ExReleaseFastMutex(&DAT_00014148);
    }
    if (!bVar2) goto LAB_00011d9b;
    ExFreePoolWithTag(local_168,0);
  }
  else {
    local_180 = 0;
    bVar2 = true;
    local_17e = 4000;
    local_178 = (ulonglong *)ExAllocatePoolWithTag(1,4000,0x31504556);
    if (local_178 == (ulonglong *)0x0) goto LAB_00011d9b;
    FUN_000120c0(local_178,0,(ulonglong)local_17e);
    local_170 = 0;
    local_16e = 4000;
    local_168 = (ulonglong *)ExAllocatePoolWithTag(1,4000,0x32504556);
    if (local_168 != (ulonglong *)0x0) {
      FUN_000120c0(local_168,0,(ulonglong)local_16e);
      goto LAB_00011b79;
    }
  }
  ExFreePoolWithTag(local_178,0);
LAB_00011d9b:
  FUN_00012050(local_48 ^ (ulonglong)auStack_1a8);
  return;
}

