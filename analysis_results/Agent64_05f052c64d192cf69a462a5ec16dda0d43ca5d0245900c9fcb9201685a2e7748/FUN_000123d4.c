// Function: FUN_000123d4
// Address: 000123d4
// Decompiled by Ghidra


void FUN_000123d4(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_2 + 0x20);
  KeSetEvent(*(undefined8 *)(*(longlong *)(param_2 + 0x40) + 0x60),0,0);
  if (lVar1 != 0) {
    *(undefined8 *)(lVar1 + 0x38) = 0;
    *(undefined4 *)(lVar1 + 0x30) = 0;
    IoStartNextPacket(param_2,0);
    IofCompleteRequest(lVar1,0);
  }
  return;
}

