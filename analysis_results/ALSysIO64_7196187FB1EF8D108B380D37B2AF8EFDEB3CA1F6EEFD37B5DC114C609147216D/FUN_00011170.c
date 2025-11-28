// Function: FUN_00011170
// Address: 00011170
// Decompiled by Ghidra


int FUN_00011170(undefined8 param_1,longlong param_2)

{
  uint *puVar1;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  undefined4 *puVar5;
  undefined8 *puVar6;
  undefined4 uVar7;
  int iVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  undefined4 in_stack_ffffffffffffffec;
  
  pcVar4 = *(char **)(param_2 + 0xb8);
  puVar1 = (uint *)(param_2 + 0x38);
  puVar1[0] = 0;
  puVar1[1] = 0;
  cVar2 = *pcVar4;
  iVar8 = -0x3ffffffe;
  if ((cVar2 == '\0') || (cVar2 == '\x02')) goto LAB_0001145f;
  if (cVar2 != '\x0e') goto switchD_000111ee_caseD_9c402605;
  uVar10 = (ulonglong)*(uint *)(pcVar4 + 0x18);
  switch(*(uint *)(pcVar4 + 0x18)) {
  case 0x9c402604:
    uVar9 = FUN_000115b0(uVar10,*(undefined4 **)(param_2 + 0x18),(ulonglong)*(uint *)(pcVar4 + 0x10)
                         ,*(undefined4 **)(param_2 + 0x18),
                         CONCAT44(in_stack_ffffffffffffffec,*(undefined4 *)(pcVar4 + 8)),puVar1);
    iVar8 = (int)uVar9;
    break;
  case 0x9c402608:
    uVar9 = FUN_00011640(uVar10,*(undefined4 **)(param_2 + 0x18));
    iVar8 = (int)uVar9;
    break;
  case 0x9c402618:
    puVar6 = *(undefined8 **)(param_2 + 0x18);
    uVar9 = *puVar6;
    uVar3 = *(uint *)(puVar6 + 1);
    DbgPrint("io 356");
    uVar9 = FUN_00012eb0(uVar9,puVar6,(ulonglong)uVar3);
    iVar8 = (int)uVar9;
    if (iVar8 != 0) {
      *puVar1 = 0;
      break;
    }
    *puVar1 = uVar3;
    goto LAB_0001145f;
  case 0x9c40261c:
    puVar6 = *(undefined8 **)(param_2 + 0x18);
    uVar9 = *puVar6;
    uVar3 = *(uint *)(puVar6 + 1);
    DbgPrint("io 385");
    *puVar1 = 0;
    uVar9 = FUN_00012f50(uVar9,(void *)((longlong)puVar6 + 0xc),(ulonglong)uVar3);
    iVar8 = (int)uVar9;
    break;
  case 0x9c402620:
    iVar8 = FUN_000119e0(uVar10,*(undefined4 **)(param_2 + 0x18),(ulonglong)*(uint *)(pcVar4 + 0x10)
                         ,*(undefined4 **)(param_2 + 0x18),
                         CONCAT44(in_stack_ffffffffffffffec,*(undefined4 *)(pcVar4 + 8)),puVar1);
    break;
  case 0x9c402624:
    puVar5 = *(undefined4 **)(param_2 + 0x18);
    DbgPrint("io 390");
    *puVar5 = 0x20008;
    *puVar1 = 4;
    goto LAB_0001145f;
  case 0x9c402628:
    puVar5 = *(undefined4 **)(param_2 + 0x18);
    DbgPrint("io 407");
    uVar7 = FUN_00013230();
    *puVar5 = uVar7;
    *puVar1 = 4;
    goto LAB_0001145f;
  case 0x9c40262c:
    uVar9 = FUN_00011b00(uVar10,*(uint **)(param_2 + 0x18),(ulonglong)*(uint *)(pcVar4 + 0x10),
                         *(uint **)(param_2 + 0x18),
                         CONCAT44(in_stack_ffffffffffffffec,*(undefined4 *)(pcVar4 + 8)),puVar1);
    iVar8 = (int)uVar9;
    break;
  case 0x9c402630:
    uVar9 = FUN_000116e0(uVar10,*(undefined4 **)(param_2 + 0x18),(ulonglong)*(uint *)(pcVar4 + 0x10)
                         ,*(undefined4 **)(param_2 + 0x18),
                         CONCAT44(in_stack_ffffffffffffffec,*(undefined4 *)(pcVar4 + 8)),puVar1);
    iVar8 = (int)uVar9;
    break;
  case 0x9c402634:
    uVar9 = FUN_00011760(uVar10,*(undefined4 **)(param_2 + 0x18));
    iVar8 = (int)uVar9;
    break;
  case 0x9c402638:
    uVar9 = FUN_000117e0(uVar10,*(undefined4 **)(param_2 + 0x18),(ulonglong)*(uint *)(pcVar4 + 0x10)
                         ,*(undefined4 **)(param_2 + 0x18),
                         CONCAT44(in_stack_ffffffffffffffec,*(undefined4 *)(pcVar4 + 8)),puVar1);
    iVar8 = (int)uVar9;
    break;
  case 0x9c40263c:
    uVar9 = FUN_00011860(uVar10,*(undefined4 **)(param_2 + 0x18));
    iVar8 = (int)uVar9;
    break;
  case 0x9c402640:
    uVar9 = FUN_000118e0(uVar10,*(undefined4 **)(param_2 + 0x18),(ulonglong)*(uint *)(pcVar4 + 0x10)
                         ,*(undefined4 **)(param_2 + 0x18),
                         CONCAT44(in_stack_ffffffffffffffec,*(undefined4 *)(pcVar4 + 8)),puVar1);
    iVar8 = (int)uVar9;
    break;
  case 0x9c402644:
    uVar9 = FUN_00011960(uVar10,*(undefined4 **)(param_2 + 0x18));
    iVar8 = (int)uVar9;
    break;
  case 0x9c402648:
    iVar8 = FUN_00011da0(uVar10,*(ulonglong **)(param_2 + 0x18));
    break;
  case 0x9c40264c:
    puVar6 = *(undefined8 **)(param_2 + 0x18);
    DbgPrint("io 420");
    DbgPrint("misc 215");
    if (puVar6 != (undefined8 *)0x0) {
      FUN_00012ff0(puVar6);
    }
    *puVar1 = 0x28;
LAB_0001145f:
    iVar8 = 0;
  }
switchD_000111ee_caseD_9c402605:
  *(int *)(param_2 + 0x30) = iVar8;
  IofCompleteRequest(param_2,0);
  return iVar8;
}

