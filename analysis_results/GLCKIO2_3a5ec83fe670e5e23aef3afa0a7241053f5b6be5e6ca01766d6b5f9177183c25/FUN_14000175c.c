// Function: FUN_14000175c
// Address: 14000175c
// Decompiled by Ghidra


ulonglong FUN_14000175c(void)

{
  ulonglong uVar1;
  longlong *plVar2;
  longlong local_res8 [4];
  
  local_res8[0] = 0;
  uVar1 = FUN_1400016e8(local_res8);
  if (-1 < (int)uVar1) {
    plVar2 = &DAT_140004010;
    do {
      if (*plVar2 == local_res8[0]) {
        return 0;
      }
      plVar2 = plVar2 + 1;
      uVar1 = 0xc0000001;
    } while ((longlong)plVar2 < 0x140004210);
  }
  return uVar1;
}

