// Function: FUN_140002d10
// Address: 140002d10
// Decompiled by Ghidra


undefined8 FUN_140002d10(short param_1,ushort param_2,ushort param_3)

{
  byte bVar1;
  char cVar2;
  short sVar3;
  ulonglong uVar4;
  uint uVar5;
  
  uVar5 = (uint)param_3;
  sVar3 = param_1 + 1;
  out(sVar3,0x1f);
  bVar1 = in(sVar3);
  if ((bVar1 & 0x1f) != 0) {
    do {
      uVar4 = (ulonglong)param_2;
      if (param_2 != 0) {
        do {
          out(0x80,0xff);
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
      }
      out(sVar3,0x1f);
      uVar5 = uVar5 - 1;
      if (uVar5 == 0) {
        return 0xffffffff;
      }
      cVar2 = in(sVar3);
    } while ((cVar2 != '\x10') && (bVar1 = in(sVar3), (bVar1 & 0x1f) != 0));
  }
  return 0;
}

