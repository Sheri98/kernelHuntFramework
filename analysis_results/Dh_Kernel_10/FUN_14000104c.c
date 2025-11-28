// Function: FUN_14000104c
// Address: 14000104c
// Decompiled by Ghidra


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14000104c(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined1 local_40;
  undefined8 *local_38;
  undefined1 local_28 [16];
  ulonglong local_18;
  
  local_18 = DAT_140004010 ^ (ulonglong)auStack_68;
  _DAT_140004358 = 0;
  DbgPrintEx(0,0,"DriverEntry....\r\n");
  RtlInitUnicodeString(&DAT_140004340,L"\\DosDevices\\DianHuRing0");
  RtlInitUnicodeString(&DAT_140004330,L"\\DosDevices\\DianHuRing0");
  KeInitializeSpinLock(&DAT_140004098);
  DbgPrintEx(0,0,"RegistryPath->Buffer %ws\r\n",*(undefined8 *)(param_2 + 8));
  local_38 = &DAT_140004350;
  local_40 = 0;
  local_48 = 0x100;
  iVar1 = IoCreateDevice(param_1,0,&DAT_140004340,0x22);
  if (iVar1 == 0) {
    puVar3 = (undefined8 *)(param_1 + 0x70);
    for (lVar2 = 0x1b; lVar2 != 0; lVar2 = lVar2 + -1) {
      *puVar3 = FUN_14000186c;
      puVar3 = puVar3 + 1;
    }
    *(code **)(param_1 + 0xe0) = FUN_140001000;
    *(code **)(param_1 + 0x90) = FUN_140001980;
    *(code **)(param_1 + 0x68) = FUN_140001894;
    *(uint *)(DAT_140004350 + 0x30) = *(uint *)(DAT_140004350 + 0x30) | 4;
    *(uint *)(DAT_140004350 + 0x30) = *(uint *)(DAT_140004350 + 0x30) & 0xffffff7f;
    IoCreateSymbolicLink(&DAT_140004330,&DAT_140004340);
    RtlInitUnicodeString(local_28,L"NtQuerySystemInformation");
    DAT_1400040a0 = MmGetSystemRoutineAddress(local_28);
    RtlInitUnicodeString(local_28,L"ObRegisterCallbacks");
    _DAT_1400040a8 = MmGetSystemRoutineAddress(local_28);
    RtlInitUnicodeString(local_28,L"ObUnRegisterCallbacks");
    _DAT_1400040b0 = MmGetSystemRoutineAddress(local_28);
    DAT_1400040c0 = &DAT_1400040b8;
    DAT_1400040b8 = &DAT_1400040b8;
    DAT_1400040d0 = &DAT_1400040c8;
    DAT_1400040c8 = &DAT_1400040c8;
  }
  FUN_140001c10(local_18 ^ (ulonglong)auStack_68);
  return;
}

