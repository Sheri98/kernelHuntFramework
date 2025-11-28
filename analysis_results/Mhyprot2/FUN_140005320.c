// Function: FUN_140005320
// Address: 140005320
// Decompiled by Ghidra


ulonglong FUN_140005320(ulonglong *param_1,uint param_2,undefined8 *param_3)

{
  int iVar1;
  char cVar2;
  undefined8 uVar3;
  code *pcVar4;
  code *pcVar5;
  code *pcVar6;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  uint uVar7;
  bool bVar8;
  
  uVar3 = MmIsAddressValid(param_3);
  if (((char)uVar3 == '\0') || (uVar3 = MmIsAddressValid(*param_3), (char)uVar3 == '\0')) {
    return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
  }
  pcVar4 = (code *)FUN_140005784(*param_1);
  pcVar5 = pcVar4;
  if ((pcVar4 == (code *)0x0) || (pcVar5 = (code *)MmIsAddressValid(pcVar4), (char)pcVar5 == '\0'))
  goto LAB_14000544f;
  pcVar6 = (code *)ObGetObjectType(pcVar4);
  if (pcVar6 == *(code **)PsProcessType_exref) {
    pcVar5 = pcVar6;
    if (*(int *)(param_3 + 1) != 0) goto LAB_14000544f;
    cVar2 = FUN_1400055f0((undefined8 *)*param_3,(longlong)pcVar4);
    pcVar5 = (code *)CONCAT71(extraout_var,cVar2);
    if (cVar2 != '\0') goto LAB_14000544f;
    pcVar5 = (code *)FUN_140003528((longlong)pcVar4);
    cVar2 = (char)pcVar5;
  }
  else {
    pcVar5 = PsThreadType_exref;
    if (pcVar6 != *(code **)PsThreadType_exref) goto LAB_14000544f;
    pcVar6 = (code *)IoThreadToProcess(pcVar4);
    pcVar5 = (code *)FUN_140003d08((longlong)pcVar6);
    iVar1 = *(int *)(param_3 + 1);
    uVar7 = (uint)pcVar5;
    if (iVar1 != 0) {
      if (iVar1 == 1) {
        uVar7 = *(uint *)((longlong)param_3 + 0xc);
        bVar8 = pcVar5 != (code *)(ulonglong)uVar7;
        pcVar5 = (code *)(ulonglong)uVar7;
        if (bVar8) goto LAB_14000544f;
      }
      else if (iVar1 != 2) goto LAB_14000544f;
      pcVar5 = (code *)FUN_14000589c((longlong *)*param_3,uVar7,param_2,(longlong)pcVar4);
      goto LAB_14000544f;
    }
    cVar2 = FUN_1400055f0((undefined8 *)*param_3,(longlong)pcVar6);
    pcVar5 = (code *)CONCAT71(extraout_var_00,cVar2);
    if (cVar2 != '\0') goto LAB_14000544f;
    pcVar5 = (code *)FUN_140003528((longlong)pcVar6);
    cVar2 = (char)pcVar5;
    pcVar4 = pcVar6;
    param_2 = uVar7;
  }
  if (cVar2 == '\0') {
    pcVar5 = (code *)FUN_1400057bc((longlong *)*param_3,param_2,(longlong)pcVar4);
  }
LAB_14000544f:
  return (ulonglong)pcVar5 & 0xffffffffffffff00;
}

