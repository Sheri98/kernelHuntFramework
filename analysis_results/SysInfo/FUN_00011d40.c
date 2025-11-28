// Function: FUN_00011d40
// Address: 00011d40
// Decompiled by Ghidra


undefined8 FUN_00011d40(uint *param_1,int param_2,undefined8 param_3,int param_4,int *param_5)

{
  uint uVar1;
  int iVar2;
  
  if (param_2 != 8) {
    return 0xc000000d;
  }
  uVar1 = *param_1;
  iVar2 = HalGetBusDataByOffset
                    (4,uVar1 >> 8 & 0xff,uVar1 >> 3 & 0x1f | (uVar1 & 7) << 5,param_3,param_1[1],
                     param_4);
  if (iVar2 == 0) {
    *param_5 = 0;
    return 0xe0000001;
  }
  if ((param_4 != 2) && (iVar2 == 2)) {
    *param_5 = 0;
    return 0xe0000002;
  }
  if (param_4 != iVar2) {
    *param_5 = 0;
    return 0xe0000004;
  }
  *param_5 = param_4;
  return 0;
}

