// Function: FUN_140001628
// Address: 140001628
// Decompiled by Ghidra


int FUN_140001628(longlong param_1)

{
  int iVar1;
  undefined8 local_res18 [2];
  undefined1 local_28 [16];
  undefined1 local_18 [16];
  
  local_res18[0] = 0;
  RtlInitUnicodeString(local_28,L"\\Device\\GLCKIo2");
  iVar1 = IoCreateDevice(param_1,0,local_28,0x8010,0,0,local_res18);
  if (-1 < iVar1) {
    *(code **)(param_1 + 0x70) = FUN_140001ac0;
    *(code **)(param_1 + 0x80) = FUN_140001ac0;
    *(code **)(param_1 + 0xe0) = FUN_140001ac0;
    *(code **)(param_1 + 0x68) = FUN_140001d64;
    RtlInitUnicodeString(local_18,L"\\DosDevices\\GLCKIo2");
    iVar1 = IoCreateSymbolicLink(local_18,local_28);
    if (iVar1 < 0) {
      IoDeleteDevice(local_res18[0]);
    }
  }
  return iVar1;
}

