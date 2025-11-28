// Function: FUN_00011088
// Address: 00011088
// Decompiled by Ghidra


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00011088(longlong param_1)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  int iVar5;
  undefined1 auStack_108 [32];
  undefined4 local_e8;
  undefined1 local_e0;
  longlong *local_d8;
  longlong local_c8;
  undefined1 local_c0 [16];
  undefined1 local_b0 [16];
  undefined1 local_a0 [16];
  undefined1 local_90 [8];
  undefined8 local_88 [7];
  undefined8 local_50 [8];
  ulonglong local_10;
  
  local_10 = DAT_00014100 ^ (ulonglong)auStack_108;
  iVar5 = 0;
  local_c8 = 0;
  FUN_000121c0(local_88,(undefined8 *)L"\\Device\\VProEventMonitor",0x32);
  FUN_000121c0(local_50,(undefined8 *)L"\\DosDevices\\VProEventMonitor",0x3a);
  DbgPrint("VProEventMonitor.sys: Windows NT4/2000/XP/.NET Event Monitors Driver - Built on %s at %s\n"
           ,"Jun 28 2012","16:23:45");
  _DAT_00014148 = 1;
  _DAT_00014150 = 0;
  _DAT_00014158 = 0;
  KeInitializeEvent(&DAT_00014160,1,0);
  RtlInitUnicodeString(local_b0,local_88);
  DbgPrint("VProEventMonitor.sys: Creating Device Object.\n");
  local_d8 = &local_c8;
  local_e0 = 0;
  local_e8 = 0;
  iVar1 = IoCreateDevice(param_1,0x18,local_b0,0x9600);
  if (-1 < iVar1) {
    DbgPrint("VProEventMonitor.sys: SUCCESS Creating Device Object.\n");
    DAT_00014188 = local_c8;
    RtlInitUnicodeString(local_c0,local_50);
    iVar1 = IoCreateSymbolicLink(local_c0,local_b0);
    if (iVar1 < 0) {
      DbgPrint("VProEventMonitor.sys: IoCreateSymbolicLink failed.\n");
    }
    *(code **)(param_1 + 0x70) = FUN_000112e0;
    *(code **)(param_1 + 0x80) = FUN_000112e0;
    *(code **)(param_1 + 0x100) = FUN_000112e0;
    *(code **)(param_1 + 0x88) = FUN_000112e0;
    *(code **)(param_1 + 0x90) = FUN_000112e0;
    *(code **)(param_1 + 0xe0) = FUN_000112e0;
    lVar4 = *(longlong *)(local_c8 + 0x40);
    RtlInitUnicodeString(local_a0,L"\\BaseNamedObjects\\Global\\VProEventMonitorEvent");
    uVar3 = IoCreateNotificationEvent(local_a0,local_90);
    *(undefined8 *)(lVar4 + 8) = uVar3;
    KeClearEvent(uVar3);
    if (-1 < iVar1) {
      DbgPrint("VProEventMonitor.sys: Entry - VProEventMonintorGetProcNameOffset().\n");
      lVar4 = IoGetCurrentProcess();
      do {
        iVar2 = strncmp("System",(char *)(iVar5 + lVar4),6);
        iVar1 = iVar5;
        if (iVar2 == 0) break;
        iVar5 = iVar5 + 1;
        iVar1 = 0;
      } while (iVar5 < 0x3000);
      goto LAB_000112ac;
    }
  }
  DbgPrint("VProEventMonitor.sys: Device Creation failed.\n");
  iVar1 = DAT_00014190;
  if (local_c8 != 0) {
    IoDeleteSymbolicLink(local_c0);
    IoDeleteDevice(local_c8);
    iVar1 = DAT_00014190;
  }
LAB_000112ac:
  DAT_00014190 = iVar1;
  FUN_00012050(local_10 ^ (ulonglong)auStack_108);
  return;
}

