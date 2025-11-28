// Function: FUN_00011008
// Address: 00011008
// Decompiled by Ghidra


int FUN_00011008(longlong param_1)

{
  undefined8 *puVar1;
  int iVar2;
  longlong local_res8 [4];
  undefined1 local_28 [16];
  undefined1 local_18 [16];
  
  *(code **)(param_1 + 0x70) = FUN_000110e4;
  *(code **)(param_1 + 0x80) = FUN_000110e4;
  *(code **)(param_1 + 0xe0) = FUN_000110e4;
  *(code **)(param_1 + 0x68) = FUN_000118b0;
  RtlInitUnicodeString(local_28,L"\\Device\\atillk64");
  iVar2 = IoCreateDevice(param_1,0x10,local_28,0x22,0,0,local_res8);
  if (-1 < iVar2) {
    puVar1 = *(undefined8 **)(local_res8[0] + 0x40);
    *puVar1 = 0;
    puVar1[1] = 0;
    RtlInitUnicodeString(local_18,L"\\DosDevices\\atillk64");
    iVar2 = IoCreateSymbolicLink(local_18,local_28);
    if (iVar2 < 0) {
      IoDeleteDevice(local_res8[0]);
    }
    else {
      *(uint *)(local_res8[0] + 0x30) = *(uint *)(local_res8[0] + 0x30) | 4;
      **(longlong **)(local_res8[0] + 0x40) = local_res8[0];
    }
  }
  return iVar2;
}

