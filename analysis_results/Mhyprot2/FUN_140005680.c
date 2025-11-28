// Function: FUN_140005680
// Address: 140005680
// Decompiled by Ghidra


ulonglong FUN_140005680(ulonglong *param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  code *pcVar2;
  ulonglong uVar3;
  code *pcVar4;
  code *pcVar5;
  bool bVar6;
  
  pcVar2 = (code *)MmIsAddressValid(param_3);
  if ((char)pcVar2 == '\0') {
LAB_1400056aa:
    uVar3 = CONCAT71((int7)((ulonglong)pcVar2 >> 8),1);
  }
  else {
    pcVar4 = (code *)FUN_140005784(*param_1);
    pcVar5 = pcVar4;
    if (pcVar4 != (code *)0x0) {
      pcVar5 = (code *)MmIsAddressValid(pcVar4);
      if ((char)pcVar5 != '\0') {
        uVar1 = *param_3;
        pcVar2 = (code *)ObGetObjectType(pcVar4);
        if (pcVar2 == *(code **)PsProcessType_exref) {
          bVar6 = param_2 == uVar1;
        }
        else {
          pcVar5 = PsThreadType_exref;
          if (pcVar2 != *(code **)PsThreadType_exref) goto LAB_140005713;
          pcVar4 = (code *)IoThreadToProcess(pcVar4);
          pcVar2 = (code *)FUN_140003d08((longlong)pcVar4);
          bVar6 = pcVar2 == (code *)(ulonglong)uVar1;
        }
        pcVar5 = pcVar2;
        if (bVar6) {
          *(code **)(param_3 + 2) = pcVar4;
          goto LAB_1400056aa;
        }
      }
    }
LAB_140005713:
    uVar3 = (ulonglong)pcVar5 & 0xffffffffffffff00;
  }
  return uVar3;
}

