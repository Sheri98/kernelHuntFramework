// Function: FUN_00011c0c
// Address: 00011c0c
// Decompiled by Ghidra


undefined8 FUN_00011c0c(short param_1,undefined8 param_2,undefined1 param_3,undefined2 *param_4)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  undefined2 uVar4;
  longlong lVar5;
  int iVar6;
  
  out(param_1 + 7,param_3);
  KeStallExecutionProcessor(100,param_1 + 7);
  cVar1 = FUN_00011bc8(param_1);
  if (cVar1 == '\x01') {
    bVar2 = in(param_1 + 1);
    if ((bVar2 & 4) == 0) {
      iVar6 = 0x8000;
      do {
        bVar2 = in(param_1 + 7);
        if ((bVar2 & 8) != 0) {
          lVar5 = 0x100;
          do {
            uVar4 = in(param_1);
            *param_4 = uVar4;
            param_4 = param_4 + 1;
            lVar5 = lVar5 + -1;
          } while (lVar5 != 0);
          FUN_00011bc8(param_1);
          return 0;
        }
        KeStallExecutionProcessor(100);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    else {
      bVar2 = in(param_1 + 5);
      bVar3 = in(param_1 + 4);
      if ((uint)bVar3 + (uint)bVar2 * 0x100 == 0xeb14) {
        return 0xc0000002;
      }
    }
  }
  return 0xc00000a3;
}

