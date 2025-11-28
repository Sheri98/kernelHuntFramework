// Function: FUN_000115b0
// Address: 000115b0
// Decompiled by Ghidra


/* WARNING: Removing unreachable block (ram,0x00013458) */
/* WARNING: Removing unreachable block (ram,0x0001347c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_000115b0(undefined8 param_1,longlong param_2)

{
  char *pcVar1;
  uint *puVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  uint uVar5;
  byte bVar6;
  ushort uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  longlong lVar11;
  uint *puVar12;
  undefined8 *puVar13;
  undefined8 *puVar14;
  longlong lVar15;
  undefined8 uVar16;
  longlong lVar17;
  ulonglong uVar18;
  longlong lVar19;
  longlong lVar20;
  ulonglong *puVar21;
  short sVar22;
  undefined8 *puVar23;
  undefined2 uVar24;
  int iVar25;
  longlong *plVar26;
  int iVar27;
  undefined4 *puVar28;
  uint uVar29;
  ulonglong uVar30;
  uint uVar31;
  uint uVar32;
  bool bVar33;
  undefined8 in_CR0;
  undefined8 in_CR2;
  undefined8 in_CR3;
  double dVar34;
  double dVar35;
  double dVar36;
  double dVar37;
  float fVar38;
  ulonglong local_res8;
  byte local_res10;
  uint local_res18 [2];
  uint local_res20 [2];
  byte local_2f8;
  ushort local_2f4;
  uint local_2e8;
  uint local_2e4;
  uint local_2c8;
  uint local_2c4;
  uint local_2c0;
  uint local_2bc;
  uint local_2b8;
  uint local_2b4;
  uint local_2b0;
  int local_2ac;
  uint local_2a8;
  uint local_2a4;
  ulonglong local_2a0;
  ulonglong local_298;
  uint local_290;
  uint local_28c;
  uint local_288;
  uint local_284;
  uint local_280;
  uint local_27c;
  uint local_278;
  uint local_274;
  uint local_270;
  uint local_26c;
  ushort *local_268;
  uint local_260;
  uint local_25c;
  uint local_258;
  uint local_254;
  uint local_250;
  int local_248;
  undefined4 uStack_244;
  uint local_240;
  uint local_23c;
  undefined4 local_238;
  undefined4 local_234;
  undefined4 local_230;
  uint local_22c;
  uint local_228;
  float local_224;
  uint local_220;
  uint local_21c;
  uint local_218;
  uint local_214;
  undefined4 local_210;
  uint local_20c;
  uint local_208 [2];
  int local_200;
  undefined4 uStack_1fc;
  uint local_1f8;
  undefined4 local_1f0;
  undefined4 local_1ec;
  uint local_1e8;
  uint local_1e4;
  uint local_1e0;
  uint local_1dc;
  uint local_1d8;
  longlong local_1d0;
  uint local_1c8;
  longlong local_1c0;
  uint local_1b8;
  ulonglong local_1b0;
  uint local_1a8;
  ulonglong local_1a0;
  uint local_198;
  uint uStack_194;
  undefined8 local_190;
  longlong local_188;
  uint local_180;
  uint uStack_17c;
  uint local_178;
  undefined4 uStack_174;
  longlong *local_170;
  longlong local_168;
  uint local_160;
  uint uStack_15c;
  longlong *local_158;
  longlong local_150;
  uint local_148;
  uint uStack_144;
  longlong *local_140;
  uint local_138;
  uint uStack_134;
  uint local_130;
  undefined4 *local_128;
  uint local_120;
  uint local_11c;
  uint local_118;
  longlong local_110;
  ulonglong local_108;
  double local_100;
  ulonglong local_f8;
  uint local_f0;
  undefined4 local_ec;
  uint local_e8;
  uint local_e0;
  uint local_dc;
  uint local_d8;
  undefined1 local_d0 [16];
  ulonglong local_c0;
  ulonglong local_b8;
  ulonglong local_b0;
  ulonglong local_a0;
  ulonglong local_98;
  ulonglong local_90;
  undefined1 local_80 [16];
  longlong local_70;
  
  puVar13 = (undefined8 *)0x0;
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  pcVar1 = *(char **)(param_2 + 0xb8);
  puVar2 = *(uint **)(param_2 + 0x18);
  if (*pcVar1 != '\x0e') goto LAB_00014267;
  uVar8 = *(uint *)(pcVar1 + 0x18);
  uVar9 = 0;
  if (uVar8 < 0x9c402501) {
    if (uVar8 == 0x9c402500) {
      if ((*(uint *)(pcVar1 + 8) < 0x10) || (*(uint *)(pcVar1 + 0x10) < 0x10)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        local_260 = *puVar2;
        local_25c = puVar2[1];
        local_258 = puVar2[2];
        local_254 = puVar2[3];
        FUN_00014590(&local_260);
        *puVar2 = local_260;
        puVar2[1] = local_25c;
        puVar2[2] = local_258;
        puVar2[3] = local_254;
        *(undefined8 *)(param_2 + 0x38) = 0x10;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      goto LAB_00014267;
    }
    switch(uVar8) {
    case 0x9c402400:
      if ((*(uint *)(pcVar1 + 8) < 8) || (*(uint *)(pcVar1 + 0x10) < 4)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        uVar16 = rdmsr(*puVar2);
        *puVar2 = (uint)uVar16;
        puVar2[1] = (uint)((ulonglong)uVar16 >> 0x20);
        *(undefined8 *)(param_2 + 0x38) = 8;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    default:
      goto switchD_0001163e_caseD_9c402401;
    case 0x9c402404:
      if ((*(uint *)(pcVar1 + 8) < 8) || (*(uint *)(pcVar1 + 0x10) < 4)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        bVar6 = in((short)*puVar2);
        *puVar2 = (uint)bVar6;
        puVar2[1] = 0x87654321;
        *(undefined8 *)(param_2 + 0x38) = 8;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c402408:
      if ((*(uint *)(pcVar1 + 8) < 8) || (*(uint *)(pcVar1 + 0x10) < 8)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        out((short)*puVar2,(char)puVar2[1]);
        *puVar2 = 0x87654321;
        puVar2[1] = 0x87654321;
        *(undefined8 *)(param_2 + 0x38) = 8;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c40240c:
      if ((*(uint *)(pcVar1 + 8) < 8) || (*(uint *)(pcVar1 + 0x10) < 4)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        uVar7 = in((short)*puVar2);
        *puVar2 = (uint)uVar7;
        puVar2[1] = 0x87654321;
        *(undefined8 *)(param_2 + 0x38) = 8;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c402410:
      if ((*(uint *)(pcVar1 + 8) < 8) || (*(uint *)(pcVar1 + 0x10) < 8)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        out((short)*puVar2,(short)puVar2[1]);
        *puVar2 = 0x87654321;
        puVar2[1] = 0x87654321;
        *(undefined8 *)(param_2 + 0x38) = 8;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c402414:
      if ((*(uint *)(pcVar1 + 8) < 8) || (*(uint *)(pcVar1 + 0x10) < 4)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        uVar8 = in((short)*puVar2);
        *puVar2 = uVar8;
        puVar2[1] = 0x87654321;
        *(undefined8 *)(param_2 + 0x38) = 8;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c402418:
      if ((*(uint *)(pcVar1 + 8) < 8) || (*(uint *)(pcVar1 + 0x10) < 8)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        out((short)*puVar2,puVar2[1]);
        *puVar2 = 0x87654321;
        puVar2[1] = 0x87654321;
        *(undefined8 *)(param_2 + 0x38) = 8;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c402420:
      if ((*(uint *)(pcVar1 + 8) < 8) || (*(uint *)(pcVar1 + 0x10) < 0x14)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        uStack_194 = *puVar2;
        local_198 = puVar2[1];
        uVar8 = puVar2[2];
        uVar9 = puVar2[4];
        lVar15 = CONCAT44(puVar2[3],uVar9);
        uVar18 = CONCAT44(uStack_194,local_198);
        local_70 = lVar15;
        plVar26 = FUN_00011170(uVar18,uVar8);
        if (plVar26 == (longlong *)0x0) {
          lVar11 = MmMapIoSpace(uVar18,uVar8,0);
          local_2bc = 0;
          while ((uint)puVar13 < uVar8) {
            *(undefined1 *)((longlong)puVar13 + lVar15) =
                 *(undefined1 *)((longlong)puVar13 + lVar11);
            local_2bc = (uint)puVar13 + 1;
            puVar13 = (undefined8 *)(ulonglong)local_2bc;
          }
          MmUnmapIoSpace(lVar11,uVar8);
          *puVar2 = 0x22222222;
        }
        else {
          lVar11 = *plVar26;
          lVar17 = plVar26[1];
          local_2bc = 0;
          while ((uint)puVar13 < uVar8) {
            *(undefined1 *)((longlong)puVar13 + lVar15) =
                 *(undefined1 *)((longlong)puVar13 + (uVar18 - lVar11) + lVar17);
            local_2bc = (uint)puVar13 + 1;
            puVar13 = (undefined8 *)(ulonglong)local_2bc;
          }
          *puVar2 = 0x11111111;
        }
        puVar2[1] = uVar9;
        *(undefined8 *)(param_2 + 0x38) = 8;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c402424:
      if ((*(uint *)(pcVar1 + 8) < 8) || (*(uint *)(pcVar1 + 0x10) < 0xc)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        wrmsr(*puVar2,CONCAT44(puVar2[1],puVar2[2]));
        *puVar2 = puVar2[2];
        puVar2[1] = puVar2[1];
        *(undefined8 *)(param_2 + 0x38) = 8;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c402428:
      if ((*(uint *)(pcVar1 + 8) < 8) || (*(uint *)(pcVar1 + 0x10) < 4)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        uVar8 = *puVar2;
        if (uVar8 == 0) {
          *puVar2 = (uint)in_CR0;
          puVar2[1] = (uint)((ulonglong)in_CR0 >> 0x20);
          *(undefined8 *)(param_2 + 0x38) = 8;
          *(undefined4 *)(param_2 + 0x30) = 0;
        }
        else if (uVar8 == 2) {
          *puVar2 = (uint)in_CR2;
          puVar2[1] = (uint)((ulonglong)in_CR2 >> 0x20);
          *(undefined8 *)(param_2 + 0x38) = 8;
          *(undefined4 *)(param_2 + 0x30) = 0;
        }
        else if (uVar8 == 3) {
          *puVar2 = (uint)in_CR3;
          puVar2[1] = (uint)((ulonglong)in_CR3 >> 0x20);
          *(undefined8 *)(param_2 + 0x38) = 8;
          *(undefined4 *)(param_2 + 0x30) = 0;
        }
        else {
          *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
        }
      }
      break;
    case 0x9c40242c:
      if ((*(uint *)(pcVar1 + 8) < 8) || (*(uint *)(pcVar1 + 0x10) < 0xc)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else if (*puVar2 == 0) {
        *(undefined8 *)(param_2 + 0x38) = 8;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      else if (*puVar2 == 3) {
        *(undefined8 *)(param_2 + 0x38) = 8;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      else {
        *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
      }
      break;
    case 0x9c402430:
      if ((*(uint *)(pcVar1 + 8) < 8) || (*(uint *)(pcVar1 + 0x10) < 0xc)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        uStack_15c = *puVar2;
        local_160 = puVar2[1];
        uVar8 = puVar2[2];
        uVar18 = CONCAT44(uStack_15c,local_160);
        plVar26 = FUN_00011170(uVar18,4);
        if (plVar26 == (longlong *)0x0) {
          puVar12 = (uint *)MmMapIoSpace(uVar18,4,0);
          *puVar12 = uVar8;
          MmUnmapIoSpace(puVar12,4);
          *puVar2 = 0x22222222;
        }
        else {
          *(uint *)((uVar18 - *plVar26) + plVar26[1]) = uVar8;
          *puVar2 = 0x11111111;
        }
        puVar2[1] = uVar8;
        *(undefined8 *)(param_2 + 0x38) = 8;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c402438:
      if (*(uint *)(pcVar1 + 8) < 4) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        *puVar2 = 0x141;
        *(undefined8 *)(param_2 + 0x38) = 4;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c40243c:
      if ((*(uint *)(pcVar1 + 8) < 0x10) || (*(uint *)(pcVar1 + 0x10) < 8)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        local_230 = 0;
        local_210 = 0;
        local_234 = 0;
        PsGetVersion(&local_234,&local_210,&local_230,0);
        uVar8 = *puVar2;
        uStack_1fc = 0;
        local_200 = puVar2[1] + 0x300;
        local_130 = uVar8;
        lVar15 = MmMapIoSpace(local_200,0x100,0);
        local_f0 = *(uint *)(lVar15 + 0x20);
        local_ec = *(undefined4 *)(lVar15 + 0xe0);
        uVar9 = *(uint *)(lVar15 + 0x80);
        *(uint *)(lVar15 + 0x20) = local_f0 & 0xfffdffff;
        *(undefined4 *)(lVar15 + 0xe0) = 2;
        *(undefined4 *)(lVar15 + 0x80) = 0xffffffff;
        local_22c = *(uint *)(lVar15 + 0x90);
        uVar24 = (undefined2)uVar8;
        local_2b4 = in(uVar24);
        local_2b4 = local_2b4 & 0xffffff;
        uVar8 = local_22c;
        uVar29 = local_2b4;
        do {
          uVar31 = *(uint *)(lVar15 + 0x90);
          if (uVar31 < 0xfff00000) {
            *(undefined4 *)(lVar15 + 0x80) = 0xffffffff;
            uVar31 = *(uint *)(lVar15 + 0x90);
            local_2b4 = in(uVar24);
            local_2b4 = local_2b4 & 0xffffff;
            local_22c = uVar31;
            uVar8 = uVar31;
            uVar29 = local_2b4;
          }
          local_270 = in(uVar24);
          local_270 = local_270 & 0xffffff;
          if (local_270 < uVar29) {
            local_270 = local_270 + 0xffffff;
          }
        } while (local_270 - uVar29 < 15000);
        dVar34 = (double)local_270 - (double)uVar29;
        if (dVar34 <= _DAT_00015158) {
          fVar38 = 0.0;
        }
        else {
          fVar38 = (float)((((double)uVar8 - (double)uVar31) * _DAT_00015150) / dVar34);
        }
        *(uint *)(lVar15 + 0x20) = local_f0;
        *(undefined4 *)(lVar15 + 0xe0) = local_ec;
        *(uint *)(lVar15 + 0x80) = uVar9;
        local_e8 = uVar9;
        MmUnmapIoSpace(lVar15,0x100);
        *puVar2 = (uint)(longlong)fVar38;
        puVar2[1] = (uint)(longlong)((double)uVar8 - (double)uVar31);
        puVar2[2] = (uint)(longlong)dVar34;
        puVar2[3] = uVar9;
        *(undefined8 *)(param_2 + 0x38) = 0x10;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c402448:
      if ((*(uint *)(pcVar1 + 8) < 4) || (*(uint *)(pcVar1 + 0x10) < 0x1c)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        uVar8 = HalGetBusDataByOffset
                          (4,*puVar2,(puVar2[2] & 7) << 5 | puVar2[1] & 0x1f,
                           CONCAT44(puVar2[5],puVar2[6]),puVar2[3],puVar2[4]);
        *puVar2 = uVar8;
        *(undefined8 *)(param_2 + 0x38) = 4;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c40244c:
      if ((*(uint *)(pcVar1 + 8) < 4) || (*(uint *)(pcVar1 + 0x10) < 0x1c)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        uVar8 = HalSetBusDataByOffset
                          (4,*puVar2,(puVar2[2] & 7) << 5 | puVar2[1] & 0x1f,
                           CONCAT44(puVar2[5],puVar2[6]),puVar2[3],puVar2[4]);
        *puVar2 = uVar8;
        *(undefined8 *)(param_2 + 0x38) = 4;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c402450:
      if ((*(uint *)(pcVar1 + 8) < 0x34) || (*(uint *)(pcVar1 + 0x10) < 8)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        PsGetVersion(&local_21c,local_res18,local_res20,0);
        RtlInitAnsiString(local_80,CONCAT44(*puVar2,puVar2[1]));
        RtlAnsiStringToUnicodeString(local_d0,local_80,1);
        iVar25 = IoGetDeviceObjectPointer(local_d0,0x80,&local_1c0,&local_1d0);
        if (iVar25 < 0) {
          puVar2[10] = 0xffffffff;
          puVar2[0xb] = 0xffffffff;
          puVar2[10] = 0xffffffff;
          puVar2[9] = 0xffffffff;
          puVar2[8] = 0xffffffff;
          puVar2[7] = 0xffffffff;
          puVar2[6] = 0xffffffff;
          puVar2[5] = 0xffffffff;
          puVar2[4] = 0xffffffff;
          puVar2[3] = 0xffffffff;
          puVar2[2] = 0xffffffff;
          puVar2[1] = 0xffffffff;
          *puVar2 = 0xffffffff;
        }
        else {
          *puVar2 = (uint)local_1d0;
          puVar2[1] = (uint)((ulonglong)local_1d0 >> 0x20);
          lVar15 = *(longlong *)(local_1d0 + 0x40);
          local_140 = (longlong *)(lVar15 + 8);
          if ((((local_21c == 6) && (local_res18[0] == 4)) ||
              ((local_21c == 10 && (local_res18[0] == 0)))) && (0x37ba < local_res20[0])) {
            local_140 = (longlong *)(lVar15 + 0x10);
          }
          plVar26 = (longlong *)0x0;
          if (local_21c < 6) {
            plVar26 = (longlong *)(lVar15 + 0x1e8);
          }
          else if (local_21c == 6) {
            if (local_res18[0] < 2) {
              plVar26 = (longlong *)(lVar15 + 0x240);
            }
            else if (local_res18[0] == 2) {
              plVar26 = (longlong *)(lVar15 + 0x2a0);
            }
            else if (local_res18[0] == 3) {
              plVar26 = (longlong *)(lVar15 + 0x2b0);
            }
            else if (local_res18[0] == 4) {
              if (local_res20[0] < 0x37bb) {
                plVar26 = (longlong *)(lVar15 + 0x2c0);
              }
              else {
                plVar26 = (longlong *)(lVar15 + 0x2c8);
              }
            }
          }
          else if ((local_21c == 10) && (local_res18[0] == 0)) {
            if (local_res20[0] < 0x37bb) {
              plVar26 = (longlong *)(lVar15 + 0x2c0);
            }
            else {
              plVar26 = (longlong *)(lVar15 + 0x2c8);
            }
          }
          if ((plVar26 == (longlong *)0x0) || (*local_140 != 0x5f534750)) {
            puVar2[0xc] = 0xffffffff;
            puVar2[0xb] = 0xffffffff;
            puVar2[10] = 0xffffffff;
            puVar2[9] = 0xffffffff;
            puVar2[8] = 0xffffffff;
            puVar2[7] = 0xffffffff;
            puVar2[6] = 0xffffffff;
            puVar2[5] = 0xffffffff;
            puVar2[4] = 0xffffffff;
            puVar2[3] = 0xffffffff;
            puVar2[2] = 0xffffffff;
          }
          else {
            if ((local_21c == 6) && (local_res18[0] == 3)) {
              puVar14 = (undefined8 *)(*plVar26 + -0x70);
            }
            else if (((local_21c == 6) && (local_res18[0] == 4)) ||
                    ((local_21c == 10 && (local_res18[0] == 0)))) {
              if (local_res20[0] < 0x37bb) {
                puVar14 = (undefined8 *)(*plVar26 + -0x70);
              }
              else {
                puVar14 = (undefined8 *)(*plVar26 + -0x78);
              }
            }
            else {
              puVar14 = (undefined8 *)*plVar26;
            }
            do {
              iVar25 = FUN_00011010((longlong)puVar14);
              puVar23 = puVar14;
              if (iVar25 == 0x5f5f5f5c) break;
              puVar14 = (undefined8 *)puVar14[2];
              puVar23 = puVar13;
            } while (puVar14 != (undefined8 *)0x0);
            if (puVar23 != (undefined8 *)0x0) {
              puVar2[2] = (uint)puVar23;
              puVar2[3] = (uint)((ulonglong)puVar23 >> 0x20);
              uVar16 = FUN_00011090(puVar23);
              puVar2[4] = (uint)uVar16;
              puVar2[5] = (uint)((ulonglong)uVar16 >> 0x20);
              uVar16 = puVar23[2];
              puVar2[6] = (uint)uVar16;
              puVar2[7] = (uint)((ulonglong)uVar16 >> 0x20);
              uVar16 = puVar23[3];
              puVar2[8] = (uint)uVar16;
              puVar2[9] = (uint)((ulonglong)uVar16 >> 0x20);
              uVar16 = FUN_00011100((longlong)puVar23);
              puVar2[10] = (uint)uVar16;
              puVar2[0xb] = (uint)((ulonglong)uVar16 >> 0x20);
              uVar8 = FUN_00011010((longlong)puVar23);
              puVar2[0xc] = uVar8;
            }
          }
          ObfDereferenceObject(local_1c0);
        }
        RtlFreeUnicodeString(local_d0);
        *(undefined8 *)(param_2 + 0x38) = 0x34;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c402454:
      if ((*(uint *)(pcVar1 + 8) < 0x2c) || (*(uint *)(pcVar1 + 0x10) < 0xc)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        puVar14 = *(undefined8 **)puVar2;
        uVar8 = puVar2[2];
        if (puVar14 == (undefined8 *)0x0) {
          puVar2[10] = 0xffffffff;
          puVar2[9] = 0xffffffff;
          puVar2[8] = 0xffffffff;
          puVar2[7] = 0xffffffff;
          puVar2[6] = 0xffffffff;
          puVar2[5] = 0xffffffff;
          puVar2[4] = 0xffffffff;
          puVar2[3] = 0xffffffff;
          puVar2[2] = 0xffffffff;
          puVar2[1] = 0xffffffff;
          *puVar2 = 0xffffffff;
        }
        else {
          if (uVar8 == 1) {
            puVar13 = (undefined8 *)puVar14[2];
          }
          else if (uVar8 == 2) {
            puVar13 = (undefined8 *)puVar14[3];
          }
          else if (uVar8 == 3) {
            puVar13 = (undefined8 *)FUN_00011090(puVar14);
          }
          if (puVar13 == (undefined8 *)0x0) {
            puVar2[10] = 0xffffffff;
            puVar2[9] = 0xffffffff;
            puVar2[8] = 0xffffffff;
            puVar2[7] = 0xffffffff;
            puVar2[6] = 0xffffffff;
            puVar2[5] = 0xffffffff;
            puVar2[4] = 0xffffffff;
            puVar2[3] = 0xffffffff;
            puVar2[2] = 0xffffffff;
            puVar2[1] = 0xffffffff;
            *puVar2 = 0xffffffff;
          }
          else {
            *puVar2 = (uint)puVar13;
            puVar2[1] = (uint)((ulonglong)puVar13 >> 0x20);
            uVar16 = FUN_00011090(puVar13);
            puVar2[2] = (uint)uVar16;
            puVar2[3] = (uint)((ulonglong)uVar16 >> 0x20);
            uVar16 = puVar13[2];
            puVar2[4] = (uint)uVar16;
            puVar2[5] = (uint)((ulonglong)uVar16 >> 0x20);
            uVar16 = puVar13[3];
            puVar2[6] = (uint)uVar16;
            puVar2[7] = (uint)((ulonglong)uVar16 >> 0x20);
            uVar16 = FUN_00011100((longlong)puVar13);
            puVar2[8] = (uint)uVar16;
            puVar2[9] = (uint)((ulonglong)uVar16 >> 0x20);
            uVar8 = FUN_00011010((longlong)puVar13);
            puVar2[10] = uVar8;
          }
        }
        *(undefined8 *)(param_2 + 0x38) = 0x2c;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c402458:
      if ((*(uint *)(pcVar1 + 8) < 8) || (*(uint *)(pcVar1 + 0x10) < 0x1c)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        PsGetVersion(&local_2a8,&local_280,&local_290,0);
        lVar15 = *(longlong *)puVar2;
        lVar11 = *(longlong *)(puVar2 + 2);
        uVar8 = puVar2[5];
        puVar28 = (undefined4 *)CONCAT44(puVar2[4],uVar8);
        uVar9 = puVar2[6];
        if ((lVar11 == 0) || (lVar17 = *(longlong *)(lVar11 + 0x10), lVar17 == 0)) {
          puVar2[1] = 0xffffffff;
          *puVar2 = 0xffffffff;
        }
        else {
          lVar19 = *(longlong *)(lVar15 + 0x40);
          local_170 = (longlong *)(lVar19 + 8);
          if ((((local_2a8 == 6) && (local_280 == 4)) || ((local_2a8 == 10 && (local_280 == 0)))) &&
             (0x37ba < local_290)) {
            local_170 = (longlong *)(lVar19 + 0x10);
          }
          plVar26 = (longlong *)0x0;
          if (local_2a8 < 6) {
            plVar26 = (longlong *)(lVar19 + 0x1e8);
          }
          else if (local_2a8 == 6) {
            if (local_280 < 2) {
              plVar26 = (longlong *)(lVar19 + 0x240);
            }
            else if (local_280 == 2) {
              plVar26 = (longlong *)(lVar19 + 0x2a0);
            }
            else if (local_280 == 3) {
              plVar26 = (longlong *)(lVar19 + 0x2b0);
            }
            else if (local_280 == 4) {
              if (local_290 < 0x37bb) {
                plVar26 = (longlong *)(lVar19 + 0x2c0);
              }
              else {
                plVar26 = (longlong *)(lVar19 + 0x2c8);
              }
            }
          }
          else if ((local_2a8 == 10) && (local_280 == 0)) {
            if (local_290 < 0x37bb) {
              plVar26 = (longlong *)(lVar19 + 0x2c0);
            }
            else {
              plVar26 = (longlong *)(lVar19 + 0x2c8);
            }
          }
          if ((plVar26 == (longlong *)0x0) || (*local_170 != 0x5f534750)) {
            puVar2[1] = 0xffffffff;
            *puVar2 = 0xffffffff;
          }
          else {
            lVar19 = *plVar26;
            if ((local_2a8 == 6) && (local_280 == 3)) {
              *plVar26 = lVar17 + 0x70;
            }
            else if (((local_2a8 == 6) && (local_280 == 4)) ||
                    ((local_2a8 == 10 && (local_280 == 0)))) {
              if (local_290 < 0x37bb) {
                *plVar26 = lVar17 + 0x70;
              }
              else {
                *plVar26 = lVar17 + 0x78;
              }
            }
            else {
              *plVar26 = lVar17;
            }
            local_1f0 = 0x42696541;
            local_1ec = FUN_00011010(lVar11);
            *puVar28 = 0;
            local_2a4 = FUN_00011280(lVar15,0x32c004,&local_1f0,8,puVar28,0x14);
            if ((local_2a4 == 0x80000005) && ((uint)puVar28[1] < uVar9)) {
              local_2a4 = FUN_00011280(lVar15,0x32c004,&local_1f0,8,puVar28,puVar28[1]);
            }
            *puVar2 = local_2a4;
            puVar2[1] = uVar8;
            *plVar26 = lVar19;
          }
        }
        *(undefined8 *)(param_2 + 0x38) = 8;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c40245c:
      if ((*(uint *)(pcVar1 + 8) < 8) || (*(uint *)(pcVar1 + 0x10) < 0xc)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        uStack_134 = *puVar2;
        local_138 = puVar2[1];
        uVar8 = puVar2[2];
        uVar18 = CONCAT44(uStack_134,local_138);
        puVar14 = FUN_00011170(uVar18,uVar8);
        if (puVar14 == (undefined8 *)0x0) {
          local_214 = 0;
          puVar14 = puVar13;
          while (iVar25 = (int)puVar14, iVar25 < 0x20) {
            lVar15 = (longlong)iVar25;
            puVar21 = &DAT_00016140 + lVar15 * 3;
            if ((((int)*puVar21 == 0) &&
                (*(int *)((longlong)&DAT_00016140 + lVar15 * 0x18 + 4) == 0)) &&
               ((&DAT_00016150)[lVar15 * 6] == 0)) {
              if (puVar21 != (ulonglong *)0x0) {
                puVar13 = (undefined8 *)MmMapIoSpace(uVar18,uVar8,0);
                *puVar21 = uVar18;
                (&DAT_00016148)[lVar15 * 3] = puVar13;
                (&DAT_00016150)[lVar15 * 6] = uVar8;
              }
              break;
            }
            local_214 = iVar25 + 1;
            puVar14 = (undefined8 *)(ulonglong)local_214;
          }
        }
        else {
          puVar13 = (undefined8 *)puVar14[1];
        }
        *puVar2 = (uint)puVar13;
        puVar2[1] = (uint)((ulonglong)puVar13 >> 0x20);
        *(undefined8 *)(param_2 + 0x38) = 8;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c402460:
      if ((*(uint *)(pcVar1 + 8) < 8) || (*(uint *)(pcVar1 + 0x10) < 0xc)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        uVar8 = *puVar2;
        uVar9 = puVar2[1];
        uVar29 = puVar2[2];
        local_180 = uVar9;
        uStack_17c = uVar8;
        puVar14 = FUN_00011170(CONCAT44(uVar8,uVar9),uVar29);
        if (puVar14 == (undefined8 *)0x0) {
          MmUnmapIoSpace(_DAT_00000008,uVar29);
          local_1f8 = 0;
          while (iVar25 = (int)puVar13, iVar25 < 0x20) {
            lVar15 = (longlong)iVar25;
            if (((*(uint *)(&DAT_00016140 + lVar15 * 3) == uVar9) &&
                (*(uint *)((longlong)&DAT_00016140 + lVar15 * 0x18 + 4) == uVar8)) &&
               ((&DAT_00016150)[lVar15 * 6] == uVar29)) {
              *(undefined4 *)(&DAT_00016140 + lVar15 * 3) = 0;
              *(undefined4 *)((longlong)&DAT_00016140 + lVar15 * 0x18 + 4) = 0;
              (&DAT_00016150)[lVar15 * 6] = 0;
              break;
            }
            local_1f8 = iVar25 + 1;
            puVar13 = (undefined8 *)(ulonglong)local_1f8;
          }
        }
        *puVar2 = 0x12345678;
        puVar2[1] = 0x87654321;
        *(undefined8 *)(param_2 + 0x38) = 8;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c402464:
      if ((*(uint *)(pcVar1 + 8) < 8) || (*(uint *)(pcVar1 + 0x10) < 8)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        local_118 = *puVar2;
        local_284 = puVar2[1];
        lVar15 = rdmsr(local_284);
        uVar24 = (undefined2)local_118;
        uVar8 = in(uVar24);
        uVar8 = uVar8 & 0xffffff;
        do {
          uVar9 = in(uVar24);
          uVar9 = uVar9 & 0xffffff;
          if (uVar9 < uVar8) {
            uVar9 = uVar9 + 0xffffff;
          }
        } while (uVar9 - uVar8 < 15000);
        lVar11 = rdmsr(local_284);
        uVar9 = in(uVar24);
        uVar9 = uVar9 & 0xffffff;
        if (uVar9 < uVar8) {
          uVar9 = uVar9 + 0xffffff;
        }
        dVar34 = (double)lVar11;
        if (lVar11 < 0) {
          dVar34 = dVar34 + DAT_00015148;
        }
        dVar36 = (double)lVar15;
        if (lVar15 < 0) {
          dVar36 = dVar36 + DAT_00015148;
        }
        local_224 = (float)((dVar34 - dVar36) / ((double)uVar9 - (double)uVar8)) * _DAT_00015140;
        *puVar2 = 0;
        puVar2[1] = (uint)local_224;
        *(undefined8 *)(param_2 + 0x38) = 8;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c402468:
      if ((*(uint *)(pcVar1 + 8) < 0x10) || (*(uint *)(pcVar1 + 0x10) < 0xc)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        uVar8 = *puVar2;
        uVar9 = puVar2[2];
        local_2e4 = 0;
        local_2f8 = 0;
        uVar31 = 0;
        local_278 = 0;
        local_2c8 = 0;
        uVar29 = puVar2[1];
        iVar25 = 1000;
        local_2ac = 1000;
        sVar22 = (short)uVar8;
        bVar6 = in(sVar22);
        while ((bVar6 & 0x40) != 0) {
          iVar25 = iVar25 + -1;
          local_2ac = iVar25;
          if (iVar25 < 0) {
            uVar31 = (uint)bVar6;
            local_278 = (uint)bVar6;
            local_2e4 = 0;
            goto LAB_00012b66;
          }
          KeStallExecutionProcessor(10);
          bVar6 = in(sVar22);
        }
        out(sVar22,0xbf);
        out(sVar22 + 4,(char)uVar29 * '\x02' | 1);
        out(sVar22 + 3,(char)uVar9);
        uVar8 = uVar8 + 2;
        uVar24 = (undefined2)uVar8;
        bVar6 = in(uVar24);
        out(uVar24,bVar6 & 0xa8 | 8);
        KeStallExecutionProcessor(5,uVar8 & 0xffff);
        out(uVar24,bVar6 & 0xa8 | 0x48);
        KeStallExecutionProcessor(100,uVar8 & 0xffff);
        local_2ac = 1000;
        bVar6 = in(sVar22);
        while (iVar25 = local_2ac, (bVar6 & 1) != 0) {
          KeStallExecutionProcessor();
          local_2ac = iVar25 + -1;
          if (local_2ac < 0) {
            uVar31 = 0xee;
            local_278 = 0xee;
            local_2c8 = 0;
            goto LAB_00012b66;
          }
          bVar6 = in(sVar22);
        }
        local_2c8 = (uint)bVar6;
        if ((((bVar6 & 4) == 0) && ((bVar6 & 8) == 0)) && ((bVar6 & 0x10) == 0)) {
          local_2e4 = 1;
          local_2f8 = in(sVar22 + 5);
        }
        else {
          local_2e4 = 0;
        }
LAB_00012b66:
        bVar6 = in(sVar22);
        out(sVar22,bVar6 | 0x44);
        *puVar2 = local_2e4;
        puVar2[1] = (uint)local_2f8;
        puVar2[2] = uVar31;
        puVar2[3] = local_2c8;
        *(undefined8 *)(param_2 + 0x38) = 0x10;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c40246c:
      if ((*(uint *)(pcVar1 + 8) < 0x10) || (*(uint *)(pcVar1 + 0x10) < 0x14)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        uVar8 = *puVar2;
        local_res18[0] = puVar2[1];
        uVar9 = puVar2[2];
        uVar29 = puVar2[3];
        uVar31 = puVar2[4];
        iVar25 = local_res18[0] + 8;
        uVar32 = uVar8 >> 8 & 7;
        local_res20[0] = uVar8 >> 0xb & 0x1f;
        local_res8._0_4_ = uVar8 >> 0x10 & 0xff;
        FUN_000111f0(uVar8 >> 0x10 & 0xff,local_res20[0],uVar32,iVar25,&local_298);
        uVar5 = local_res20[0];
        local_298 = (ulonglong)(uVar9 << 0x1c) | local_298 & 0xff | 0x8000000;
        FUN_00011230((uint)local_res8,local_res20[0],uVar32,iVar25,local_298);
        uVar8 = local_res18[0];
        local_298 = (ulonglong)(((uVar29 & 7 | 0xffffff80) << 8 | uVar31) << 0x10);
        FUN_00011230((uint)local_res8,uVar5,uVar32,local_res18[0] + 4,local_298);
        iVar25 = 100000;
        while ((-1 < iVar25 &&
               ((FUN_000111f0((uint)local_res8,uVar5,uVar32,uVar8,&local_2a0),
                ((uint)local_2a0 >> 0x1c & 1) != 0 || ((local_2a0 & 0xa0000000) == 0))))) {
          iVar25 = iVar25 + -1;
        }
        if (((uint)local_2a0 & 0xa0000000) != 0x80000000) {
          iVar27 = 1000;
          for (iVar25 = 1000; uVar8 = local_res18[0], -1 < iVar25; iVar25 = iVar25 + -1) {
            FUN_000111f0((uint)local_res8,uVar5,uVar32,local_res18[0] + 8,&local_298);
            local_298 = local_298 ^ 0x8000000;
            FUN_00011230((uint)local_res8,uVar5,uVar32,uVar8 + 8,local_298);
            FUN_000111f0((uint)local_res8,uVar5,uVar32,local_res18[0],&local_2a0);
            if ((local_2a0 & 0xffffffffb0000000) == 0x10000000) break;
          }
          while ((-1 < iVar27 &&
                 ((FUN_000111f0((uint)local_res8,uVar5,uVar32,local_res18[0],&local_2a0),
                  ((uint)local_2a0 >> 0x1c & 1) != 0 || ((local_2a0 & 0xa0000000) == 0))))) {
            iVar27 = iVar27 + -1;
          }
        }
        uVar8 = (uint)local_2a0;
        bVar33 = (uVar8 & 0xa0000000) != 0x80000000;
        if (bVar33) {
          uVar9 = 0xff;
        }
        else {
          uVar9 = uVar8 & 0xff;
        }
        *puVar2 = (uint)!bVar33;
        puVar2[1] = uVar9;
        puVar2[2] = (uint)(local_2a0 >> 0x20);
        puVar2[3] = uVar8;
        *(undefined8 *)(param_2 + 0x38) = 0x10;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c4024a8:
      if ((*(uint *)(pcVar1 + 8) < 0x10) || (*(uint *)(pcVar1 + 0x10) < 0xc)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        sVar22 = (short)*puVar2;
        out(sVar22 + 3,(char)puVar2[2]);
        out(sVar22 + 2,(char)puVar2[1] * '\x02' | 1);
        out(sVar22,7);
        bVar6 = in(sVar22 + 1);
        uVar8 = (uint)bVar6;
        local_1e4 = 1000;
        do {
          if ((char)uVar8 < '\0') {
            local_res10 = in(sVar22 + 4);
            uVar9 = 1;
            goto LAB_00012f4a;
          }
          local_20c = 0;
          local_1d8 = 0;
          puVar14 = puVar13;
          puVar23 = puVar13;
          while ((uint)puVar14 < 20000) {
            local_20c = (int)puVar23 + 1;
            puVar23 = (undefined8 *)(ulonglong)local_20c;
            local_1d8 = (uint)puVar14 + 1;
            puVar14 = (undefined8 *)(ulonglong)local_1d8;
          }
          bVar6 = in(sVar22 + 1);
          uVar8 = (uint)bVar6;
          local_1e4 = local_1e4 - 1;
        } while (-1 < (int)local_1e4);
        local_res10 = (byte)param_2;
LAB_00012f4a:
        *puVar2 = uVar9;
        puVar2[1] = (uint)local_res10;
        puVar2[2] = uVar8;
        puVar2[3] = local_1e4;
        *(undefined8 *)(param_2 + 0x38) = 0x10;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
    }
  }
  else {
    switch(uVar8) {
    case 0x9c402504:
      if ((*(uint *)(pcVar1 + 8) < 8) || (*(uint *)(pcVar1 + 0x10) < 0x2c)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        PsGetVersion(&local_220,&local_27c,&local_274,0);
        local_1c0 = *(longlong *)puVar2;
        local_1b0 = *(ulonglong *)(puVar2 + 2);
        uVar8 = puVar2[4];
        if (3 < puVar2[4]) {
          uVar8 = 3;
        }
        uVar9 = puVar2[5];
        local_res18[0] = puVar2[6];
        local_res20[0] = puVar2[7];
        uVar29 = puVar2[9];
        puVar28 = (undefined4 *)CONCAT44(puVar2[8],uVar29);
        local_2b0 = puVar2[10];
        local_128 = puVar28;
        if ((local_1b0 == 0) || (lVar15 = *(longlong *)(local_1b0 + 0x10), lVar15 == 0)) {
          puVar2[1] = 0xffffffff;
          *puVar2 = 0xffffffff;
        }
        else {
          lVar11 = *(longlong *)(local_1c0 + 0x40);
          local_158 = (longlong *)(lVar11 + 8);
          if ((((local_220 == 6) && (local_27c == 4)) || ((local_220 == 10 && (local_27c == 0)))) &&
             (0x37ba < local_274)) {
            local_158 = (longlong *)(lVar11 + 0x10);
          }
          plVar26 = (longlong *)0x0;
          if (local_220 < 6) {
            plVar26 = (longlong *)(lVar11 + 0x1e8);
          }
          else if (local_220 == 6) {
            if (local_27c < 2) {
              plVar26 = (longlong *)(lVar11 + 0x240);
            }
            else if (local_27c == 2) {
              plVar26 = (longlong *)(lVar11 + 0x2a0);
            }
            else if (local_27c == 3) {
              plVar26 = (longlong *)(lVar11 + 0x2b0);
            }
            else if (local_27c == 4) {
              if (local_274 < 0x37bb) {
                plVar26 = (longlong *)(lVar11 + 0x2c0);
              }
              else {
                plVar26 = (longlong *)(lVar11 + 0x2c8);
              }
            }
          }
          else if ((local_220 == 10) && (local_27c == 0)) {
            if (local_274 < 0x37bb) {
              plVar26 = (longlong *)(lVar11 + 0x2c0);
            }
            else {
              plVar26 = (longlong *)(lVar11 + 0x2c8);
            }
          }
          if ((plVar26 == (longlong *)0x0) || (*local_158 != 0x5f534750)) {
            puVar2[1] = 0xffffffff;
            *puVar2 = 0xffffffff;
          }
          else {
            local_1d0 = *plVar26;
            if ((local_220 == 6) && (local_27c == 3)) {
              *plVar26 = lVar15 + 0x70;
            }
            else if (((local_220 == 6) && (local_27c == 4)) ||
                    ((local_220 == 10 && (local_27c == 0)))) {
              if (local_274 < 0x37bb) {
                *plVar26 = lVar15 + 0x70;
              }
              else {
                *plVar26 = lVar15 + 0x78;
              }
            }
            else {
              *plVar26 = lVar15;
            }
            local_2c4 = uVar8 * 8 + 0x19;
            local_1a0 = (ulonglong)local_2c4;
            puVar21 = (ulonglong *)ExAllocatePoolWithTag(0,local_1a0,0x454d5750);
            if (puVar21 == (ulonglong *)0x0) {
              puVar2[1] = 0xffffffff;
              *puVar2 = 0xffffffff;
            }
            else {
              FUN_00014840(puVar21,0,local_1a0);
              *(undefined4 *)puVar21 = 0x43696541;
              uVar10 = FUN_00011010(local_1b0);
              lVar15 = local_1c0;
              uVar31 = local_2c4;
              *(undefined4 *)((longlong)puVar21 + 4) = uVar10;
              *(uint *)(puVar21 + 1) = uVar8 * 8;
              *(uint *)((longlong)puVar21 + 0xc) = uVar8;
              *(undefined2 *)(puVar21 + 2) = 0;
              *(undefined2 *)((longlong)puVar21 + 0x12) = 4;
              *(uint *)((longlong)puVar21 + 0x14) = uVar9;
              if (1 < uVar8) {
                *(undefined2 *)(puVar21 + 3) = 0;
                *(undefined2 *)((longlong)puVar21 + 0x1a) = 4;
                *(uint *)((longlong)puVar21 + 0x1c) = local_res18[0];
              }
              if (2 < uVar8) {
                *(undefined2 *)(puVar21 + 4) = 0;
                *(undefined2 *)((longlong)puVar21 + 0x22) = 4;
                *(uint *)((longlong)puVar21 + 0x24) = local_res20[0];
              }
              *puVar28 = 0;
              local_2a4 = FUN_00011280(local_1c0,0x32c004,puVar21,local_2c4,puVar28,0x14);
              if ((local_2a4 == 0x80000005) && ((uint)puVar28[1] < local_2b0)) {
                local_2a4 = FUN_00011280(lVar15,0x32c004,puVar21,uVar31,puVar28,puVar28[1]);
              }
              *puVar2 = local_2a4;
              puVar2[1] = uVar29;
              ExFreePoolWithTag(puVar21,0);
              *plVar26 = local_1d0;
            }
          }
        }
        *(undefined8 *)(param_2 + 0x38) = 8;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    default:
switchD_0001163e_caseD_9c402401:
      *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
      break;
    case 0x9c402508:
      if ((*(uint *)(pcVar1 + 8) < 8) || (*(uint *)(pcVar1 + 0x10) < 0x14)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        uStack_144 = *puVar2;
        local_148 = puVar2[1];
        local_1a8 = puVar2[2];
        uVar8 = puVar2[3];
        local_2e8 = uVar8 >> 0x10;
        local_288 = puVar2[4];
        bVar33 = uVar8 >> 0x10 == 0;
        uVar9 = (uint)bVar33;
        local_26c = (uint)bVar33;
        local_11c = uVar8 & 0xffff;
        local_110 = MmMapIoSpace(CONCAT44(uStack_144,local_148),0x20);
        local_268 = (ushort *)(local_110 + 0x10);
        local_2b8 = 1;
        if ((uVar8 & 0xffff) == 0) {
          do {
            if ((uVar9 == 0) && (local_2e8 = local_2e8 - 1, (int)local_2e8 < 0)) {
              local_2b8 = 0;
              break;
            }
            uVar7 = *local_268;
            LOCK();
            local_2f4 = *local_268;
            if (uVar7 == local_2f4) {
              *local_268 = uVar7 & 0xfffc;
              local_2f4 = uVar7;
            }
            UNLOCK();
            local_1e0 = 0;
            local_250 = 0;
            puVar14 = puVar13;
            puVar23 = puVar13;
            while ((uint)puVar14 < 1000) {
              local_1e0 = (int)puVar23 + 1;
              puVar23 = (undefined8 *)(ulonglong)local_1e0;
              local_250 = (uint)puVar14 + 1;
              puVar14 = (undefined8 *)(ulonglong)local_250;
            }
            uVar9 = local_26c;
          } while (local_2f4 != uVar7);
          if ((local_2f4 & 1) != 0) {
            if (local_288 == 0x8086) {
              if (local_1a8 != 0) {
                sVar22 = (short)local_1a8 + 0x30;
                bVar6 = in(sVar22);
                out(sVar22,bVar6 | 0x80);
              }
            }
            else if (local_288 == 0x1022) {
              out(0xcd6,0x74);
              bVar6 = in(0xcd7);
              out(0xcd7,bVar6 | 0x80);
            }
          }
        }
        else {
          do {
            if ((uVar9 == 0) && (local_2e8 = local_2e8 - 1, (int)local_2e8 < 0)) {
              local_2b8 = 0;
              break;
            }
            uVar7 = *local_268;
            LOCK();
            local_2f4 = *local_268;
            if (uVar7 == local_2f4) {
              *local_268 = (short)(uVar7 | 4) >> 1;
              local_2f4 = uVar7;
            }
            UNLOCK();
            local_1c8 = 0;
            local_218 = 0;
            puVar14 = puVar13;
            puVar23 = puVar13;
            while ((uint)puVar14 < 1000) {
              local_1c8 = (int)puVar23 + 1;
              puVar23 = (undefined8 *)(ulonglong)local_1c8;
              local_218 = (uint)puVar14 + 1;
              puVar14 = (undefined8 *)(ulonglong)local_218;
            }
            uVar9 = local_26c;
          } while ((local_2f4 != uVar7) || ((local_2f4 & 2) != 0));
        }
        MmUnmapIoSpace(local_110,0x20);
        *puVar2 = local_2b8;
        puVar2[1] = (int)(short)local_2f4;
        *(undefined8 *)(param_2 + 0x38) = 8;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c402510:
      if (*(uint *)(pcVar1 + 8) < 0xc) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        PsGetVersion(local_208,&local_240,&local_23c,0);
        *puVar2 = local_208[0];
        puVar2[1] = local_240;
        puVar2[2] = local_23c;
        *(undefined8 *)(param_2 + 0x38) = 0xc;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c402514:
      if ((*(uint *)(pcVar1 + 8) < 8) || (*(uint *)(pcVar1 + 0x10) < 8)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        uStack_174 = 0;
        local_178 = *puVar2;
        lVar15 = MmMapIoSpace(local_178,0x200,0);
        local_284 = puVar2[1];
        uVar18 = rdmsr(local_284);
        dVar34 = (double)*(uint *)(lVar15 + 0xf4) * DAT_00015120 + (double)*(uint *)(lVar15 + 0xf0);
        uVar8 = 50000;
        local_100 = dVar34;
        local_f8 = uVar18;
        do {
          uVar30 = rdmsr(local_284);
          if (uVar30 < uVar18) {
            uVar18 = rdmsr(local_284);
            dVar34 = (double)*(uint *)(lVar15 + 0xf4) * DAT_00015120 +
                     (double)*(uint *)(lVar15 + 0xf0);
            local_100 = dVar34;
            local_f8 = uVar18;
          }
          uVar8 = uVar8 - 1;
        } while ((-1 < (int)uVar8) &&
                (((double)*(uint *)(lVar15 + 0xf4) * DAT_00015120 + (double)*(uint *)(lVar15 + 0xf0)
                 ) - dVar34 < DAT_00015118));
        lVar11 = rdmsr(local_284);
        dVar35 = (double)*(uint *)(lVar15 + 0xf4) * DAT_00015120;
        uVar9 = *(uint *)(lVar15 + 0xf0);
        dVar36 = (double)lVar11;
        if (lVar11 < 0) {
          dVar36 = dVar36 + DAT_00015148;
        }
        dVar37 = (double)(longlong)uVar18;
        if ((longlong)uVar18 < 0) {
          dVar37 = dVar37 + DAT_00015148;
        }
        dVar36 = (dVar36 - dVar37) * _DAT_00015110;
        local_1e8 = uVar8;
        MmUnmapIoSpace(lVar15,0x200);
        *puVar2 = uVar8;
        puVar2[1] = (uint)(longlong)(dVar36 / ((dVar35 + (double)uVar9) - dVar34));
        *(undefined8 *)(param_2 + 0x38) = 8;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c402518:
      if ((*(uint *)(pcVar1 + 8) < 0x10) || (*(uint *)(pcVar1 + 0x10) < 4)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        local_238 = 0;
        local_2b0 = 0;
        local_2c4 = 0;
        PsGetVersion(&local_2c4,&local_2b0,&local_238,0);
        local_120 = *puVar2;
        local_a0 = rdmsr(0x832);
        local_a0 = local_a0 & 0xffffffff;
        local_98 = rdmsr(0x83e);
        local_98 = local_98 & 0xffffffff;
        local_90 = rdmsr(0x838);
        local_90 = local_90 & 0xffffffff;
        uVar18 = rdmsr(0x832);
        wrmsr(0x832,uVar18 & 0xfffdffff);
        wrmsr(0x83e,2);
        wrmsr(0x838,0xffffffff);
        uVar18 = rdmsr(0x839);
        uVar18 = uVar18 & 0xffffffff;
        uVar24 = (undefined2)local_120;
        uVar8 = in(uVar24);
        uVar8 = uVar8 & 0xffffff;
        local_1b8 = 0;
        puVar14 = puVar13;
        local_2c0 = uVar8;
        local_1b0 = uVar18;
        do {
          uVar30 = rdmsr(0x839);
          uVar30 = uVar30 & 0xffffffff;
          if (uVar30 < 0xfff00000) {
            wrmsr(0x838,0xffffffff);
            uVar30 = rdmsr(0x839);
            uVar30 = uVar30 & 0xffffffff;
            uVar8 = in(uVar24);
            uVar8 = uVar8 & 0xffffff;
            local_1b8 = (int)puVar13 + 1;
            puVar13 = (undefined8 *)(ulonglong)local_1b8;
            uVar18 = uVar30;
            local_2c0 = uVar8;
            local_1b0 = uVar30;
          }
          local_28c = in(uVar24);
          local_28c = local_28c & 0xffffff;
          if (local_28c < uVar8) {
            local_28c = local_28c + 0xffffff;
          }
          local_228 = (int)puVar14 + 1;
          puVar14 = (undefined8 *)(ulonglong)local_228;
        } while (local_28c - uVar8 < 15000);
        wrmsr(0x832,local_a0);
        wrmsr(0x83e,local_98);
        wrmsr(0x838,local_90);
        *puVar2 = (uint)(longlong)
                        ((((double)uVar18 - (double)uVar30) * _DAT_00015150) /
                        ((double)local_28c - (double)uVar8));
        puVar2[1] = (uint)puVar13;
        puVar2[2] = local_228;
        puVar2[3] = (uint)uVar18;
        *(undefined8 *)(param_2 + 0x38) = 0x10;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c40251c:
      if ((*(uint *)(pcVar1 + 8) < 8) || (*(uint *)(pcVar1 + 0x10) < 4)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        uVar8 = *puVar2;
        lVar15 = rdmsr(uVar8);
        local_284 = uVar8;
        lVar17 = KeQueryPerformanceCounter(&local_168);
        lVar11 = local_168 * 5;
        do {
          lVar19 = KeQueryPerformanceCounter(0);
        } while (lVar19 - lVar17 < lVar11 / 1000);
        lVar11 = rdmsr(uVar8);
        lVar19 = KeQueryPerformanceCounter(0);
        auVar3._8_8_ = 0;
        auVar3._0_8_ = lVar19 - lVar17;
        auVar4._8_8_ = 0;
        auVar4._0_8_ = (lVar11 - lVar15) * local_168;
        *puVar2 = SUB164(auVar4 / auVar3,4);
        puVar2[1] = SUB164(auVar4 / auVar3,0);
        *(undefined8 *)(param_2 + 0x38) = 8;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c402520:
      if ((*(uint *)(pcVar1 + 8) < 0x10) || (*(uint *)(pcVar1 + 0x10) < 4)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        uStack_244 = 0;
        local_248 = *puVar2 + 0x300;
        lVar11 = MmMapIoSpace(local_248,0x100,0);
        local_res18[0] = *(uint *)(lVar11 + 0x20);
        local_res20[0] = *(uint *)(lVar11 + 0xe0);
        local_2a8 = *(uint *)(lVar11 + 0x80);
        *(uint *)(lVar11 + 0x20) = local_res18[0] & 0xfffdffff;
        *(undefined4 *)(lVar11 + 0xe0) = 2;
        *(undefined4 *)(lVar11 + 0x80) = 0xffffffff;
        uVar8 = *(uint *)(lVar11 + 0x90);
        local_1dc = uVar8;
        local_e0 = local_res18[0];
        local_dc = local_res20[0];
        local_d8 = local_2a8;
        lVar17 = KeQueryPerformanceCounter(&local_150);
        lVar15 = local_150 * 5;
        do {
          uVar9 = *(uint *)(lVar11 + 0x90);
          if (*(uint *)(lVar11 + 0x90) < 0xfff00000) {
            *(undefined4 *)(lVar11 + 0x80) = 0xffffffff;
            uVar8 = *(uint *)(lVar11 + 0x90);
            local_1dc = uVar8;
            lVar17 = KeQueryPerformanceCounter(0);
            uVar9 = uVar8;
          }
          lVar19 = KeQueryPerformanceCounter(0);
          uVar31 = local_2a8;
          uVar29 = local_res20[0];
        } while (lVar19 - lVar17 < lVar15 / 1000);
        if (lVar19 - lVar17 < 1) {
          local_190 = 0;
        }
        else {
          local_190 = (longlong)((ulonglong)(uVar8 - uVar9) * local_150 * 8) / (lVar19 - lVar17);
        }
        lVar15 = local_190;
        *(uint *)(lVar11 + 0x20) = local_res18[0];
        *(uint *)(lVar11 + 0xe0) = local_res20[0];
        *(uint *)(lVar11 + 0x80) = local_2a8;
        MmUnmapIoSpace(lVar11,0x100);
        *puVar2 = (uint)lVar15;
        puVar2[1] = local_190._4_4_;
        puVar2[2] = uVar29;
        puVar2[3] = uVar31;
        *(undefined8 *)(param_2 + 0x38) = 0x10;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c402524:
      if (*(uint *)(pcVar1 + 8) < 0x10) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        local_c0 = rdmsr(0x832);
        local_c0 = local_c0 & 0xffffffff;
        local_b8 = rdmsr(0x83e);
        local_b8 = local_b8 & 0xffffffff;
        local_b0 = rdmsr(0x838);
        local_b0 = local_b0 & 0xffffffff;
        uVar18 = rdmsr(0x832);
        wrmsr(0x832,uVar18 & 0xfffdffff);
        wrmsr(0x83e,2);
        wrmsr(0x838,0xffffffff);
        uVar18 = rdmsr(0x839);
        uVar18 = uVar18 & 0xffffffff;
        local_108 = uVar18;
        lVar11 = KeQueryPerformanceCounter(&local_188);
        lVar15 = local_188 * 5;
        do {
          uVar30 = rdmsr(0x839);
          local_res8 = uVar30 & 0xffffffff;
          if ((uVar30 & 0xffffffff) < 0xfff00000) {
            wrmsr(0x838,0xffffffff);
            uVar18 = rdmsr(0x839);
            uVar18 = uVar18 & 0xffffffff;
            local_108 = uVar18;
            lVar11 = KeQueryPerformanceCounter(0);
            local_res8 = uVar18;
          }
          lVar17 = KeQueryPerformanceCounter(0);
        } while (lVar17 - lVar11 < lVar15 / 1000);
        if (lVar17 - lVar11 < 1) {
          uVar18 = 0;
          local_128 = (undefined4 *)0x0;
        }
        else {
          uVar18 = ((uVar18 - local_res8) * local_188 * 8) / (ulonglong)(lVar17 - lVar11);
        }
        wrmsr(0x832,local_c0);
        wrmsr(0x83e,local_b8);
        wrmsr(0x838,local_b0);
        *puVar2 = (uint)uVar18;
        puVar2[1] = (uint)(uVar18 >> 0x20);
        puVar2[2] = (uint)local_b8;
        puVar2[3] = (uint)local_b0;
        *(undefined8 *)(param_2 + 0x38) = 0x10;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c402528:
      if (*(uint *)(pcVar1 + 8) < 8) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        lVar15 = rdmsr(0xe8);
        lVar11 = rdmsr(0xe7);
        lVar19 = KeQueryPerformanceCounter(&local_1a0);
        lVar17 = local_1a0 * 5;
        do {
          lVar20 = KeQueryPerformanceCounter(0);
        } while (lVar20 - lVar19 < lVar17 / 1000);
        lVar17 = rdmsr(0xe8);
        lVar19 = rdmsr(0xe7);
        KeQueryPerformanceCounter(0);
        dVar34 = (double)(lVar17 - lVar15);
        if (lVar17 - lVar15 < 0) {
          dVar34 = dVar34 + DAT_00015148;
        }
        dVar36 = (double)(lVar19 - lVar11);
        if (lVar19 - lVar11 < 0) {
          dVar36 = dVar36 + DAT_00015148;
        }
        if ((double)((ulonglong)dVar36 & _DAT_00015130) <= _DAT_00015158) {
          fVar38 = 0.0;
        }
        else {
          fVar38 = (float)((dVar34 * _DAT_00015128) / dVar36);
        }
        *puVar2 = (uint)(longlong)fVar38;
        puVar2[1] = (uint)(longlong)dVar34;
        *(undefined8 *)(param_2 + 0x38) = 8;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
    }
  }
LAB_00014267:
  uVar10 = *(undefined4 *)(param_2 + 0x30);
  IofCompleteRequest(param_2,0);
  return uVar10;
}

