// Function: FUN_00012b80
// Address: 00012b80
// Decompiled by Ghidra


undefined8 FUN_00012b80(undefined8 param_1,ulonglong param_2)

{
  ulonglong uVar1;
  
  uVar1 = param_2;
  DAT_00014048 = FUN_00012760();
  if (DAT_00014048 == 4) {
    FUN_00011090(0x1000);
    if (DAT_00014040 == 0) {
      DAT_00014040 = MmMapIoSpace(0xe0000,0x1fffe,0);
    }
    uVar1 = (ulonglong)DAT_0001404c;
    if (DAT_0001404c != 0) {
      out(DAT_0001404c,0x20);
    }
  }
  else if (DAT_00014048 == 5) {
    DAT_0001404c = FUN_00012230();
    FUN_00011090(0x1000);
    if (DAT_00014040 == 0) {
      DAT_00014040 = MmMapIoSpace(0xf0000,0xffff,0);
    }
    uVar1 = (ulonglong)DAT_0001404c;
    if (DAT_0001404c != 0) {
      out(DAT_0001404c,0x7f);
      uVar1 = 0;
      out(0xe1,0);
    }
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,uVar1 & 0xffffffffffffff00);
  return 0;
}

