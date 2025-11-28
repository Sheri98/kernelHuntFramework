// Function: FUN_000119e0
// Address: 000119e0
// Decompiled by Ghidra


void FUN_000119e0(undefined8 param_1,undefined4 *param_2,undefined8 param_3,undefined4 *param_4,
                 undefined8 param_5,undefined4 *param_6)

{
  undefined4 uVar1;
  undefined1 auStack_178 [32];
  undefined4 local_158;
  undefined4 local_150;
  uint local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 *local_138;
  undefined1 local_128 [256];
  ulonglong local_28;
  
  local_28 = DAT_00016100 ^ (ulonglong)auStack_178;
  local_138 = param_6;
  uVar1 = *param_2;
  local_144 = uVar1;
  DbgPrint("io 320");
  local_148 = (uint)(byte)local_148 ^ (param_2[1] ^ (uint)(byte)local_148) & 0x1f;
  local_148 = local_148 ^ (param_2[2] << 5 ^ local_148) & 0xe0;
  local_150 = 8;
  local_158 = 0;
  local_140 = HalGetBusDataByOffset(4,uVar1,local_148,local_128);
  *param_4 = local_140;
  *param_6 = 4;
  FUN_00013640(local_28 ^ (ulonglong)auStack_178);
  return;
}

