// Function: __GSHandlerCheck_SEH
// Address: 00013bfc
// Decompiled by Ghidra


/* Library Function - Single Match
    __GSHandlerCheck_SEH
   
   Library: Visual Studio 2019 Release */

EXCEPTION_DISPOSITION
__GSHandlerCheck_SEH
          (_EXCEPTION_RECORD *param_1,void *param_2,_CONTEXT *param_3,_DISPATCHER_CONTEXT *param_4)

{
  uint *puVar1;
  uint uVar2;
  EXCEPTION_DISPOSITION EVar3;
  uint uVar4;
  
  puVar1 = *(uint **)(param_4 + 0x38) + (ulonglong)**(uint **)(param_4 + 0x38) * 4 + 1;
  __GSHandlerCheckCommon((ulonglong)param_2,(longlong)param_4,puVar1);
  uVar2 = *puVar1;
  EVar3 = ExceptionContinueSearch;
  uVar4 = uVar2 & 2;
  if ((param_1->ExceptionFlags & 0x66) == 0) {
    uVar4 = uVar2 & 1;
  }
  if (uVar4 != 0) {
    EVar3 = __C_specific_handler(param_1,param_2,param_3,param_4);
  }
  return EVar3;
}

