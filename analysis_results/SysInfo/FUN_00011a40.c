// Function: FUN_00011a40
// Address: 00011a40
// Decompiled by Ghidra


undefined1 FUN_00011a40(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_2 + 0x40);
  if (*(longlong *)(lVar1 + 0x1d0) != 0) {
    IoDisconnectInterrupt();
    *(undefined8 *)(lVar1 + 0x1d0) = 0;
  }
  KeInsertQueueDpc(param_2 + 200,*(undefined8 *)(param_2 + 0x20),8);
  return 1;
}

