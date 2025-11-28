// Function: FUN_000116c0
// Address: 000116c0
// Decompiled by Ghidra


int FUN_000116c0(longlong param_1)

{
  int iVar1;
  undefined8 local_38;
  undefined1 local_30 [16];
  undefined1 local_20 [32];
  
  local_38 = 0;
  DbgPrint("Entering DriverEntry");
  RtlInitUnicodeString(local_30,L"\\Device\\MsIo");
  iVar1 = IoCreateDevice(param_1,0,local_30,0x8010,0,0,&local_38);
  if (iVar1 < 0) {
    DbgPrint("ERROR: IoCreateDevice failed");
  }
  else {
    *(code **)(param_1 + 0xe0) = FUN_000113f0;
    *(code **)(param_1 + 0x80) = FUN_000113f0;
    *(code **)(param_1 + 0x70) = FUN_000113f0;
    *(code **)(param_1 + 0x68) = FUN_00011010;
    RtlInitUnicodeString(local_20,L"\\DosDevices\\MsIo");
    iVar1 = IoCreateSymbolicLink(local_20,local_30);
    if (iVar1 < 0) {
      DbgPrint("ERROR: IoCreateSymbolicLink failed");
      IoDeleteDevice(local_38);
    }
  }
  DbgPrint("Leaving DriverEntry");
  return iVar1;
}

