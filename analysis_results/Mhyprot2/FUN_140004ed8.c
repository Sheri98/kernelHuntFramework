// Function: FUN_140004ed8
// Address: 140004ed8
// Decompiled by Ghidra


bool FUN_140004ed8(undefined8 param_1,undefined8 param_2,ulonglong param_3)

{
  ulonglong uVar1;
  short *psVar2;
  longlong lVar3;
  bool bVar4;
  
  lVar3 = 0;
  uVar1 = FUN_140004df0(DAT_14000a678,'\0');
  if ((char)uVar1 == '\0') {
    if (DAT_14000a678 != (short *)0x0) {
      ObUnRegisterCallbacks();
      DAT_14000a678 = (short *)0x0;
    }
    psVar2 = DAT_14000a680;
    if (DAT_14000a680 != (short *)0x0) {
      ObUnRegisterCallbacks();
      DAT_14000a680 = (short *)0x0;
    }
    FUN_1400051b0(psVar2,lVar3,param_3);
    bVar4 = false;
  }
  else {
    uVar1 = FUN_140004df0(DAT_14000a680,'\x01');
    bVar4 = (char)uVar1 != '\0';
  }
  return bVar4;
}

