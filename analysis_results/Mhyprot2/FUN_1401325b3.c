// Function: FUN_1401325b3
// Address: 1401325b3
// Decompiled by Ghidra


void FUN_1401325b3(undefined8 param_1,undefined2 param_2)

{
  byte *pbVar1;
  undefined1 in_AL;
  undefined7 in_register_00000001;
  uint unaff_ESI;
  
  *(undefined8 *)((ulonglong)unaff_ESI - 8) = 0xffffffffffffff88;
  pbVar1 = (byte *)(CONCAT71(in_register_00000001,in_AL) + -0x12a64799);
  *pbVar1 = *pbVar1 & (byte)((ushort)param_2 >> 8);
  out(param_2,in_AL);
  return;
}

