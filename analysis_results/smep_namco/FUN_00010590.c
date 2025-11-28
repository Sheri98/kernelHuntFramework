// Function: FUN_00010590
// Address: 00010590
// Decompiled by Ghidra


undefined4 FUN_00010590(undefined8 param_1,longlong param_2)

{
  int iVar1;
  char *pcVar2;
  uint *puVar3;
  bool bVar4;
  uint uVar5;
  undefined7 extraout_var;
  uint uVar6;
  undefined *puVar7;
  uint uVar8;
  
  pcVar2 = *(char **)(param_2 + 0xb8);
  puVar3 = *(uint **)(param_2 + 0x18);
  uVar6 = 0;
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  iVar1 = *(int *)(pcVar2 + 0x18);
  if (*pcVar2 != '\x0e') {
    *(undefined4 *)(param_2 + 0x30) = 0xc0000002;
    goto LAB_00010626;
  }
  uVar8 = 0;
  if (iVar1 == -0x55fedfbc) {
    uVar8 = 4;
    uVar5 = 4;
  }
  else {
    uVar5 = uVar6;
    if (iVar1 == -0x55fecfbc) {
      uVar5 = 8;
      uVar8 = 4;
    }
  }
  if ((*(uint *)(pcVar2 + 0x10) != uVar5) || (*(uint *)(pcVar2 + 8) != uVar8)) {
    *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
    goto LAB_00010626;
  }
  if (iVar1 == -0x55fedfbc) {
    puVar7 = (undefined *)(ulonglong)*puVar3;
LAB_0001060e:
    bVar4 = FUN_00010524(puVar7);
    uVar6 = (uint)CONCAT71(extraout_var,bVar4);
  }
  else if (iVar1 == -0x55fecfbc) {
    puVar7 = *(undefined **)puVar3;
    goto LAB_0001060e;
  }
  *puVar3 = uVar6;
  *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar8;
LAB_00010626:
  IofCompleteRequest(param_2,0);
  return *(undefined4 *)(param_2 + 0x30);
}

