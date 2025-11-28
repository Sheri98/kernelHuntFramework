// Function: FUN_14000377c
// Address: 14000377c
// Decompiled by Ghidra


undefined8 FUN_14000377c(longlong param_1,uint *param_2)

{
  uint *puVar1;
  uint uVar2;
  undefined8 ***pppuVar3;
  uint uVar4;
  uint uVar5;
  char cVar6;
  uint uVar7;
  undefined8 uVar8;
  undefined8 ***pppuVar9;
  ulonglong uVar10;
  undefined8 **local_18;
  undefined8 **local_10;
  
  local_10 = &local_18;
  local_18 = &local_18;
  FUN_140003874((longlong *)&local_18,param_1);
  uVar7 = FUN_140006ca4(&local_18);
  uVar2 = *param_2;
  *param_2 = uVar7;
  pppuVar9 = (undefined8 ***)local_18;
  if (uVar2 < uVar7) {
    while (pppuVar9 != &local_18) {
      cVar6 = MmIsAddressValid(pppuVar9);
      if (cVar6 == '\0') break;
      pppuVar3 = (undefined8 ***)*pppuVar9;
      ExFreePoolWithTag(pppuVar9,0);
      pppuVar9 = pppuVar3;
    }
    uVar8 = 0xc0000023;
  }
  else {
    uVar10 = 0;
    while (pppuVar9 != &local_18) {
      cVar6 = MmIsAddressValid(pppuVar9);
      if (cVar6 == '\0') break;
      cVar6 = MmIsAddressValid(pppuVar9);
      if (cVar6 == '\0') break;
      if ((uint)uVar10 < uVar7) {
        uVar2 = *(uint *)((longlong)pppuVar9 + 0x14);
        uVar4 = *(uint *)(pppuVar9 + 3);
        uVar5 = *(uint *)((longlong)pppuVar9 + 0x1c);
        puVar1 = param_2 + uVar10 * 6 + 2;
        *puVar1 = *(uint *)(pppuVar9 + 2);
        puVar1[1] = uVar2;
        puVar1[2] = uVar4;
        puVar1[3] = uVar5;
        *(undefined8 ***)(param_2 + uVar10 * 6 + 6) = pppuVar9[4];
      }
      pppuVar3 = (undefined8 ***)*pppuVar9;
      uVar10 = (ulonglong)((uint)uVar10 + 1);
      ExFreePoolWithTag(pppuVar9,0);
      pppuVar9 = pppuVar3;
    }
    uVar8 = 0;
  }
  return uVar8;
}

