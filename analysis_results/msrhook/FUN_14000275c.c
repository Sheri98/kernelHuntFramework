// Function: FUN_14000275c
// Address: 14000275c
// Decompiled by Ghidra


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_14000275c(short param_1,ushort param_2)

{
  char cVar1;
  
  cVar1 = '\0';
  if (((param_1 == 0x2a) || (param_1 == 0x36)) && (cVar1 = '\0', param_2 == 0)) {
    cVar1 = '\x01';
  }
  if (((param_1 == 0x2a) || (param_1 == 0x36)) && (param_2 == 1)) {
    cVar1 = '\x02';
  }
  if (param_1 == 0x1d) {
    if ((param_2 & 0xfffd) == 0) {
      cVar1 = '\x03';
    }
    if ((param_2 - 1 & 0xfffd) == 0) {
      cVar1 = '\x04';
    }
  }
  if (cVar1 == '\x01') {
    DAT_1400050f4 = *(int *)(&DAT_140005000 + (longlong)DAT_1400050f4 * 4);
  }
  else if (cVar1 == '\x02') {
    DAT_1400050f4 = *(int *)(&DAT_140005020 + (longlong)DAT_1400050f4 * 4);
  }
  else if (cVar1 == '\x03') {
    DAT_1400050f4 = *(int *)(&DAT_140005040 + (longlong)DAT_1400050f4 * 4);
  }
  else {
    if (cVar1 != '\x04') {
      DAT_1400050f4 = 0;
      return 0;
    }
    DAT_1400050f4 = *(int *)(&DAT_140005060 + (longlong)DAT_1400050f4 * 4);
  }
  if (DAT_1400050f4 != 8) {
    return 0;
  }
  _DAT_1400061a0 = FUN_140001bb4();
  FUN_140002930(1);
  return 1;
}

