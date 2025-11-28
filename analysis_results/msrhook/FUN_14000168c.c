// Function: FUN_14000168c
// Address: 14000168c
// Decompiled by Ghidra


undefined4 FUN_14000168c(longlong param_1)

{
  byte bVar1;
  undefined4 uVar2;
  
  bVar1 = FUN_140002c28('\x01');
  *(ulonglong *)(param_1 + 0x38) = (ulonglong)bVar1;
  uVar2 = 0;
  if (bVar1 == 0) {
    uVar2 = 0xc000000d;
  }
  return uVar2;
}

