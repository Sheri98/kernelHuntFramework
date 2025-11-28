// Function: FUN_140003acc
// Address: 140003acc
// Decompiled by Ghidra


ulonglong FUN_140003acc(int param_1,longlong *param_2,uint *param_3)

{
  undefined4 *puVar1;
  undefined8 *puVar2;
  undefined8 ***pppuVar3;
  longlong lVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined8 **ppuVar8;
  uint uVar9;
  void *in_RAX;
  undefined8 uVar10;
  undefined4 extraout_var;
  undefined8 ****ppppuVar11;
  undefined8 ****ppppuVar12;
  undefined8 ***local_38;
  undefined8 ***local_30;
  
  if (param_1 != 0) {
    local_30 = &local_38;
    local_38 = &local_38;
    uVar10 = FUN_1400054c4(1,(longlong)&local_38,param_1);
    if ((char)uVar10 == '\0') {
      return uVar10;
    }
    uVar9 = FUN_140006ca4(&local_38);
    in_RAX = (void *)CONCAT44(extraout_var,uVar9);
    *param_3 = uVar9;
    if (uVar9 != 0) {
      in_RAX = (void *)ExAllocatePool(0);
      *param_2 = (longlong)in_RAX;
      if (in_RAX != (void *)0x0) {
        memset(in_RAX,0,(ulonglong)*param_3 << 5);
        uVar9 = 0;
        ppppuVar12 = (undefined8 ****)local_38;
        while (((ppppuVar11 = &local_38, ppppuVar12 != ppppuVar11 &&
                (ppppuVar11 = (undefined8 ****)MmIsAddressValid(ppppuVar12),
                (char)ppppuVar11 != '\0')) &&
               (ppppuVar11 = (undefined8 ****)MmIsAddressValid(ppppuVar12), (char)ppppuVar11 != '\0'
               ))) {
          pppuVar3 = ppppuVar12[2];
          ppppuVar11 = (undefined8 ****)MmIsAddressValid(pppuVar3);
          if ((char)ppppuVar11 == '\0') break;
          if (uVar9 < *param_3) {
            lVar4 = *param_2;
            uVar5 = *(undefined4 *)((longlong)pppuVar3 + 4);
            uVar6 = *(undefined4 *)(pppuVar3 + 1);
            uVar7 = *(undefined4 *)((longlong)pppuVar3 + 0xc);
            puVar1 = (undefined4 *)((ulonglong)uVar9 * 0x20 + lVar4);
            *puVar1 = *(undefined4 *)pppuVar3;
            puVar1[1] = uVar5;
            puVar1[2] = uVar6;
            puVar1[3] = uVar7;
            ppuVar8 = pppuVar3[3];
            puVar2 = (undefined8 *)((ulonglong)uVar9 * 0x20 + 0x10 + lVar4);
            *puVar2 = pppuVar3[2];
            puVar2[1] = ppuVar8;
          }
          uVar9 = uVar9 + 1;
          ppppuVar11 = (undefined8 ****)*ppppuVar12;
          ExFreePoolWithTag(pppuVar3,0);
          ExFreePoolWithTag(ppppuVar12);
          ppppuVar12 = ppppuVar11;
        }
        return CONCAT71((int7)((ulonglong)ppppuVar11 >> 8),1);
      }
    }
  }
  return (ulonglong)in_RAX & 0xffffffffffffff00;
}

