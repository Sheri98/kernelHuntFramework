// Function: FUN_140002068
// Address: 140002068
// Decompiled by Ghidra


void FUN_140002068(longlong param_1)

{
  longlong lVar1;
  
  if (param_1 != DAT_1400075c0) {
    lVar1 = *(longlong *)(param_1 + 0x40);
    if (*(longlong *)(lVar1 + 0x30) != 0) {
      IoDetachDevice();
    }
    *(undefined8 *)(lVar1 + 0x30) = 0;
    IoDeleteDevice(param_1);
    *(undefined8 *)(lVar1 + 8) = 0;
    DbgPrint("Detach Finished\n");
    FUN_140001994();
    FUN_140002868(*(longlong *)(lVar1 + 0x38));
  }
  return;
}

