// Function: FUN_14000293c
// Address: 14000293c
// Decompiled by Ghidra


bool FUN_14000293c(undefined8 param_1)

{
  undefined1 uVar1;
  char cVar2;
  
  uVar1 = MmIsAddressValid();
  DbgPrint("Valid(dwHandle)=%x",uVar1);
  cVar2 = MmIsAddressValid(param_1);
  if (cVar2 != '\0') {
    MmFreeContiguousMemory(param_1);
  }
  return cVar2 != '\0';
}

