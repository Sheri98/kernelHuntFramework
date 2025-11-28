// Function: FUN_000111c0
// Address: 000111c0
// Decompiled by Ghidra


/* WARNING: Removing unreachable block (ram,0x0001125b) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_000111c0(longlong param_1,longlong param_2)

{
  int *piVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  int iVar6;
  int local_30;
  int local_28;
  
  uVar5 = _DAT_fffff78000000014;
  piVar1 = *(int **)(param_1 + 0x18);
  if ((*(int *)(param_2 + 0x10) != 4) || (*(uint *)(param_2 + 8) < 4)) {
    return 0xc000000d;
  }
  uVar3 = rdtsc();
  FUN_00011190(500);
  uVar4 = rdtsc();
  local_30 = (int)uVar5;
  local_28 = (int)uVar4;
  uVar2 = (ulonglong)(uint)(local_28 - (int)uVar3) /
          ((ulonglong)(uint)((int)_DAT_fffff78000000014 - local_30) / 1000);
  iVar6 = (int)uVar2;
  if ((((DAT_00013000 != 0) && (iVar6 - DAT_00013000 != 0)) &&
      ((uint)(uVar2 / (uint)(iVar6 - DAT_00013000)) < 0x3e9)) && (DAT_00013004 == 0)) {
    DAT_00013004 = 1;
    *piVar1 = DAT_00013000;
    return 0;
  }
  DAT_00013004 = 0;
  DAT_00013000 = iVar6;
  *piVar1 = iVar6;
  return 0;
}

