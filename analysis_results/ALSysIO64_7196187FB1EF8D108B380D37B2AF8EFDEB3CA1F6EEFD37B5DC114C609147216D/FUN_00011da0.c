// Function: FUN_00011da0
// Address: 00011da0
// Decompiled by Ghidra


void FUN_00011da0(undefined8 param_1,ulonglong *param_2)

{
  ulonglong uVar1;
  ulonglong *puVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  longlong lVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  ulonglong uVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  undefined8 *puVar14;
  undefined8 *puVar15;
  undefined8 *puVar16;
  undefined4 *in_stack_00000030;
  undefined1 auStack_2c8 [32];
  int *local_2a8;
  undefined4 local_2a0;
  undefined1 local_298;
  undefined1 *local_290;
  undefined1 *local_288;
  int local_278;
  longlong local_270;
  int local_268;
  undefined4 local_264;
  undefined4 local_260;
  undefined4 local_25c;
  undefined4 local_258;
  undefined4 local_250;
  undefined4 local_24c;
  ulonglong *local_248;
  undefined8 *local_240;
  int local_238;
  undefined8 *local_230;
  undefined8 *local_228;
  ulonglong local_220;
  undefined8 *local_218;
  ulonglong local_210;
  ulonglong local_208;
  ulonglong local_200;
  ulonglong local_1f8;
  ulonglong local_1f0;
  undefined4 *local_1e8;
  ulonglong local_1e0;
  undefined8 local_1d8;
  undefined8 local_1d0;
  ulonglong local_1c8;
  undefined8 local_1c0;
  undefined8 local_1b8;
  ulonglong local_1b0;
  undefined1 local_1a8 [24];
  undefined8 *local_190;
  undefined8 *local_188;
  undefined8 local_178;
  undefined1 local_170 [16];
  undefined1 local_160 [16];
  undefined1 local_150 [24];
  undefined1 local_138 [256];
  ulonglong local_38;
  
  local_38 = DAT_00016100 ^ (ulonglong)auStack_2c8;
  local_1e8 = in_stack_00000030;
  DbgPrint();
  if (param_2 == (ulonglong *)0x0) goto LAB_00012c19;
  puVar9 = (undefined8 *)0x0;
  local_268 = 0;
  local_264 = 0;
  local_260 = 0;
  local_25c = 0;
  local_258 = 0;
  local_228 = (undefined8 *)0x0;
  local_220 = 0;
  local_218 = (undefined8 *)0x0;
  local_188 = (undefined8 *)0x0;
  local_190 = (undefined8 *)0x0;
  local_200 = 0;
  local_1f8 = 0;
  local_1b0 = 0;
  local_1f0 = 0;
  local_208 = 0;
  local_210 = 0;
  local_240 = (undefined8 *)0x0;
  local_230 = (undefined8 *)0x0;
  local_1d8 = 0;
  local_1e0 = 0;
  local_1d0 = 0;
  local_1c8 = 0;
  local_1c0 = 0;
  local_1b8 = 0;
  local_270 = 0;
  RtlInitAnsiString(local_150,param_2 + 0x25);
  RtlAnsiStringToUnicodeString(local_170,local_150,1);
  iVar4 = IoGetDeviceObjectPointer(local_170,0x80,&local_178,&local_270);
  if (((iVar4 != 0) || (local_270 == 0)) || (cVar3 = MmIsAddressValid(), cVar3 == '\0'))
  goto LAB_00012c19;
  ObfDereferenceObject(local_178);
  RtlFreeUnicodeString(local_170);
  lVar8 = *(longlong *)(local_270 + 0x40);
  iVar4 = FUN_00011bd0();
  if (iVar4 == 0) {
    local_248 = (ulonglong *)(lVar8 + 0x1e8);
  }
  else {
    local_248 = (ulonglong *)(lVar8 + 0x240);
  }
  if ((char)*param_2 == '\0') {
    memcpy(local_138,param_2 + 0x25,0x100);
    FUN_00013ca0(param_2,0,0x228);
    memcpy(param_2 + 0x25,local_138,0x100);
    cVar3 = MmIsAddressValid((longlong *)(lVar8 + 8));
    puVar2 = local_248;
    puVar14 = puVar9;
    puVar15 = puVar9;
    puVar16 = puVar9;
    if (((cVar3 == '\0') || (cVar3 = MmIsAddressValid(local_248), cVar3 == '\0')) ||
       (*(longlong *)(lVar8 + 8) != 0x5f534750)) {
      puVar13 = (undefined8 *)0x0;
      puVar10 = local_230;
    }
    else {
      puVar13 = (undefined8 *)*puVar2;
      local_278 = 1;
      while (iVar4 = local_278, local_278 < 1000) {
        cVar3 = MmIsAddressValid(puVar13);
        puVar10 = puVar9;
        puVar12 = local_228;
        if (((cVar3 == '\0') ||
            (iVar5 = FUN_00011d70((longlong)puVar13), puVar10 = puVar13, puVar12 = puVar13,
            iVar5 == 0x5f5f5f5c)) ||
           (puVar13 = (undefined8 *)puVar13[2], puVar10 = puVar9, puVar12 = local_228,
           puVar13 == (undefined8 *)0x0)) goto LAB_0001205c;
        local_278 = iVar4 + 1;
      }
      puVar10 = (undefined8 *)0x0;
      puVar12 = local_228;
LAB_0001205c:
      local_228 = puVar12;
      if ((puVar10 != (undefined8 *)0x0) && (cVar3 = MmIsAddressValid(puVar10), cVar3 != '\0')) {
        uVar11 = puVar10[3];
        local_278 = 1;
        while ((iVar4 = local_278, local_278 < 1000 &&
               (cVar3 = MmIsAddressValid(uVar11), cVar3 != '\0'))) {
          iVar5 = FUN_00011d70(uVar11);
          if (iVar5 == 0x5f42535f) {
            local_200 = uVar11;
          }
          iVar5 = FUN_00011d70(uVar11);
          if (iVar5 == 0x5f5a545f) {
            local_220 = uVar11;
          }
          uVar11 = *(ulonglong *)(uVar11 + 8);
          if (uVar11 == 0) break;
          local_278 = iVar4 + 1;
        }
      }
      uVar11 = local_220;
      if ((local_220 != 0) && (cVar3 = MmIsAddressValid(local_220), cVar3 != '\0')) {
        puVar14 = *(undefined8 **)(uVar11 + 0x18);
        local_278 = 1;
        while (((iVar4 = local_278, puVar15 = puVar9, local_278 < 1000 &&
                (cVar3 = MmIsAddressValid(puVar14), cVar3 != '\0')) && (puVar9 == (undefined8 *)0x0)
               )) {
          puVar13 = (undefined8 *)puVar14[3];
          local_238 = 1;
          while (((iVar5 = local_238, puVar15 = puVar9, puVar10 = local_218, puVar12 = local_188,
                  local_238 < 1000 &&
                  (cVar3 = MmIsAddressValid(puVar13), puVar10 = local_218, puVar12 = local_188,
                  cVar3 != '\0')) &&
                 ((iVar6 = FUN_00011d70((longlong)puVar13), puVar15 = puVar13, puVar10 = puVar14,
                  puVar12 = puVar13, iVar6 != 0x504d545f &&
                  (puVar13 = (undefined8 *)puVar13[1], puVar15 = puVar9, puVar10 = local_218,
                  puVar12 = local_188, puVar13 != (undefined8 *)0x0))))) {
            local_238 = iVar5 + 1;
          }
          local_188 = puVar12;
          local_218 = puVar10;
          puVar14 = (undefined8 *)puVar14[1];
          if (puVar14 == (undefined8 *)0x0) break;
          local_278 = iVar4 + 1;
          puVar9 = puVar15;
        }
        lVar8 = *(longlong *)(local_220 + 0x18);
        local_278 = 1;
        while (((iVar4 = local_278, puVar14 = local_218, local_278 < 1000 &&
                (cVar3 = MmIsAddressValid(lVar8), puVar14 = local_218, cVar3 != '\0')) &&
               (puVar16 == (undefined8 *)0x0))) {
          puVar9 = *(undefined8 **)(lVar8 + 0x18);
          local_238 = 1;
          while ((((iVar5 = local_238, puVar13 = puVar16, puVar14 = local_190, local_238 < 1000 &&
                   (cVar3 = MmIsAddressValid(puVar9), puVar14 = local_190, cVar3 != '\0')) &&
                  (iVar6 = FUN_00011d70((longlong)puVar9), puVar13 = puVar9, puVar14 = puVar9,
                  iVar6 != 0x5452435f)) &&
                 (puVar9 = (undefined8 *)puVar9[1], puVar13 = puVar16, puVar14 = local_190,
                 puVar9 != (undefined8 *)0x0))) {
            local_238 = iVar5 + 1;
          }
          local_190 = puVar14;
          lVar8 = *(longlong *)(lVar8 + 8);
          puVar14 = local_218;
          puVar16 = puVar13;
          if (lVar8 == 0) break;
          local_278 = iVar4 + 1;
        }
      }
      uVar11 = local_200;
      if ((local_200 != 0) && (cVar3 = MmIsAddressValid(local_200), cVar3 != '\0')) {
        uVar11 = *(ulonglong *)(uVar11 + 0x18);
        local_278 = 1;
        while ((iVar4 = local_278, local_278 < 1000 &&
               (cVar3 = MmIsAddressValid(uVar11), cVar3 != '\0'))) {
          iVar5 = FUN_00011d70(uVar11);
          if (iVar5 == 0x444b5441) {
            local_1f8 = uVar11;
          }
          iVar5 = FUN_00011d70(uVar11);
          if (iVar5 == 0x30494350) {
            local_1f0 = uVar11;
          }
          uVar11 = *(ulonglong *)(uVar11 + 8);
          if (uVar11 == 0) break;
          local_278 = iVar4 + 1;
        }
      }
      uVar11 = local_1f8;
      uVar1 = local_1b0;
      if ((local_1f8 != 0) &&
         (cVar3 = MmIsAddressValid(local_1f8), uVar1 = local_1b0, cVar3 != '\0')) {
        uVar11 = *(ulonglong *)(uVar11 + 0x18);
        local_278 = 1;
        while ((((iVar4 = local_278, uVar1 = local_1b0, local_278 < 1000 &&
                 (cVar3 = MmIsAddressValid(uVar11), uVar1 = local_1b0, cVar3 != '\0')) &&
                (iVar5 = FUN_00011d70(uVar11), uVar1 = uVar11, iVar5 != 0x52504d54)) &&
               (uVar11 = *(ulonglong *)(uVar11 + 8), uVar1 = local_1b0, uVar11 != 0))) {
          local_278 = iVar4 + 1;
        }
      }
      local_1b0 = uVar1;
      uVar11 = local_1f0;
      if ((local_1f0 != 0) && (cVar3 = MmIsAddressValid(local_1f0), cVar3 != '\0')) {
        uVar11 = *(ulonglong *)(uVar11 + 0x18);
        local_278 = 1;
        while ((iVar4 = local_278, local_278 < 1000 &&
               (cVar3 = MmIsAddressValid(uVar11), cVar3 != '\0'))) {
          iVar5 = FUN_00011d70(uVar11);
          if (iVar5 == 0x5f43504c) {
            local_208 = uVar11;
          }
          iVar5 = FUN_00011d70(uVar11);
          if (iVar5 == 0x4243504c) {
            local_210 = uVar11;
          }
          uVar11 = *(ulonglong *)(uVar11 + 8);
          if (uVar11 == 0) break;
          local_278 = iVar4 + 1;
        }
      }
      uVar11 = local_208;
      puVar9 = local_240;
      if ((local_208 != 0) &&
         (cVar3 = MmIsAddressValid(local_208), puVar9 = local_240, cVar3 != '\0')) {
        puVar13 = *(undefined8 **)(uVar11 + 0x18);
        local_278 = 1;
        while ((((iVar4 = local_278, puVar9 = local_240, local_278 < 1000 &&
                 (cVar3 = MmIsAddressValid(puVar13), puVar9 = local_240, cVar3 != '\0')) &&
                (iVar5 = FUN_00011d70((longlong)puVar13), puVar9 = puVar13, iVar5 != 0x5f304345)) &&
               (puVar13 = (undefined8 *)puVar13[1], puVar9 = local_240, puVar13 != (undefined8 *)0x0
               ))) {
          local_278 = iVar4 + 1;
        }
      }
      local_240 = puVar9;
      uVar11 = local_210;
      puVar13 = local_240;
      puVar9 = puVar13;
      puVar10 = local_240;
      if ((local_210 != 0) &&
         (cVar3 = MmIsAddressValid(local_210), puVar10 = local_240, cVar3 != '\0')) {
        puVar12 = *(undefined8 **)(uVar11 + 0x18);
        local_278 = 1;
        while (((iVar4 = local_278, puVar9 = puVar13, puVar10 = local_240, local_278 < 1000 &&
                (cVar3 = MmIsAddressValid(puVar12), puVar10 = local_240, cVar3 != '\0')) &&
               ((iVar5 = FUN_00011d70((longlong)puVar12), puVar9 = puVar12, puVar10 = puVar12,
                iVar5 != 0x5f304345 &&
                (puVar12 = (undefined8 *)puVar12[1], puVar9 = puVar13, puVar10 = local_240,
                puVar12 != (undefined8 *)0x0))))) {
          local_278 = iVar4 + 1;
        }
      }
      local_240 = puVar10;
      puVar13 = local_230;
      puVar10 = local_230;
      if ((puVar9 != (undefined8 *)0x0) &&
         (cVar3 = MmIsAddressValid(puVar9), puVar13 = local_230, puVar10 = local_230, cVar3 != '\0')
         ) {
        puVar12 = (undefined8 *)puVar9[3];
        local_278 = 1;
        while ((((iVar4 = local_278, puVar13 = local_230, puVar10 = local_230, local_278 < 1000 &&
                 (cVar3 = MmIsAddressValid(puVar12), puVar13 = local_230, puVar10 = local_230,
                 cVar3 != '\0')) &&
                (iVar5 = FUN_00011d70((longlong)puVar12), puVar13 = puVar12, puVar10 = puVar12,
                iVar5 != 0x504d5443)) &&
               (puVar12 = (undefined8 *)puVar12[1], puVar13 = local_230, puVar10 = local_230,
               puVar12 != (undefined8 *)0x0))) {
          local_278 = iVar4 + 1;
        }
      }
    }
    local_230 = puVar10;
    if (local_228 != (undefined8 *)0x0) {
      param_2[1] = (ulonglong)local_228;
      uVar7 = FUN_00011d70((longlong)local_228);
      *(undefined4 *)(param_2 + 2) = uVar7;
    }
    if (local_220 != 0) {
      param_2[3] = local_220;
      uVar7 = FUN_00011d70(local_220);
      *(undefined4 *)(param_2 + 4) = uVar7;
    }
    if (puVar14 != (undefined8 *)0x0) {
      param_2[5] = (ulonglong)puVar14;
      uVar7 = FUN_00011d70((longlong)puVar14);
      *(undefined4 *)(param_2 + 6) = uVar7;
    }
    if (puVar15 != (undefined8 *)0x0) {
      param_2[7] = (ulonglong)puVar15;
      uVar7 = FUN_00011d70((longlong)puVar15);
      *(undefined4 *)(param_2 + 8) = uVar7;
      param_2[9] = puVar15[2];
    }
    if (puVar16 != (undefined8 *)0x0) {
      param_2[10] = (ulonglong)puVar16;
      uVar7 = FUN_00011d70((longlong)puVar16);
      *(undefined4 *)(param_2 + 0xb) = uVar7;
      param_2[0xc] = puVar16[2];
    }
    if (local_200 != 0) {
      param_2[0xd] = local_200;
      uVar7 = FUN_00011d70(local_200);
      *(undefined4 *)(param_2 + 0xe) = uVar7;
    }
    if (local_1f8 != 0) {
      param_2[0x1a] = local_1f8;
      uVar7 = FUN_00011d70(local_1f8);
      *(undefined4 *)(param_2 + 0x1b) = uVar7;
    }
    if (local_1b0 != 0) {
      param_2[0x1c] = local_1b0;
      uVar7 = FUN_00011d70(local_1b0);
      *(undefined4 *)(param_2 + 0x1d) = uVar7;
    }
    if (local_1f0 != 0) {
      param_2[0xf] = local_1f0;
      uVar7 = FUN_00011d70(local_1f0);
      *(undefined4 *)(param_2 + 0x10) = uVar7;
    }
    if (local_208 != 0) {
      param_2[0x11] = local_208;
      uVar7 = FUN_00011d70(local_208);
      *(undefined4 *)(param_2 + 0x12) = uVar7;
    }
    if (local_210 != 0) {
      param_2[0x13] = local_210;
      uVar7 = FUN_00011d70(local_210);
      *(undefined4 *)(param_2 + 0x14) = uVar7;
    }
    if (puVar9 != (undefined8 *)0x0) {
      param_2[0x15] = (ulonglong)puVar9;
      uVar7 = FUN_00011d70((longlong)puVar9);
      *(undefined4 *)(param_2 + 0x16) = uVar7;
    }
    if (puVar13 != (undefined8 *)0x0) {
      param_2[0x17] = (ulonglong)puVar13;
      uVar7 = FUN_00011d70((longlong)puVar13);
      *(undefined4 *)(param_2 + 0x18) = uVar7;
      param_2[0x19] = puVar13[2];
    }
    if (puVar15 == (undefined8 *)0x0) {
      if (puVar13 != (undefined8 *)0x0) {
        local_1d8 = *puVar13;
        local_1d0 = puVar13[1];
        local_1e0 = puVar13[2];
        local_1c0 = puVar13[3];
        local_1b8 = puVar13[4];
        local_1c8 = local_1e0;
      }
    }
    else {
      local_1d8 = *puVar15;
      local_1d0 = puVar15[1];
      local_1e0 = puVar15[2];
      local_1c0 = puVar15[3];
      local_1b8 = puVar15[4];
      local_1c8 = local_1e0;
    }
    *(undefined1 *)param_2 = 1;
    uVar11 = local_1e0;
LAB_00012824:
    if (((uVar11 != 0) && (cVar3 = MmIsAddressValid(uVar11), cVar3 != '\0')) &&
       (uVar1 = *local_248, uVar1 != 0)) {
      *local_248 = uVar11;
      KeInitializeEvent(local_1a8,0,0);
      local_250 = 0x42696541;
      local_24c = FUN_00011d70((longlong)&local_1d8);
      local_268 = 0;
      local_288 = local_160;
      local_290 = local_1a8;
      local_298 = 0;
      local_2a0 = 0x14;
      local_2a8 = &local_268;
      lVar8 = IoBuildDeviceIoControlRequest(0x32c004,local_270,&local_250,8);
      *(undefined4 *)(param_2 + 0x20) = 1;
      if (lVar8 != 0) {
        *(undefined4 *)(param_2 + 0x20) = 2;
        iVar4 = IofCallDriver(local_270,lVar8);
        if (iVar4 == 0x103) {
          local_2a8 = (int *)0x0;
          KeWaitForSingleObject(local_1a8,0,0,0);
        }
        *(undefined4 *)(param_2 + 0x20) = 3;
        *(int *)((longlong)param_2 + 0x104) = iVar4;
        if (local_268 == 0x426f6541) {
          *(undefined4 *)(param_2 + 0x20) = 4;
          *(undefined4 *)(param_2 + 0x21) = local_264;
          *(undefined4 *)((longlong)param_2 + 0x10c) = local_260;
          *(undefined4 *)(param_2 + 0x22) = local_258;
        }
      }
      *local_248 = uVar1;
    }
  }
  else {
    uVar11 = param_2[9];
    if (uVar11 != 0) {
      local_1b8 = CONCAT44((int)param_2[8],(int)param_2[8]);
      local_1c8 = uVar11;
      goto LAB_00012824;
    }
    uVar11 = param_2[0x19];
    if (uVar11 != 0) {
      local_1b8 = CONCAT44((int)param_2[0x18],(int)param_2[0x18]);
      local_1c8 = uVar11;
      goto LAB_00012824;
    }
    local_1c8 = 0;
  }
  if ((param_2[0xc] != 0) && (uVar11 = *local_248, uVar11 != 0)) {
    *local_248 = param_2[0xc];
    KeInitializeEvent(local_1a8,0,0);
    local_250 = 0x42696541;
    local_24c = (undefined4)param_2[0xb];
    local_268 = 0;
    local_288 = local_160;
    local_290 = local_1a8;
    local_298 = 0;
    local_2a0 = 0x14;
    local_2a8 = &local_268;
    lVar8 = IoBuildDeviceIoControlRequest(0x32c004,local_270,&local_250,8);
    *(undefined4 *)((longlong)param_2 + 0xec) = 1;
    if (lVar8 != 0) {
      *(undefined4 *)((longlong)param_2 + 0xec) = 2;
      iVar4 = IofCallDriver(local_270,lVar8);
      if (iVar4 == 0x103) {
        local_2a8 = (int *)0x0;
        KeWaitForSingleObject(local_1a8,0,0,0);
      }
      *(undefined4 *)((longlong)param_2 + 0xec) = 3;
      *(int *)(param_2 + 0x1e) = iVar4;
      if (local_268 == 0x426f6541) {
        *(undefined4 *)((longlong)param_2 + 0xec) = 4;
        *(undefined4 *)((longlong)param_2 + 0xf4) = local_264;
        *(undefined4 *)(param_2 + 0x1f) = local_260;
        *(undefined4 *)((longlong)param_2 + 0xfc) = local_258;
      }
    }
    *local_248 = uVar11;
  }
  in_stack_00000030 = local_1e8;
  if ((param_2[9] != 0) && (uVar11 = *local_248, uVar11 != 0)) {
    *local_248 = param_2[9];
    KeInitializeEvent(local_1a8,0,0);
    local_250 = 0x42696541;
    local_24c = (undefined4)param_2[8];
    local_268 = 0;
    local_288 = local_160;
    local_290 = local_1a8;
    local_298 = 0;
    local_2a0 = 0x14;
    local_2a8 = &local_268;
    lVar8 = IoBuildDeviceIoControlRequest(0x32c004,local_270,&local_250,8);
    *(undefined4 *)((longlong)param_2 + 0x114) = 1;
    if (lVar8 != 0) {
      *(undefined4 *)((longlong)param_2 + 0x114) = 2;
      iVar4 = IofCallDriver(local_270,lVar8);
      if (iVar4 == 0x103) {
        local_2a8 = (int *)0x0;
        KeWaitForSingleObject(local_1a8,0,0,0);
      }
      *(undefined4 *)((longlong)param_2 + 0x114) = 3;
      *(int *)(param_2 + 0x23) = iVar4;
      if (local_268 == 0x426f6541) {
        *(undefined4 *)((longlong)param_2 + 0x114) = 4;
        *(undefined4 *)((longlong)param_2 + 0x11c) = local_264;
        *(undefined4 *)(param_2 + 0x24) = local_260;
        *(undefined4 *)((longlong)param_2 + 0x124) = local_258;
      }
    }
    *local_248 = uVar11;
    in_stack_00000030 = local_1e8;
  }
LAB_00012c19:
  *in_stack_00000030 = 0x228;
  FUN_00013640(local_38 ^ (ulonglong)auStack_2c8);
  return;
}

