// Function: FUN_14013278d
// Address: 14013278d
// Decompiled by Ghidra


int FUN_14013278d(void)

{
  uint *puVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  longlong unaff_RDI;
  undefined1 *puVar8;
  undefined1 uStack0000000000000028;
  undefined8 *puStack0000000000000030;
  longlong in_stack_00000080;
  
  uVar5 = FUN_14001b5f8(L"\\Device\\mhyprot2");
  RtlInitUnicodeString(&stack0x00000040,uVar5);
  puStack0000000000000030 = &stack0x00000080;
  puVar8 = &stack0x00000040;
  uStack0000000000000028 = 0;
  iVar3 = IoCreateDevice();
  if (-1 < iVar3) {
    *(uint *)(in_stack_00000080 + 0x30) = *(uint *)(in_stack_00000080 + 0x30) | 4;
    uVar5 = FUN_14001b5f8(L"\\DosDevices\\mhyprot2");
    RtlInitUnicodeString(&stack0x00000050,uVar5);
    puVar7 = &stack0x00000040;
    puVar6 = &stack0x00000050;
    iVar3 = IoCreateSymbolicLink();
    if (-1 < iVar3) {
      *(code **)(unaff_RDI + 0x70) = FUN_14000d6a0;
      *(code **)(unaff_RDI + 0x80) = FUN_14000d660;
      *(code **)(unaff_RDI + 0xe0) = FUN_14000d6e0;
      *(code **)(unaff_RDI + 0x68) = FUN_14000da80;
      puVar1 = (uint *)(*(longlong *)(unaff_RDI + 0x28) + 0x68);
      *puVar1 = *puVar1 | 0x20;
      uVar4 = FUN_1400070a0();
      if (((char)uVar4 == '\0') || (cVar2 = FUN_1400013b8(), cVar2 == '\0')) {
        IoDeleteSymbolicLink(&stack0x00000050);
        IoDeleteDevice(in_stack_00000080);
      }
      else {
        FUN_1400051b0(puVar6,(longlong)puVar7,(ulonglong)puVar8);
        FUN_140004b54();
        FUN_140006a00();
      }
      iVar3 = FUN_14000e145();
      return iVar3;
    }
    IoDeleteDevice(in_stack_00000080);
  }
  return iVar3;
}

