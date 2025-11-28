// Function: FUN_00011180
// Address: 00011180
// Decompiled by Ghidra


int FUN_00011180(undefined8 param_1,longlong param_2)

{
  uint *puVar1;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  int *piVar5;
  undefined8 *puVar6;
  int iVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  int iVar10;
  undefined4 in_stack_ffffffffffffffdc;
  ulonglong local_10;
  
  pcVar4 = *(char **)(param_2 + 0xb8);
  puVar1 = (uint *)(param_2 + 0x38);
  puVar1[0] = 0;
  puVar1[1] = 0;
  cVar2 = *pcVar4;
  iVar10 = 0;
  iVar7 = iVar10;
  if (((cVar2 != '\0') && (cVar2 != '\x02')) && (iVar7 = -0x3ffffffe, cVar2 == '\x0e')) {
    uVar9 = (ulonglong)*(uint *)(pcVar4 + 0x18);
    switch(*(uint *)(pcVar4 + 0x18)) {
    case 0x9c402604:
      uVar8 = FUN_000115d0(uVar9,*(undefined4 **)(param_2 + 0x18),
                           (ulonglong)*(uint *)(pcVar4 + 0x10),*(undefined4 **)(param_2 + 0x18),
                           CONCAT44(in_stack_ffffffffffffffdc,*(undefined4 *)(pcVar4 + 8)),puVar1);
      iVar7 = (int)uVar8;
      break;
    case 0x9c402608:
      uVar8 = FUN_00011640(uVar9,*(undefined4 **)(param_2 + 0x18));
      iVar7 = (int)uVar8;
      break;
    case 0x9c402618:
      puVar6 = *(undefined8 **)(param_2 + 0x18);
      uVar3 = *(uint *)(puVar6 + 1);
      uVar8 = FUN_00012c00(*puVar6,puVar6,(ulonglong)uVar3);
      if ((int)uVar8 == 0) {
        *puVar1 = uVar3;
        iVar7 = iVar10;
      }
      else {
        *puVar1 = 0;
        iVar7 = (int)uVar8;
      }
      break;
    case 0x9c40261c:
      puVar6 = *(undefined8 **)(param_2 + 0x18);
      uVar8 = *puVar6;
      uVar3 = *(uint *)(puVar6 + 1);
      *puVar1 = 0;
      uVar8 = FUN_00012c90(uVar8,(void *)((longlong)puVar6 + 0xc),(ulonglong)uVar3);
      iVar7 = (int)uVar8;
      break;
    case 0x9c402620:
      iVar7 = FUN_00011910(uVar9,*(undefined4 **)(param_2 + 0x18),
                           (ulonglong)*(uint *)(pcVar4 + 0x10),*(undefined4 **)(param_2 + 0x18),
                           CONCAT44(in_stack_ffffffffffffffdc,*(undefined4 *)(pcVar4 + 8)),puVar1);
      break;
    case 0x9c402624:
      **(undefined4 **)(param_2 + 0x18) = 0x20009;
      *puVar1 = 4;
      iVar7 = iVar10;
      break;
    case 0x9c402628:
      piVar5 = *(int **)(param_2 + 0x18);
      if ((DAT_00015118 != 0) && (DAT_00015140 == 0)) {
        FUN_00013040();
      }
      DAT_00015118 = 0;
      *piVar5 = DAT_00015140;
      *puVar1 = 4;
      iVar7 = iVar10;
      break;
    case 0x9c40262c:
      uVar8 = FUN_00011a20(uVar9,*(uint **)(param_2 + 0x18),(ulonglong)*(uint *)(pcVar4 + 0x10),
                           *(uint **)(param_2 + 0x18),
                           CONCAT44(in_stack_ffffffffffffffdc,*(undefined4 *)(pcVar4 + 8)),puVar1);
      iVar7 = (int)uVar8;
      break;
    case 0x9c402630:
      uVar8 = FUN_000116b0(uVar9,*(undefined4 **)(param_2 + 0x18),
                           (ulonglong)*(uint *)(pcVar4 + 0x10),*(undefined4 **)(param_2 + 0x18),
                           CONCAT44(in_stack_ffffffffffffffdc,*(undefined4 *)(pcVar4 + 8)),puVar1);
      iVar7 = (int)uVar8;
      break;
    case 0x9c402634:
      uVar8 = FUN_00011710(uVar9,*(undefined4 **)(param_2 + 0x18));
      iVar7 = (int)uVar8;
      break;
    case 0x9c402638:
      uVar8 = FUN_00011770(uVar9,*(undefined4 **)(param_2 + 0x18),
                           (ulonglong)*(uint *)(pcVar4 + 0x10),*(undefined4 **)(param_2 + 0x18),
                           CONCAT44(in_stack_ffffffffffffffdc,*(undefined4 *)(pcVar4 + 8)),puVar1);
      iVar7 = (int)uVar8;
      break;
    case 0x9c40263c:
      uVar8 = FUN_000117e0(uVar9,*(undefined4 **)(param_2 + 0x18));
      iVar7 = (int)uVar8;
      break;
    case 0x9c402640:
      uVar8 = FUN_00011840(uVar9,*(undefined4 **)(param_2 + 0x18),
                           (ulonglong)*(uint *)(pcVar4 + 0x10),*(undefined4 **)(param_2 + 0x18),
                           CONCAT44(in_stack_ffffffffffffffdc,*(undefined4 *)(pcVar4 + 8)),puVar1);
      iVar7 = (int)uVar8;
      break;
    case 0x9c402644:
      uVar8 = FUN_000118b0(uVar9,*(undefined4 **)(param_2 + 0x18));
      iVar7 = (int)uVar8;
      break;
    case 0x9c402648:
      iVar7 = FUN_00011b90(uVar9,*(ulonglong **)(param_2 + 0x18));
      break;
    case 0x9c40264c:
      if (*(undefined8 **)(param_2 + 0x18) != (undefined8 *)0x0) {
        FUN_00012e10(*(undefined8 **)(param_2 + 0x18));
      }
      *puVar1 = 0x24;
      iVar7 = iVar10;
      break;
    case 0x9c402650:
      puVar6 = *(undefined8 **)(param_2 + 0x18);
      uVar8 = FUN_00012d20();
      local_10 = (ulonglong)DAT_00015190;
      *puVar6 = uVar8;
      puVar6[1] = local_10;
      *puVar1 = 0x10;
      iVar7 = iVar10;
    }
  }
  *(int *)(param_2 + 0x30) = iVar7;
  IofCompleteRequest(param_2,0);
  return iVar7;
}

