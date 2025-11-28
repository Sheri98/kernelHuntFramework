// Function: FUN_140001540
// Address: 140001540
// Decompiled by Ghidra


undefined4 FUN_140001540(longlong param_1)

{
  byte bVar1;
  undefined4 uVar2;
  
  bVar1 = FUN_140002c28('\0');
  *(ulonglong *)(param_1 + 0x38) = (ulonglong)bVar1;
  uVar2 = 0;
  if (bVar1 == 0) {
    uVar2 = 0xc000000d;
  }
  return uVar2;
}

