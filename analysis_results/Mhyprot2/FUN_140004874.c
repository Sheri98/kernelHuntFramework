// Function: FUN_140004874
// Address: 140004874
// Decompiled by Ghidra


bool FUN_140004874(void)

{
  char cVar1;
  
  if (((DAT_14000a670 != (char *)0x0) ||
      (DAT_14000a670 = FUN_14000700c(), DAT_14000a670 != (char *)0x0)) &&
     (cVar1 = MmIsAddressValid(DAT_14000a670), cVar1 != '\0')) {
    return ((byte)*(undefined4 *)DAT_14000a670 & 0xf) == 0xf;
  }
  return true;
}

