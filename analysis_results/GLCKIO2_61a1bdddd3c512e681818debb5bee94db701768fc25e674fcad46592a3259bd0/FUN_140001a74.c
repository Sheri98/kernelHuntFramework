// Function: FUN_140001a74
// Address: 140001a74
// Decompiled by Ghidra


ulonglong FUN_140001a74(void)

{
  ulonglong uVar1;
  longlong *plVar2;
  ulonglong uVar3;
  int iVar4;
  longlong local_res8 [4];
  
  local_res8[0] = 0;
  uVar1 = FUN_1400016e8(local_res8);
  uVar3 = uVar1;
  if (-1 < (int)uVar1) {
    plVar2 = &DAT_140004010;
    iVar4 = 0;
    do {
      if (*plVar2 == local_res8[0]) {
        (&DAT_140004010)[iVar4] = 0;
        return 0;
      }
      iVar4 = iVar4 + 1;
      plVar2 = plVar2 + 1;
      uVar3 = uVar1 & 0xffffffff;
    } while ((longlong)plVar2 < 0x140004210);
  }
  return uVar3;
}

