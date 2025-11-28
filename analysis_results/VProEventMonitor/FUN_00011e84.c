// Function: FUN_00011e84
// Address: 00011e84
// Decompiled by Ghidra


int FUN_00011e84(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  longlong lVar2;
  int local_res8 [2];
  longlong local_res18;
  undefined8 local_58;
  undefined8 local_50;
  undefined1 local_48 [16];
  undefined4 local_38 [2];
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_res8[0] = 0;
  local_res18 = 0;
  local_50 = 0;
  local_30 = 0;
  local_28 = 0;
  local_18 = 0;
  local_10 = 0;
  local_38[0] = 0x30;
  local_20 = 0x200;
  local_58 = param_1;
  iVar1 = ZwOpenProcess(&local_res18,0x1f0fff,local_38,&local_58);
  DbgPrint("VProEventMonitor.sys: Entry - GetProcessImageName().\n");
  if (iVar1 < 0) {
    DbgPrint("Failed to open process id %d with status 0x%x\n",param_1,iVar1);
  }
  else {
    if (DAT_00014140 == (code *)0x0) {
      RtlInitUnicodeString(local_48,L"ZwQueryInformationProcess");
      DAT_00014140 = (code *)MmGetSystemRoutineAddress(local_48);
      if (DAT_00014140 == (code *)0x0) {
        DbgPrint("Cannot resolve ZwQueryInformationProcess\n");
        iVar1 = -0x3ffffffe;
        goto LAB_0001200d;
      }
    }
    iVar1 = (*DAT_00014140)(local_res18,0x1b,0,0,local_res8);
    if (iVar1 == -0x3ffffffc) {
      if (local_res8[0] - 0x10U < 0x10000) {
        lVar2 = ExAllocatePoolWithTag(1,local_res8[0],0x69706744);
        if (lVar2 == 0) {
          iVar1 = -0x3fffff66;
        }
        else {
          iVar1 = (*DAT_00014140)(local_res18,0x1b,lVar2,local_res8[0],local_res8);
          if (-1 < iVar1) {
            RtlCopyUnicodeString(param_2,lVar2);
          }
          ExFreePoolWithTag(lVar2,0);
        }
      }
      else {
        iVar1 = -0x7ffffffb;
      }
    }
  }
LAB_0001200d:
  if (local_res18 != 0) {
    ZwClose();
  }
  return iVar1;
}

