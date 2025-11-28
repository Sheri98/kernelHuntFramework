// Function: FUN_00012110
// Address: 00012110
// Decompiled by Ghidra


undefined4 FUN_00012110(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = HalGetBusDataByOffset
                    (4,*param_1,param_1[1] & 0x1f | (param_1[2] & 7) << 5,param_1 + 6,param_1[4],
                     param_1[5]);
  return uVar1;
}

