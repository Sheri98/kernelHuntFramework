// Function: FUN_00011870
// Address: 00011870
// Decompiled by Ghidra


undefined8 FUN_00011870(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  undefined2 *puVar5;
  ulonglong uVar4;
  
  uVar1 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  uVar2 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
  puVar5 = *(undefined2 **)(param_2 + 0x18);
  *(undefined8 *)(param_2 + 0x38) = 0;
  if ((0x107 < uVar1) && (0x47 < uVar2)) {
    if (DAT_00014048 == 4) {
      uVar4 = FUN_00011410((longlong)puVar5);
      cVar3 = (char)uVar4;
    }
    else {
      if (DAT_00014048 != 5) {
        return 0;
      }
      uVar4 = FUN_00011700((longlong)puVar5);
      cVar3 = (char)uVar4;
    }
    if (cVar3 != '\0') {
      *puVar5 = *puVar5;
      puVar5[1] = puVar5[1];
      *(undefined4 *)(puVar5 + 2) = *(undefined4 *)(puVar5 + 2);
      *(undefined8 *)(param_2 + 0x38) = 0x48;
    }
  }
  return 0;
}

