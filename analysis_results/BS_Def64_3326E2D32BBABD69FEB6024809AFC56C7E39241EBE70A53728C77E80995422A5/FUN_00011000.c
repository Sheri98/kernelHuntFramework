// Function: FUN_00011000
// Address: 00011000
// Decompiled by Ghidra


undefined8 FUN_00011000(undefined8 param_1,longlong param_2)

{
  char cVar1;
  uint uVar2;
  undefined2 *puVar3;
  char *pcVar4;
  
  puVar3 = *(undefined2 **)(param_2 + 0x18);
  uVar2 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(puVar3 + 4) = 0;
  *puVar3 = 0;
  *(char (*) [8])(puVar3 + 6) = s_Unknown_00011080;
  if (7 < uVar2) {
    if ((DAT_00014048 == 4) || (DAT_00014048 == 5)) {
      *(undefined4 *)(puVar3 + 4) = DAT_00014000;
      pcVar4 = &DAT_00014070;
      do {
        cVar1 = *pcVar4;
        *(char *)((longlong)(puVar3 + -0xa032) + (longlong)pcVar4) = cVar1;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      *puVar3 = 0xa3f;
    }
    *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar2;
  }
  return 0;
}

