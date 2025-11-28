// Function: FUN_000110d8
// Address: 000110d8
// Decompiled by Ghidra


uint FUN_000110d8(undefined8 param_1,longlong param_2)

{
  uint *puVar1;
  char *pcVar2;
  undefined4 *puVar3;
  uint *puVar4;
  undefined1 uVar5;
  undefined2 uVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  undefined8 uVar10;
  int iVar11;
  uint uVar12;
  
  puVar1 = (uint *)(param_2 + 0x38);
  pcVar2 = *(char **)(param_2 + 0xb8);
  puVar1[0] = 0;
  puVar1[1] = 0;
  uVar12 = 0xc0000002;
  if (*pcVar2 == '\0') {
    if (DAT_00013110 != -1) {
      DAT_00013110 = DAT_00013110 + 1;
    }
  }
  else if (*pcVar2 == '\x02') {
    if (DAT_00013110 != -1) {
      DAT_00013110 = DAT_00013110 + -1;
    }
  }
  else {
    if (*pcVar2 != '\x0e') goto LAB_000113d9;
    uVar9 = *(uint *)(pcVar2 + 0x18);
    if (0x9c406104 < uVar9) {
      if (uVar9 == 0x9c406144) {
        uVar12 = *(uint *)(pcVar2 + 8);
        puVar4 = *(uint **)(param_2 + 0x18);
        if (*(int *)(pcVar2 + 0x10) == 8) {
          uVar9 = *puVar4;
          uVar9 = HalGetBusDataByOffset
                            (4,uVar9 >> 8 & 0xff,uVar9 >> 3 & 0x1f | (uVar9 & 7) << 5,puVar4,
                             puVar4[1],uVar12);
          if (uVar9 == 0) {
            uVar12 = 0xe0000001;
          }
          else if ((uVar12 == 2) || (uVar9 != 2)) {
            if (uVar12 == uVar9) {
              *puVar1 = uVar12;
              goto LAB_000113d7;
            }
            uVar12 = 0xe0000004;
          }
          else {
            uVar12 = 0xe0000002;
          }
          *puVar1 = 0;
          goto LAB_000113d9;
        }
      }
      else {
        if ((((uVar9 == 0x9c40a0c8) || (uVar9 == 0x9c40a0d8)) || (uVar9 == 0x9c40a0dc)) ||
           (uVar9 == 0x9c40a0e0)) {
          puVar3 = *(undefined4 **)(param_2 + 0x18);
          uVar6 = (undefined2)*puVar3;
          if (uVar9 == 0x9c40a0d8) {
            out(uVar6,*(undefined1 *)(puVar3 + 1));
          }
          else if (uVar9 == 0x9c40a0dc) {
            out(uVar6,*(undefined2 *)(puVar3 + 1));
          }
          else {
            if (uVar9 != 0x9c40a0e0) goto LAB_00011342;
            out(uVar6,puVar3[1]);
          }
          goto LAB_000113d7;
        }
        if (uVar9 == 0x9c40a108) {
          uVar10 = FUN_000115ac(*(undefined8 **)(param_2 + 0x18),*(uint *)(pcVar2 + 0x10),
                                *(undefined8 **)(param_2 + 0x18),(ulonglong)*(uint *)(pcVar2 + 8),
                                puVar1);
          uVar12 = (uint)uVar10;
          goto LAB_000113d9;
        }
        if (uVar9 != 0x9c40a148) goto LAB_000113d9;
        uVar12 = *(uint *)(pcVar2 + 0x10);
        if (7 < uVar12) {
          puVar4 = *(uint **)(param_2 + 0x18);
          *puVar1 = 0;
          iVar11 = uVar12 - 8;
          uVar12 = *puVar4;
          iVar8 = HalSetBusDataByOffset
                            (4,uVar12 >> 8 & 0xff,uVar12 >> 3 & 0x1f | (uVar12 & 7) << 5,puVar4 + 2,
                             puVar4[1],iVar11);
          uVar12 = -(uint)(iVar8 != iVar11) & 0xe0000003;
          goto LAB_000113d9;
        }
      }
LAB_00011342:
      uVar12 = 0xc000000d;
      goto LAB_000113d9;
    }
    if (uVar9 == 0x9c406104) {
      uVar10 = FUN_000114e4(*(undefined8 **)(param_2 + 0x18),*(int *)(pcVar2 + 0x10),
                            (undefined4 *)*(undefined8 **)(param_2 + 0x18),*(uint *)(pcVar2 + 8),
                            puVar1);
      uVar12 = (uint)uVar10;
      goto LAB_000113d9;
    }
    if (uVar9 == 0x9c402084) {
      uVar10 = FUN_00011448(*(undefined4 **)(param_2 + 0x18),(ulonglong)*(uint *)(pcVar2 + 0x10),
                            (undefined8 *)*(undefined4 **)(param_2 + 0x18),
                            (ulonglong)*(uint *)(pcVar2 + 8),puVar1);
      uVar12 = (uint)uVar10;
      goto LAB_000113d9;
    }
    if (uVar9 == 0x9c402088) {
      uVar10 = FUN_0001147c(*(undefined4 **)(param_2 + 0x18));
      uVar12 = (uint)uVar10;
      goto LAB_000113d9;
    }
    if (uVar9 == 0x9c40208c) {
      uVar10 = FUN_000114b0(*(undefined4 **)(param_2 + 0x18),(ulonglong)*(uint *)(pcVar2 + 0x10),
                            (ulonglong *)*(undefined4 **)(param_2 + 0x18),
                            (ulonglong)*(uint *)(pcVar2 + 8),puVar1);
      uVar12 = (uint)uVar10;
      goto LAB_000113d9;
    }
    if (uVar9 == 0x9c402090) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    if (((uVar9 != 0x9c4060c4) && (uVar9 != 0x9c4060cc)) &&
       ((uVar9 != 0x9c4060d0 && (uVar9 != 0x9c4060d4)))) goto LAB_000113d9;
    puVar3 = *(undefined4 **)(param_2 + 0x18);
    uVar12 = *(uint *)(pcVar2 + 0x10);
    uVar6 = (undefined2)*puVar3;
    if (uVar9 == 0x9c4060cc) {
      uVar5 = in(uVar6);
      *(undefined1 *)puVar3 = uVar5;
    }
    else if (uVar9 == 0x9c4060d0) {
      uVar6 = in(uVar6);
      *(undefined2 *)puVar3 = uVar6;
    }
    else {
      if (uVar9 != 0x9c4060d4) {
        *puVar1 = 0;
        goto LAB_00011342;
      }
      uVar7 = in(uVar6);
      *puVar3 = uVar7;
    }
    *puVar1 = uVar12;
  }
LAB_000113d7:
  uVar12 = 0;
LAB_000113d9:
  *(uint *)(param_2 + 0x30) = uVar12;
  IofCompleteRequest(param_2,0);
  return uVar12;
}

