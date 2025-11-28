// Function: FUN_1400015ac
// Address: 1400015ac
// Decompiled by Ghidra


void FUN_1400015ac(byte *param_1)

{
  undefined1 auStack_108 [32];
  undefined1 local_e8 [192];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = DAT_140004000 ^ (ulonglong)auStack_108;
  local_28 = 0x16157eaa;
  local_24 = 0xa6d2ae28;
  local_20 = 0x8815f7ab;
  local_1c = 0x3c4fcf09;
  thunk_FUN_14000145c((longlong)local_e8,(longlong)&local_28);
  FUN_140001000((longlong)local_e8,param_1);
  FUN_140001e60(local_18 ^ (ulonglong)auStack_108);
  return;
}

