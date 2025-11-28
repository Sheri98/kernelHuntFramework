// Function: FUN_14000197c
// Address: 14000197c
// Decompiled by Ghidra


ulonglong FUN_14000197c(undefined8 param_1,undefined4 param_2,undefined8 param_3,longlong *param_4)

{
  uint uVar1;
  ulonglong uVar2;
  undefined1 local_28 [16];
  undefined1 local_18 [16];
  
  RtlInitUnicodeString(local_28,param_1);
  uVar2 = IoCreateDevice(param_3,0x20,local_28,param_2,0,0,param_4);
  if (-1 < (int)uVar2) {
    memset(*(void **)(*param_4 + 0x40),0,0x20);
    RtlInitUnicodeString(local_18,L"\\DosDevices\\GIO");
    uVar1 = IoCreateSymbolicLink(local_18,local_28);
    uVar2 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      IoDeleteDevice(*param_4);
    }
  }
  return uVar2;
}

