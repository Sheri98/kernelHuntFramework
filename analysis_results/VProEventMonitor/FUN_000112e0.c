// Function: FUN_000112e0
// Address: 000112e0
// Decompiled by Ghidra


int FUN_000112e0(longlong param_1,longlong param_2)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = *(char **)(param_2 + 0xb8);
  *(undefined8 *)(param_2 + 0x38) = 0;
  iVar2 = 0;
  *(undefined4 *)(param_2 + 0x30) = 0;
  if (*pcVar1 == '\0') {
    DbgPrint("VProEventMonitor.sys: IRP_MJ_CREATE\n");
  }
  else if (*pcVar1 == '\x02') {
    DbgPrint("VProEventMonitor.sys: IRP_MJ_CLOSE\n");
    FUN_0001194c(param_1);
  }
  else {
    if (*pcVar1 == '\x0e') {
      DbgPrint("VProEventMonitor.sys: IRP_MJ_DEVICE_CONTROL\n");
      iVar2 = FUN_000113f8(param_2);
      return iVar2;
    }
    iVar2 = -0x3ffffff0;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000010;
  }
  IofCompleteRequest(param_2,0);
  return iVar2;
}

