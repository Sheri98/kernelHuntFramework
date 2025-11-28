// Function: FUN_140002234
// Address: 140002234
// Decompiled by Ghidra


undefined4 FUN_140002234(longlong param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  undefined4 uVar3;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  cVar1 = *(char *)(*(longlong *)(param_2 + 0xb8) + 1);
  if (cVar1 != '\0') {
    if (cVar1 != '\x02') {
      DbgPrint("DeviceObject:0x%x\n",param_1);
      DbgPrint("DeviceObject:0x%x\n",DAT_1400075c0);
      if (param_1 == DAT_1400075c0) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000010;
        IofCompleteRequest(param_2,0);
        return 0xc0000010;
      }
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      uVar3 = IofCallDriver(*(undefined8 *)(lVar2 + 0x38),param_2);
      return uVar3;
    }
    if (param_1 == DAT_1400075c0) {
      *(undefined4 *)(param_2 + 0x30) = 0;
      *(undefined8 *)(param_2 + 0x38) = 0;
      IofCompleteRequest(param_2,0);
      FUN_140001994();
    }
    else {
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      IofCallDriver(*(undefined8 *)(lVar2 + 0x38));
      FUN_140002868(*(longlong *)(lVar2 + 0x38));
      DbgPrint("devExt->LowerDeviceObject:0x%x\n",*(undefined8 *)(lVar2 + 0x38));
      IoDetachDevice(*(undefined8 *)(lVar2 + 0x38));
      DbgPrint("DeviceObject:0x%x\n",param_1);
      IoDeleteDevice(param_1);
    }
  }
  return 0;
}

