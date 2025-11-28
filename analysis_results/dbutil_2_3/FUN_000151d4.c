// Function: FUN_000151d4
// Address: 000151d4
// Decompiled by Ghidra


undefined8 FUN_000151d4(undefined8 *param_1)

{
  undefined8 uVar1;
  longlong local_38;
  undefined4 local_30;
  undefined8 local_28;
  undefined8 local_20;
  longlong local_18;
  undefined8 local_10;
  
  if (*(int *)(param_1 + 1) == 0x30) {
    memcpy(&local_38,(void *)*param_1,0x30);
    if ((param_1[2] == 0) || (param_1[2] == local_38)) {
      FUN_0001155c(0);
      FUN_0001155c(local_20);
      uVar1 = FUN_0001155c(local_28);
      local_18 = MmAllocateContiguousMemorySpecifyCache(local_30,uVar1);
      if (local_18 == 0) {
        uVar1 = 0xc00000a0;
      }
      else {
        uVar1 = MmGetPhysicalAddress(local_18);
        local_10 = FUN_00011574(uVar1);
        memcpy((void *)*param_1,&local_38,0x30);
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0xc0000005;
    }
  }
  else {
    uVar1 = 0xc000000d;
  }
  return uVar1;
}

