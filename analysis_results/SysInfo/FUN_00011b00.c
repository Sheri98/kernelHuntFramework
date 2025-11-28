// Function: FUN_00011b00
// Address: 00011b00
// Decompiled by Ghidra


undefined1 FUN_00011b00(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_2 + 0x40);
  if (*(longlong *)(lVar1 + 0x240) != 0) {
    IoDisconnectInterrupt();
    *(undefined8 *)(lVar1 + 0x240) = 0;
  }
  KeInsertQueueDpc(param_2 + 200,*(undefined8 *)(param_2 + 0x20),10);
  return 1;
}

