// Function: FUN_00011540
// Address: 00011540
// Decompiled by Ghidra


uint FUN_00011540(undefined8 param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  bool bVar1;
  undefined8 uVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined4 *puVar8;
  longlong *plVar9;
  undefined8 uVar10;
  undefined8 *puVar11;
  longlong lVar12;
  longlong lVar13;
  longlong lVar14;
  longlong lVar15;
  uint local_res18;
  longlong local_a0;
  longlong local_98;
  undefined8 *local_90;
  longlong local_88;
  undefined4 local_80 [2];
  undefined8 local_78;
  undefined1 *local_70;
  undefined4 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined1 local_50 [24];
  
  local_98 = 0;
  lVar15 = 0;
  bVar1 = false;
  if (((uint)param_3 < 0x18) || ((uint)param_4 < 8)) {
    if (DAT_00014110 != 0) {
      DbgPrint("CITMDRV.SYS: Insufficient input or output buffer\n");
      FUN_00011010("CITMDRV.SYS: Insufficient input or output buffer\n",param_2,param_3,param_4);
    }
    local_res18 = 0xc000009a;
  }
  else {
    puVar11 = (undefined8 *)param_2[1];
    local_90 = puVar11;
    if (DAT_00014110 != 0) {
      DbgPrint("CITMDRV.SYS: userVirtualAddress = 0x%p\n",puVar11);
      FUN_00011010("CITMDRV.SYS: userVirtualAddress = 0x%p\n",puVar11,param_3,param_4);
    }
    uVar10 = 0;
    uVar2 = 0;
    uVar4 = (ulonglong)*(uint *)(param_2 + 2);
    lVar15 = IoAllocateMdl(puVar11);
    local_88 = lVar15;
    if (lVar15 == 0) {
      if (DAT_00014110 != 0) {
        DbgPrint("CITMDRV.SYS: IoAllocateMdl failed\n");
        FUN_00011010("CITMDRV.SYS: IoAllocateMdl failed\n",uVar4,uVar2,uVar10);
      }
      *param_2 = 1;
    }
    else {
      uVar7 = 1;
      uVar2 = 1;
      MmProbeAndLockPages(lVar15);
      if (DAT_00014110 != 0) {
        DbgPrint("CITMDRV.SYS: MmProbeAndLockPages ok\n");
        FUN_00011010("CITMDRV.SYS: MmProbeAndLockPages ok\n",uVar2,uVar7,uVar10);
      }
      lVar13 = *param_2;
      lVar14 = lVar13 - (ulonglong)((uint)lVar13 & 0xfff);
      lVar5 = (((ulonglong)*(uint *)(param_2 + 2) + lVar13) -
              (ulonglong)((uint)((ulonglong)*(uint *)(param_2 + 2) + lVar13) & 0xfff)) + 0x1000;
      lVar12 = lVar13 - lVar14;
      lVar3 = lVar5 - lVar14;
      if (DAT_00014110 != 0) {
        DbgPrint("CITMDRV.SYS: requested Address = 0x%I64x\n",lVar13);
        FUN_00011010("CITMDRV.SYS: requested Address = 0x%I64x\n",lVar13,uVar7,uVar10);
      }
      if (DAT_00014110 != 0) {
        DbgPrint("CITMDRV.SYS: requested Size    = 0x%x\n",(int)param_2[2]);
        FUN_00011010("CITMDRV.SYS: requested Size    = 0x%x\n",(ulonglong)*(uint *)(param_2 + 2),
                     uVar7,uVar10);
      }
      if (DAT_00014110 != 0) {
        DbgPrint("CITMDRV.SYS: aligned start Address = 0x%I64x\n",lVar14);
        FUN_00011010("CITMDRV.SYS: aligned start Address = 0x%I64x\n",lVar14,uVar7,uVar10);
      }
      if (DAT_00014110 != 0) {
        DbgPrint("CITMDRV.SYS: aligned end   Address = 0x%I64x\n",lVar5);
        FUN_00011010("CITMDRV.SYS: aligned end   Address = 0x%I64x\n",lVar5,uVar7,uVar10);
      }
      if (DAT_00014110 != 0) {
        DbgPrint("CITMDRV.SYS: aligned Size          = 0x%x\n",lVar3);
        FUN_00011010("CITMDRV.SYS: aligned Size          = 0x%x\n",lVar3,uVar7,uVar10);
      }
      if (DAT_00014110 != 0) {
        DbgPrint("CITMDRV.SYS: offset                = 0x%x\n",lVar12);
        FUN_00011010("CITMDRV.SYS: offset                = 0x%x\n",lVar12,uVar7,uVar10);
      }
      RtlInitUnicodeString(local_50,L"\\Device\\PhysicalMemory");
      local_80[0] = 0x30;
      local_78 = 0;
      local_68 = 0x40;
      local_70 = local_50;
      local_60 = 0;
      local_58 = 0;
      puVar8 = local_80;
      local_res18 = ZwOpenSection(&local_98,4);
      if ((int)local_res18 < 0) {
        if (DAT_00014110 == 0) {
          bVar1 = true;
        }
        else {
          DbgPrint("CITMDRV.SYS: ZwOpenSection failed (0x%x)\n",local_res18);
          FUN_00011010("CITMDRV.SYS: ZwOpenSection failed (0x%x)\n",(ulonglong)local_res18,puVar8,
                       uVar10);
          bVar1 = true;
        }
      }
      else {
        plVar9 = &local_a0;
        puVar11 = local_90;
        local_a0 = lVar14;
        local_res18 = FUN_00011410(local_98,lVar3,plVar9,local_90,(ulonglong)*(uint *)(param_2 + 2),
                                   lVar12);
        if (local_res18 == 0xc0000018) {
          lVar13 = 0;
          uVar4 = (ulonglong)*(uint *)(param_2 + 2);
          if (DAT_00014110 != 0) {
            DbgPrint("CITMDRV.SYS: Try to split into single pages\n");
            FUN_00011010("CITMDRV.SYS: Try to split into single pages\n",lVar3,plVar9,puVar11);
          }
          for (; local_a0 = lVar14, uVar4 != 0; uVar4 = uVar4 - uVar6) {
            uVar6 = uVar4;
            if (0x1000 < uVar4 + lVar12) {
              uVar6 = 0x1000 - lVar12;
            }
            if (DAT_00014110 != 0) {
              DbgPrint("CITMDRV.SYS: aligned Address   = 0x%I64x\n",lVar14);
              FUN_00011010("CITMDRV.SYS: aligned Address   = 0x%I64x\n",local_a0,plVar9,puVar11);
            }
            if (DAT_00014110 != 0) {
              DbgPrint("CITMDRV.SYS: aligned Size      = 0x%x\n",0x1000);
              FUN_00011010("CITMDRV.SYS: aligned Size      = 0x%x\n",0x1000,plVar9,puVar11);
            }
            if (DAT_00014110 != 0) {
              DbgPrint("CITMDRV.SYS: requested Size    = 0x%x\n",uVar6);
              FUN_00011010("CITMDRV.SYS: requested Size    = 0x%x\n",uVar6,plVar9,puVar11);
            }
            if (DAT_00014110 != 0) {
              DbgPrint("CITMDRV.SYS: requested offset  = 0x%x\n",lVar12);
              FUN_00011010("CITMDRV.SYS: requested offset  = 0x%x\n",lVar12,plVar9,puVar11);
            }
            if (DAT_00014110 != 0) {
              DbgPrint("CITMDRV.SYS: userOffset        = 0x%x\n",lVar13);
              FUN_00011010("CITMDRV.SYS: userOffset        = 0x%x\n",lVar13,plVar9,puVar11);
            }
            puVar11 = (undefined8 *)(lVar13 + (longlong)local_90);
            plVar9 = &local_a0;
            local_res18 = FUN_00011410(local_98,0x1000,plVar9,puVar11,uVar6,lVar12);
            if ((int)local_res18 < 0) break;
            lVar12 = 0;
            lVar14 = lVar14 + 0x1000;
            lVar13 = lVar13 + uVar6;
          }
        }
        if ((int)local_res18 < 0) {
          if (DAT_00014110 == 0) {
            bVar1 = true;
          }
          else {
            DbgPrint("CITMDRV.SYS: ZwMapViewOfSection failed (0x%x)\n",local_res18);
            FUN_00011010("CITMDRV.SYS: ZwMapViewOfSection failed (0x%x)\n",(ulonglong)local_res18,
                         plVar9,puVar11);
            bVar1 = true;
          }
        }
        else {
          *param_2 = 0;
          bVar1 = true;
        }
      }
    }
  }
  if (lVar15 != 0) {
    if (bVar1) {
      MmUnlockPages(lVar15);
    }
    IoFreeMdl(lVar15);
  }
  if (local_98 != 0) {
    ZwClose();
  }
  return local_res18;
}

