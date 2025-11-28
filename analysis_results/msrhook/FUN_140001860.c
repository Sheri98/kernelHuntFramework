// Function: FUN_140001860
// Address: 140001860
// Decompiled by Ghidra


int FUN_140001860(longlong param_1)

{
  int local_res10;
  undefined1 local_28 [16];
  undefined1 local_18 [16];
  
  DAT_1400050e0 = DAT_1400050e0 + 1;
  if (DAT_1400050e0 == 1) {
    RtlInitUnicodeString(local_28,L"\\Device\\msrhookctrl");
    RtlInitUnicodeString(local_18,L"\\??\\msrhookctrls");
    local_res10 = IoCreateDevice(*(undefined8 *)(param_1 + 8),0x10,local_28,0x22,0x100,0,
                                 &DAT_1400075c0);
    if (local_res10 < 0) {
      DbgPrint("DeviceObject:0x%x\n",param_1);
    }
    else {
      *(uint *)(DAT_1400075c0 + 0x30) =
           *(uint *)(DAT_1400075c0 + 0x30) | *(uint *)(param_1 + 0x30) & 0x2014;
      local_res10 = IoCreateSymbolicLink(local_18,local_28);
      if (local_res10 < 0) {
        IoDeleteDevice(DAT_1400075c0);
      }
      else {
        *(undefined8 *)(*(longlong *)(DAT_1400075c0 + 0x40) + 8) = 0;
        *(uint *)(DAT_1400075c0 + 0x30) = *(uint *)(DAT_1400075c0 + 0x30) & 0xffffff7f;
        DAT_1400050f0 = 0;
        DAT_1400050e4 = 0;
        DAT_140005108 = 0;
        DAT_140005110 = 0;
        DAT_1400050e7 = 0;
        DAT_1400050fc = 0;
        DAT_14000510c = 0;
      }
    }
  }
  return local_res10;
}

