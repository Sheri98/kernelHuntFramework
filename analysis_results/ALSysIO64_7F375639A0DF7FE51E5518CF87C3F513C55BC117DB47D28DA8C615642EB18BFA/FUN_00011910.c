// Function: FUN_00011910
// Address: 00011910
// Decompiled by Ghidra


void FUN_00011910(undefined8 param_1,undefined4 *param_2,undefined8 param_3,undefined4 *param_4,
                 undefined8 param_5,undefined4 *param_6)

{
  undefined1 auStack_168 [32];
  undefined4 local_148;
  undefined4 local_140;
  uint local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 *local_128;
  undefined1 local_118 [256];
  ulonglong local_18;
  
  local_18 = DAT_00015100 ^ (ulonglong)auStack_168;
  local_128 = param_6;
  local_134 = *param_2;
  local_138 = (uint)(byte)local_138 ^ (param_2[1] ^ (uint)(byte)local_138) & 0x1f;
  local_138 = local_138 ^ (param_2[2] << 5 ^ local_138) & 0xe0;
  local_140 = 8;
  local_148 = 0;
  local_130 = HalGetBusDataByOffset(4,local_134,local_138,local_118);
  *param_4 = local_130;
  *param_6 = 4;
  FUN_000133b0(local_18 ^ (ulonglong)auStack_168);
  return;
}

