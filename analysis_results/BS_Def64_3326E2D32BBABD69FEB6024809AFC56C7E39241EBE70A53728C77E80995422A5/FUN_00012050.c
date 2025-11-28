// Function: FUN_00012050
// Address: 00012050
// Decompiled by Ghidra


ulonglong FUN_00012050(void)

{
  ulonglong uVar1;
  undefined8 uVar2;
  longlong lVar3;
  byte bVar4;
  ulonglong uVar5;
  ushort *puVar6;
  char cVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  uint uVar10;
  char local_60 [32];
  
  builtin_strncpy(local_60,"$ASF",5);
  builtin_strncpy(local_60 + 5,"$AAF",5);
  builtin_strncpy(local_60 + 10,"$FSC",5);
  builtin_strncpy(local_60 + 0xf,"$AAP",5);
  cVar7 = '\0';
  uVar1 = MmMapIoSpace(0xe0000,0x1ffff,0);
  if (uVar1 != 0) {
    uVar9 = 0;
    do {
      if (cVar7 != '\0') break;
      uVar8 = 0;
      do {
        uVar5 = 0;
        while (*(char *)(uVar8 + uVar5 + uVar1) == local_60[uVar5 + uVar9 * 5]) {
          bVar4 = (byte)uVar5 + 1;
          uVar5 = (ulonglong)bVar4;
          if (3 < bVar4) goto LAB_0001214b;
        }
        if (3 < (byte)uVar5) {
LAB_0001214b:
          lVar3 = uVar8 + uVar1;
          DAT_0001404c = *(undefined2 *)(lVar3 + 0xc);
          DAT_00014050 = (int)*(char *)(lVar3 + 4) + (int)uVar8;
          puVar6 = (ushort *)
                   ((((*(uint *)(lVar3 + 8) >> 0xc & 0xffff0) - 0xe0000) +
                    (*(uint *)(lVar3 + 8) & 0xffff)) + uVar1);
          DAT_00014058 = *(undefined4 *)(puVar6 + 2);
          DAT_0001405c = *(undefined4 *)(puVar6 + 4);
          uVar8 = (ulonglong)*puVar6;
          DAT_00014000 = (uint)*(ushort *)(uVar8 + 0x10006 + uVar1) << 10;
          strncpy(&DAT_00014070,
                  (char *)((ulonglong)*(ushort *)(uVar8 + 0x10008 + uVar1) + 0x10000 + uVar1),100);
          DAT_00014054 = *(undefined2 *)(uVar8 + 0x1000a + uVar1);
          cVar7 = '\x01';
          break;
        }
        uVar10 = (int)uVar8 + 1;
        uVar8 = (ulonglong)uVar10;
      } while (uVar10 < 0x1fff0);
      bVar4 = (char)uVar9 + 1;
      uVar9 = (ulonglong)bVar4;
    } while (bVar4 < 4);
    uVar2 = MmUnmapIoSpace(uVar1,0x1ffff);
    uVar1 = CONCAT71((int7)((ulonglong)uVar2 >> 8),cVar7);
  }
  return uVar1;
}

