// Function: FUN_1400049e0
// Address: 1400049e0
// Decompiled by Ghidra


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400049e0(ushort *param_1,longlong param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  bool bVar7;
  char cVar8;
  ushort uVar9;
  longlong lVar10;
  undefined8 *puVar11;
  undefined8 *puVar12;
  
  if (((DAT_14000a378 != 0) && (DAT_14000a388 != (undefined8 *)0x0)) && (DAT_14000a380 != 0)) {
    bVar7 = FUN_140006974();
    if ((bVar7) && (param_1 != (ushort *)0x0)) {
      cVar8 = MmIsAddressValid(param_1);
      if ((cVar8 != '\0') && (param_2 != 0)) {
        KeWaitForSingleObject(&DAT_14000a390,0,0,0,0);
        KeClearEvent(&DAT_14000a390);
        memset(&DAT_14000a3c4,0,0x208);
        _DAT_14000a3c0 = (undefined4)param_2;
        uVar9 = *param_1;
        if (0x101 < uVar9) {
          uVar9 = 0x102;
        }
        FUN_1400075c0((undefined8 *)&DAT_14000a3c4,*(undefined8 **)(param_1 + 4),(ulonglong)uVar9);
        lVar10 = 4;
        puVar5 = DAT_14000a388;
        puVar6 = (undefined8 *)&DAT_14000a3c0;
        do {
          puVar12 = puVar6;
          puVar11 = puVar5;
          uVar4 = puVar12[1];
          *puVar11 = *puVar12;
          puVar11[1] = uVar4;
          uVar4 = puVar12[3];
          puVar11[2] = puVar12[2];
          puVar11[3] = uVar4;
          uVar4 = puVar12[5];
          puVar11[4] = puVar12[4];
          puVar11[5] = uVar4;
          uVar4 = puVar12[7];
          puVar11[6] = puVar12[6];
          puVar11[7] = uVar4;
          uVar4 = puVar12[9];
          puVar11[8] = puVar12[8];
          puVar11[9] = uVar4;
          uVar4 = puVar12[0xb];
          puVar11[10] = puVar12[10];
          puVar11[0xb] = uVar4;
          uVar1 = *(undefined4 *)((longlong)puVar12 + 100);
          uVar2 = *(undefined4 *)(puVar12 + 0xd);
          uVar3 = *(undefined4 *)((longlong)puVar12 + 0x6c);
          *(undefined4 *)(puVar11 + 0xc) = *(undefined4 *)(puVar12 + 0xc);
          *(undefined4 *)((longlong)puVar11 + 100) = uVar1;
          *(undefined4 *)(puVar11 + 0xd) = uVar2;
          *(undefined4 *)((longlong)puVar11 + 0x6c) = uVar3;
          uVar1 = *(undefined4 *)((longlong)puVar12 + 0x74);
          uVar2 = *(undefined4 *)(puVar12 + 0xf);
          uVar3 = *(undefined4 *)((longlong)puVar12 + 0x7c);
          *(undefined4 *)(puVar11 + 0xe) = *(undefined4 *)(puVar12 + 0xe);
          *(undefined4 *)((longlong)puVar11 + 0x74) = uVar1;
          *(undefined4 *)(puVar11 + 0xf) = uVar2;
          *(undefined4 *)((longlong)puVar11 + 0x7c) = uVar3;
          lVar10 = lVar10 + -1;
          puVar5 = puVar11 + 0x10;
          puVar6 = puVar12 + 0x10;
        } while (lVar10 != 0);
        puVar11[0x10] = puVar12[0x10];
        *(undefined4 *)(puVar11 + 0x11) = *(undefined4 *)(puVar12 + 0x11);
        KeSetEvent(DAT_14000a380,0,0);
        KeSetEvent(&DAT_14000a390,0,0);
      }
    }
  }
  return;
}

