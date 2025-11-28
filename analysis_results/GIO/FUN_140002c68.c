// Function: FUN_140002c68
// Address: 140002c68
// Decompiled by Ghidra


undefined1
FUN_140002c68(short param_1,char param_2,undefined1 param_3,ushort param_4,ushort param_5)

{
  undefined1 uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  
  uVar2 = FUN_140002c1c(param_1,param_4,param_5);
  if ((int)uVar2 != -1) {
    out(param_1 + 4,param_2 * '\x02' + '\x01');
    out(param_1 + 3,param_3);
    out(param_1,0xff);
    out(param_1 + 5,0xff);
    out(param_1 + 2,0x48);
    if (param_4 != 0) {
      uVar3 = (ulonglong)param_4;
      do {
        out(0x80,0xff);
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
    uVar2 = FUN_140002c1c(param_1,param_4,param_5);
    if ((int)uVar2 != -1) {
      uVar1 = in(param_1 + 5);
      return uVar1;
    }
  }
  return 0;
}

