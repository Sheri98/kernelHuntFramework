// Function: FUN_14013228e
// Address: 14013228e
// Decompiled by Ghidra


void FUN_14013228e(void)

{
  code *pcVar1;
  undefined1 uVar2;
  
  uVar2 = FUN_1400a7de0();
  out(0x68,uVar2);
  in(0x53);
  FUN_1400e6084();
  pcVar1 = (code *)swi(1);
  (*pcVar1)();
  return;
}

