// Function: FUN_00011c00
// Address: 00011c00
// Decompiled by Ghidra


ulonglong FUN_00011c00(undefined4 param_1,uint *param_2,uint param_3,undefined8 *param_4,
                      uint param_5,undefined4 *param_6,undefined4 *param_7)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  switch(param_1) {
  case 0xfa002ee0:
    if (((param_4 != (undefined8 *)0x0) && (param_2 != (uint *)0x0)) &&
       ((param_5 == param_3 || (0xf < param_5)))) {
      uVar2 = FUN_000119f0(param_2,param_7);
      uVar3 = uVar2 & 0xffffffff;
      if ((int)uVar2 != 0) {
        return uVar3;
      }
      *param_6 = 0x14;
LAB_00011dc1:
      FUN_00012050(param_4,(undefined8 *)param_2,0x14);
      return uVar3;
    }
    break;
  default:
    return 0xc000000d;
  case 0xfa002ee4:
    if (param_2 != (uint *)0x0) {
      uVar3 = FUN_00011b60(param_2,(longlong)param_7);
      *param_6 = 0;
      return uVar3 & 0xffffffff;
    }
    break;
  case 0xfa002ee8:
    if (param_2 != (uint *)0x0) {
      uVar1 = FUN_000117b0((undefined8 *)param_2);
      if (uVar1 != 0) {
        return (ulonglong)uVar1;
      }
      *param_6 = 0x14;
      FUN_00012050(param_4,(undefined8 *)param_2,0x14);
      return (ulonglong)uVar1;
    }
    break;
  case 0xfa002eec:
    if (((param_4 != (undefined8 *)0x0) && (param_2 != (uint *)0x0)) &&
       ((param_5 == param_3 || (0xf < param_5)))) {
      uVar1 = FUN_000110a0(param_2);
      if (uVar1 != 0) {
        return (ulonglong)uVar1;
      }
      *param_6 = 0x10;
      FUN_00012050(param_4,(undefined8 *)param_2,0x10);
      return (ulonglong)uVar1;
    }
    break;
  case 0xfa002ef0:
    if ((param_2 != (uint *)0x0) && (0xf < param_3)) {
      uVar1 = FUN_000112b0(param_2);
      *param_6 = 0;
      return (ulonglong)uVar1;
    }
    break;
  case 0xfa002ef8:
    if (param_2 != (uint *)0x0) {
      uVar1 = FUN_000119b0(*(undefined8 *)param_2);
      uVar3 = (ulonglong)uVar1;
      if (uVar1 != 0) {
        return uVar3;
      }
      *param_6 = 0x14;
      goto LAB_00011dc1;
    }
    break;
  case 0xfa002efc:
    if ((param_2 != (uint *)0x0) && (0x15 < param_3)) {
      uVar1 = FUN_000114c0(param_2);
      *param_6 = 0x16;
      return (ulonglong)uVar1;
    }
    break;
  case 0xfa002f08:
    if ((param_4 != (undefined8 *)0x0) || (3 < param_5)) {
      *(undefined2 *)param_4 = 2;
      *(undefined2 *)((longlong)param_4 + 2) = 3;
      *param_6 = 4;
      return 0;
    }
    break;
  case 0xfa002f1c:
    if ((param_2 != (uint *)0x0) && (0x25 < param_3)) {
      uVar3 = FUN_000116a0(param_2);
      *param_6 = 0x26;
      return uVar3 & 0xffffffff;
    }
  }
  return 0xc0000206;
}

