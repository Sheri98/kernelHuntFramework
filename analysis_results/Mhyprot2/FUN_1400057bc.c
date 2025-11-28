// Function: FUN_1400057bc
// Address: 1400057bc
// Decompiled by Ghidra


void FUN_1400057bc(longlong *param_1,undefined4 param_2,longlong param_3)

{
  code *pcVar1;
  int iVar2;
  longlong *plVar3;
  undefined4 *_Dst;
  undefined8 uVar4;
  longlong lVar5;
  
  plVar3 = (longlong *)ExAllocatePool(0,0x18);
  _Dst = (undefined4 *)ExAllocatePool(0);
  memset(_Dst,0,0x2a8);
  plVar3[2] = (longlong)_Dst;
  ObfReferenceObject(param_3);
  *_Dst = param_2;
  *(longlong *)(_Dst + 0x84) = param_3;
  uVar4 = FUN_140003d8c(param_3);
  *(undefined8 *)(_Dst + 0x86) = uVar4;
  iVar2 = FUN_14000344c();
  _Dst[0x88] = (uint)(iVar2 != 0x20);
  FUN_140003c9c(param_3,(undefined8 *)(_Dst + 1),0x104);
  ObfDereferenceObject(param_3);
  lVar5 = *param_1;
  if (*(longlong **)(lVar5 + 8) != param_1) {
    pcVar1 = (code *)swi(0x29);
    lVar5 = (*pcVar1)(3);
  }
  *plVar3 = lVar5;
  plVar3[1] = (longlong)param_1;
  *(longlong **)(lVar5 + 8) = plVar3;
  *param_1 = (longlong)plVar3;
  return;
}

