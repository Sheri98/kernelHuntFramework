// Function: FUN_00011230
// Address: 00011230
// Decompiled by Ghidra


void FUN_00011230(undefined4 param_1,uint param_2,uint param_3,undefined4 param_4,undefined8 param_5
                 )

{
  HalSetBusDataByOffset(4,param_1,(param_3 & 7) << 5 | param_2 & 0x1f,&param_5,param_4,4);
  return;
}

