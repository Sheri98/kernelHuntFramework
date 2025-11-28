// Function: FUN_00011220
// Address: 00011220
// Decompiled by Ghidra


/* WARNING: Removing unreachable block (ram,0x000112e4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00011220(longlong param_1,longlong param_2)

{
  int *piVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int local_38;
  int local_30;
  
  uVar5 = _DAT_fffff78000000014;
  piVar1 = *(int **)(param_1 + 0x18);
  if ((*(int *)(param_2 + 0x10) == 4) && (3 < *(uint *)(param_2 + 8))) {
    uVar3 = rdtsc();
    FUN_000111f0(500);
    uVar6 = _DAT_fffff78000000014;
    uVar4 = rdtsc();
    DbgPrint("HHHHHHHHHHHHHHHH[AsmaIns] <RDTSC> Interval2.QuadPart=%d \n");
    local_38 = (int)uVar6;
    local_30 = (int)uVar5;
    uVar9 = (uint)(local_38 - local_30) / 1000;
    uVar2 = (ulonglong)(uint)((int)uVar4 - (int)uVar3) / (ulonglong)uVar9;
    DbgPrint("HHHHHHHHHHHHHHHH[AsmaIns] <GpdIoctlGetCpuFrequence> ulTmp1=%d \n",uVar9);
    iVar8 = (int)uVar2;
    DbgPrint("HHHHHHHHHHHHHHHH[AsmaIns] <GpdIoctlGetCpuFrequence> ulTmp2=%d \n");
    if ((((DAT_00014000 == 0) || (uVar7 = iVar8 - DAT_00014000, uVar7 == 0)) ||
        (1000 < (uint)(uVar2 / uVar7))) || (DAT_00014004 != 0)) {
      DAT_00014004 = 0;
      DAT_00014000 = iVar8;
    }
    else {
      DAT_00014004 = 1;
    }
    iVar8 = DAT_00014000;
    *piVar1 = DAT_00014000;
    DbgPrint("HHHHHHHHHHHHHHHH[AsmaIns] <GpdIoctlGetCpuFrequence> ulTmp1=%d \n",uVar9);
    DbgPrint("HHHHHHHHHHHHHHHH[AsmaIns] <GpdIoctlGetCpuFrequence> ulTmp2=%d \n",iVar8);
    return 0;
  }
  return 0xc000000d;
}

