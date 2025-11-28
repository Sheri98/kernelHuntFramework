// Function: FUN_00011630
// Address: 00011630
// Decompiled by Ghidra


undefined8 FUN_00011630(undefined8 param_1,undefined8 param_2)

{
  undefined1 uVar1;
  undefined8 in_RAX;
  undefined8 uVar2;
  
  uVar2 = FUN_000116c9();
  out((short)param_2,(char)uVar2);
  uVar1 = in(0x81);
  out(0x81,uVar1);
  FUN_000116a6(param_1,param_2);
  return in_RAX;
}

