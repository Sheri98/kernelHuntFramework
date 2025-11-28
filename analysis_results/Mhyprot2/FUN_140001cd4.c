// Function: FUN_140001cd4
// Address: 140001cd4
// Decompiled by Ghidra


ulonglong FUN_140001cd4(longlong *param_1,uint *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  longlong **pplVar4;
  longlong *plVar5;
  uint uVar6;
  undefined4 extraout_var;
  void *_Dst;
  longlong ***ppplVar7;
  longlong ***ppplVar8;
  longlong *plVar9;
  longlong ***ppplVar10;
  longlong lVar11;
  longlong **local_18;
  longlong **local_10;
  
  local_10 = (longlong **)&local_18;
  local_18 = (longlong **)&local_18;
  FUN_140001524(0x140007ad0,(longlong *)&local_18);
  FUN_1400017fc((longlong *)&local_18);
  uVar6 = FUN_140006ca4(&local_18);
  _Dst = (void *)CONCAT44(extraout_var,uVar6);
  *param_2 = uVar6;
  if (uVar6 != 0) {
    _Dst = (void *)ExAllocatePool(0);
    *param_1 = (longlong)_Dst;
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,(ulonglong)*param_2 * 0x420);
      ppplVar7 = &local_18;
      uVar6 = 0;
      ppplVar10 = (longlong ***)local_18;
      if ((longlong ***)local_18 != ppplVar7) {
        do {
          ppplVar7 = (longlong ***)MmIsAddressValid(ppplVar10);
          if (((char)ppplVar7 == '\0') ||
             (ppplVar7 = (longlong ***)MmIsAddressValid(ppplVar10), (char)ppplVar7 == '\0')) break;
          if (uVar6 < *param_2) {
            lVar11 = 8;
            ppplVar7 = ppplVar10 + 2;
            plVar5 = (longlong *)((ulonglong)uVar6 * 0x420 + *param_1);
            do {
              plVar9 = plVar5;
              ppplVar8 = ppplVar7;
              pplVar4 = ppplVar8[1];
              *plVar9 = (longlong)*ppplVar8;
              plVar9[1] = (longlong)pplVar4;
              pplVar4 = ppplVar8[3];
              plVar9[2] = (longlong)ppplVar8[2];
              plVar9[3] = (longlong)pplVar4;
              pplVar4 = ppplVar8[5];
              plVar9[4] = (longlong)ppplVar8[4];
              plVar9[5] = (longlong)pplVar4;
              pplVar4 = ppplVar8[7];
              plVar9[6] = (longlong)ppplVar8[6];
              plVar9[7] = (longlong)pplVar4;
              pplVar4 = ppplVar8[9];
              plVar9[8] = (longlong)ppplVar8[8];
              plVar9[9] = (longlong)pplVar4;
              pplVar4 = ppplVar8[0xb];
              plVar9[10] = (longlong)ppplVar8[10];
              plVar9[0xb] = (longlong)pplVar4;
              pplVar4 = ppplVar8[0xd];
              plVar9[0xc] = (longlong)ppplVar8[0xc];
              plVar9[0xd] = (longlong)pplVar4;
              pplVar4 = ppplVar8[0xf];
              plVar9[0xe] = (longlong)ppplVar8[0xe];
              plVar9[0xf] = (longlong)pplVar4;
              lVar11 = lVar11 + -1;
              ppplVar7 = ppplVar8 + 0x10;
              plVar5 = plVar9 + 0x10;
            } while (lVar11 != 0);
            uVar1 = *(undefined4 *)((longlong)ppplVar8 + 0x84);
            uVar2 = *(undefined4 *)(ppplVar8 + 0x11);
            uVar3 = *(undefined4 *)((longlong)ppplVar8 + 0x8c);
            *(undefined4 *)(plVar9 + 0x10) = *(undefined4 *)(ppplVar8 + 0x10);
            *(undefined4 *)((longlong)plVar9 + 0x84) = uVar1;
            *(undefined4 *)(plVar9 + 0x11) = uVar2;
            *(undefined4 *)((longlong)plVar9 + 0x8c) = uVar3;
            pplVar4 = ppplVar8[0x13];
            plVar9[0x12] = (longlong)ppplVar8[0x12];
            plVar9[0x13] = (longlong)pplVar4;
          }
          ppplVar8 = (longlong ***)*ppplVar10;
          uVar6 = uVar6 + 1;
          ppplVar7 = (longlong ***)ExFreePoolWithTag(ppplVar10,0);
          ppplVar10 = ppplVar8;
        } while (ppplVar8 != &local_18);
      }
      return CONCAT71((int7)((ulonglong)ppplVar7 >> 8),1);
    }
  }
  return (ulonglong)_Dst & 0xffffffffffffff00;
}

