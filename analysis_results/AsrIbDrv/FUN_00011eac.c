// Function: FUN_00011eac
// Address: 00011eac
// Decompiled by Ghidra


undefined8 FUN_00011eac(undefined4 *param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  *(undefined8 *)(param_1 + 2) = 0;
  lVar2 = MmAllocateContiguousMemorySpecifyCache(*param_1,0x100000,0xf0000000,0x10000,1);
  *(longlong *)(param_1 + 2) = lVar2;
  if (lVar2 == 0) {
    uVar3 = 0xc0000001;
  }
  else {
    uVar1 = MmGetPhysicalAddress(lVar2);
    param_1[1] = uVar1;
    uVar3 = 0;
  }
  return uVar3;
}

