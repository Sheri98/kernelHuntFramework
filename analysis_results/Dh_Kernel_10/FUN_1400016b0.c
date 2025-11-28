// Function: FUN_1400016b0
// Address: 1400016b0
// Decompiled by Ghidra


void FUN_1400016b0(longlong param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 auStack_88 [8];
  undefined1 auStack_80 [24];
  undefined8 *local_68;
  undefined8 local_60;
  undefined1 local_58 [48];
  ulonglong local_28;
  
  puVar6 = auStack_88;
  puVar7 = auStack_88;
  puVar8 = auStack_88;
  local_28 = DAT_140004010 ^ (ulonglong)auStack_88;
  iVar2 = PsLookupProcessByProcessId(*(undefined4 *)(param_1 + 0x1c),&local_60);
  if (iVar2 < 0) {
    ObfDereferenceObject(local_60);
    goto LAB_140001846;
  }
  puVar3 = (undefined8 *)ExAllocatePoolWithTag(0,*(undefined8 *)(param_1 + 0x14),0x524432);
  local_68 = puVar3;
  KeStackAttachProcess(local_60,local_58);
  ProbeForRead(*(undefined8 *)(param_1 + 4),*(undefined8 *)(param_1 + 0x14),1);
  FUN_140002180(puVar3,*(undefined8 **)(param_1 + 4),*(ulonglong *)(param_1 + 0x14));
  KeUnstackDetachProcess(local_58);
  puVar8 = auStack_88;
  if (*(ulonglong *)(param_1 + 0x14) < 0x30) {
    puVar4 = (undefined8 *)ExAllocatePool(1,0xa0);
    if (puVar4 != (undefined8 *)0x0) {
      FUN_140002180(puVar4 + 2,puVar3,*(ulonglong *)(param_1 + 0x14));
      *(undefined1 *)(*(longlong *)(param_1 + 0x14) + 0x10 + (longlong)puVar4) = 0;
    }
    if (param_2 == 0) {
      uVar5 = FUN_140001228((char *)(puVar4 + 2),0x1400040c8);
      if ((int)uVar5 != 0) goto LAB_14000180b;
      if ((undefined8 *)*DAT_1400040d0 != &DAT_1400040c8) {
        pcVar1 = (code *)swi(0x29);
        DAT_1400040d0 = (undefined8 *)(*pcVar1)(3);
        puVar7 = auStack_80;
      }
      *puVar4 = &DAT_1400040c8;
      puVar4[1] = DAT_1400040d0;
      *DAT_1400040d0 = puVar4;
      puVar8 = puVar7;
      DAT_1400040d0 = puVar4;
    }
    else {
      uVar5 = FUN_140001228((char *)(puVar4 + 2),0x1400040b8);
      if ((int)uVar5 == 0) {
        if ((undefined8 *)*DAT_1400040c0 != &DAT_1400040b8) {
          pcVar1 = (code *)swi(0x29);
          DAT_1400040c0 = (undefined8 *)(*pcVar1)(3);
          puVar6 = auStack_80;
        }
        *puVar4 = &DAT_1400040b8;
        puVar4[1] = DAT_1400040c0;
        *DAT_1400040c0 = puVar4;
        puVar8 = puVar6;
        DAT_1400040c0 = puVar4;
      }
      else {
LAB_14000180b:
        ExFreePoolWithTag(puVar4,0);
        puVar8 = auStack_88;
      }
    }
  }
  *(undefined8 *)(puVar8 + -8) = 0x140001838;
  ObfDereferenceObject(*(undefined8 *)(puVar8 + 0x28));
  *(undefined8 *)(puVar8 + -8) = 0x140001846;
  ExFreePoolWithTag(puVar3,0x524432);
LAB_140001846:
  *(undefined8 *)(puVar8 + -8) = 0x140001855;
  FUN_140001c10(*(ulonglong *)(puVar8 + 0x60) ^ (ulonglong)puVar8);
  return;
}

