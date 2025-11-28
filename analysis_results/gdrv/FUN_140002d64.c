// Function: FUN_140002d64
// Address: 140002d64
// Decompiled by Ghidra


undefined1
FUN_140002d64(short param_1,char param_2,undefined1 param_3,ushort param_4,ushort param_5)

{
  char cVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  
  out(param_1,0);
  uVar3 = FUN_140002d10(param_1,param_4,param_5);
  if ((int)uVar3 != -1) {
    out(param_1,0);
    out(param_1 + 4,0xff);
    out(param_1 + 2,param_2 * '\x02');
    out(param_1 + 3,param_3);
    out(param_1 + 1,0x1f);
    out(param_1,7);
    if (param_4 != 0) {
      uVar4 = (ulonglong)param_4;
      do {
        out(0x80,0xff);
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
    }
    uVar3 = FUN_140002d10(param_1,param_4,param_5);
    if (((int)uVar3 != -1) && (cVar1 = in(param_1), cVar1 == '\0')) {
      uVar2 = in(param_1 + 4);
      return uVar2;
    }
  }
  return 0;
}

