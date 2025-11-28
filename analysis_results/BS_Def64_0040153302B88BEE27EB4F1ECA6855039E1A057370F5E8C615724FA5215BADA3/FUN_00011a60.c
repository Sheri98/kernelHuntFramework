// Function: FUN_00011a60
// Address: 00011a60
// Decompiled by Ghidra


undefined8 FUN_00011a60(undefined8 param_1,ulonglong param_2)

{
  ulonglong uVar1;
  
  if (DAT_00014048 == 4) {
    FUN_00011140();
    if (DAT_0001404c != 0) {
      out(DAT_0001404c,0x24);
    }
    uVar1 = 0x1fffe;
  }
  else {
    uVar1 = param_2;
    if (DAT_00014048 != 5) goto LAB_00011ae9;
    FUN_00011140();
    if (DAT_0001404c != 0) {
      *(undefined1 *)((ulonglong)DAT_00014050 + DAT_00014040) = 4;
      out(DAT_0001404c,0x7f);
      out(0xe1,0);
    }
    uVar1 = 0xffff;
  }
  MmUnmapIoSpace(DAT_00014040,uVar1);
  DAT_00014040 = 0;
LAB_00011ae9:
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,uVar1 & 0xffffffffffffff00);
  return 0;
}

