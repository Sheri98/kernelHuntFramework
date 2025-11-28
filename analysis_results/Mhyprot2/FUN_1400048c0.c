// Function: FUN_1400048c0
// Address: 1400048c0
// Decompiled by Ghidra


ulonglong FUN_1400048c0(void)

{
  bool bVar1;
  ulonglong uVar2;
  undefined7 extraout_var;
  
  uVar2 = FUN_140007338();
  if ((char)uVar2 == '\0') {
LAB_1400048f5:
    uVar2 = CONCAT71((int7)(uVar2 >> 8),1);
  }
  else {
    bVar1 = FUN_140004874();
    uVar2 = CONCAT71(extraout_var,bVar1);
    if (bVar1) {
      uVar2 = FUN_1400047a4();
      if ((char)uVar2 != '\0') {
        uVar2 = FUN_1400046d4();
        if ((char)uVar2 != '\0') {
          uVar2 = FUN_140004904();
          if ((char)uVar2 != '\0') goto LAB_1400048f5;
        }
      }
    }
    uVar2 = uVar2 & 0xffffffffffffff00;
  }
  return uVar2;
}

