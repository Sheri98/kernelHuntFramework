// Function: FUN_1400016e8
// Address: 1400016e8
// Decompiled by Ghidra


ulonglong FUN_1400016e8(undefined8 *param_1)

{
  ulonglong uVar1;
  undefined1 local_48 [16];
  undefined1 local_38 [32];
  undefined8 local_18;
  
  if (DAT_140004210 == (code *)0x0) {
    RtlInitUnicodeString(local_48,L"ZwQueryInformationProcess");
    DAT_140004210 = (code *)MmGetSystemRoutineAddress(local_48);
    if (DAT_140004210 == (code *)0x0) {
      return 0xc0000001;
    }
  }
  uVar1 = (*DAT_140004210)(0xffffffffffffffff,0,local_38,0x30,0);
  if (-1 < (int)uVar1) {
    *param_1 = local_18;
    uVar1 = uVar1 & 0xffffffff;
  }
  return uVar1;
}

