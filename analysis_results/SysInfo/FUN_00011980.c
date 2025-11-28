// Function: FUN_00011980
// Address: 00011980
// Decompiled by Ghidra


undefined1 FUN_00011980(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_2 + 0x40);
  if (*(longlong *)(lVar1 + 0x160) != 0) {
    IoDisconnectInterrupt();
    *(undefined8 *)(lVar1 + 0x160) = 0;
  }
  KeInsertQueueDpc(param_2 + 200,*(undefined8 *)(param_2 + 0x20),6);
  return 1;
}

