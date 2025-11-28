// Function: FUN_000118f0
// Address: 000118f0
// Decompiled by Ghidra


undefined8 FUN_000118f0(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  uint uVar2;
  undefined2 *puVar3;
  char cVar4;
  ulonglong uVar5;
  
  uVar1 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  uVar2 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
  puVar3 = *(undefined2 **)(param_2 + 0x18);
  *(undefined8 *)(param_2 + 0x38) = 0;
  if ((0x47 < uVar1) && (0x107 < uVar2)) {
    if (DAT_00014048 == 4) {
      uVar5 = FUN_000111b0((longlong)puVar3,(longlong)puVar3);
      cVar4 = (char)uVar5;
    }
    else {
      if (DAT_00014048 != 5) {
        return 0;
      }
      uVar5 = FUN_00011500((longlong)puVar3,(longlong)puVar3);
      cVar4 = (char)uVar5;
    }
    if (cVar4 != '\0') {
      *puVar3 = *puVar3;
      puVar3[1] = puVar3[1];
      *(undefined4 *)(puVar3 + 2) = *(undefined4 *)(puVar3 + 2);
      *(undefined8 *)(param_2 + 0x38) = 0x108;
    }
  }
  return 0;
}

