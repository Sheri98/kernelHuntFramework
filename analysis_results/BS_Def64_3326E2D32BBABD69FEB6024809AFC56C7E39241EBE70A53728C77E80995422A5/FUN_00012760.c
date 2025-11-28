// Function: FUN_00012760
// Address: 00012760
// Decompiled by Ghidra


short FUN_00012760(void)

{
  bool bVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  char *pcVar6;
  ushort *puVar7;
  undefined1 *puVar8;
  uint uVar9;
  ulonglong uVar10;
  short sVar11;
  char local_f8 [16];
  int local_e8;
  undefined4 uStack_e4;
  char local_e0;
  undefined1 local_df [39];
  char local_b8;
  undefined1 local_b7 [127];
  
  bVar1 = true;
  sVar11 = 0;
  local_e8 = 0xf0000;
  uStack_e4 = 0;
  lVar3 = MmMapIoSpace(0xf0000,0xffff,0);
  if (lVar3 == 0) {
    return 0;
  }
  iVar2 = strncmp((char *)(lVar3 + 0xf400),"AMIBIOS 08",10);
  if (iVar2 == 0) {
    builtin_strncpy(local_f8,"$ASUSAMI$",9);
    local_f8[9] = 0;
    uVar4 = FUN_00012050();
    if ((char)uVar4 != '\0') {
      local_e8 = -DAT_00014000;
      uStack_e4 = 0;
      lVar5 = MmMapIoSpace(local_e8,DAT_00014000 + -1,0);
      if (lVar5 != 0) {
        uVar4 = 0;
        do {
          uVar10 = 0;
          while ((uint)*(byte *)(uVar10 + uVar4 + lVar5) == (int)local_f8[uVar10]) {
            uVar9 = (uint)uVar10 + 1;
            uVar10 = (ulonglong)uVar9;
            if (8 < uVar9) goto LAB_0001286b;
          }
          if (8 < (uint)uVar10) {
LAB_0001286b:
            sVar11 = 4;
            break;
          }
          uVar9 = (int)uVar4 + 1;
          uVar4 = (ulonglong)uVar9;
        } while (uVar9 <= DAT_00014000 - 0x10U);
        MmUnmapIoSpace(lVar5,DAT_00014000 + -1);
        if (sVar11 != 0) goto LAB_00012b15;
      }
      uVar4 = 0;
      do {
        uVar9 = 0;
        while ((uint)*(byte *)(uVar9 + uVar4 + lVar3) == (int)local_f8[uVar9]) {
          uVar9 = uVar9 + 1;
          if (8 < uVar9) goto LAB_000128af;
        }
        if (8 < uVar9) {
LAB_000128af:
          sVar11 = 4;
          goto LAB_00012b15;
        }
        uVar9 = (int)uVar4 + 1;
        uVar4 = (ulonglong)uVar9;
      } while (uVar9 < 0xfff1);
    }
  }
  builtin_strncpy(local_f8,"$ASUSAWARD",0xb);
  uVar4 = 0;
  do {
    uVar9 = 0;
    while ((uint)*(byte *)(uVar9 + uVar4 + lVar3) == (int)local_f8[uVar9]) {
      uVar9 = uVar9 + 1;
      if (9 < uVar9) goto LAB_0001293d;
    }
    if (9 < uVar9) {
LAB_0001293d:
      lVar5 = uVar4 + lVar3;
      DAT_00014050 = (int)*(char *)(lVar5 + 10) + (int)uVar4;
      DAT_00014000 = (uint)*(ushort *)(lVar5 + 0xe) << 10;
      strncpy(&DAT_00014070,(char *)((ulonglong)*(ushort *)(lVar5 + 0x10) + lVar3),100);
      sVar11 = 5;
      goto LAB_00012b15;
    }
    uVar9 = (int)uVar4 + 1;
    uVar4 = (ulonglong)uVar9;
  } while (uVar9 < 0xfff1);
  local_b8 = '\0';
  puVar8 = local_b7;
  for (lVar5 = 0x7f; lVar5 != 0; lVar5 = lVar5 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  strncpy(&local_b8,(char *)(lVar3 + 0xe0c1),0x7f);
  pcVar6 = strstr(&local_b8,"ASUS");
  if (pcVar6 != (char *)0x0) {
    local_e0 = '\0';
    puVar8 = local_df;
    for (lVar5 = 0x1f; lVar5 != 0; lVar5 = lVar5 + -1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    strncpy(&local_e0,(char *)(lVar3 + 0xe061),0x1f);
    pcVar6 = strstr(&local_e0,"Phoenix-Award");
    if ((pcVar6 != (char *)0x0) ||
       (pcVar6 = strstr(&local_e0,"Phoenix - Award"), pcVar6 != (char *)0x0)) {
      sVar11 = 2;
      goto LAB_00012b15;
    }
  }
  builtin_strncpy(local_f8,"ASUS_FLASH",0xb);
  uVar4 = 0;
  do {
    uVar9 = 0;
    while ((uint)*(byte *)(uVar9 + uVar4 + lVar3) == (int)local_f8[uVar9]) {
      uVar9 = uVar9 + 1;
      if (9 < uVar9) goto LAB_00012a90;
    }
    if (9 < uVar9) {
LAB_00012a90:
      lVar5 = uVar4 + lVar3;
      if ((0x400 < *(ushort *)(lVar5 + 0x16)) || (0x400 < *(ushort *)(lVar5 + 0x1c))) {
        bVar1 = false;
      }
      if (((uint)uVar4 < 0xfff0) && (bVar1)) {
        if (*(byte *)(lVar5 + 0xf) < 0x22) {
          sVar11 = 1;
        }
        else {
          DAT_0001404c = *(undefined2 *)(lVar5 + 0x2a);
          puVar7 = (ushort *)((ulonglong)(*(int *)(lVar5 + 0x2c) + 0x10000000) + lVar3);
          DAT_00014000 = *(int *)(puVar7 + 2);
          strncpy(&DAT_00014070,(char *)((ulonglong)*puVar7 + lVar3),100);
          sVar11 = 3;
        }
      }
      break;
    }
    uVar9 = (uint)uVar4 + 1;
    uVar4 = (ulonglong)uVar9;
  } while (uVar9 < 0xfff1);
LAB_00012b15:
  MmUnmapIoSpace(lVar3,0xffff);
  return sVar11;
}

