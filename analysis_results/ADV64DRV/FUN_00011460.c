// Function: FUN_00011460
// Address: 00011460
// Decompiled by Ghidra


int FUN_00011460(longlong param_1,longlong param_2)

{
  int iVar1;
  char *pcVar2;
  undefined8 uVar3;
  int iVar4;
  
  pcVar2 = *(char **)(param_2 + 0xb8);
  *(undefined8 *)(param_2 + 0x38) = 0;
  iVar4 = -0x3ffffffe;
  if (*pcVar2 == '\x0e') {
    iVar1 = *(int *)(pcVar2 + 0x18);
    if (iVar1 == 0x224000) {
      iVar4 = 0;
    }
    else if (iVar1 == 0x224004) {
      uVar3 = FUN_00011040(*(undefined8 *)(param_1 + 0x40),param_2,(longlong)pcVar2);
      iVar4 = (int)uVar3;
    }
    else if (iVar1 == 0x224010) {
      if (*(uint *)(pcVar2 + 8) < 4) {
        iVar4 = -0x3fffffdd;
      }
      else {
        iVar4 = 0;
        **(undefined4 **)(param_2 + 0x18) = 0x20000;
        *(undefined8 *)(param_2 + 0x38) = 4;
      }
    }
  }
  *(int *)(param_2 + 0x30) = iVar4;
  if (iVar4 != 0x103) {
    IofCompleteRequest(param_2,0);
  }
  return iVar4;
}

