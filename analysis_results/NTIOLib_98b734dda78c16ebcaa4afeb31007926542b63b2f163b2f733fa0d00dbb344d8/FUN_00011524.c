// Function: FUN_00011524
// Address: 00011524
// Decompiled by Ghidra


undefined8
FUN_00011524(undefined4 *param_1,undefined8 param_2,ulonglong *param_3,undefined8 param_4,
            undefined4 *param_5)

{
  ulonglong uVar1;
  undefined8 in_RAX;
  
  uVar1 = rdpmc(*param_1);
  *param_3 = CONCAT44((int)((ulonglong)in_RAX >> 0x20),(int)uVar1) | uVar1 & 0xffffffff00000000;
  *param_5 = 8;
  return 0;
}

