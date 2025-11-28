// Function: FUN_1400032b0
// Address: 1400032b0
// Decompiled by Ghidra


int FUN_1400032b0(uint *param_1,ulonglong *param_2)

{
  longlong ***ppplVar1;
  longlong ***ppplVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  longlong ****pppplVar6;
  undefined1 *puVar7;
  uint uVar8;
  ulonglong uVar9;
  longlong local_res8;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [24];
  longlong ***local_48;
  longlong ***local_40;
  undefined1 local_38 [48];
  
  uVar8 = 0;
  local_res8 = 0;
  uVar4 = *param_1 ^ 0xcdfe;
  *param_1 = uVar4;
  puVar7 = auStack_68;
  if ((param_2 == (ulonglong *)0x0) || (puVar7 = auStack_68, uVar4 == 0)) goto LAB_140003435;
  local_40 = (longlong ***)&local_48;
  local_48 = (longlong ***)&local_48;
  iVar5 = PsLookupProcessByProcessId(uVar4,&local_res8);
  if (iVar5 < 0) {
LAB_14000340d:
    while ((longlong ****)local_48 != &local_48) {
      ppplVar1 = (longlong ***)*local_48;
      if (((longlong ***)ppplVar1[1] != local_48) ||
         (ppplVar2 = (longlong ***)local_48[1], (longlong ***)*ppplVar2 != local_48)) {
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(3);
        puVar7 = auStack_60;
        goto LAB_140003435;
      }
      *ppplVar2 = (longlong **)ppplVar1;
      ppplVar1[1] = (longlong **)ppplVar2;
      ExFreePoolWithTag(local_48,0x4746544d);
    }
  }
  else {
    KeStackAttachProcess(local_res8,local_38);
    iVar5 = FUN_1400030b8((longlong *)&local_48,0x10000,*(ulonglong *)MmHighestUserAddress_exref,
                          '\x01');
    KeUnstackDetachProcess(local_38);
    if (iVar5 < 0) goto LAB_14000340d;
    pppplVar6 = (longlong ****)local_48;
    if ((longlong ****)local_48 != &local_48) {
      do {
        pppplVar6 = (longlong ****)*pppplVar6;
        uVar8 = uVar8 + 1;
      } while (pppplVar6 != &local_48);
    }
    uVar9 = *param_2;
    *param_2 = (ulonglong)uVar8;
    if (uVar9 < uVar8) goto LAB_14000340d;
    pppplVar6 = (longlong ****)local_48;
    uVar9 = 0;
    if ((longlong ****)local_48 != &local_48) {
      do {
        param_2[uVar9 * 6 + 2] = (ulonglong)pppplVar6[3];
        *(undefined4 *)(param_2 + uVar9 * 6 + 3) = *(undefined4 *)(pppplVar6 + 4);
        param_2[uVar9 * 6 + 1] = (ulonglong)pppplVar6[2];
        *(undefined4 *)((longlong)param_2 + uVar9 * 0x30 + 0x2c) =
             *(undefined4 *)((longlong)pppplVar6 + 0x34);
        param_2[uVar9 * 6 + 4] = (ulonglong)pppplVar6[5];
        *(undefined4 *)(param_2 + uVar9 * 6 + 5) = *(undefined4 *)(pppplVar6 + 6);
        *(undefined4 *)(param_2 + uVar9 * 6 + 6) = *(undefined4 *)(pppplVar6 + 7);
        pppplVar6 = (longlong ****)*pppplVar6;
        uVar9 = (ulonglong)((int)uVar9 + 1);
      } while (pppplVar6 != &local_48);
      goto LAB_14000340d;
    }
  }
  puVar7 = auStack_68;
  if (local_res8 != 0) {
    ObfDereferenceObject();
    puVar7 = auStack_68;
  }
LAB_140003435:
  return (int)*(undefined8 *)(puVar7 + 0x88);
}

