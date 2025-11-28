// Function: FUN_00011008
// Address: 00011008
// Decompiled by Ghidra


int FUN_00011008(longlong param_1)

{
  undefined8 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  longlong local_res8 [4];
  undefined1 local_28 [16];
  undefined1 local_18 [16];
  
  *(code **)(param_1 + 0x70) = FUN_000110e4;
  *(code **)(param_1 + 0x80) = FUN_000110e4;
  *(code **)(param_1 + 0xe0) = FUN_000110e4;
  *(code **)(param_1 + 0x68) = FUN_00011300;
  RtlInitUnicodeString(local_28,L"\\Device\\ASMMAP64");
  iVar3 = IoCreateDevice(param_1,0x10,local_28,40000,0,0,local_res8);
  if (-1 < iVar3) {
    puVar1 = *(undefined8 **)(local_res8[0] + 0x40);
    *puVar1 = 0;
    puVar1[1] = 0;
    RtlInitUnicodeString(local_18,L"\\DosDevices\\ASMMAP64");
    iVar3 = IoCreateSymbolicLink(local_18,local_28);
    if (iVar3 < 0) {
      IoDeleteDevice(local_res8[0]);
    }
    else {
      puVar2 = *(undefined4 **)(local_res8[0] + 0x40);
      *(longlong *)(puVar2 + 2) = local_res8[0];
      *puVar2 = 40000;
    }
  }
  return iVar3;
}

