// Function: FUN_14008c092
// Address: 14008c092
// Decompiled by Ghidra


void FUN_14008c092(void)

{
  short sVar1;
  int iVar2;
  ushort unaff_BX;
  undefined8 auStack_60 [2];
  
  sVar1 = 0;
  if (unaff_BX != 0) {
    for (; (unaff_BX >> sVar1 & 1) == 0; sVar1 = sVar1 + 1) {
    }
  }
  auStack_60[0] = 0;
  iVar2 = 0x1f;
  if ((uint)auStack_60 != 0) {
    for (; (uint)auStack_60 >> iVar2 == 0; iVar2 = iVar2 + -1) {
    }
  }
  FUN_1400ac314();
  return;
}

