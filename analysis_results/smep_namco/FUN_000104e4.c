// Function: FUN_000104e4
// Address: 000104e4
// Decompiled by Ghidra


undefined4 FUN_000104e4(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  if ((**(char **)(param_2 + 0xb8) != '\0') && (**(char **)(param_2 + 0xb8) != '\x02')) {
    *(undefined4 *)(param_2 + 0x30) = 0xc0000002;
  }
  IofCompleteRequest(param_2,0);
  return *(undefined4 *)(param_2 + 0x30);
}

