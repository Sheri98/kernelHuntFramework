// Function: FUN_00011eb0
// Address: 00011eb0
// Decompiled by Ghidra


undefined4 FUN_00011eb0(longlong param_1,longlong param_2)

{
  undefined4 *puVar1;
  char *pcVar2;
  ulonglong uVar3;
  undefined4 uVar4;
  uint local_res8 [4];
  
  puVar1 = *(undefined4 **)(param_1 + 0x40);
  pcVar2 = *(char **)(param_2 + 0xb8);
  uVar4 = 0;
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  if (*pcVar2 == '\x0e') {
    local_res8[0] = 0;
    uVar3 = FUN_00011c00(*(undefined4 *)(pcVar2 + 0x18),*(uint **)(param_2 + 0x18),
                         *(uint *)(pcVar2 + 0x10),(undefined8 *)*(uint **)(param_2 + 0x18),
                         *(uint *)(pcVar2 + 8),local_res8,puVar1);
    *(ulonglong *)(param_2 + 0x38) = (ulonglong)local_res8[0];
    uVar4 = (undefined4)uVar3;
  }
  *(undefined4 *)(param_2 + 0x30) = uVar4;
  IofCompleteRequest(param_2,0);
  return uVar4;
}

