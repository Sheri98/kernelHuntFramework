// Function: FUN_00011360
// Address: 00011360
// Decompiled by Ghidra


int FUN_00011360(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  int iVar1;
  
  DbgPrint("Entering UnmapPhysicalMemory");
  iVar1 = ZwUnmapViewOfSection(0xffffffffffffffff,param_2);
  if (iVar1 < 0) {
    DbgPrint("ERROR: UnmapViewOfSection failed");
  }
  if (param_3 != 0) {
    ObfDereferenceObject(param_3);
  }
  ZwClose(param_1);
  DbgPrint("Leaving UnmapPhysicalMemory");
  return iVar1;
}

