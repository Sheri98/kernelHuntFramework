// Function: FUN_140004f44
// Address: 140004f44
// Decompiled by Ghidra


undefined4 FUN_140004f44(char param_1)

{
  int *piVar1;
  int iVar2;
  undefined1 uVar3;
  longlong lVar4;
  uint uVar5;
  
  uVar3 = 0;
  uVar5 = 0;
  lVar4 = 0;
  if (param_1 == '\0') {
    do {
      iVar2 = *(int *)(FUN_140004fb0 + lVar4);
      piVar1 = (int *)((longlong)&DAT_14000a690 + lVar4);
      lVar4 = lVar4 + 4;
      if (*piVar1 != iVar2) {
        uVar3 = 1;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < 8);
  }
  else {
    do {
      iVar2 = *(int *)(FUN_1400050d0 + lVar4);
      piVar1 = (int *)((longlong)&DAT_14000a6b0 + lVar4);
      lVar4 = lVar4 + 4;
      if (*piVar1 != iVar2) {
        uVar3 = 1;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < 8);
  }
  return CONCAT31((int3)((uint)iVar2 >> 8),uVar3);
}

