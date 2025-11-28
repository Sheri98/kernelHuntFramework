// Function: FUN_00011010
// Address: 00011010
// Decompiled by Ghidra


int FUN_00011010(longlong param_1)

{
  undefined8 *puVar1;
  int iVar2;
  longlong lVar3;
  longlong local_res8;
  undefined1 local_28 [16];
  undefined1 local_18 [16];
  
  *(code **)(param_1 + 0x70) = FUN_00011180;
  *(code **)(param_1 + 0x80) = FUN_00011180;
  *(code **)(param_1 + 0xe0) = FUN_00011180;
  *(undefined8 *)(param_1 + 0x60) = 0;
  *(code **)(param_1 + 0x68) = FUN_00011540;
  RtlInitUnicodeString(local_28,L"\\Device\\ALSysIO");
  iVar2 = IoCreateDevice(param_1,0x390,local_28,40000,0,1,&local_res8);
  if (-1 < iVar2) {
    FUN_00013a10(*(ulonglong **)(local_res8 + 0x40),0,0x390);
    RtlInitUnicodeString(local_18,L"\\DosDevices\\ALSysIO");
    iVar2 = IoCreateSymbolicLink(local_18,local_28);
    if (iVar2 < 0) {
      IoDeleteDevice(local_res8);
    }
  }
  puVar1 = *(undefined8 **)(local_res8 + 0x40);
  puVar1[1] = local_res8;
  *(undefined4 *)puVar1 = 40000;
  lVar3 = 0x10;
  do {
    *(undefined1 *)(puVar1 + 3) = 0;
    puVar1[7] = 0;
    lVar3 = lVar3 + -1;
    puVar1 = puVar1 + 7;
  } while (lVar3 != 0);
  if ((DAT_00015118 != 0) && (DAT_00015140 == 0)) {
    FUN_00013040();
  }
  DAT_00015118 = 0;
  RtlInitUnicodeString(local_28,L"PsGetVersion");
  DAT_00015178 = MmGetSystemRoutineAddress(local_28);
  RtlInitUnicodeString(local_28,L"RtlGetVersion");
  DAT_00015170 = MmGetSystemRoutineAddress(local_28);
  return iVar2;
}

