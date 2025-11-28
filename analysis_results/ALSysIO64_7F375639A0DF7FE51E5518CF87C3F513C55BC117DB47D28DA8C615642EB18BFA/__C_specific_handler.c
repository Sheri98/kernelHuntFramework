// Function: __C_specific_handler
// Address: 00013414
// Decompiled by Ghidra


/* Library Function - Single Match
    __C_specific_handler
   
   Library: Visual Studio 2019 Release */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  longlong lVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  ulonglong uVar5;
  uint uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  _EXCEPTION_RECORD *local_38;
  _CONTEXT *local_30;
  
  lVar1 = *(longlong *)(DispatcherContext + 8);
  uVar6 = *(uint *)(DispatcherContext + 0x48);
  uVar7 = (ulonglong)(int)uVar6;
  puVar2 = *(uint **)(DispatcherContext + 0x38);
  uVar8 = *(longlong *)DispatcherContext - lVar1;
  if ((ExceptionRecord->ExceptionFlags & 0x66) == 0) {
    if (uVar6 < *puVar2) {
      puVar4 = puVar2 + uVar7 * 4 + 3;
      local_38 = ExceptionRecord;
      local_30 = ContextRecord;
      do {
        if (((puVar4[-2] <= uVar8) && (uVar8 < puVar4[-1])) && (puVar4[1] != 0)) {
          if (*puVar4 != 1) {
            iVar3 = (*(code *)((ulonglong)*puVar4 + lVar1))(&local_38,EstablisherFrame);
            if (iVar3 < 0) {
              return ExceptionContinueExecution;
            }
            if (iVar3 < 1) goto LAB_000134e5;
          }
          _NLG_Notify();
          RtlUnwindEx(EstablisherFrame,(PVOID)((ulonglong)puVar4[1] + lVar1),ExceptionRecord,
                      (PVOID)(longlong)(int)ExceptionRecord->ExceptionCode,
                      *(PCONTEXT *)(DispatcherContext + 0x28),
                      *(PUNWIND_HISTORY_TABLE *)(DispatcherContext + 0x40));
          FUN_00013b40();
        }
LAB_000134e5:
        uVar6 = (int)uVar7 + 1;
        uVar7 = (ulonglong)uVar6;
        puVar4 = puVar4 + 4;
      } while (uVar6 < *puVar2);
    }
  }
  else {
    uVar5 = *(longlong *)(DispatcherContext + 0x20) - lVar1;
    if (uVar6 < *puVar2) {
      puVar4 = puVar2 + uVar7 * 4 + 2;
      do {
        if (puVar4[-1] <= uVar8) {
          uVar6 = *puVar4;
          if (uVar8 < uVar6) {
            if (((puVar4[-1] <= uVar5) && (uVar5 <= uVar6)) &&
               ((ExceptionRecord->ExceptionFlags & 0x20) != 0)) {
              return ExceptionContinueSearch;
            }
            if (puVar4[2] == 0) {
              *(int *)(DispatcherContext + 0x48) = (int)uVar7 + 1;
              (*(code *)((ulonglong)puVar4[1] + lVar1))
                        (CONCAT71((uint7)(uint3)(uVar6 >> 8),1),EstablisherFrame);
            }
            else if (uVar5 == puVar4[2]) {
              return ExceptionContinueSearch;
            }
          }
        }
        uVar6 = (int)uVar7 + 1;
        uVar7 = (ulonglong)uVar6;
        puVar4 = puVar4 + 4;
      } while (uVar6 < *puVar2);
    }
  }
  return ExceptionContinueSearch;
}

