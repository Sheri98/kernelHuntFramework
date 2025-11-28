// Function: FUN_140002c28
// Address: 140002c28
// Decompiled by Ghidra


char FUN_140002c28(char param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined8 local_res10;
  
  DAT_1400050ec = 1;
  local_res10 = 0xfffffffffff85ee0;
  KeDelayExecutionThread(0,0,&local_res10);
  uVar2 = 0x47;
  if (param_1 == '\0') {
    uVar2 = 0x36;
  }
  FUN_140002d74();
  cVar1 = FUN_140002b50();
  if (cVar1 != '\0') {
    FUN_14000101a(0x60);
    cVar1 = FUN_140002b50();
    cVar1 = cVar1 != '\0';
    if ((bool)cVar1) {
      FUN_140001012(uVar2);
    }
  }
  DAT_1400050ec = 0;
  return cVar1;
}

