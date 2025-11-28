// Function: FUN_140006654
// Address: 140006654
// Decompiled by Ghidra


ulonglong FUN_140006654(undefined4 param_1,longlong param_2)

{
  undefined8 uVar1;
  char cVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined8 *puVar6;
  longlong lVar7;
  longlong lVar8;
  uint uVar9;
  undefined4 *puVar10;
  longlong local_res18;
  undefined8 local_78;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined8 local_68;
  undefined1 local_60 [56];
  
  if (DAT_14000a6e0 == 0) {
    RtlInitUnicodeString(&local_78,L"PsGetThreadWin32Thread");
    DAT_14000a6e0 = MmGetSystemRoutineAddress(&local_78);
    if (DAT_14000a6e0 == 0) {
      return 0xffffffffffffffff;
    }
  }
  local_res18 = 0;
  iVar3 = PsLookupThreadByThreadId(param_1,&local_res18);
  if (iVar3 == 0) {
    if (local_res18 == 0) {
      lVar5 = 0;
    }
    else {
      lVar5 = PsGetThreadProcess();
    }
    if (lVar5 == 0) {
      uVar4 = 0xfffffffd;
    }
    else {
      puVar6 = (undefined8 *)(*(code *)PTR__guard_dispatch_icall_140008328)(local_res18);
      if (DAT_14000a748 == 100) {
        if (puVar6 == (undefined8 *)0x0) {
          puVar6 = (undefined8 *)0x0;
        }
        else {
          puVar6 = (undefined8 *)*puVar6;
        }
      }
      if (puVar6 == (undefined8 *)0x0) {
        uVar4 = 0xfffffffc;
      }
      else {
        lVar8 = DAT_14000a740 + (longlong)puVar6;
        KeStackAttachProcess(lVar5,local_60);
        uVar9 = 0;
        cVar2 = MmIsAddressValid(lVar8);
        if (cVar2 != '\0') {
          lVar5 = -1;
          lVar7 = 0;
          do {
            puVar6 = *(undefined8 **)(lVar8 + lVar5 * 8);
            if (puVar6 != (undefined8 *)0x0) {
              puVar10 = (undefined4 *)(lVar7 * 0x18 + param_2);
              do {
                cVar2 = MmIsAddressValid(puVar6);
                if ((cVar2 == '\0') || (0xf < lVar7)) break;
                uVar1 = *puVar6;
                uVar9 = uVar9 + 1;
                lVar7 = lVar7 + 1;
                uStack_70 = *(undefined4 *)(puVar6 + 6);
                uStack_6c = *(undefined4 *)((longlong)puVar6 + 0x44);
                local_68 = puVar6[7];
                local_78._0_4_ = (undefined4)uVar1;
                local_78._4_4_ = (undefined4)((ulonglong)uVar1 >> 0x20);
                *puVar10 = (undefined4)local_78;
                puVar10[1] = local_78._4_4_;
                puVar10[2] = uStack_70;
                puVar10[3] = uStack_6c;
                *(undefined8 *)(puVar10 + 4) = local_68;
                puVar10 = puVar10 + 6;
                puVar6 = (undefined8 *)puVar6[5];
                local_78 = uVar1;
              } while (puVar6 != (undefined8 *)0x0);
            }
            lVar5 = lVar5 + 1;
          } while (lVar5 < 0xf);
        }
        KeUnstackDetachProcess(local_60);
        uVar4 = (ulonglong)uVar9;
      }
    }
  }
  else {
    uVar4 = 0xfffffffe;
  }
  return uVar4;
}

