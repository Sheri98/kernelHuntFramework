// Function: FUN_14009f035
// Address: 14009f035
// Decompiled by Ghidra


void FUN_14009f035(void)

{
  short sVar1;
  
  sVar1 = 0;
  if ((ushort)&stack0x00000000 != 0) {
    for (; ((ushort)&stack0x00000000 >> sVar1 & 1) == 0; sVar1 = sVar1 + 1) {
    }
  }
  FUN_140065a82();
  return;
}

