// Function: FUN_000110e4
// Address: 000110e4
// Decompiled by Ghidra


ulonglong FUN_000110e4(longlong param_1,longlong param_2)

{
  char *pcVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  pcVar1 = *(char **)(param_2 + 0xb8);
  uVar3 = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  lVar2 = *(longlong *)(param_1 + 0x40);
  if ((*pcVar1 != '\0') && (*pcVar1 != '\x02')) {
    if (*pcVar1 == '\x0e') {
      *(undefined4 *)(lVar2 + 8) = *(undefined4 *)(pcVar1 + 0x18);
      uVar3 = FUN_00011150(lVar2,param_2,(longlong)pcVar1,*(uint *)(pcVar1 + 0x18));
      uVar3 = uVar3 & 0xffffffff;
    }
    else {
      uVar3 = 0xc000000d;
    }
  }
  *(int *)(param_2 + 0x30) = (int)uVar3;
  IofCompleteRequest(param_2,0);
  return uVar3;
}

