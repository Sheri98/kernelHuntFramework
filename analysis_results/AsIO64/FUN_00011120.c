// Function: FUN_00011120
// Address: 00011120
// Decompiled by Ghidra


undefined8 FUN_00011120(longlong param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  uint uStack_34;
  
  iVar1 = *(int *)(param_2 + 0x10);
  uVar2 = *(uint *)(param_2 + 8);
  puVar3 = *(undefined4 **)(param_1 + 0x18);
  DbgPrint("[WrMsr] In\n");
  if ((iVar1 == 0xc) && (7 < uVar2)) {
    wrmsr(*puVar3,(ulonglong)(uint)puVar3[1] * 0x100000000 + (ulonglong)(uint)puVar3[2]);
    uVar4 = rdmsr(*puVar3);
    uStack_34 = (uint)((ulonglong)uVar4 >> 0x20);
    puVar3[2] = uStack_34;
    puVar3[3] = (int)uVar4;
    *(undefined8 *)(param_1 + 0x38) = 8;
    DbgPrint("[WrMsr] Out\n");
    return 0;
  }
  return 0xc000000d;
}

