// Function: FUN_140001e54
// Address: 140001e54
// Decompiled by Ghidra


void FUN_140001e54(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  ulonglong uVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x28);
  memset(param_2 + 1,0,0x418);
  *param_2 = param_1;
  lVar2 = *(longlong *)(param_1 + 0x18);
  param_2[1] = lVar2;
  *(undefined4 *)(param_2 + 2) = *(undefined4 *)(param_1 + 0x20);
  if (lVar2 == 0) {
    cVar3 = MmIsAddressValid(lVar1);
    if (cVar3 == '\x01') {
      param_2[1] = *(longlong *)(lVar1 + 0x30);
    }
  }
  if ((int)param_2[2] == 0) {
    cVar3 = MmIsAddressValid(lVar1);
    if (cVar3 == '\x01') {
      *(undefined4 *)(param_2 + 2) = *(undefined4 *)(lVar1 + 0x40);
    }
  }
  if ((undefined8 *)(param_1 + 0x40) != (undefined8 *)0x0) {
    uVar4 = 0x7f;
    if (*(ushort *)(param_1 + 0x38) < 0x80) {
      uVar4 = (ulonglong)*(ushort *)(param_1 + 0x38);
    }
    FUN_1400075c0((undefined8 *)((longlong)param_2 + 0x14),*(undefined8 **)(param_1 + 0x40),uVar4);
  }
  cVar3 = MmIsAddressValid(lVar1);
  if ((cVar3 == '\x01') && ((undefined8 *)(lVar1 + 0x50) != (undefined8 *)0x0)) {
    uVar4 = 0x103;
    if (*(ushort *)(lVar1 + 0x48) < 0x104) {
      uVar4 = (ulonglong)*(ushort *)(lVar1 + 0x48);
    }
    FUN_1400075c0((undefined8 *)((longlong)param_2 + 0x114),*(undefined8 **)(lVar1 + 0x50),uVar4);
  }
  return;
}

