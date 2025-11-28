// Function: FUN_1400034a8
// Address: 1400034a8
// Decompiled by Ghidra


ulonglong FUN_1400034a8(uint param_1)

{
  char cVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  
  uVar2 = FUN_14000556c(param_1);
  cVar1 = MmIsAddressValid(uVar2);
  if ((((cVar1 == '\0') || (uVar2 == 0xffffffffffffffff)) || (uVar2 == 0)) ||
     ((cVar1 = MmIsAddressValid(uVar2 - 0x30), cVar1 == '\0' || (*(longlong *)(uVar2 - 0x30) == 0)))
     ) {
    uVar4 = 0;
  }
  else {
    uVar3 = FUN_140003528(uVar2);
    uVar4 = 0;
    if ((char)uVar3 != '\x01') {
      uVar4 = uVar2;
    }
  }
  return uVar4;
}

