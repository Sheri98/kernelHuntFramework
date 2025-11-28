// Function: FUN_00011040
// Address: 00011040
// Decompiled by Ghidra


undefined8 FUN_00011040(longlong param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  uint uStack_34;
  
  iVar1 = *(int *)(param_2 + 0x10);
  uVar2 = *(uint *)(param_2 + 8);
  puVar3 = *(uint **)(param_1 + 0x18);
  DbgPrint("[SetMultipiler] In\n");
  if ((iVar1 == 4) && (3 < uVar2)) {
    uVar4 = rdmsr(0x2d);
    uStack_34 = (uint)((ulonglong)uVar4 >> 0x20);
    uVar5 = (ulonglong)uStack_34 * 0x100000000 + (ulonglong)*puVar3;
    uVar6 = uVar5 >> 0x20;
    wrmsr(0x2d,uVar6 << 0x20 | uVar5 & 0xffffffff);
    *puVar3 = uStack_34;
    *(undefined8 *)(param_1 + 0x38) = 4;
    DbgPrint("[SetMultipiler] Out\n",uVar6);
    return 0;
  }
  return 0xc000000d;
}

