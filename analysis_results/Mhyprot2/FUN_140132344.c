// Function: FUN_140132344
// Address: 140132344
// Decompiled by Ghidra


void FUN_140132344(undefined8 param_1,undefined2 param_2)

{
  code *pcVar1;
  longlong in_RAX;
  byte in_CF;
  
  *(int *)(in_RAX + -0xf8d50db) =
       (*(int *)(in_RAX + -0xf8d50db) - (int)&stack0x00000000) - (uint)in_CF;
  out(param_2,(uint)in_RAX | 0x39ac0bec);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

