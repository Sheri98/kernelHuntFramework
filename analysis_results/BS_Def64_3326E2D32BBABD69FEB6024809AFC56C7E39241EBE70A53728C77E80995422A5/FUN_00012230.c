// Function: FUN_00012230
// Address: 00012230
// Decompiled by Ghidra


undefined2 FUN_00012230(void)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined2 uVar4;
  ulonglong uVar5;
  char local_30 [32];
  
  builtin_strncpy(local_30,"$@AWDFLASH",0xb);
  uVar4 = 0;
  lVar1 = MmMapIoSpace(0xf0000);
  if (lVar1 == 0) {
    return 0;
  }
  uVar5 = 0;
  while( true ) {
    uVar3 = 0;
    while (*(char *)(uVar5 + uVar3 + lVar1) == local_30[uVar3]) {
      uVar2 = (uint)uVar3 + 1;
      uVar3 = (ulonglong)uVar2;
      if (9 < uVar2) goto LAB_000122cb;
    }
    if (9 < (uint)uVar3) break;
    uVar2 = (int)uVar5 + 1;
    uVar5 = (ulonglong)uVar2;
    if (0xffdf < uVar2) {
LAB_000122d4:
      MmUnmapIoSpace(lVar1,0xffff);
      return uVar4;
    }
  }
LAB_000122cb:
  uVar4 = *(undefined2 *)(uVar5 + 0x2a + lVar1);
  goto LAB_000122d4;
}

