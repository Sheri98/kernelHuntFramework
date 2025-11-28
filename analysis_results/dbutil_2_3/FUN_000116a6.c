// Function: FUN_000116a6
// Address: 000116a6
// Decompiled by Ghidra


undefined2 FUN_000116a6(undefined8 param_1,undefined8 param_2)

{
  undefined1 in_AL;
  undefined1 uVar1;
  undefined1 in_AH;
  undefined6 in_register_00000002;
  undefined8 unaff_RBX;
  undefined8 *unaff_RBP;
  undefined8 unaff_RSI;
  undefined8 unaff_RDI;
  
  *unaff_RBP = CONCAT62(in_register_00000002,CONCAT11(in_AH,in_AL));
  unaff_RBP[1] = unaff_RBX;
  unaff_RBP[2] = param_1;
  unaff_RBP[3] = param_2;
  unaff_RBP[4] = unaff_RSI;
  unaff_RBP[5] = unaff_RDI;
  uVar1 = in(0x81);
  out(0x81,uVar1);
  return CONCAT11(in_AH,in_AL);
}

