// Function: FUN_00012216
// Address: 00012216
// Decompiled by Ghidra


uint FUN_00012216(void)

{
  byte in_ID;
  
  return ((uint)((in_ID & 1) != 1) * 0x200000 ^ (uint)(in_ID & 1) * 0x200000) >> 0x15;
}

