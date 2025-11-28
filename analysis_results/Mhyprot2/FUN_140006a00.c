// Function: FUN_140006a00
// Address: 140006a00
// Decompiled by Ghidra


void FUN_140006a00(void)

{
  undefined8 local_res8 [4];
  undefined1 local_48 [8];
  undefined8 local_40;
  undefined4 local_38 [2];
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  LOCK();
  DAT_14000a6e8 = 0;
  UNLOCK();
  local_38[0] = 0x30;
  local_30 = 0;
  local_20 = 0x200;
  local_28 = 0;
  local_res8[0] = 0;
  local_18 = 0;
  uStack_10 = 0;
  PsCreateSystemThread(local_res8,0,local_38,0,local_48,FUN_140006a80,0);
  PsLookupThreadByThreadId(local_40,&DAT_14000a6f0);
  return;
}

