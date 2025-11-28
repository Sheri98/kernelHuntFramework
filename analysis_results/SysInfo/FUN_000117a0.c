// Function: FUN_000117a0
// Address: 000117a0
// Decompiled by Ghidra


undefined1 FUN_000117a0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_2 + 0x40);
  if (*(longlong *)(lVar1 + 0x48) != 0) {
    IoDisconnectInterrupt();
    *(undefined8 *)(lVar1 + 0x48) = 0;
  }
  KeInsertQueueDpc(param_2 + 200,*(undefined8 *)(param_2 + 0x20),1);
  return 1;
}

