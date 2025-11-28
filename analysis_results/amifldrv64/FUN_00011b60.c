// Function: FUN_00011b60
// Address: 00011b60
// Decompiled by Ghidra


undefined8 FUN_00011b60(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)(param_2 + 0x18);
  lVar2 = *(longlong *)(param_2 + 0x10);
  if (((*(longlong *)(param_2 + 8) != 0) || (lVar1 != 0)) || (lVar2 != 0)) {
    MmUnmapLockedPages(*(longlong *)(param_2 + 8),lVar1);
    IoFreeMdl(lVar1);
    MmFreeContiguousMemory(lVar2);
  }
  return 0;
}

