// Function: FUN_14000589c
// Address: 14000589c
// Decompiled by Ghidra


void FUN_14000589c(longlong *param_1,undefined4 param_2,undefined4 param_3,longlong param_4)

{
  code *pcVar1;
  byte bVar2;
  longlong *plVar3;
  undefined4 *puVar4;
  longlong lVar5;
  
  plVar3 = (longlong *)ExAllocatePool(0,0x18);
  puVar4 = (undefined4 *)ExAllocatePool(0,0x20);
  plVar3[2] = (longlong)puVar4;
  *puVar4 = param_2;
  puVar4[1] = param_3;
  ObfReferenceObject(param_4);
  *(longlong *)(puVar4 + 2) = param_4;
  lVar5 = FUN_1400068c8(param_4);
  *(longlong *)(puVar4 + 4) = lVar5;
  bVar2 = FUN_1400067f4(param_4);
  puVar4[6] = (uint)(bVar2 != 0);
  ObfDereferenceObject(param_4);
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

