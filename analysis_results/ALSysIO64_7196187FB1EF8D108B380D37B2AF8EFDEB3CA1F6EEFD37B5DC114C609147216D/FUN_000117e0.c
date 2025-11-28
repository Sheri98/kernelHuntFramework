// Function: FUN_000117e0
// Address: 000117e0
// Decompiled by Ghidra


undefined8
FUN_000117e0(undefined8 param_1,undefined4 *param_2,undefined8 param_3,uint *param_4,
            undefined8 param_5,undefined4 *param_6)

{
  undefined4 uVar1;
  ushort uVar2;
  
  uVar1 = *param_2;
  DbgPrint("io 208");
  uVar2 = in((short)uVar1);
  *param_4 = (uint)uVar2;
  *param_6 = 4;
  return 0;
}

