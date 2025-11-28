// Function: entry
// Address: 0001063c
// Decompiled by Ghidra


ulonglong entry(longlong param_1)

{
  short *psVar1;
  short sVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined2 *puVar6;
  undefined8 local_res18 [2];
  undefined1 local_38 [16];
  undefined1 local_28 [24];
  
  puVar6 = &DAT_00010880;
  lVar5 = 0;
  do {
    psVar1 = (short *)((longlong)&DAT_00010774 + lVar5);
    *(short *)((longlong)&DAT_00010880 + lVar5) = *psVar1;
    lVar5 = lVar5 + 2;
  } while (*psVar1 != 0);
  FUN_000103ac(&DAT_00010880,(short *)&DAT_00010980);
  RtlInitUnicodeString(local_38,puVar6);
  uVar4 = IoCreateDevice(param_1,0,local_38,0xaa01,0,0,local_res18);
  if (-1 < (int)uVar4) {
    lVar5 = 0;
    puVar6 = &DAT_00010840;
    do {
      sVar2 = *(short *)((longlong)L"\\DosDevices\\" + lVar5);
      *(short *)((longlong)&DAT_00010840 + lVar5) = sVar2;
      lVar5 = lVar5 + 2;
    } while (sVar2 != 0);
    FUN_000103ac(&DAT_00010840,(short *)&DAT_00010980);
    RtlInitUnicodeString(local_28,puVar6);
    uVar3 = IoCreateSymbolicLink(local_28,local_38);
    uVar4 = (ulonglong)uVar3;
    if ((int)uVar3 < 0) {
      IoDeleteDevice(local_res18[0]);
    }
    else {
      *(code **)(param_1 + 0x80) = FUN_000104e4;
      *(code **)(param_1 + 0x70) = FUN_000104e4;
      *(code **)(param_1 + 0xe0) = FUN_00010590;
      *(code **)(param_1 + 0x68) = FUN_0001047c;
    }
  }
  return uVar4;
}

