// Function: FUN_1400010c6
// Address: 1400010c6
// Decompiled by Ghidra


undefined8 FUN_1400010c6(void)

{
  undefined8 uVar1;
  undefined8 in_RAX;
  
  uVar1 = rdmsr(DAT_140005044);
  DAT_140005040 = (int)uVar1;
  DAT_14000503c = (int)((ulonglong)uVar1 >> 0x20);
  return in_RAX;
}

