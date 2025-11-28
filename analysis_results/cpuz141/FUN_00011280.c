// Function: FUN_00011280
// Address: 00011280
// Decompiled by Ghidra


int FUN_00011280(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined8 param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  undefined8 local_38;
  int local_30 [4];
  undefined1 local_20 [24];
  
  KeInitializeEvent(local_20,1);
  lVar3 = IoBuildDeviceIoControlRequest
                    (0x32c004,param_1,param_3,param_4,param_5,param_6,0,local_20,local_30);
  if (lVar3 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    iVar1 = IofCallDriver(param_1,lVar3);
    if (iVar1 == 0x103) {
      local_38 = 0xfffffffffff0bdc0;
      iVar2 = KeWaitForSingleObject(local_20,0,0,0,&local_38);
      iVar1 = local_30[0];
      if (iVar2 == 0x102) {
        IoCancelIrp(lVar3);
        KeWaitForSingleObject(local_20,0,0,0,0);
        iVar1 = 0x102;
      }
    }
  }
  return iVar1;
}

