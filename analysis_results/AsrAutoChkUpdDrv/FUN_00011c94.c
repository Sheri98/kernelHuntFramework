// Function: FUN_00011c94
// Address: 00011c94
// Decompiled by Ghidra


undefined1 FUN_00011c94(short param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0x8000;
  do {
    cVar1 = in(param_1 + 7);
    if (-1 < cVar1) {
      return 1;
    }
    KeStallExecutionProcessor(100);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 0;
}

