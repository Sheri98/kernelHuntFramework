// Function: FUN_00011a50
// Address: 00011a50
// Decompiled by Ghidra


ulonglong FUN_00011a50(short *param_1)

{
  short sVar1;
  int iVar2;
  undefined1 uVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  byte bVar7;
  byte bVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  uint uVar13;
  ulonglong uVar14;
  undefined8 unaff_RBP;
  int iVar15;
  
  cVar5 = '\0';
  uVar3 = in(*param_1 + 6);
  sVar1 = *param_1;
  cVar6 = (char)param_1[1];
  iVar2 = (int)CONCAT62((int6)((ulonglong)unaff_RBP >> 0x10),sVar1);
  uVar11 = (undefined2)(iVar2 + 7U);
  cVar4 = in(uVar11);
  if ((cVar4 != -1) && (cVar4 < '\0')) {
    uVar10 = 0x80000011;
    goto LAB_00011b3b;
  }
  uVar12 = (undefined2)(iVar2 + 6U);
  out(uVar12,cVar6);
  KeStallExecutionProcessor(10,iVar2 + 6U & 0xffff);
  out((short)(iVar2 + 1),0);
  KeStallExecutionProcessor(10,iVar2 + 1);
  iVar15 = 0x1000;
  if (cVar6 != '\0') {
    do {
      cVar5 = in(uVar12);
      KeStallExecutionProcessor(10);
      iVar15 = iVar15 + -1;
      if (iVar15 == 0) goto LAB_00011b36;
    } while (cVar5 != cVar6);
  }
  cVar6 = in(uVar11);
  if ((cVar6 != -1) && (cVar6 != cVar5)) {
    cVar6 = in(uVar11);
    if (cVar6 != '\0') {
      iVar15 = 0x8000;
      do {
        uVar13 = iVar2 + 7U & 0xffff;
        cVar6 = in(uVar11);
        if (-1 < cVar6) goto LAB_00011b84;
        KeStallExecutionProcessor(100);
        iVar15 = iVar15 + -1;
      } while (iVar15 != 0);
      uVar10 = 0xc00000a3;
      goto LAB_00011b3b;
    }
    out(uVar11,8);
    KeStallExecutionProcessor(100);
    FUN_00011bc8(sVar1);
    bVar7 = in(sVar1 + 5);
    uVar13 = iVar2 + 4;
    bVar8 = in((short)uVar13);
    if ((uint)bVar8 + (uint)bVar7 * 0x100 == 0xeb14) {
LAB_00011b84:
      uVar14 = (ulonglong)CONCAT31((int3)(uVar13 >> 8),(char)param_1[1]);
      uVar9 = FUN_00011c0c(*param_1,uVar14,0xec,(undefined2 *)((longlong)param_1 + 3));
      uVar10 = uVar9 & 0xffffffff;
      if ((int)uVar9 == -0x3ffffffe) {
        uVar10 = FUN_00011c0c(*param_1,CONCAT71((int7)(uVar14 >> 8),(char)param_1[1]),0xa1,
                              (undefined2 *)((longlong)param_1 + 3));
        uVar10 = uVar10 & 0xffffffff;
      }
      goto LAB_00011b3b;
    }
  }
LAB_00011b36:
  uVar10 = 0xc000009d;
LAB_00011b3b:
  out(*param_1 + 6,uVar3);
  return uVar10;
}

