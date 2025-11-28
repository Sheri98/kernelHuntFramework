// Function: FUN_00012178
// Address: 00012178
// Decompiled by Ghidra


void FUN_00012178(undefined8 param_1,longlong param_2,longlong param_3)

{
  undefined8 uVar1;
  undefined1 auStack_118 [32];
  undefined8 local_f8;
  undefined8 local_f0;
  undefined1 local_e8 [16];
  undefined1 local_d8 [16];
  wchar_t local_c8 [40];
  wchar_t local_78 [40];
  ulonglong local_28;
  
  local_28 = DAT_00014100 ^ (ulonglong)auStack_118;
  local_f8 = 0;
  local_f0 = 0;
  _snwprintf(local_c8,0x28,L"\\BaseNamedObjects\\HW64IrqEvent%d");
  RtlInitUnicodeString(local_e8,local_c8);
  uVar1 = IoCreateNotificationEvent(local_e8,&local_f8);
  *(undefined8 *)(param_2 + 0x60) = uVar1;
  _snwprintf(local_78,0x28,L"\\BaseNamedObjects\\HW64KbdEvent%d");
  RtlInitUnicodeString(local_d8,local_78);
  uVar1 = IoCreateNotificationEvent(local_d8,&local_f0);
  *(undefined4 *)(param_2 + 0xcc) = 0;
  *(undefined4 *)(param_2 + 0xa0) = 0;
  *(undefined8 *)(param_2 + 0x98) = uVar1;
  *(undefined8 *)(param_2 + 0xa8) = 0;
  *(undefined8 *)(param_2 + 0xb0) = 0;
  *(undefined8 *)(param_2 + 0xb8) = 0;
  *(undefined8 *)(param_2 + 0xc0) = 0;
  *(undefined1 *)(param_2 + 0x58) = 0;
  *(undefined8 *)(param_3 + 0x38) = 0;
  FUN_000127f0(local_28 ^ (ulonglong)auStack_118);
  return;
}

