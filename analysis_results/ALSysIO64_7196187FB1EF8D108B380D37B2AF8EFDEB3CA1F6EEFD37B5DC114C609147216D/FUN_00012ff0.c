// Function: FUN_00012ff0
// Address: 00012ff0
// Decompiled by Ghidra


ulonglong FUN_00012ff0(undefined8 *param_1)

{
  void *pvVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  uint uVar4;
  undefined8 *puVar6;
  ulonglong uVar7;
  ulonglong uVar5;
  
  uVar7 = 0;
  if (DAT_00016110 == 0) {
    *param_1 = DAT_00016148;
    param_1[1] = DAT_00016150;
    param_1[2] = DAT_00016158;
    param_1[3] = DAT_00016160;
    param_1[4] = DAT_00016168;
    return 1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  DAT_00016148 = 0;
  DAT_00016150 = 0;
  DAT_00016158 = 0;
  DAT_00016160 = 0;
  DAT_00016168 = 0;
  pvVar1 = (void *)ExAllocatePoolWithTag(0,0x1ffff,0x62696f73);
  if (pvVar1 == (void *)0x0) {
    DbgPrint("GetRsdPtr - Could not allocate buffer\n");
    return 0;
  }
  uVar2 = FUN_00012eb0(0xe0000,pvVar1,0x1ffff);
  if ((int)uVar2 != 0) {
    DbgPrint("GetRsdPtr - Could not read Bios space\n");
    ExFreePoolWithTag(pvVar1,0x62696f73);
    return 0;
  }
  DAT_00016110 = 0;
  uVar3 = uVar7;
  uVar5 = uVar7;
  while ((*(int *)(uVar3 + (longlong)pvVar1) != 0x20445352 ||
         (*(int *)(uVar3 + 4 + (longlong)pvVar1) != 0x20525450))) {
    uVar4 = (int)uVar5 + 0x10;
    uVar5 = (ulonglong)uVar4;
    uVar3 = uVar3 + 0x10;
    if (0x1fffe < uVar4) {
LAB_000131fd:
      ExFreePoolWithTag(pvVar1,0x62696f73);
      return uVar7;
    }
  }
  puVar6 = (undefined8 *)((longlong)(int)uVar5 + (longlong)pvVar1);
  if (puVar6 != (undefined8 *)0x0) {
    DAT_00016148 = *puVar6;
    DAT_00016150 = puVar6[1];
    if ((byte)((ulonglong)DAT_00016150 >> 0x38) < 2) {
      DAT_00016158 = CONCAT44(0x14,*(undefined4 *)(puVar6 + 2));
    }
    else {
      DAT_00016148 = *puVar6;
      DAT_00016150 = puVar6[1];
      DAT_00016158 = puVar6[2];
      DAT_00016160 = puVar6[3];
      DAT_00016168 = puVar6[4];
    }
    uVar7 = 1;
    *param_1 = DAT_00016148;
    param_1[1] = DAT_00016150;
    param_1[2] = DAT_00016158;
    param_1[3] = DAT_00016160;
    param_1[4] = DAT_00016168;
  }
  goto LAB_000131fd;
}

