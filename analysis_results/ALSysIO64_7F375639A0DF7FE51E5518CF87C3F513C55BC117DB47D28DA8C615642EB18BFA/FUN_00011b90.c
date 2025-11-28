// Function: FUN_00011b90
// Address: 00011b90
// Decompiled by Ghidra


void FUN_00011b90(undefined8 param_1,ulonglong *param_2)

{
  ulonglong uVar1;
  ulonglong *puVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  longlong lVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined4 uVar9;
  undefined8 *puVar10;
  ulonglong uVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  undefined8 *puVar14;
  undefined8 *puVar15;
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
  
  local_38 = DAT_00015100 ^ (ulonglong)auStack_2c8;
  local_1e8 = in_stack_00000030;
  if (param_2 == (ulonglong *)0x0) goto LAB_00012962;
  puVar7 = (undefined8 *)0x0;
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
  iVar5 = IoGetDeviceObjectPointer(local_170,0x80,&local_178,&local_270);
  if (((iVar5 != 0) || (local_270 == 0)) || (cVar4 = MmIsAddressValid(), cVar4 == '\0'))
  goto LAB_00012962;
  ObfDereferenceObject(local_178);
  RtlFreeUnicodeString(local_170);
  lVar6 = *(longlong *)(local_270 + 0x40);
  iVar5 = FUN_00011ae0();
  if (iVar5 == 0) {
    local_248 = (ulonglong *)(lVar6 + 0x1e8);
  }
  else {
    local_248 = (ulonglong *)(lVar6 + 0x240);
  }
  if ((char)*param_2 == '\0') {
    memcpy(local_138,param_2 + 0x25,0x100);
    FUN_00013a10(param_2,0,0x228);
    memcpy(param_2 + 0x25,local_138,0x100);
    cVar4 = MmIsAddressValid((longlong *)(lVar6 + 8));
    puVar2 = local_248;
    puVar13 = puVar7;
    puVar14 = puVar7;
    puVar15 = puVar7;
    if (((cVar4 == '\0') || (cVar4 = MmIsAddressValid(local_248), cVar4 == '\0')) ||
       (*(longlong *)(lVar6 + 8) != 0x5f534750)) {
      puVar8 = (undefined8 *)0x0;
      puVar10 = local_230;
    }
    else {
      puVar8 = (undefined8 *)*puVar2;
      local_278 = 1;
      while (iVar5 = local_278, local_278 < 1000) {
        cVar4 = MmIsAddressValid(puVar8);
        puVar10 = puVar7;
        puVar12 = local_228;
        if (((cVar4 == '\0') ||
            (puVar10 = puVar8, puVar12 = puVar8, *(int *)(puVar8 + 4) == 0x5f5f5f5c)) ||
           (puVar8 = (undefined8 *)puVar8[2], puVar10 = puVar7, puVar12 = local_228,
           puVar8 == (undefined8 *)0x0)) goto LAB_00011e36;
        local_278 = iVar5 + 1;
      }
      puVar10 = (undefined8 *)0x0;
      puVar12 = local_228;
LAB_00011e36:
      local_228 = puVar12;
      if ((puVar10 != (undefined8 *)0x0) && (cVar4 = MmIsAddressValid(puVar10), cVar4 != '\0')) {
        uVar11 = puVar10[3];
        local_278 = 1;
        while ((iVar5 = local_278, local_278 < 1000 &&
               (cVar4 = MmIsAddressValid(uVar11), cVar4 != '\0'))) {
          if (*(int *)(uVar11 + 0x20) == 0x5f42535f) {
            local_200 = uVar11;
          }
          if (*(int *)(uVar11 + 0x20) == 0x5f5a545f) {
            local_220 = uVar11;
          }
          uVar11 = *(ulonglong *)(uVar11 + 8);
          if (uVar11 == 0) break;
          local_278 = iVar5 + 1;
        }
      }
      uVar11 = local_220;
      if ((local_220 != 0) && (cVar4 = MmIsAddressValid(local_220), cVar4 != '\0')) {
        puVar13 = *(undefined8 **)(uVar11 + 0x18);
        local_278 = 1;
        while (((iVar5 = local_278, puVar14 = puVar7, local_278 < 1000 &&
                (cVar4 = MmIsAddressValid(puVar13), cVar4 != '\0')) && (puVar7 == (undefined8 *)0x0)
               )) {
          puVar8 = (undefined8 *)puVar13[3];
          local_238 = 1;
          while (((iVar3 = local_238, puVar14 = puVar7, puVar10 = local_218, puVar12 = local_188,
                  local_238 < 1000 &&
                  (cVar4 = MmIsAddressValid(puVar8), puVar10 = local_218, puVar12 = local_188,
                  cVar4 != '\0')) &&
                 ((puVar14 = puVar8, puVar10 = puVar13, puVar12 = puVar8,
                  *(int *)(puVar8 + 4) != 0x504d545f &&
                  (puVar8 = (undefined8 *)puVar8[1], puVar14 = puVar7, puVar10 = local_218,
                  puVar12 = local_188, puVar8 != (undefined8 *)0x0))))) {
            local_238 = iVar3 + 1;
          }
          local_188 = puVar12;
          local_218 = puVar10;
          puVar13 = (undefined8 *)puVar13[1];
          if (puVar13 == (undefined8 *)0x0) break;
          local_278 = iVar5 + 1;
          puVar7 = puVar14;
        }
        lVar6 = *(longlong *)(local_220 + 0x18);
        local_278 = 1;
        while (((iVar5 = local_278, puVar13 = local_218, local_278 < 1000 &&
                (cVar4 = MmIsAddressValid(lVar6), puVar13 = local_218, cVar4 != '\0')) &&
               (puVar15 == (undefined8 *)0x0))) {
          puVar7 = *(undefined8 **)(lVar6 + 0x18);
          local_238 = 1;
          while ((((iVar3 = local_238, puVar8 = puVar15, puVar13 = local_190, local_238 < 1000 &&
                   (cVar4 = MmIsAddressValid(puVar7), puVar13 = local_190, cVar4 != '\0')) &&
                  (puVar8 = puVar7, puVar13 = puVar7, *(int *)(puVar7 + 4) != 0x5452435f)) &&
                 (puVar7 = (undefined8 *)puVar7[1], puVar8 = puVar15, puVar13 = local_190,
                 puVar7 != (undefined8 *)0x0))) {
            local_238 = iVar3 + 1;
          }
          local_190 = puVar13;
          lVar6 = *(longlong *)(lVar6 + 8);
          puVar13 = local_218;
          puVar15 = puVar8;
          if (lVar6 == 0) break;
          local_278 = iVar5 + 1;
        }
      }
      uVar11 = local_200;
      if ((local_200 != 0) && (cVar4 = MmIsAddressValid(local_200), cVar4 != '\0')) {
        uVar11 = *(ulonglong *)(uVar11 + 0x18);
        local_278 = 1;
        while ((iVar5 = local_278, local_278 < 1000 &&
               (cVar4 = MmIsAddressValid(uVar11), cVar4 != '\0'))) {
          if (*(int *)(uVar11 + 0x20) == 0x444b5441) {
            local_1f8 = uVar11;
          }
          if (*(int *)(uVar11 + 0x20) == 0x30494350) {
            local_1f0 = uVar11;
          }
          uVar11 = *(ulonglong *)(uVar11 + 8);
          if (uVar11 == 0) break;
          local_278 = iVar5 + 1;
        }
      }
      uVar11 = local_1f8;
      uVar1 = local_1b0;
      if ((local_1f8 != 0) &&
         (cVar4 = MmIsAddressValid(local_1f8), uVar1 = local_1b0, cVar4 != '\0')) {
        uVar11 = *(ulonglong *)(uVar11 + 0x18);
        local_278 = 1;
        while ((((iVar5 = local_278, uVar1 = local_1b0, local_278 < 1000 &&
                 (cVar4 = MmIsAddressValid(uVar11), uVar1 = local_1b0, cVar4 != '\0')) &&
                (uVar1 = uVar11, *(int *)(uVar11 + 0x20) != 0x52504d54)) &&
               (uVar11 = *(ulonglong *)(uVar11 + 8), uVar1 = local_1b0, uVar11 != 0))) {
          local_278 = iVar5 + 1;
        }
      }
      local_1b0 = uVar1;
      uVar11 = local_1f0;
      if ((local_1f0 != 0) && (cVar4 = MmIsAddressValid(local_1f0), cVar4 != '\0')) {
        uVar11 = *(ulonglong *)(uVar11 + 0x18);
        local_278 = 1;
        while ((iVar5 = local_278, local_278 < 1000 &&
               (cVar4 = MmIsAddressValid(uVar11), cVar4 != '\0'))) {
          if (*(int *)(uVar11 + 0x20) == 0x5f43504c) {
            local_208 = uVar11;
          }
          if (*(int *)(uVar11 + 0x20) == 0x4243504c) {
            local_210 = uVar11;
          }
          uVar11 = *(ulonglong *)(uVar11 + 8);
          if (uVar11 == 0) break;
          local_278 = iVar5 + 1;
        }
      }
      uVar11 = local_208;
      puVar7 = local_240;
      if ((local_208 != 0) &&
         (cVar4 = MmIsAddressValid(local_208), puVar7 = local_240, cVar4 != '\0')) {
        puVar8 = *(undefined8 **)(uVar11 + 0x18);
        local_278 = 1;
        while ((((iVar5 = local_278, puVar7 = local_240, local_278 < 1000 &&
                 (cVar4 = MmIsAddressValid(puVar8), puVar7 = local_240, cVar4 != '\0')) &&
                (puVar7 = puVar8, *(int *)(puVar8 + 4) != 0x5f304345)) &&
               (puVar8 = (undefined8 *)puVar8[1], puVar7 = local_240, puVar8 != (undefined8 *)0x0)))
        {
          local_278 = iVar5 + 1;
        }
      }
      local_240 = puVar7;
      uVar11 = local_210;
      puVar8 = local_240;
      puVar7 = puVar8;
      puVar10 = local_240;
      if ((local_210 != 0) &&
         (cVar4 = MmIsAddressValid(local_210), puVar10 = local_240, cVar4 != '\0')) {
        puVar12 = *(undefined8 **)(uVar11 + 0x18);
        local_278 = 1;
        while (((iVar5 = local_278, puVar7 = puVar8, puVar10 = local_240, local_278 < 1000 &&
                (cVar4 = MmIsAddressValid(puVar12), puVar10 = local_240, cVar4 != '\0')) &&
               ((puVar7 = puVar12, puVar10 = puVar12, *(int *)(puVar12 + 4) != 0x5f304345 &&
                (puVar12 = (undefined8 *)puVar12[1], puVar7 = puVar8, puVar10 = local_240,
                puVar12 != (undefined8 *)0x0))))) {
          local_278 = iVar5 + 1;
        }
      }
      local_240 = puVar10;
      puVar8 = local_230;
      puVar10 = local_230;
      if ((puVar7 != (undefined8 *)0x0) &&
         (cVar4 = MmIsAddressValid(puVar7), puVar8 = local_230, puVar10 = local_230, cVar4 != '\0'))
      {
        puVar12 = (undefined8 *)puVar7[3];
        local_278 = 1;
        while ((((iVar5 = local_278, puVar8 = local_230, puVar10 = local_230, local_278 < 1000 &&
                 (cVar4 = MmIsAddressValid(puVar12), puVar8 = local_230, puVar10 = local_230,
                 cVar4 != '\0')) &&
                (puVar8 = puVar12, puVar10 = puVar12, *(int *)(puVar12 + 4) != 0x504d5443)) &&
               (puVar12 = (undefined8 *)puVar12[1], puVar8 = local_230, puVar10 = local_230,
               puVar12 != (undefined8 *)0x0))) {
          local_278 = iVar5 + 1;
        }
      }
    }
    local_230 = puVar10;
    if (local_228 != (undefined8 *)0x0) {
      param_2[1] = (ulonglong)local_228;
      *(undefined4 *)(param_2 + 2) = *(undefined4 *)(local_228 + 4);
    }
    if (local_220 != 0) {
      param_2[3] = local_220;
      *(undefined4 *)(param_2 + 4) = *(undefined4 *)(local_220 + 0x20);
    }
    if (puVar13 != (undefined8 *)0x0) {
      param_2[5] = (ulonglong)puVar13;
      *(undefined4 *)(param_2 + 6) = *(undefined4 *)(puVar13 + 4);
    }
    if (puVar14 != (undefined8 *)0x0) {
      param_2[7] = (ulonglong)puVar14;
      *(undefined4 *)(param_2 + 8) = *(undefined4 *)(puVar14 + 4);
      param_2[9] = puVar14[2];
    }
    if (puVar15 != (undefined8 *)0x0) {
      param_2[10] = (ulonglong)puVar15;
      *(undefined4 *)(param_2 + 0xb) = *(undefined4 *)(puVar15 + 4);
      param_2[0xc] = puVar15[2];
    }
    if (local_200 != 0) {
      param_2[0xd] = local_200;
      *(undefined4 *)(param_2 + 0xe) = *(undefined4 *)(local_200 + 0x20);
    }
    if (local_1f8 != 0) {
      param_2[0x1a] = local_1f8;
      *(undefined4 *)(param_2 + 0x1b) = *(undefined4 *)(local_1f8 + 0x20);
    }
    if (local_1b0 != 0) {
      param_2[0x1c] = local_1b0;
      *(undefined4 *)(param_2 + 0x1d) = *(undefined4 *)(local_1b0 + 0x20);
    }
    if (local_1f0 != 0) {
      param_2[0xf] = local_1f0;
      *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(local_1f0 + 0x20);
    }
    if (local_208 != 0) {
      param_2[0x11] = local_208;
      *(undefined4 *)(param_2 + 0x12) = *(undefined4 *)(local_208 + 0x20);
    }
    if (local_210 != 0) {
      param_2[0x13] = local_210;
      *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(local_210 + 0x20);
    }
    if (puVar7 != (undefined8 *)0x0) {
      param_2[0x15] = (ulonglong)puVar7;
      *(undefined4 *)(param_2 + 0x16) = *(undefined4 *)(puVar7 + 4);
    }
    if (puVar8 != (undefined8 *)0x0) {
      param_2[0x17] = (ulonglong)puVar8;
      *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(puVar8 + 4);
      param_2[0x19] = puVar8[2];
    }
    if (puVar14 == (undefined8 *)0x0) {
      if (puVar8 != (undefined8 *)0x0) {
        local_1d8 = *puVar8;
        local_1d0 = puVar8[1];
        local_1e0 = puVar8[2];
        local_1c0 = puVar8[3];
        local_1b8 = puVar8[4];
        local_1c8 = local_1e0;
      }
    }
    else {
      local_1d8 = *puVar14;
      local_1d0 = puVar14[1];
      local_1e0 = puVar14[2];
      local_1c0 = puVar14[3];
      local_1b8 = puVar14[4];
      local_1c8 = local_1e0;
    }
    *(undefined1 *)param_2 = 1;
    uVar11 = local_1e0;
    uVar9 = (undefined4)local_1b8;
LAB_0001257a:
    if (((uVar11 != 0) && (cVar4 = MmIsAddressValid(uVar11), cVar4 != '\0')) &&
       (uVar1 = *local_248, uVar1 != 0)) {
      *local_248 = uVar11;
      KeInitializeEvent(local_1a8,0,0);
      local_250 = 0x42696541;
      local_268 = 0;
      local_288 = local_160;
      local_290 = local_1a8;
      local_298 = 0;
      local_2a0 = 0x14;
      local_2a8 = &local_268;
      local_24c = uVar9;
      lVar6 = IoBuildDeviceIoControlRequest(0x32c004,local_270,&local_250,8);
      *(undefined4 *)(param_2 + 0x20) = 1;
      if (lVar6 != 0) {
        *(undefined4 *)(param_2 + 0x20) = 2;
        iVar5 = IofCallDriver(local_270,lVar6);
        if (iVar5 == 0x103) {
          local_2a8 = (int *)0x0;
          KeWaitForSingleObject(local_1a8,0,0,0);
        }
        *(undefined4 *)(param_2 + 0x20) = 3;
        *(int *)((longlong)param_2 + 0x104) = iVar5;
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
      uVar9 = (undefined4)param_2[8];
      local_1b8 = CONCAT44(uVar9,uVar9);
      local_1c8 = uVar11;
      goto LAB_0001257a;
    }
    uVar11 = param_2[0x19];
    if (uVar11 != 0) {
      uVar9 = (undefined4)param_2[0x18];
      local_1b8 = CONCAT44(uVar9,uVar9);
      local_1c8 = uVar11;
      goto LAB_0001257a;
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
    lVar6 = IoBuildDeviceIoControlRequest(0x32c004,local_270,&local_250,8);
    *(undefined4 *)((longlong)param_2 + 0xec) = 1;
    if (lVar6 != 0) {
      *(undefined4 *)((longlong)param_2 + 0xec) = 2;
      iVar5 = IofCallDriver(local_270,lVar6);
      if (iVar5 == 0x103) {
        local_2a8 = (int *)0x0;
        KeWaitForSingleObject(local_1a8,0,0,0);
      }
      *(undefined4 *)((longlong)param_2 + 0xec) = 3;
      *(int *)(param_2 + 0x1e) = iVar5;
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
    lVar6 = IoBuildDeviceIoControlRequest(0x32c004,local_270,&local_250,8);
    *(undefined4 *)((longlong)param_2 + 0x114) = 1;
    if (lVar6 != 0) {
      *(undefined4 *)((longlong)param_2 + 0x114) = 2;
      iVar5 = IofCallDriver(local_270,lVar6);
      if (iVar5 == 0x103) {
        local_2a8 = (int *)0x0;
        KeWaitForSingleObject(local_1a8,0,0,0);
      }
      *(undefined4 *)((longlong)param_2 + 0x114) = 3;
      *(int *)(param_2 + 0x23) = iVar5;
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
LAB_00012962:
  *in_stack_00000030 = 0x228;
  FUN_000133b0(local_38 ^ (ulonglong)auStack_2c8);
  return;
}

