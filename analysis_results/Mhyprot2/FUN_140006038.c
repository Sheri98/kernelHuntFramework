// Function: FUN_140006038
// Address: 140006038
// Decompiled by Ghidra


uint FUN_140006038(longlong param_1,int *param_2)

{
  uint uVar1;
  undefined8 ******ppppppuVar2;
  undefined8 *******pppppppuVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 *****pppppuVar7;
  undefined8 ******ppppppuVar8;
  undefined8 *puVar9;
  char cVar10;
  uint uVar11;
  undefined8 uVar12;
  undefined8 ******ppppppuVar13;
  longlong lVar14;
  undefined8 *puVar15;
  undefined8 *******pppppppuVar16;
  uint uVar17;
  undefined8 ******local_28;
  undefined8 ******local_20;
  
  if (*param_2 == 0x88) {
    uVar1 = param_2[1];
    local_20 = &local_28;
    local_28 = &local_28;
    uVar12 = FUN_1400054c4(0,(longlong)&local_28,0);
    if ((char)uVar12 != '\0') {
      uVar17 = 0;
      uVar11 = FUN_140006ca4(&local_28);
      pppppppuVar16 = (undefined8 *******)local_28;
      if (uVar1 < uVar11) {
        FUN_140005d58(&local_28);
        return uVar11;
      }
      while( true ) {
        if (pppppppuVar16 == &local_28) {
          return uVar11;
        }
        cVar10 = MmIsAddressValid(pppppppuVar16);
        if (cVar10 == '\0') {
          return uVar11;
        }
        cVar10 = MmIsAddressValid(pppppppuVar16);
        if (cVar10 == '\0') {
          return uVar11;
        }
        ppppppuVar2 = pppppppuVar16[2];
        cVar10 = MmIsAddressValid(ppppppuVar2);
        if (cVar10 == '\0') break;
        if (uVar17 < uVar1) {
          lVar14 = 5;
          ppppppuVar8 = ppppppuVar2;
          puVar9 = (undefined8 *)((ulonglong)uVar17 * 0x2a8 + param_1);
          do {
            puVar15 = puVar9;
            ppppppuVar13 = ppppppuVar8;
            pppppuVar7 = ppppppuVar13[1];
            *puVar15 = *ppppppuVar13;
            puVar15[1] = pppppuVar7;
            pppppuVar7 = ppppppuVar13[3];
            puVar15[2] = ppppppuVar13[2];
            puVar15[3] = pppppuVar7;
            pppppuVar7 = ppppppuVar13[5];
            puVar15[4] = ppppppuVar13[4];
            puVar15[5] = pppppuVar7;
            pppppuVar7 = ppppppuVar13[7];
            puVar15[6] = ppppppuVar13[6];
            puVar15[7] = pppppuVar7;
            pppppuVar7 = ppppppuVar13[9];
            puVar15[8] = ppppppuVar13[8];
            puVar15[9] = pppppuVar7;
            pppppuVar7 = ppppppuVar13[0xb];
            puVar15[10] = ppppppuVar13[10];
            puVar15[0xb] = pppppuVar7;
            pppppuVar7 = ppppppuVar13[0xd];
            puVar15[0xc] = ppppppuVar13[0xc];
            puVar15[0xd] = pppppuVar7;
            pppppuVar7 = ppppppuVar13[0xf];
            puVar15[0xe] = ppppppuVar13[0xe];
            puVar15[0xf] = pppppuVar7;
            lVar14 = lVar14 + -1;
            ppppppuVar8 = ppppppuVar13 + 0x10;
            puVar9 = puVar15 + 0x10;
          } while (lVar14 != 0);
          uVar4 = *(undefined4 *)((longlong)ppppppuVar13 + 0x84);
          uVar5 = *(undefined4 *)(ppppppuVar13 + 0x11);
          uVar6 = *(undefined4 *)((longlong)ppppppuVar13 + 0x8c);
          *(undefined4 *)(puVar15 + 0x10) = *(undefined4 *)(ppppppuVar13 + 0x10);
          *(undefined4 *)((longlong)puVar15 + 0x84) = uVar4;
          *(undefined4 *)(puVar15 + 0x11) = uVar5;
          *(undefined4 *)((longlong)puVar15 + 0x8c) = uVar6;
          pppppuVar7 = ppppppuVar13[0x13];
          puVar15[0x12] = ppppppuVar13[0x12];
          puVar15[0x13] = pppppuVar7;
          puVar15[0x14] = ppppppuVar13[0x14];
        }
        pppppppuVar3 = (undefined8 *******)*pppppppuVar16;
        uVar17 = uVar17 + 1;
        ExFreePoolWithTag(ppppppuVar2,0);
        ExFreePoolWithTag(pppppppuVar16);
        pppppppuVar16 = pppppppuVar3;
      }
      return uVar11;
    }
  }
  return 0xffffffff;
}

