// Function: FUN_00012130
// Address: 00012130
// Decompiled by Ghidra


undefined8
FUN_00012130(PEXCEPTION_RECORD param_1,PVOID param_2,undefined8 param_3,longlong *param_4)

{
  longlong lVar1;
  uint *puVar2;
  int iVar3;
  ulonglong uVar4;
  uint *puVar5;
  uint uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  PEXCEPTION_RECORD local_58;
  undefined8 local_50;
  
  lVar1 = param_4[1];
  uVar8 = *param_4 - lVar1;
  puVar2 = (uint *)param_4[7];
  uVar6 = 0;
  if ((param_1->ExceptionFlags & 0x66) == 0) {
    local_58 = param_1;
    local_50 = param_3;
    if (*puVar2 != 0) {
      do {
        if (((puVar2[(ulonglong)uVar6 * 4 + 1] <= uVar8) &&
            (uVar8 < puVar2[(ulonglong)uVar6 * 4 + 2])) && (puVar2[(ulonglong)uVar6 * 4 + 4] != 0))
        {
          if (puVar2[(ulonglong)uVar6 * 4 + 3] != 1) {
            iVar3 = (*(code *)((ulonglong)puVar2[(ulonglong)uVar6 * 4 + 3] + lVar1))
                              (&local_58,param_2);
            if (iVar3 < 0) {
              return 0;
            }
            if (iVar3 < 1) goto LAB_00012203;
          }
          RtlUnwindEx(param_2,(PVOID)((ulonglong)puVar2[(ulonglong)uVar6 * 4 + 4] + lVar1),param_1,
                      (PVOID)(longlong)(int)param_1->ExceptionCode,(PCONTEXT)param_4[5],
                      (PUNWIND_HISTORY_TABLE)param_4[8]);
        }
LAB_00012203:
        uVar6 = uVar6 + 1;
      } while (uVar6 < *puVar2);
    }
  }
  else {
    uVar7 = param_4[4] - lVar1;
    if (*puVar2 != 0) {
      do {
        puVar5 = puVar2 + (ulonglong)uVar6 * 4;
        if ((puVar5[1] <= uVar8) && (uVar4 = (ulonglong)puVar5[2], uVar8 < uVar4)) {
          if ((puVar5[1] <= uVar7) && (uVar7 <= uVar4)) {
            return 1;
          }
          if (puVar5[4] == 0) {
            *param_4 = uVar4 + lVar1;
            (*(code *)((ulonglong)puVar5[3] + lVar1))
                      (CONCAT71((int7)((ulonglong)puVar5 >> 8),1),param_2);
          }
          else if (uVar7 == puVar5[4]) {
            return 1;
          }
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < *puVar2);
    }
  }
  return 1;
}

