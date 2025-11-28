// Function: FUN_00011000
// Address: 00011000
// Decompiled by Ghidra


/* WARNING: Removing unreachable block (ram,0x00011863) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00011000(undefined8 param_1,ulonglong param_2)

{
  uint uVar1;
  char *pcVar2;
  uint *puVar3;
  byte bVar4;
  ushort uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint *puVar9;
  longlong lVar10;
  undefined2 uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  undefined8 in_CR0;
  undefined8 in_CR2;
  undefined8 in_CR3;
  
  uVar13 = 0;
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  pcVar2 = *(char **)(param_2 + 0xb8);
  puVar3 = *(uint **)(param_2 + 0x18);
  uVar12 = param_2;
  if (*pcVar2 == '\x0e') {
    uVar12 = 0x1106d;
    switch(*(undefined4 *)(pcVar2 + 0x18)) {
    case 0x9c402400:
      if ((*(uint *)(pcVar2 + 8) < 8) || (*(uint *)(pcVar2 + 0x10) < 4)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        uVar13 = rdmsr(*puVar3);
        uVar12 = uVar13 >> 0x20;
        *puVar3 = (uint)uVar13;
        puVar3[1] = (uint)(uVar13 >> 0x20);
        *(undefined8 *)(param_2 + 0x38) = 8;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    default:
      uVar12 = 0x1106d;
      *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
      break;
    case 0x9c402404:
      if ((*(uint *)(pcVar2 + 8) < 8) || (*(uint *)(pcVar2 + 0x10) < 4)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        uVar12 = CONCAT62(1,(short)*puVar3);
        bVar4 = in((short)*puVar3);
        *puVar3 = (uint)bVar4;
        puVar3[1] = 0x87654321;
        *(undefined8 *)(param_2 + 0x38) = 8;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c402408:
      if ((*(uint *)(pcVar2 + 8) < 8) || (*(uint *)(pcVar2 + 0x10) < 8)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        uVar12 = CONCAT62(1,(short)*puVar3);
        out((short)*puVar3,(char)puVar3[1]);
        *puVar3 = 0x87654321;
        puVar3[1] = 0x87654321;
        *(undefined8 *)(param_2 + 0x38) = 8;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c40240c:
      if ((*(uint *)(pcVar2 + 8) < 8) || (*(uint *)(pcVar2 + 0x10) < 4)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        uVar12 = CONCAT62(1,(short)*puVar3);
        uVar5 = in((short)*puVar3);
        *puVar3 = (uint)uVar5;
        puVar3[1] = 0x87654321;
        *(undefined8 *)(param_2 + 0x38) = 8;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c402410:
      if ((*(uint *)(pcVar2 + 8) < 8) || (*(uint *)(pcVar2 + 0x10) < 8)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        uVar12 = CONCAT62(1,(short)*puVar3);
        out((short)*puVar3,(short)puVar3[1]);
        *puVar3 = 0x87654321;
        puVar3[1] = 0x87654321;
        *(undefined8 *)(param_2 + 0x38) = 8;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c402414:
      if ((*(uint *)(pcVar2 + 8) < 8) || (*(uint *)(pcVar2 + 0x10) < 4)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        uVar12 = CONCAT62(1,(short)*puVar3);
        uVar8 = in((short)*puVar3);
        *puVar3 = uVar8;
        puVar3[1] = 0x87654321;
        *(undefined8 *)(param_2 + 0x38) = 8;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c402418:
      if ((*(uint *)(pcVar2 + 8) < 8) || (*(uint *)(pcVar2 + 0x10) < 8)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        uVar12 = CONCAT62(1,(short)*puVar3);
        out((short)*puVar3,puVar3[1]);
        *puVar3 = 0x87654321;
        puVar3[1] = 0x87654321;
        *(undefined8 *)(param_2 + 0x38) = 8;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c402420:
      if ((*(uint *)(pcVar2 + 8) < 8) || (*(uint *)(pcVar2 + 0x10) < 0x10)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        uVar8 = puVar3[2];
        uVar1 = puVar3[3];
        lVar10 = MmMapIoSpace(CONCAT44(*puVar3,puVar3[1]),uVar8,0);
        while (uVar6 = (uint)uVar13, uVar6 < uVar8) {
          *(undefined1 *)(longlong)(int)(uVar6 + uVar1) = *(undefined1 *)(uVar13 + lVar10);
          uVar13 = (ulonglong)(uVar6 + 1);
        }
        *puVar3 = uVar8;
        puVar3[1] = uVar1;
        uVar12 = (ulonglong)uVar8;
        MmUnmapIoSpace(lVar10,uVar12);
        *(undefined8 *)(param_2 + 0x38) = 8;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c402424:
      if ((*(uint *)(pcVar2 + 8) < 8) || (*(uint *)(pcVar2 + 0x10) < 0xc)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        uVar8 = puVar3[1];
        uVar12 = (ulonglong)uVar8;
        wrmsr(*puVar3,CONCAT44(uVar8,puVar3[2]));
        *puVar3 = puVar3[2];
        puVar3[1] = uVar8;
        *(undefined8 *)(param_2 + 0x38) = 8;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c402428:
      if ((*(uint *)(pcVar2 + 8) < 8) || (*(uint *)(pcVar2 + 0x10) < 4)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        uVar8 = *puVar3;
        if (uVar8 == 0) {
          *puVar3 = (uint)in_CR0;
          puVar3[1] = (uint)((ulonglong)in_CR0 >> 0x20);
          *(undefined8 *)(param_2 + 0x38) = 8;
          *(undefined4 *)(param_2 + 0x30) = 0;
        }
        else if (uVar8 == 2) {
          *puVar3 = (uint)in_CR2;
          puVar3[1] = (uint)((ulonglong)in_CR2 >> 0x20);
          *(undefined8 *)(param_2 + 0x38) = 8;
          *(undefined4 *)(param_2 + 0x30) = 0;
        }
        else if (uVar8 == 3) {
          *puVar3 = (uint)in_CR3;
          puVar3[1] = (uint)((ulonglong)in_CR3 >> 0x20);
          *(undefined8 *)(param_2 + 0x38) = 8;
          *(undefined4 *)(param_2 + 0x30) = 0;
        }
        else {
          *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
        }
      }
      break;
    case 0x9c40242c:
      if ((*(uint *)(pcVar2 + 8) < 8) || (*(uint *)(pcVar2 + 0x10) < 0xc)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        uVar12 = (ulonglong)puVar3[1];
        if (*puVar3 == 0) {
          *(undefined8 *)(param_2 + 0x38) = 8;
          *(undefined4 *)(param_2 + 0x30) = 0;
        }
        else if (*puVar3 == 3) {
          *(undefined8 *)(param_2 + 0x38) = 8;
          *(undefined4 *)(param_2 + 0x30) = 0;
        }
        else {
          *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
        }
      }
      break;
    case 0x9c402430:
      if ((*(uint *)(pcVar2 + 8) < 8) || (*(uint *)(pcVar2 + 0x10) < 0xc)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        uVar8 = puVar3[2];
        puVar9 = (uint *)MmMapIoSpace(CONCAT44(*puVar3,puVar3[1]),4,0);
        *puVar9 = uVar8;
        *puVar3 = uVar8;
        puVar3[1] = uVar8;
        uVar12 = 0;
        MmUnmapIoSpace(puVar9,4);
        *(undefined8 *)(param_2 + 0x38) = 8;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c402438:
      if (*(uint *)(pcVar2 + 8) < 4) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        *puVar3 = 0x128;
        *(undefined8 *)(param_2 + 0x38) = 4;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c40243c:
      if ((7 < *(uint *)(pcVar2 + 8)) && (7 < *(uint *)(pcVar2 + 0x10))) {
        uVar8 = *puVar3;
        lVar10 = MmMapIoSpace(puVar3[1] + 0x300,0x100,0);
        uVar1 = *(uint *)(lVar10 + 0x20);
        *(uint *)(lVar10 + 0x20) = uVar1 & 0xfffdffff;
        uVar7 = *(undefined4 *)(lVar10 + 0xe0);
        *(undefined4 *)(lVar10 + 0xe0) = 2;
        *(undefined4 *)(lVar10 + 0x80) = 0xffffffff;
        uVar11 = (undefined2)uVar8;
        uVar8 = in(uVar11);
        do {
          uVar6 = in(uVar11);
          uVar6 = uVar6 & 0xffffff;
          if (uVar6 < (uVar8 & 0xffffff)) {
            uVar6 = uVar6 + 0xffffff;
          }
        } while (uVar6 - (uVar8 & 0xffffff) < 15000);
        in(uVar11);
        *(undefined4 *)(lVar10 + 0xe0) = uVar7;
        *(uint *)(lVar10 + 0x20) = uVar1;
                    /* WARNING: Could not recover jumptable at 0x000117e9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar7 = (*(code *)(&DAT_000117eb + DAT_00011b24))();
        return uVar7;
      }
      *(undefined8 *)(param_2 + 0x38) = 0;
      *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      break;
    case 0x9c402448:
      if ((*(uint *)(pcVar2 + 8) < 4) || (*(uint *)(pcVar2 + 0x10) < 0x18)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        uVar12 = (ulonglong)*puVar3;
        uVar8 = HalGetBusDataByOffset
                          (4,uVar12,puVar3[1] & 0x1f ^ (puVar3[2] & 7) << 5,(longlong)(int)puVar3[5]
                           ,puVar3[3],puVar3[4]);
        *puVar3 = uVar8;
        *(undefined8 *)(param_2 + 0x38) = 4;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      break;
    case 0x9c40244c:
      if ((*(uint *)(pcVar2 + 8) < 4) || (*(uint *)(pcVar2 + 0x10) < 0x18)) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
      }
      else {
        uVar12 = (ulonglong)*puVar3;
        uVar8 = HalSetBusDataByOffset
                          (4,uVar12,puVar3[1] & 0x1f ^ (puVar3[2] & 7) << 5,(longlong)(int)puVar3[5]
                           ,puVar3[3],puVar3[4]);
        *puVar3 = uVar8;
        *(undefined8 *)(param_2 + 0x38) = 4;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
    }
  }
  uVar7 = *(undefined4 *)(param_2 + 0x30);
  IofCompleteRequest(param_2,uVar12 & 0xffffffffffffff00);
  return uVar7;
}

