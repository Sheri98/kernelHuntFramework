// Function: FUN_140002d74
// Address: 140002d74
// Decompiled by Ghidra


undefined8 FUN_140002d74(void)

{
  byte bVar1;
  
  while( true ) {
    bVar1 = FUN_14000100c();
    if ((bVar1 & 1) == 0) break;
    FUN_140001006();
    KeStallExecutionProcessor(0x28);
  }
  return 1;
}

