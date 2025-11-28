// Function: FUN_14000297c
// Address: 14000297c
// Decompiled by Ghidra


ulonglong FUN_14000297c(undefined8 param_1)

{
  ulonglong uVar1;
  
  uVar1 = MmGetPhysicalAddress();
  DbgPrint("Physical Address=%x,dwLins=%x",uVar1,param_1);
  return uVar1 & 0xffffffff;
}

