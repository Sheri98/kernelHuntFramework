// Function: FUN_00011590
// Address: 00011590
// Decompiled by Ghidra


undefined8 FUN_00011590(void)

{
  char cVar1;
  ushort uVar2;
  ulonglong uVar3;
  longlong lVar4;
  char *pcVar5;
  uint uVar6;
  int iVar8;
  ulonglong uVar9;
  undefined1 *puVar10;
  char local_48 [48];
  ulonglong uVar7;
  
  iVar8 = -DAT_00014000;
  builtin_strncpy(local_48,"KAFLASH",8);
  local_48[0x10] = 0;
  pcVar5 = local_48 + 0x11;
  for (lVar4 = 0x13; lVar4 != 0; lVar4 = lVar4 + -1) {
    *pcVar5 = '\0';
    pcVar5 = pcVar5 + 1;
  }
  local_48[8] = '\0';
  local_48[9] = '\0';
  local_48[10] = '\x0f';
  local_48[0xb] = '\0';
  uVar9 = 0;
  local_48[0xc] = '\0';
  local_48[0xd] = '\0';
  local_48[0xe] = '\0';
  local_48[0xf] = '\0';
  lVar4 = MmMapIoSpace(0xf0000,0xffff,0);
  uVar3 = uVar9;
  if (lVar4 == 0) {
    return 0;
  }
  while( true ) {
    uVar7 = uVar9;
    while (*(char *)(uVar3 + uVar7 + lVar4) == local_48[uVar7]) {
      uVar6 = (uint)uVar7 + 1;
      uVar7 = (ulonglong)uVar6;
      if (6 < uVar6) goto LAB_00011638;
    }
    if (6 < (uint)uVar7) break;
    uVar6 = (int)uVar3 + 1;
    uVar3 = (ulonglong)uVar6;
    if (0xffdf < uVar6) goto LAB_00011663;
  }
LAB_00011638:
  pcVar5 = (char *)((ulonglong)*(ushort *)(uVar3 + 0xe + lVar4) + lVar4);
  uVar2 = *(ushort *)(uVar3 + 0xe + lVar4);
  do {
    cVar1 = *pcVar5;
    pcVar5[(longlong)(local_48 + (-lVar4 - (ulonglong)uVar2) + 0x10)] = cVar1;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
LAB_00011663:
  uVar3 = MmUnmapIoSpace(lVar4,0xffff);
  puVar10 = (undefined1 *)((ulonglong)DAT_00014050 + DAT_00014040);
  while (local_48[0x10] != 0) {
    if (local_48[uVar9 + 0x11] != 0) {
      uVar3 = (ulonglong)(byte)local_48[uVar9 + 0x11];
      do {
        *puVar10 = 2;
        *(int *)(puVar10 + 5) = iVar8;
        *(uint *)(puVar10 + 9) = (uint)(byte)local_48[0x10] * 0x400;
        out(DAT_0001404c,0x7f);
        out(0xe1,0);
        iVar8 = iVar8 + (uint)(byte)local_48[0x10] * 0x400;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
    uVar3 = (ulonglong)((int)uVar9 + 2);
    uVar9 = uVar3;
    local_48[0x10] = local_48[uVar3 + 0x10];
  }
  return CONCAT71((int7)(uVar3 >> 8),1);
}

