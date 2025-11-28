// Function: FUN_140004c70
// Address: 140004c70
// Decompiled by Ghidra


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140004c70(undefined4 param_1,undefined4 param_2,undefined8 *param_3,ushort *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  ushort uVar7;
  undefined8 in_RAX;
  undefined8 *puVar8;
  undefined8 *puVar9;
  longlong lVar10;
  
  if (param_3 != (undefined8 *)0x0) {
    in_RAX = MmIsAddressValid(param_4);
    if ((char)in_RAX != '\0') {
      _DAT_14000a150 = param_1;
      _DAT_14000a154 = param_2;
      memset(&DAT_14000a168,0,0x208);
      _DAT_14000a158 = *param_3;
      _DAT_14000a160 = *(undefined4 *)(param_3 + 1);
      _DAT_14000a164 = *(undefined2 *)((longlong)param_3 + 0xc);
      DAT_14000a166 = *(undefined1 *)((longlong)param_3 + 0xe);
      uVar7 = 0x102;
      if (*param_4 < 0x103) {
        uVar7 = *param_4;
      }
      FUN_1400075c0((undefined8 *)&DAT_14000a168,*(undefined8 **)(param_4 + 4),(ulonglong)uVar7);
      DAT_14000a370 = 0;
      lVar10 = 4;
      puVar5 = DAT_14000a130;
      puVar6 = (undefined8 *)&DAT_14000a150;
      do {
        puVar9 = puVar6;
        puVar8 = puVar5;
        uVar4 = puVar9[1];
        *puVar8 = *puVar9;
        puVar8[1] = uVar4;
        uVar4 = puVar9[3];
        puVar8[2] = puVar9[2];
        puVar8[3] = uVar4;
        uVar4 = puVar9[5];
        puVar8[4] = puVar9[4];
        puVar8[5] = uVar4;
        uVar4 = puVar9[7];
        puVar8[6] = puVar9[6];
        puVar8[7] = uVar4;
        uVar4 = puVar9[9];
        puVar8[8] = puVar9[8];
        puVar8[9] = uVar4;
        uVar4 = puVar9[0xb];
        puVar8[10] = puVar9[10];
        puVar8[0xb] = uVar4;
        uVar4 = puVar9[0xd];
        puVar8[0xc] = puVar9[0xc];
        puVar8[0xd] = uVar4;
        uVar4 = puVar9[0xf];
        puVar8[0xe] = puVar9[0xe];
        puVar8[0xf] = uVar4;
        lVar10 = lVar10 + -1;
        puVar5 = puVar8 + 0x10;
        puVar6 = puVar9 + 0x10;
      } while (lVar10 != 0);
      uVar1 = *(undefined4 *)((longlong)puVar9 + 0x84);
      uVar2 = *(undefined4 *)(puVar9 + 0x11);
      uVar3 = *(undefined4 *)((longlong)puVar9 + 0x8c);
      *(undefined4 *)(puVar8 + 0x10) = *(undefined4 *)(puVar9 + 0x10);
      *(undefined4 *)((longlong)puVar8 + 0x84) = uVar1;
      *(undefined4 *)(puVar8 + 0x11) = uVar2;
      *(undefined4 *)((longlong)puVar8 + 0x8c) = uVar3;
      uVar1 = *(undefined4 *)((longlong)puVar9 + 0x94);
      uVar2 = *(undefined4 *)(puVar9 + 0x13);
      uVar3 = *(undefined4 *)((longlong)puVar9 + 0x9c);
      *(undefined4 *)(puVar8 + 0x12) = *(undefined4 *)(puVar9 + 0x12);
      *(undefined4 *)((longlong)puVar8 + 0x94) = uVar1;
      *(undefined4 *)(puVar8 + 0x13) = uVar2;
      *(undefined4 *)((longlong)puVar8 + 0x9c) = uVar3;
      in_RAX = KeSetEvent(DAT_14000a128,0,0);
      DAT_14000a370 = 2;
    }
  }
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
}

