// Function: FUN_00011144
// Address: 00011144
// Decompiled by Ghidra


undefined4 FUN_00011144(undefined8 param_1,longlong param_2)

{
  undefined4 uVar1;
  ulonglong uVar2;
  
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  if (**(char **)(param_2 + 0xb8) == '\x0e') {
    if (*(int *)(*(char **)(param_2 + 0xb8) + 0x18) == -0x7fffe000) {
      uVar2 = FUN_00011234(param_1,*(ulonglong **)(param_2 + 0x18));
      *(int *)(param_2 + 0x30) = (int)uVar2;
      if ((int)uVar2 < 0) {
        *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
      }
      else {
        *(undefined8 *)(param_2 + 0x38) = 4;
      }
    }
    else {
      *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
    }
  }
  uVar1 = *(undefined4 *)(param_2 + 0x30);
  IofCompleteRequest(param_2,0);
  return uVar1;
}

