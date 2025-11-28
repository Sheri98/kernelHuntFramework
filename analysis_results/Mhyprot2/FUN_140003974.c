// Function: FUN_140003974
// Address: 140003974
// Decompiled by Ghidra


ulonglong FUN_140003974(longlong *param_1,uint *param_2)

{
  longlong ***ppplVar1;
  longlong ****pppplVar2;
  uint uVar3;
  void *_Dst;
  undefined4 extraout_var;
  longlong ****pppplVar4;
  longlong ****pppplVar5;
  uint uVar6;
  longlong lVar7;
  longlong ***local_28;
  longlong ***local_20;
  
  local_20 = (longlong ***)&local_28;
  local_28 = (longlong ***)&local_28;
  _Dst = (void *)FUN_1400054c4(0,(longlong)&local_28,0);
  if ((char)_Dst != '\0') {
    uVar6 = 0;
    uVar3 = FUN_140006ca4(&local_28);
    _Dst = (void *)CONCAT44(extraout_var,uVar3);
    *param_2 = uVar3;
    if (uVar3 != 0) {
      _Dst = (void *)ExAllocatePool(0);
      *param_1 = (longlong)_Dst;
      if (_Dst != (void *)0x0) {
        memset(_Dst,0,(ulonglong)*param_2 * 0x218);
        pppplVar4 = &local_28;
        pppplVar5 = (longlong ****)local_28;
        if ((longlong ****)local_28 != pppplVar4) {
          do {
            pppplVar4 = (longlong ****)MmIsAddressValid(pppplVar5);
            if (((char)pppplVar4 == '\0') ||
               (pppplVar4 = (longlong ****)MmIsAddressValid(pppplVar5), (char)pppplVar4 == '\0'))
            break;
            ppplVar1 = pppplVar5[2];
            pppplVar4 = (longlong ****)MmIsAddressValid(ppplVar1);
            if ((char)pppplVar4 == '\0') break;
            if (uVar6 < *param_2) {
              lVar7 = (ulonglong)uVar6 * 0x218;
              *(undefined4 *)(lVar7 + *param_1) = *(undefined4 *)ppplVar1;
              *(longlong ***)(lVar7 + 0x210 + *param_1) = ppplVar1[1];
              FUN_140003c9c(ppplVar1[1],(undefined8 *)(*param_1 + 4 + lVar7),0x104);
            }
            pppplVar2 = (longlong ****)*pppplVar5;
            uVar6 = uVar6 + 1;
            ExFreePoolWithTag(ppplVar1,0);
            pppplVar4 = (longlong ****)ExFreePoolWithTag(pppplVar5);
            pppplVar5 = pppplVar2;
          } while (pppplVar2 != &local_28);
        }
        return CONCAT71((int7)((ulonglong)pppplVar4 >> 8),1);
      }
    }
  }
  return (ulonglong)_Dst & 0xffffffffffffff00;
}

