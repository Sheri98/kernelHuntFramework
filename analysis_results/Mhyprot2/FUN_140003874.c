// Function: FUN_140003874
// Address: 140003874
// Decompiled by Ghidra


undefined8 FUN_140003874(longlong *param_1,longlong param_2)

{
  longlong lVar1;
  code *pcVar2;
  ulonglong uVar3;
  int iVar4;
  uint *puVar5;
  undefined8 uVar6;
  longlong *plVar7;
  uint uVar8;
  ulonglong uVar9;
  undefined4 local_res18 [4];
  undefined4 local_28;
  
  puVar5 = (uint *)ExAllocatePool(0,0x100000);
  if (puVar5 == (uint *)0x0) {
    uVar6 = 0xc0000001;
  }
  else {
    local_res18[0] = 0;
    iVar4 = ZwQuerySystemInformation(0x42,puVar5,0x100000,local_res18);
    if ((iVar4 == 0) && (uVar9 = 0, *puVar5 != 0)) {
      do {
        uVar6 = *(undefined8 *)(puVar5 + uVar9 * 6 + 6);
        lVar1 = *(longlong *)(puVar5 + uVar9 * 6 + 2);
        uVar3 = *(ulonglong *)(puVar5 + uVar9 * 6 + 2 + 2);
        if (((*(ulonglong *)(param_2 + 8) == 0) || (*(ulonglong *)(param_2 + 8) <= uVar3)) &&
           ((*(ulonglong *)(param_2 + 0x10) == 0 || (uVar3 <= *(ulonglong *)(param_2 + 0x10))))) {
          plVar7 = (longlong *)ExAllocatePool(0,0x28);
          plVar7[2] = lVar1;
          local_28 = (undefined4)uVar6;
          *(undefined4 *)(plVar7 + 4) = local_28;
          plVar7[3] = uVar3;
          lVar1 = *param_1;
          if (*(longlong **)(lVar1 + 8) != param_1) {
            pcVar2 = (code *)swi(0x29);
            (*pcVar2)(3);
            pcVar2 = (code *)swi(3);
            uVar6 = (*pcVar2)();
            return uVar6;
          }
          *plVar7 = lVar1;
          plVar7[1] = (longlong)param_1;
          *(longlong **)(lVar1 + 8) = plVar7;
          *param_1 = (longlong)plVar7;
        }
        uVar8 = (int)uVar9 + 1;
        uVar9 = (ulonglong)uVar8;
      } while (uVar8 < *puVar5);
    }
    ExFreePoolWithTag(puVar5,0);
    uVar6 = 0;
  }
  return uVar6;
}

