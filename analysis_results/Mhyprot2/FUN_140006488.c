// Function: FUN_140006488
// Address: 140006488
// Decompiled by Ghidra


uint FUN_140006488(uint param_1,longlong param_2,uint param_3)

{
  undefined8 uVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  longlong lVar5;
  uint *_Dst;
  longlong lVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  longlong *plVar11;
  ulonglong uVar12;
  uint local_res20 [2];
  longlong local_48;
  undefined1 local_40 [24];
  
  uVar7 = 0xffffffff;
  RtlInitUnicodeString(local_40,L"ZwQuerySystemInformation");
  lVar5 = MmGetSystemRoutineAddress(local_40);
  uVar8 = 0xffffffff;
  if (lVar5 != 0) {
    local_res20[0] = 0;
    iVar4 = (*(code *)PTR__guard_dispatch_icall_140008328)(5,0,0,local_res20);
    uVar8 = uVar7;
    if (((iVar4 == -0x3ffffffc) && (local_res20[0] != 0)) &&
       (_Dst = (uint *)ExAllocatePool(0), _Dst != (uint *)0x0)) {
      memset(_Dst,0,(ulonglong)local_res20[0]);
      iVar4 = (*(code *)PTR__guard_dispatch_icall_140008328)(5,_Dst,local_res20[0],local_res20);
      puVar9 = _Dst;
      if (-1 < iVar4) {
        while (cVar2 = MmIsAddressValid(puVar9), uVar8 = 0xffffffff, cVar2 != '\0') {
          if (puVar9[0x14] == param_1) {
            uVar8 = puVar9[1];
            if ((uVar8 <= param_3) && (uVar12 = 0, uVar8 != 0)) {
              plVar11 = (longlong *)(param_2 + 8);
              puVar10 = puVar9 + 0x4c;
              do {
                uVar1 = *(undefined8 *)puVar10;
                local_48 = 0;
                PsLookupThreadByThreadId(uVar1,&local_48);
                lVar5 = local_48;
                *(uint *)(plVar11 + -1) = puVar9[0x14];
                *(int *)((longlong)plVar11 + -4) = (int)uVar1;
                *plVar11 = local_48;
                lVar6 = FUN_1400068c8(local_48);
                plVar11[1] = lVar6;
                lVar6 = FUN_14000687c(lVar5);
                plVar11[2] = lVar6;
                bVar3 = FUN_1400067f4(lVar5);
                *(uint *)(plVar11 + 3) = (uint)(bVar3 != 0);
                if (lVar5 != 0) {
                  ObfDereferenceObject(lVar5);
                }
                uVar12 = uVar12 + 1;
                puVar10 = puVar10 + 0x14;
                plVar11 = plVar11 + 0x15;
              } while (uVar12 < puVar9[1]);
            }
            break;
          }
          uVar8 = uVar7;
          if ((*puVar9 == 0) ||
             (puVar9 = (uint *)((longlong)puVar9 + (ulonglong)*puVar9), puVar9 == (uint *)0x0))
          break;
        }
        ExFreePoolWithTag(_Dst,0);
      }
    }
  }
  return uVar8;
}

