// Function: FUN_140001980
// Address: 140001980
// Decompiled by Ghidra


undefined4 FUN_140001980(undefined8 param_1,longlong param_2)

{
  byte *pbVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  longlong lVar5;
  uint uVar6;
  
  uVar4 = 0;
  if ((((*(longlong *)(param_2 + 0xb8) != 0) &&
       (piVar2 = *(int **)(param_2 + 0x18), piVar2 != (int *)0x0)) &&
      (*(longlong *)(piVar2 + 5) != 0)) && (uVar4 = 0, *piVar2 == -0x77885545)) {
    uVar6 = 0x811c9dc5;
    lVar5 = 0;
    do {
      pbVar1 = (byte *)(lVar5 + (longlong)piVar2);
      lVar5 = lVar5 + 1;
      uVar3 = *pbVar1 ^ uVar6;
      uVar6 = uVar3 * 0x1000193;
    } while (lVar5 < 0x2c);
    uVar3 = uVar3 * 0x1326193;
    uVar6 = (uVar3 >> 7 ^ uVar3) * 9;
    uVar6 = (uVar6 >> 0x11 ^ uVar6) * 0x21;
    if ((uint)((ulonglong)uVar6 * 0x780ed4c7 >> 0x3e) * 0x77885545 + uVar6 == piVar2[0xb]) {
      uVar4 = FUN_1400013dc((undefined8 *)piVar2);
    }
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = uVar4;
  IofCompleteRequest(param_2,0);
  return uVar4;
}

