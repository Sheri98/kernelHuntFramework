// Function: FUN_00011650
// Address: 00011650
// Decompiled by Ghidra


undefined8 FUN_00011650(longlong param_1,int param_2)

{
  undefined1 uVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  lVar3 = (longlong)param_2 * 0x38;
  if (*(char *)(lVar3 + 0x18 + param_1) == '\0') {
    uVar2 = 0xc0000005;
  }
  else if (*(longlong *)(lVar3 + 0x10 + param_1) == 0) {
    KeClearEvent(*(undefined8 *)(lVar3 + 0x40 + param_1));
    uVar1 = *(undefined1 *)(lVar3 + 0x28 + param_1);
    uVar2 = IoConnectInterrupt(lVar3 + 0x10 + param_1,(&PTR_FUN_00014100)[param_2],
                               *(undefined8 *)(param_1 + 8),0,
                               *(undefined4 *)(lVar3 + 0x2c + param_1),uVar1,uVar1,
                               *(undefined4 *)(lVar3 + 0x30 + param_1),
                               *(undefined1 *)(lVar3 + 0x34 + param_1),
                               *(undefined8 *)(lVar3 + 0x20 + param_1),0);
  }
  else {
    uVar2 = 0xc0000005;
  }
  return uVar2;
}

