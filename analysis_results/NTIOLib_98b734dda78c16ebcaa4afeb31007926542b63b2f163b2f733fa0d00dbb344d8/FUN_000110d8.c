// Function: FUN_000110d8
// Address: 000110d8
// Decompiled by Ghidra


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
    if (*pcVar2 != '\x0e') goto LAB_0001144a;
    uVar9 = *(uint *)(pcVar2 + 0x18);
    if (0xc35060d4 < uVar9) {
      if (uVar9 == 0xc3506104) {
        uVar10 = FUN_00011558(*(undefined8 **)(param_2 + 0x18),*(int *)(pcVar2 + 0x10),
                              (undefined4 *)*(undefined8 **)(param_2 + 0x18),*(uint *)(pcVar2 + 8),
                              puVar1);
        uVar12 = (uint)uVar10;
        goto LAB_0001144a;
      }
      if (uVar9 != 0xc3506144) {
        if (uVar9 == 0xc3506184) {
          **(undefined8 **)(param_2 + 0x18) = _DAT_fffff78000000008;
          *puVar1 = 8;
        }
        else {
          if (((uVar9 != 0xc350a0c8) && (uVar9 != 0xc350a0d8)) &&
             ((uVar9 != 0xc350a0dc && (uVar9 != 0xc350a0e0)))) {
            if (uVar9 == 0xc350a108) {
              uVar10 = FUN_00011620(*(undefined8 **)(param_2 + 0x18),*(uint *)(pcVar2 + 0x10),
                                    *(undefined8 **)(param_2 + 0x18),
                                    (ulonglong)*(uint *)(pcVar2 + 8),puVar1);
              uVar12 = (uint)uVar10;
              goto LAB_0001144a;
            }
            if (uVar9 != 0xc350a148) goto LAB_0001144a;
            uVar12 = *(uint *)(pcVar2 + 0x10);
            if (7 < uVar12) {
              puVar4 = *(uint **)(param_2 + 0x18);
              *puVar1 = 0;
              iVar11 = uVar12 - 8;
              uVar12 = *puVar4;
              iVar8 = HalSetBusDataByOffset
                                (4,uVar12 >> 8 & 0xff,uVar12 >> 3 & 0x1f | (uVar12 & 7) << 5,
                                 puVar4 + 2,puVar4[1],iVar11);
              uVar12 = -(uint)(iVar8 != iVar11) & 0xe0000003;
              goto LAB_0001144a;
            }
            goto LAB_000111b1;
          }
          puVar3 = *(undefined4 **)(param_2 + 0x18);
          uVar6 = (undefined2)*puVar3;
          if (uVar9 == 0xc350a0d8) {
            out(uVar6,*(undefined1 *)(puVar3 + 1));
          }
          else if (uVar9 == 0xc350a0dc) {
            out(uVar6,*(undefined2 *)(puVar3 + 1));
          }
          else {
            if (uVar9 != 0xc350a0e0) goto LAB_000111b1;
            out(uVar6,puVar3[1]);
          }
        }
        goto LAB_00011448;
      }
      uVar12 = *(uint *)(pcVar2 + 8);
      puVar4 = *(uint **)(param_2 + 0x18);
      if (*(int *)(pcVar2 + 0x10) == 8) {
        uVar9 = *puVar4;
        uVar9 = HalGetBusDataByOffset
                          (4,uVar9 >> 8 & 0xff,uVar9 >> 3 & 0x1f | (uVar9 & 7) << 5,puVar4,puVar4[1]
                           ,uVar12);
        if (uVar9 == 0) {
          uVar12 = 0xe0000001;
        }
        else if ((uVar12 == 2) || (uVar9 != 2)) {
          if (uVar12 == uVar9) {
            *puVar1 = uVar12;
            goto LAB_00011448;
          }
          uVar12 = 0xe0000004;
        }
        else {
          uVar12 = 0xe0000002;
        }
        *puVar1 = 0;
        goto LAB_0001144a;
      }
LAB_000111b1:
      uVar12 = 0xc000000d;
      goto LAB_0001144a;
    }
    if (uVar9 == 0xc35060d4) {
LAB_00011189:
      puVar3 = *(undefined4 **)(param_2 + 0x18);
      uVar12 = *(uint *)(pcVar2 + 0x10);
      uVar6 = (undefined2)*puVar3;
      if (uVar9 == 0xc35060cc) {
        uVar5 = in(uVar6);
        *(undefined1 *)puVar3 = uVar5;
      }
      else if (uVar9 == 0xc35060d0) {
        uVar6 = in(uVar6);
        *(undefined2 *)puVar3 = uVar6;
      }
      else {
        if (uVar9 != 0xc35060d4) {
          *puVar1 = 0;
          goto LAB_000111b1;
        }
        uVar7 = in(uVar6);
        *puVar3 = uVar7;
      }
      *puVar1 = uVar12;
    }
    else {
      if (uVar9 == 0xc3502000) {
        **(undefined4 **)(param_2 + 0x18) = 0x2000000;
      }
      else {
        if (uVar9 != 0xc3502004) {
          if (uVar9 == 0xc3502084) {
            uVar10 = FUN_000114bc(*(undefined4 **)(param_2 + 0x18),
                                  (ulonglong)*(uint *)(pcVar2 + 0x10),
                                  (undefined8 *)*(undefined4 **)(param_2 + 0x18),
                                  (ulonglong)*(uint *)(pcVar2 + 8),puVar1);
            uVar12 = (uint)uVar10;
            goto LAB_0001144a;
          }
          if (uVar9 == 0xc3502088) {
            uVar10 = FUN_000114f0(*(undefined4 **)(param_2 + 0x18));
            uVar12 = (uint)uVar10;
            goto LAB_0001144a;
          }
          if (uVar9 == 0xc350208c) {
            uVar10 = FUN_00011524(*(undefined4 **)(param_2 + 0x18),
                                  (ulonglong)*(uint *)(pcVar2 + 0x10),
                                  (ulonglong *)*(undefined4 **)(param_2 + 0x18),
                                  (ulonglong)*(uint *)(pcVar2 + 8),puVar1);
            uVar12 = (uint)uVar10;
            goto LAB_0001144a;
          }
          if (uVar9 == 0xc3502090) {
            do {
                    /* WARNING: Do nothing block with infinite loop */
            } while( true );
          }
          if (((uVar9 != 0xc35060c4) && (uVar9 != 0xc35060cc)) && (uVar9 != 0xc35060d0))
          goto LAB_0001144a;
          goto LAB_00011189;
        }
        **(int **)(param_2 + 0x18) = DAT_00013110;
      }
      puVar1[0] = 4;
      puVar1[1] = 0;
    }
  }
LAB_00011448:
  uVar12 = 0;
LAB_0001144a:
  *(uint *)(param_2 + 0x30) = uVar12;
  IofCompleteRequest(param_2,0);
  return uVar12;
}

