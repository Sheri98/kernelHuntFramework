// Function: FUN_1400069b4
// Address: 1400069b4
// Decompiled by Ghidra


undefined8 FUN_1400069b4(undefined8 param_1,undefined8 param_2,ulonglong param_3)

{
  bool bVar1;
  undefined8 uVar2;
  uint7 extraout_var;
  
  uVar2 = FUN_1400048c0();
  if ((char)uVar2 != '\0') {
    bVar1 = FUN_140004ed8(param_1,param_2,param_3);
    uVar2 = CONCAT71(extraout_var,bVar1);
    if (bVar1) {
      return (ulonglong)extraout_var << 8;
    }
  }
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}

