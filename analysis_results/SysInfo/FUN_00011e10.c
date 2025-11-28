// Function: FUN_00011e10
// Address: 00011e10
// Decompiled by Ghidra


undefined4
FUN_00011e10(uint *param_1,uint param_2,undefined8 param_3,undefined8 param_4,undefined4 *param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_2 < 8) {
    return 0xc000000d;
  }
  *param_5 = 0;
  uVar1 = *param_1;
  iVar2 = HalSetBusDataByOffset
                    (4,uVar1 >> 8 & 0xff,uVar1 >> 3 & 0x1f | (uVar1 & 7) << 5,param_1 + 2,param_1[1]
                     ,param_2 - 8);
  uVar3 = 0;
  if (iVar2 != param_2 - 8) {
    uVar3 = 0xe0000003;
  }
  return uVar3;
}

