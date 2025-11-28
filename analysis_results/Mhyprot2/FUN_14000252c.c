// Function: FUN_14000252c
// Address: 14000252c
// Decompiled by Ghidra


void FUN_14000252c(longlong *param_1,longlong param_2)

{
  code *pcVar1;
  longlong *plVar2;
  longlong lVar3;
  uint uVar4;
  ushort local_28 [4];
  undefined8 *local_20;
  ushort local_18 [4];
  undefined8 *local_10;
  
  FUN_140002e2c((short *)local_18,(short *)(ulonglong)*(uint *)(param_2 + 0x28));
  FUN_140002e2c((short *)local_28,(short *)(ulonglong)*(uint *)(param_2 + 0x30));
  plVar2 = (longlong *)ExAllocatePool(0);
  memset(plVar2 + 2,0,0x318);
  plVar2[2] = (ulonglong)*(uint *)(param_2 + 0x18);
  *(undefined4 *)(plVar2 + 3) = *(undefined4 *)(param_2 + 0x20);
  uVar4 = 0x7f;
  if (local_28[0] < 0x80) {
    uVar4 = (uint)local_28[0];
  }
  FUN_1400075c0((undefined8 *)((longlong)plVar2 + 0x1c),local_20,(ulonglong)uVar4);
  uVar4 = 0x103;
  if (local_18[0] < 0x104) {
    uVar4 = (uint)local_18[0];
  }
  FUN_1400075c0((undefined8 *)((longlong)plVar2 + 0x11c),local_10,(ulonglong)uVar4);
  lVar3 = *param_1;
  if (*(longlong **)(lVar3 + 8) != param_1) {
    pcVar1 = (code *)swi(0x29);
    lVar3 = (*pcVar1)(3);
  }
  *plVar2 = lVar3;
  plVar2[1] = (longlong)param_1;
  *(longlong **)(lVar3 + 8) = plVar2;
  *param_1 = (longlong)plVar2;
  return;
}

