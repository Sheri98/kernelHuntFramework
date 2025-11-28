// Function: FUN_140002b50
// Address: 140002b50
// Decompiled by Ghidra


undefined1 FUN_140002b50(void)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = 5000;
  do {
    bVar1 = FUN_14000100c();
    if (iVar2 == 0) {
      return 0;
    }
    iVar2 = iVar2 + -1;
    KeStallExecutionProcessor(0x28);
  } while ((bVar1 & 2) != 0);
  return 1;
}

