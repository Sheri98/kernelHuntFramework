// Function: FUN_00011780
// Address: 00011780
// Decompiled by Ghidra


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00011780(undefined8 param_1,longlong param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  undefined8 uVar6;
  longlong lVar7;
  undefined1 *puVar8;
  ulonglong uVar5;
  
  *(undefined8 *)(param_2 + 0x38) = 0;
  if (DAT_00014048 == 4) {
    puVar8 = &DAT_00014300;
    for (lVar7 = 0x4004; iVar3 = DAT_0001405c, iVar2 = DAT_00014000, lVar7 != 0; lVar7 = lVar7 + -1)
    {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    iVar1 = DAT_00014000;
    if (DAT_00014060 != '\0') {
      iVar1 = DAT_00014000 - DAT_0001405c;
    }
    *(int *)(&DAT_00016304 + (longlong)_DAT_00014300 * 4) = iVar1 + -1;
    *(int *)(&DAT_00014304 + (longlong)_DAT_00014300 * 4) = (iVar2 - DAT_00014058) - iVar3;
    _DAT_00014300 = _DAT_00014300 + 1;
    uVar5 = FUN_00011270();
    cVar4 = (char)uVar5;
  }
  else {
    if (DAT_00014048 != 5) {
      return 0;
    }
    uVar6 = FUN_00011550();
    cVar4 = (char)uVar6;
  }
  if (cVar4 != '\0') {
    *(undefined8 *)(param_2 + 0x38) = 1;
  }
  return 0;
}

