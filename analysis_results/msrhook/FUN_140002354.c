// Function: FUN_140002354
// Address: 140002354
// Decompiled by Ghidra


undefined8 FUN_140002354(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  
  if (param_1 == DAT_1400075c0) {
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000010;
    IofCompleteRequest(param_2,0);
    uVar2 = 0xc0000010;
  }
  else {
    lVar1 = *(longlong *)(param_1 + 0x40);
    PoStartNextPowerIrp(param_2);
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    uVar2 = PoCallDriver(*(undefined8 *)(lVar1 + 0x38),param_2);
  }
  return uVar2;
}

