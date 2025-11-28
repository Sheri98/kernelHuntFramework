// Function: FUN_00011e48
// Address: 00011e48
// Decompiled by Ghidra


undefined8 FUN_00011e48(ulonglong *param_1,undefined8 param_2,longlong param_3)

{
  short sVar1;
  char cVar2;
  byte bVar3;
  undefined2 uVar4;
  uint uVar5;
  short sVar6;
  longlong lVar7;
  
  cVar2 = (char)*param_1;
  if (cVar2 == '\x01') {
    sVar6 = 0x1f0;
  }
  else if (cVar2 == '\x02') {
LAB_00011e88:
    sVar6 = 0x170;
  }
  else if (cVar2 == '\x03') {
    sVar6 = 0x1e8;
  }
  else {
    if (cVar2 != '\x04') goto LAB_00011e88;
    sVar6 = 0x168;
  }
  sVar1 = sVar6 + 7;
  out(sVar6 + 6,(-(*(char *)((longlong)param_1 + 1) != '\0') & 0xf0U) + 0xb0);
  out(sVar1,0xec);
  FUN_00012860(param_1,0,0x200);
  uVar5 = 0;
  lVar7 = 0xff;
  do {
    cVar2 = in(sVar1);
    if (-1 < cVar2) {
      uVar5 = 0;
      goto LAB_00011ed6;
    }
  } while (((cVar2 != '\0') && (cVar2 != -1)) && (uVar5 = uVar5 + 1, uVar5 < 320000));
  goto LAB_00011f35;
LAB_00011f0d:
  do {
    KeStallExecutionProcessor(1);
    uVar4 = in(sVar6);
    *(undefined2 *)param_1 = uVar4;
    param_1 = (ulonglong *)((longlong)param_1 + 2);
    lVar7 = lVar7 + -1;
  } while (lVar7 != 0);
  out(sVar6 + 2,8);
  out(sVar1,0x81);
  goto LAB_00011f35;
  while (((bVar3 != 0 && (bVar3 != 0xff)) && (uVar5 = uVar5 + 1, uVar5 < 320000))) {
LAB_00011ed6:
    bVar3 = in(sVar1);
    if ((bVar3 & 8) != 0) goto LAB_00011f0d;
  }
  uVar5 = 0;
  out(sVar1,0xa1);
  do {
    bVar3 = in(sVar1);
    if ((bVar3 & 8) != 0) goto LAB_00011f0d;
  } while (((bVar3 != 0) && (bVar3 != 0xff)) && (uVar5 = uVar5 + 1, uVar5 < 320000));
LAB_00011f35:
  *(undefined8 *)(param_3 + 0x38) = 0x200;
  return 0;
}

