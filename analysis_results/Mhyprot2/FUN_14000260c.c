// Function: FUN_14000260c
// Address: 14000260c
// Decompiled by Ghidra


void FUN_14000260c(longlong *param_1,longlong param_2)

{
  code *pcVar1;
  longlong *plVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  plVar2 = (longlong *)ExAllocatePool(0);
  memset(plVar2 + 2,0,0x318);
  plVar2[2] = *(longlong *)(param_2 + 0x30);
  *(undefined4 *)(plVar2 + 3) = *(undefined4 *)(param_2 + 0x40);
  uVar4 = 0x7f;
  if (*(ushort *)(param_2 + 0x58) < 0x80) {
    uVar4 = (ulonglong)*(ushort *)(param_2 + 0x58);
  }
  FUN_1400075c0((undefined8 *)((longlong)plVar2 + 0x1c),*(undefined8 **)(param_2 + 0x60),uVar4);
  uVar4 = 0x103;
  if (*(ushort *)(param_2 + 0x48) < 0x104) {
    uVar4 = (ulonglong)*(ushort *)(param_2 + 0x48);
  }
  FUN_1400075c0((undefined8 *)((longlong)plVar2 + 0x11c),*(undefined8 **)(param_2 + 0x50),uVar4);
  lVar3 = *param_1;
  if (*(longlong **)(lVar3 + 8) != param_1) {
    pcVar1 = (code *)swi(0x29);
    lVar3 = (*pcVar1)(3);
  }
  plVar2[1] = (longlong)param_1;
  *plVar2 = lVar3;
  *(longlong **)(lVar3 + 8) = plVar2;
  *param_1 = (longlong)plVar2;
  return;
}

