// Function: FUN_00011300
// Address: 00011300
// Decompiled by Ghidra


undefined4 FUN_00011300(undefined8 param_1,longlong param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  byte bVar7;
  ushort uVar8;
  uint uVar9;
  undefined4 uVar10;
  ulonglong uVar11;
  undefined2 uVar12;
  uint *puVar13;
  uint *puVar14;
  undefined8 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  uint local_48 [2];
  uint *local_40 [2];
  
  uVar15 = 0;
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  pcVar6 = *(char **)(param_2 + 0xb8);
  puVar14 = *(uint **)(param_2 + 0x18);
  iVar1 = *(int *)(pcVar6 + 0x10);
  uVar9 = *(uint *)(pcVar6 + 8);
  puVar13 = (uint *)(ulonglong)uVar9;
  uVar10 = 0;
  uVar16 = 0;
  uVar17 = 0;
  if (*pcVar6 != '\x0e') goto LAB_00011522;
  iVar2 = *(int *)(pcVar6 + 0x18);
  if (iVar2 == -0x7fffdff8) {
    if ((iVar1 == 0x1c) && (uVar9 == 0x1c)) {
      uVar11 = FUN_00011000(param_1,puVar14);
      uVar10 = (undefined4)uVar11;
      uVar15 = 0x1c;
      puVar13 = puVar14;
      goto LAB_0001151c;
    }
LAB_00011516:
    uVar10 = 0xc000000d;
    goto LAB_0001151c;
  }
  uVar17 = uVar16;
  if (iVar2 == -0x7fffdff4) {
    if (iVar1 == 0x1c) {
      local_40[0] = (uint *)0x0;
      RtlCopyMemory(local_40,puVar14 + 6,4);
      puVar13 = local_40[0];
      uVar10 = ZwUnmapViewOfSection(0xffffffffffffffff,local_40[0]);
      *(undefined4 *)(param_2 + 0x30) = uVar10;
      *(undefined8 *)(param_2 + 0x38) = 0;
    }
    else {
      *(undefined8 *)(param_2 + 0x38) = 0;
      uVar17 = 0xc000000d;
    }
    goto LAB_00011522;
  }
  if (iVar2 != -0x7fffdff0) {
    if (iVar2 == -0x7fffdfec) {
      if (iVar1 == 0xc) {
        puVar13 = (uint *)(ulonglong)*puVar14;
        uVar9 = puVar14[2];
        uVar12 = (undefined2)*puVar14;
        if (uVar9 != 1) {
          if (uVar9 == 2) {
            out(uVar12,(short)puVar14[1]);
            *(undefined8 *)(param_2 + 0x38) = 0;
            goto LAB_00011522;
          }
          if (uVar9 == 4) {
            out(uVar12,puVar14[1]);
            *(undefined8 *)(param_2 + 0x38) = 0;
            goto LAB_00011522;
          }
        }
        out(uVar12,(char)puVar14[1]);
        *(undefined8 *)(param_2 + 0x38) = 0;
      }
      else {
        *(undefined8 *)(param_2 + 0x38) = 0;
        uVar17 = 0xc000000d;
      }
    }
    else if (iVar2 == -0x7fffdfb0) {
      if ((iVar1 == 0x14) && (uVar9 == 0x14)) {
        uVar9 = puVar14[3];
        uVar3 = puVar14[2];
        uVar4 = puVar14[1];
        uVar5 = *puVar14;
        local_48[0] = 0xffffffff;
        KeEnterCriticalRegion();
        puVar13 = (uint *)(ulonglong)uVar4;
        HalGetBusDataByOffset(4,puVar13,(uVar9 & 7) << 5 | uVar3 & 0x1f,local_48,uVar5,4);
        KeLeaveCriticalRegion();
        puVar14[4] = local_48[0];
        *(undefined8 *)(param_2 + 0x38) = 0x14;
      }
      else {
        *(undefined8 *)(param_2 + 0x38) = 0;
        uVar17 = 0xc000000d;
      }
    }
    else {
      uVar17 = 0xc000000d;
    }
    goto LAB_00011522;
  }
  if ((iVar1 != 0xc) || (uVar9 != 0xc)) goto LAB_00011516;
  uVar9 = puVar14[2];
  puVar13 = (uint *)(ulonglong)(*puVar14 & 0xffff);
  uVar12 = (undefined2)*puVar14;
  if (uVar9 == 1) {
LAB_0001149d:
    bVar7 = in(uVar12);
    puVar14[1] = (uint)bVar7;
    uVar15 = 0xc;
  }
  else if (uVar9 == 2) {
    uVar8 = in(uVar12);
    puVar14[1] = (uint)uVar8;
    uVar15 = 0xc;
  }
  else {
    if (uVar9 != 4) goto LAB_0001149d;
    uVar9 = in(uVar12);
    puVar14[1] = uVar9;
    uVar15 = 0xc;
    uVar10 = 0;
  }
LAB_0001151c:
  *(undefined8 *)(param_2 + 0x38) = uVar15;
  uVar17 = uVar10;
LAB_00011522:
  *(undefined4 *)(param_2 + 0x30) = uVar17;
  IofCompleteRequest(param_2,(ulonglong)puVar13 & 0xffffffffffffff00);
  return uVar17;
}

