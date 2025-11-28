// Function: FUN_00011170
// Address: 00011170
// Decompiled by Ghidra


undefined8 * FUN_00011170(ulonglong param_1,uint param_2)

{
  ulonglong uVar1;
  uint *puVar2;
  int iVar3;
  
  iVar3 = 0;
  puVar2 = &DAT_00016150;
  while ((((uVar1 = *(ulonglong *)(puVar2 + -4), param_1 < uVar1 || (*puVar2 + uVar1 <= param_1)) ||
          (param_1 + param_2 < uVar1)) || (*puVar2 + uVar1 < param_1 + param_2))) {
    puVar2 = puVar2 + 6;
    iVar3 = iVar3 + 1;
    if (0x1644f < (longlong)puVar2) {
      return (undefined8 *)0x0;
    }
  }
  return &DAT_00016140 + (longlong)iVar3 * 3;
}

