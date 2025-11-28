// Function: FUN_140003dd8
// Address: 140003dd8
// Decompiled by Ghidra


undefined8 FUN_140003dd8(longlong param_1,longlong param_2,uint param_3)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = 0x1000 - ((uint)param_1 & 0xfff);
  if (param_3 < uVar2) {
    uVar2 = param_3;
  }
  if (uVar2 != 0x1000) {
    cVar1 = MmIsAddressValid();
    if (cVar1 != '\0') {
      FUN_140003fa8(param_1,param_2,uVar2);
    }
    param_1 = param_1 + (ulonglong)uVar2;
    param_2 = param_2 + (ulonglong)uVar2;
    param_3 = param_3 - uVar2;
  }
  for (; 0x1000 < param_3; param_3 = param_3 - 0x1000) {
    cVar1 = MmIsAddressValid(param_1);
    if (cVar1 != '\0') {
      FUN_140003fa8(param_1,param_2,0x1000);
    }
    param_1 = param_1 + 0x1000;
    param_2 = param_2 + 0x1000;
  }
  if (param_3 != 0) {
    cVar1 = MmIsAddressValid(param_1);
    if (cVar1 != '\0') {
      FUN_140003fa8(param_1,param_2,param_3);
    }
  }
  return 0;
}

