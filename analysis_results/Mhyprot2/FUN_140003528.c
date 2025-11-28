// Function: FUN_140003528
// Address: 140003528
// Decompiled by Ghidra


undefined8 FUN_140003528(longlong param_1)

{
  ulonglong uVar1;
  longlong *plVar2;
  
  uVar1 = MmIsAddressValid();
  if ((char)uVar1 == '\0') {
LAB_1400035a0:
    return CONCAT71((int7)(uVar1 >> 8),1);
  }
  if (DAT_14000a720 != 0) {
    plVar2 = (longlong *)(DAT_14000a720 + param_1);
    uVar1 = MmIsAddressValid(plVar2);
    if ((((char)uVar1 == '\0') || (*plVar2 == 0)) ||
       (uVar1 = MmIsAddressValid(), (char)uVar1 == '\0')) goto LAB_1400035a0;
  }
  uVar1 = DAT_14000a718;
  if (DAT_14000a718 != 0) {
    plVar2 = (longlong *)(param_1 + DAT_14000a718);
    uVar1 = MmIsAddressValid(plVar2);
    if ((((char)uVar1 == '\0') || (*plVar2 == 0)) ||
       (uVar1 = MmIsAddressValid(), (char)uVar1 == '\0')) goto LAB_1400035a0;
  }
  return uVar1 & 0xffffffffffffff00;
}

