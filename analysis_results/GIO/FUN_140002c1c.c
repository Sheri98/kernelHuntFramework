// Function: FUN_140002c1c
// Address: 140002c1c
// Decompiled by Ghidra


undefined8 FUN_140002c1c(undefined2 param_1,ushort param_2,ushort param_3)

{
  byte bVar1;
  ulonglong uVar2;
  uint uVar3;
  
  uVar3 = (uint)param_3;
  out(param_1,1);
  bVar1 = in(param_1);
  if ((bVar1 & 1) != 0) {
    do {
      uVar2 = (ulonglong)param_2;
      if (param_2 != 0) {
        do {
          out(0x80,0xff);
          uVar2 = uVar2 - 1;
        } while (uVar2 != 0);
      }
      out(param_1,1);
      uVar3 = uVar3 - 1;
      if (uVar3 == 0) {
        return 0xffffffff;
      }
      bVar1 = in(param_1);
    } while ((bVar1 & 1) != 0);
  }
  return 0;
}

