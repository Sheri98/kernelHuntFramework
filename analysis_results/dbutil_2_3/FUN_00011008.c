// Function: FUN_00011008
// Address: 00011008
// Decompiled by Ghidra


void FUN_00011008(longlong param_1)

{
  ulonglong *puVar1;
  int iVar2;
  undefined1 auStack_d8 [32];
  undefined4 local_b8;
  undefined1 local_b0;
  longlong *local_a8;
  longlong local_98;
  undefined1 local_90 [16];
  undefined1 local_80 [16];
  undefined1 local_70 [40];
  undefined1 local_48 [48];
  ulonglong local_18;
  
  local_18 = DAT_00013100 ^ (ulonglong)auStack_d8;
  memcpy(local_70,L"\\Device\\DBUtil_2_3",0x26);
  memcpy(local_48,L"\\DosDevices\\DBUtil_2_3",0x2e);
  RtlInitUnicodeString(local_90,local_70);
  RtlInitUnicodeString(local_80,local_48);
  local_a8 = &local_98;
  local_b0 = 1;
  local_b8 = 0;
  iVar2 = IoCreateDevice(param_1,0xa0,local_90,0x9b0c);
  if (iVar2 == 0) {
    iVar2 = IoCreateSymbolicLink(local_80);
    if (iVar2 == 0) {
      *(code **)(param_1 + 0xf0) = FUN_00011170;
      *(code **)(param_1 + 0x70) = FUN_00011170;
      *(code **)(param_1 + 0x80) = FUN_00011170;
      *(code **)(param_1 + 0xe0) = FUN_00011170;
      puVar1 = *(ulonglong **)(local_98 + 0x40);
      FUN_00011b70(puVar1,0,0xa0);
      puVar1[2] = 0;
      KeInitializeDpc(puVar1 + 3,FUN_00011590,puVar1);
      KeSetTargetProcessorDpc(puVar1 + 3,0);
      KeSetImportanceDpc(puVar1 + 3,2);
    }
    else {
      IoDeleteDevice(local_98);
    }
  }
  FUN_00011730(local_18 ^ (ulonglong)auStack_d8);
  return;
}

