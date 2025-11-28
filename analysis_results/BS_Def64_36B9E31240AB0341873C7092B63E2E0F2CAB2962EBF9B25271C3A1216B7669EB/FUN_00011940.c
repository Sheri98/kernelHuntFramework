// Function: FUN_00011940
// Address: 00011940
// Decompiled by Ghidra


ulonglong FUN_00011940(undefined8 param_1,longlong *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  undefined1 local_38 [16];
  undefined1 local_28 [16];
  
  RtlInitUnicodeString(local_38,L"\\Device\\BS_Def");
  uVar2 = IoCreateDevice(param_1,8,local_38,0x22,0,0,param_2);
  if (-1 < (int)uVar2) {
    RtlInitUnicodeString(local_28,L"\\DosDevices\\BS_Def");
    uVar1 = IoCreateSymbolicLink(local_28,local_38);
    uVar2 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      IoDeleteDevice(*param_2);
    }
    RtlZeroMemory(*(undefined8 *)(*param_2 + 0x40),8);
  }
  return uVar2;
}

