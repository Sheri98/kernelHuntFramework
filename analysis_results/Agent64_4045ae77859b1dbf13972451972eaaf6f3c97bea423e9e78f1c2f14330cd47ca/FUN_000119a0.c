// Function: FUN_000119a0
// Address: 000119a0
// Decompiled by Ghidra


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_000119a0(uint param_1,uint param_2,uint param_3,undefined8 param_4,int *param_5)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  uVar1 = in(0xcf8);
  if (param_3 != 0) {
    out(0xcf8,((param_1 & 0xf) << 5 | param_2 & 0x1f) << 0xb | 0x8000000c);
    uVar2 = in(0xcfc);
    out(0xcf8,uVar1);
    if ((uVar2 >> 0x17 & 1) == 0) {
      _DAT_00014194 = 300;
      *param_5 = -1;
      uVar5 = 0;
      goto LAB_00011a69;
    }
  }
  uVar2 = 0;
  _DAT_00014194 = 400;
  piVar4 = param_5;
  do {
    out(0xcf8,((((param_1 & 0xf | 0xffff8000) << 5 | param_2 & 0x1f) << 3 | param_3 & 7) << 6 |
              uVar2) << 2);
    iVar3 = in(0xcfc);
    *piVar4 = iVar3;
    if ((uVar2 == 0) && (*param_5 == -1)) goto LAB_00011a69;
    uVar2 = uVar2 + 1;
    piVar4 = piVar4 + 1;
  } while (uVar2 < 0x40);
  uVar5 = 0x100;
  _DAT_00014194 = 0x100;
LAB_00011a69:
  out(0xcf8,uVar1);
  return uVar5;
}

