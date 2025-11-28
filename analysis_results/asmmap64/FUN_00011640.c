// Function: FUN_00011640
// Address: 00011640
// Decompiled by Ghidra


undefined8 FUN_00011640(undefined8 param_1,longlong param_2,longlong param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  uVar1 = *(uint *)(param_3 + 0x10);
  uVar2 = *(uint *)(param_3 + 8);
  uVar6 = 0xc0000001;
  DbgPrint("\nInputBufferLength=%x,sizeof (ULONG) = %x",uVar1,4);
  DbgPrint("\nOutputBufferLength=%x,sizeof (LOGICAL_MEMORY_INFO)  = %x",uVar2,0x18);
  *(undefined8 *)(param_2 + 0x38) = 0;
  if ((uVar1 < 0x18) || (uVar2 < 0x18)) {
    DbgPrint("(MAPMEM) Buffer size error\n");
    uVar6 = 0xc000009a;
  }
  else {
    puVar3 = *(undefined4 **)(param_2 + 0x18);
    uVar4 = puVar3[4];
    DAT_00013110 = MmAllocateContiguousMemory(uVar4,0xffffffff);
    if (DAT_00013110 != 0) {
      DbgPrint("\nSystemVirtualAddress=%x",DAT_00013110);
      uVar5 = MmGetPhysicalAddress(DAT_00013110);
      DAT_00013118 = IoAllocateMdl(DAT_00013110,uVar4,0,0,0);
      if (DAT_00013118 == 0) {
        MmFreeContiguousMemory(DAT_00013110);
        *puVar3 = 0;
        puVar3[1] = 0;
        puVar3[2] = 0;
      }
      else {
        MmBuildMdlForNonPagedPool(DAT_00013118);
        DAT_00013120 = MmMapLockedPages(DAT_00013118,1);
        puVar3[2] = (int)DAT_00013120;
        uVar4 = (undefined4)((ulonglong)DAT_00013120 >> 0x20);
        puVar3[3] = uVar4;
        DbgPrint("(MAPMEM) UserVirtualAddress=%x %x\n",uVar4,puVar3[2]);
        *puVar3 = (int)uVar5;
        puVar3[1] = (int)((ulonglong)uVar5 >> 0x20);
        uVar6 = 0;
        *(undefined8 *)(param_2 + 0x38) = 0x18;
      }
      DbgPrint("\nLogical_Address=0x%x %x",puVar3[3],puVar3[2]);
      DbgPrint("\nPhysical_Address=0x%x %x",puVar3[1],*puVar3);
      DbgPrint("\nReturn Length=0x%x",*(undefined8 *)(param_2 + 0x38));
    }
  }
  return uVar6;
}

