// Function: FUN_140131fe8
// Address: 140131fe8
// Decompiled by Ghidra


void FUN_140131fe8(void)

{
  int iVar1;
  undefined8 in_stack_00000030;
  
  if (DAT_14000a710 != 0) {
    in_stack_00000030 = 0;
    iVar1 = PsLookupProcessByProcessId(DAT_14000a688,&stack0x00000030);
    if (-1 < iVar1) {
      ObfDereferenceObject(in_stack_00000030);
    }
  }
  FUN_1400014d6();
  return;
}

