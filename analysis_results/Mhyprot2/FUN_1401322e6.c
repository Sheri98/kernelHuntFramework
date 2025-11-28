// Function: FUN_1401322e6
// Address: 1401322e6
// Decompiled by Ghidra


void FUN_1401322e6(undefined8 param_1,undefined2 param_2)

{
  code *pcVar1;
  
  in(param_2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

