// Function: FUN_00011234
// Address: 00011234
// Decompiled by Ghidra


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_00011234(undefined8 param_1,ulonglong *param_2)

{
  byte *pbVar1;
  ulonglong uVar2;
  uint uVar3;
  ulonglong uVar5;
  ulonglong uVar4;
  
  uVar4 = 0;
  DAT_00013188._0_4_ = 0xf0000;
  DAT_000131cc = 0;
  DAT_000131c0 = 0;
  DAT_00013188._4_4_ = 0;
  _DAT_000131c8 = 0;
  DAT_0001319c = 0;
  DAT_00013198 = 0x8000;
  RtlInitUnicodeString(&DAT_000131a0,L"\\Device\\PhysicalMemory");
  _DAT_00013150 = &DAT_000131a0;
  _DAT_00013140 = 0x30;
  _DAT_00013148 = 0;
  _DAT_00013158 = 0x40;
  _DAT_00013160 = 0;
  _DAT_00013168 = 0;
  uVar2 = ZwOpenSection(&DAT_00013120,0xf001f,&DAT_00013140);
  DAT_000131d0 = (uint)uVar2;
  if ((int)DAT_000131d0 < 0) {
    return uVar2;
  }
  DAT_000131d0 = ObReferenceObjectByHandle(DAT_00013120,0xf001f,0,0,&DAT_00013128,0);
  if (-1 < (int)DAT_000131d0) {
    DAT_000131b8 = (ulonglong)DAT_00013198 + CONCAT44(DAT_00013188._4_4_,(undefined4)DAT_00013188);
    DAT_000131b0 = HalTranslateBusAddress
                             (DAT_000131cc,DAT_000131c0,
                              CONCAT44(DAT_00013188._4_4_,(undefined4)DAT_00013188),&DAT_0001319c,
                              &DAT_00013178);
    DAT_000131c4 = HalTranslateBusAddress
                             (DAT_000131cc,DAT_000131c0,DAT_000131b8,&DAT_000131c8,&DAT_000131b8);
    if ((DAT_000131b0 != '\0') && (DAT_000131c4 != '\0')) {
      _DAT_00013170 = DAT_000131b8 - CONCAT44(uRam000000000001317c,DAT_00013178);
      uVar3 = (uint)_DAT_00013170;
      if (uVar3 != 0) {
        DAT_00013198 = uVar3;
        if (DAT_0001319c == 0) {
          DAT_00013180 = 0;
          _DAT_00013190 = CONCAT44(uRam000000000001317c,DAT_00013178);
          DAT_000131d0 = ZwMapViewOfSection(DAT_00013120,0xffffffffffffffff,&DAT_00013180,0,
                                            _DAT_00013170 & 0xffffffff,&DAT_00013190,&DAT_00013198,1
                                            ,0,0x204);
          if ((int)DAT_000131d0 < 0) goto LAB_000114a4;
          DAT_00013180 = DAT_00013180 + (ulonglong)(DAT_00013178 - _DAT_00013190);
        }
        else {
          *param_2 = (ulonglong)DAT_00013178;
        }
        uVar2 = uVar4;
        uVar5 = uVar4;
        if (DAT_00013198 != 0) {
          do {
            pbVar1 = (byte *)(uVar5 + DAT_00013180);
            uVar3 = (int)uVar4 + 1;
            uVar4 = (ulonglong)uVar3;
            uVar5 = uVar5 + 1;
            uVar2 = (ulonglong)(byte)((byte)uVar2 ^ *pbVar1);
          } while (uVar3 < DAT_00013198);
        }
        *(char *)param_2 = (char)uVar2;
        DAT_000131d0 = ZwUnmapViewOfSection(0xffffffffffffffff,DAT_00013180);
        goto LAB_000114a4;
      }
    }
    DAT_000131d0 = 0xc0000001;
  }
LAB_000114a4:
  ZwClose(DAT_00013120);
  return (ulonglong)DAT_000131d0;
}

