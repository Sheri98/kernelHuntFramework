// Function: FUN_140001b20
// Address: 140001b20
// Decompiled by Ghidra


ulonglong FUN_140001b20(longlong *param_1,uint *param_2)

{
  int iVar1;
  uint *_Dst;
  uint *puVar2;
  undefined8 uVar3;
  longlong lVar4;
  ulonglong uVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined4 local_res18 [4];
  ushort local_48 [4];
  undefined8 *local_40;
  undefined1 local_38 [16];
  
  uVar6 = 0;
  local_res18[0] = 0;
  _Dst = (uint *)ZwQuerySystemInformation(0xb,local_res18,0,local_res18);
  if (((int)_Dst == -0x3ffffffc) &&
     (puVar2 = (uint *)ExAllocatePool(0,local_res18[0]), _Dst = puVar2, puVar2 != (uint *)0x0)) {
    iVar1 = ZwQuerySystemInformation(0xb,puVar2,local_res18[0],0);
    if (iVar1 < 0) {
      _Dst = (uint *)ExFreePoolWithTag(puVar2,0);
    }
    else {
      uVar5 = 0;
      if (*puVar2 != 0) {
        do {
          if (*(ulonglong *)MmHighestUserAddress_exref < *(ulonglong *)(puVar2 + uVar5 * 0x4a + 6))
          {
            *param_2 = *param_2 + 1;
          }
          uVar7 = (int)uVar5 + 1;
          uVar5 = (ulonglong)uVar7;
        } while (uVar7 < *puVar2);
      }
      _Dst = (uint *)(ulonglong)*param_2;
      if (*param_2 != 0) {
        _Dst = (uint *)ExAllocatePool(0);
        *param_1 = (longlong)_Dst;
        if (_Dst != (uint *)0x0) {
          memset(_Dst,0,(ulonglong)*param_2 * 0x420);
          uVar5 = 0;
          if (*puVar2 != 0) {
            do {
              if (*(ulonglong *)MmHighestUserAddress_exref <
                  *(ulonglong *)(puVar2 + uVar5 * 0x4a + 6)) {
                if (uVar6 < *param_2) {
                  lVar4 = (ulonglong)uVar6 * 0x420;
                  *(ulonglong *)(lVar4 + 8 + *param_1) = *(ulonglong *)(puVar2 + uVar5 * 0x4a + 6);
                  *(uint *)(lVar4 + 0x10 + *param_1) = puVar2[uVar5 * 0x4a + 8];
                  RtlInitString(local_38,puVar2 + uVar5 * 0x4a + 0xc);
                  RtlAnsiStringToUnicodeString(local_48,local_38,1);
                  uVar8 = 0x103;
                  if (local_48[0] < 0x104) {
                    uVar8 = (ulonglong)local_48[0];
                  }
                  FUN_1400075c0((undefined8 *)(*param_1 + 0x114 + lVar4),local_40,uVar8);
                  RtlFreeUnicodeString(local_48);
                }
                uVar6 = uVar6 + 1;
              }
              uVar7 = (int)uVar5 + 1;
              uVar5 = (ulonglong)uVar7;
            } while (uVar7 < *puVar2);
          }
          uVar3 = ExFreePoolWithTag(puVar2,0);
          return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
        }
      }
    }
  }
  return (ulonglong)_Dst & 0xffffffffffffff00;
}

