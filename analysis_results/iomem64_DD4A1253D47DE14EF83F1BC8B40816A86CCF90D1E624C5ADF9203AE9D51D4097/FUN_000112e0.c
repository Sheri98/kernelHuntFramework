// Function: FUN_000112e0
// Address: 000112e0
// Decompiled by Ghidra


undefined4 FUN_000112e0(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  char cVar2;
  byte bVar3;
  ushort uVar4;
  uint uVar5;
  longlong lVar6;
  undefined1 *puVar7;
  ulonglong uVar8;
  undefined1 *puVar9;
  uint *puVar10;
  char *pcVar11;
  undefined1 *puVar12;
  byte local_124;
  undefined4 local_100;
  int local_6c;
  char local_60 [24];
  char *local_48;
  uint *local_40;
  char local_38;
  undefined8 local_30;
  int local_28;
  
  local_100 = 0;
  lVar6 = FUN_000110e0(param_2);
  uVar5 = *(uint *)(lVar6 + 0x10);
  uVar1 = *(uint *)(lVar6 + 8);
  puVar10 = *(uint **)(param_2 + 0x18);
  local_28 = *(int *)(lVar6 + 0x18) + 0x63bcdc00;
  switch(local_28) {
  case 0:
    puVar7 = DAT_00014110;
    for (lVar6 = 0x2000; lVar6 != 0; lVar6 = lVar6 + -1) {
      *puVar7 = 0xff;
      puVar7 = puVar7 + 1;
    }
    *(undefined8 *)(param_2 + 0x38) = 0;
    local_100 = 0;
    break;
  default:
    local_100 = 0xc0000001;
    *(undefined8 *)(param_2 + 0x38) = 0;
    break;
  case 4:
    puVar7 = DAT_00014110;
    for (lVar6 = 0x2000; lVar6 != 0; lVar6 = lVar6 + -1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    *(undefined8 *)(param_2 + 0x38) = 0;
    local_100 = 0;
    break;
  case 8:
    if (2 < uVar5) {
      if (0x1fff < (ushort)*puVar10) {
        local_100 = 0xc000008c;
        break;
      }
      DAT_00014110[(ushort)*puVar10] = *(char *)((longlong)puVar10 + 2);
    }
    *(undefined8 *)(param_2 + 0x38) = 0;
    local_100 = 0;
    break;
  case 0x10:
    if ((1 < uVar5) && (uVar1 != 0)) {
      cVar2 = FUN_00011010((ushort)*puVar10);
      *(char *)puVar10 = cVar2;
    }
    *(undefined8 *)(param_2 + 0x38) = 1;
    local_100 = 0;
    break;
  case 0x14:
    if (2 < uVar5) {
      FUN_00011080((ushort)*puVar10,*(char *)((longlong)puVar10 + 2));
    }
    *(undefined8 *)(param_2 + 0x38) = 0;
    local_100 = 0;
    break;
  case 0x18:
    if ((1 < uVar5) && (1 < uVar1)) {
      uVar4 = FUN_00011030((ushort)*puVar10);
      *(ushort *)puVar10 = uVar4;
    }
    *(undefined8 *)(param_2 + 0x38) = 2;
    local_100 = 0;
    break;
  case 0x1c:
    if (3 < uVar5) {
      FUN_000110a0((ushort)*puVar10,*(ushort *)((longlong)puVar10 + 2));
    }
    *(undefined8 *)(param_2 + 0x38) = 0;
    local_100 = 0;
    break;
  case 0x20:
    if ((3 < uVar5) && (3 < uVar1)) {
      uVar5 = FUN_00011060((short)*puVar10);
      *puVar10 = uVar5;
    }
    *(undefined8 *)(param_2 + 0x38) = 4;
    local_100 = 0;
    break;
  case 0x24:
    if (7 < uVar5) {
      FUN_000110c0((short)*puVar10,puVar10[1]);
    }
    *(undefined8 *)(param_2 + 0x38) = 0;
    local_100 = 0;
    break;
  case 0x28:
    if ((1 < uVar5) && (3 < uVar1)) {
      KeEnterCriticalRegion();
      FUN_00011030((ushort)*puVar10);
      uVar5 = FUN_00011060((short)*puVar10);
      KeLeaveCriticalRegion();
      *puVar10 = uVar5;
    }
    *(undefined8 *)(param_2 + 0x38) = 4;
    local_100 = 0;
    break;
  case 0x2c:
    if (uVar5 < 0xc) {
      local_100 = 0xc0000023;
    }
    else {
      uVar5 = *puVar10;
      uVar1 = puVar10[2];
      puVar7 = (undefined1 *)MmMapIoSpace(puVar10[1],uVar5,0);
      if (puVar7 == (undefined1 *)0x0) {
        local_100 = 0xc0000001;
      }
      else {
        puVar9 = puVar7;
        puVar12 = (undefined1 *)(ulonglong)uVar1;
        for (uVar8 = (ulonglong)uVar5; uVar8 != 0; uVar8 = uVar8 - 1) {
          *puVar12 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar12 = puVar12 + 1;
        }
        MmUnmapIoSpace(puVar7,uVar5);
      }
    }
    *(undefined8 *)(param_2 + 0x38) = 0;
    break;
  case 0x30:
    if (2 < uVar5) {
      if ((char)*puVar10 == '\0') {
        local_124 = FUN_00011010(0x61);
        local_124 = local_124 & 0xfc;
      }
      else {
        FUN_00011080(0x43,0xb6);
        FUN_00011080(0x42,*(char *)((longlong)puVar10 + 2));
        FUN_00011080(0x42,*(char *)((longlong)puVar10 + 1));
        local_124 = FUN_00011010(0x61);
        local_124 = local_124 | 3;
      }
      FUN_00011080(0x61,local_124);
    }
    *(undefined8 *)(param_2 + 0x38) = 0;
    local_100 = 0;
    break;
  case 0x34:
    if ((0x10f < uVar5) && (0x10f < uVar1)) {
      uVar5 = FUN_00011f90(puVar10);
      puVar10[3] = uVar5;
    }
    *(undefined8 *)(param_2 + 0x38) = 0x110;
    local_100 = 0;
    break;
  case 0x38:
    if ((uVar5 < 2) || (uVar1 == 0)) {
      local_100 = 0xc0000023;
    }
    else {
      local_6c = 10000;
      uVar5 = *puVar10;
      local_100 = 0xc0000022;
      do {
        local_6c = local_6c + -1;
        if (local_6c < 1) break;
        cVar2 = FUN_00011010(0x66);
      } while (cVar2 != '\0');
      if (-1 < local_6c) {
        FUN_00011080(0x66,0x80);
        local_6c = 10000;
        do {
          local_6c = local_6c + -1;
          if (local_6c < 1) break;
          bVar3 = FUN_00011010(0x66);
        } while ((bVar3 & 2) != 0);
        if (-1 < local_6c) {
          FUN_00011080(0x62,(char)uVar5);
          local_6c = 10000;
          do {
            local_6c = local_6c + -1;
            if (local_6c < 1) goto LAB_00011c9b;
            bVar3 = FUN_00011010(0x66);
          } while ((bVar3 & 3) != 1);
          cVar2 = FUN_00011010(0x62);
          *(char *)puVar10 = cVar2;
          local_100 = 0;
        }
      }
    }
LAB_00011c9b:
    *(undefined8 *)(param_2 + 0x38) = 1;
    break;
  case 0x3c:
    if (0x1b < uVar5) {
      uVar5 = FUN_00012040(puVar10);
      puVar10[3] = uVar5;
    }
    *(undefined8 *)(param_2 + 0x38) = 0x1c;
    local_100 = 0;
    break;
  case 0x40:
    if ((0x1b < uVar5) && (0x1b < uVar1)) {
      uVar5 = FUN_00012110(puVar10);
      puVar10[3] = uVar5;
    }
    *(undefined8 *)(param_2 + 0x38) = 0x1c;
    local_100 = 0;
    break;
  case 0x44:
    if (uVar5 < 0xc) {
      local_100 = 0xc0000023;
    }
    else {
      uVar5 = *puVar10;
      uVar1 = puVar10[2];
      puVar7 = (undefined1 *)MmMapIoSpace(puVar10[1],uVar5,0);
      if (puVar7 == (undefined1 *)0x0) {
        local_100 = 0xc0000001;
      }
      else {
        puVar9 = (undefined1 *)(ulonglong)uVar1;
        puVar12 = puVar7;
        for (uVar8 = (ulonglong)uVar5; uVar8 != 0; uVar8 = uVar8 - 1) {
          *puVar12 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar12 = puVar12 + 1;
        }
        MmUnmapIoSpace(puVar7,uVar5);
      }
    }
    *(undefined8 *)(param_2 + 0x38) = 0;
    break;
  case 0x48:
    if ((0x13 < uVar5) && (0x13 < uVar1)) {
      local_48 = local_60;
      pcVar11 = local_60;
      local_40 = puVar10;
      for (lVar6 = 0x14; lVar6 != 0; lVar6 = lVar6 + -1) {
        *pcVar11 = (char)*puVar10;
        puVar10 = (uint *)((longlong)puVar10 + 1);
        pcVar11 = pcVar11 + 1;
      }
      FUN_000121e3((int)local_60);
      pcVar11 = local_60;
      puVar10 = local_40;
      for (lVar6 = 0x14; lVar6 != 0; lVar6 = lVar6 + -1) {
        *(char *)puVar10 = *pcVar11;
        pcVar11 = pcVar11 + 1;
        puVar10 = (uint *)((longlong)puVar10 + 1);
      }
    }
    *(undefined8 *)(param_2 + 0x38) = 0x14;
    local_100 = 0;
    break;
  case 0x4c:
    if ((uVar5 != 0) && (uVar1 != 0)) {
      uVar5 = FUN_00012216();
      local_38 = (char)uVar5;
      *(char *)puVar10 = local_38;
    }
    *(undefined8 *)(param_2 + 0x38) = 1;
    local_100 = 0;
    break;
  case 0x50:
    if (7 < uVar1) {
      FUN_0001222e((int)&local_30);
      *(undefined8 *)puVar10 = local_30;
    }
    *(undefined8 *)(param_2 + 0x38) = 8;
    local_100 = 0;
    break;
  case 0x6c:
    if ((3 < uVar5) && (3 < uVar1)) {
      uVar8 = FUN_000121e0(*puVar10);
      *puVar10 = (uint)uVar8;
    }
    *(undefined8 *)(param_2 + 0x38) = 4;
    local_100 = 0;
  }
  *(undefined4 *)(param_2 + 0x30) = local_100;
  IofCompleteRequest(param_2,0);
  return local_100;
}

