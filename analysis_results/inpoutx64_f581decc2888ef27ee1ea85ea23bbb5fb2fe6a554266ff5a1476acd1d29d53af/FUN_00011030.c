// Function: FUN_00011030
// Address: 00011030
// Decompiled by Ghidra


void FUN_00011030(longlong param_1)

{
  int iVar1;
  undefined1 auStack_d8 [32];
  undefined4 local_b8;
  undefined1 local_b0;
  undefined1 *local_a8;
  undefined1 local_98 [16];
  undefined1 local_88 [16];
  undefined1 local_78 [8];
  undefined8 local_70 [5];
  undefined8 local_48 [6];
  ulonglong local_18;
  
  local_18 = DAT_00013100 ^ (ulonglong)auStack_d8;
  FUN_000115d0(local_70,(undefined8 *)L"\\Device\\inpoutx64",0x24);
  FUN_000115d0(local_48,(undefined8 *)L"\\DosDevices\\inpoutx64",0x2c);
  RtlInitUnicodeString(local_98,local_70);
  RtlInitUnicodeString(local_88,local_48);
  local_a8 = local_78;
  local_b0 = 0;
  local_b8 = 0;
  iVar1 = IoCreateDevice(param_1,0,local_98,0x22);
  if (-1 < iVar1) {
    iVar1 = IoCreateSymbolicLink(local_88,local_98);
    if (-1 < iVar1) {
      *(code **)(param_1 + 0x70) = FUN_00011008;
      *(code **)(param_1 + 0xe0) = FUN_0001112c;
      *(code **)(param_1 + 0x68) = FUN_00011310;
    }
  }
  FUN_00011570(local_18 ^ (ulonglong)auStack_d8);
  return;
}

