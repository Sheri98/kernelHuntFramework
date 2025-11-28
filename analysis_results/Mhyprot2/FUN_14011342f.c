// Function: FUN_14011342f
// Address: 14011342f
// Decompiled by Ghidra


void FUN_14011342f(undefined8 param_1,uint param_2)

{
  short sVar1;
  int iVar2;
  ushort unaff_R15W;
  
  iVar2 = 0x1f;
  if (param_2 != 0) {
    for (; param_2 >> iVar2 == 0; iVar2 = iVar2 + -1) {
    }
  }
  sVar1 = 0;
  if (unaff_R15W != 0) {
    for (; (unaff_R15W >> sVar1 & 1) == 0; sVar1 = sVar1 + 1) {
    }
  }
  FUN_14006148a();
  return;
}

