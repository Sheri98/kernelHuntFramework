// Function: FUN_140004b54
// Address: 140004b54
// Decompiled by Ghidra


undefined8 FUN_140004b54(void)

{
  undefined8 uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar7;
  ulonglong uVar6;
  
  uVar4 = 0;
  uVar2 = uVar4;
  uVar6 = uVar4;
  do {
    uVar5 = (int)uVar6 + 1;
    uVar6 = (ulonglong)uVar5;
    *(undefined4 *)((longlong)&DAT_14000a5f8 + uVar2) = *(undefined4 *)(FUN_140004480 + uVar2);
    uVar2 = uVar2 + 4;
    uVar3 = uVar4;
    uVar7 = uVar4;
  } while (uVar5 < 8);
  do {
    uVar5 = (int)uVar7 + 1;
    *(undefined4 *)((longlong)&DAT_14000a618 + uVar3) = *(undefined4 *)(FUN_140004600 + uVar3);
    uVar3 = uVar3 + 4;
    uVar2 = uVar4;
    uVar7 = (ulonglong)uVar5;
  } while (uVar5 < 8);
  do {
    uVar5 = (int)uVar2 + 1;
    *(undefined4 *)((longlong)&DAT_14000a638 + uVar4) = *(undefined4 *)(FUN_1400049e0 + uVar4);
    uVar4 = uVar4 + 4;
    uVar2 = (ulonglong)uVar5;
  } while (uVar5 < 8);
  DAT_14000a130 = 0;
  DAT_14000a388 = 0;
  DAT_14000a3b8 = 0;
  DAT_14000a120 = 0;
  DAT_14000a128 = 0;
  DAT_14000a378 = 0;
  DAT_14000a380 = 0;
  DAT_14000a3a8 = 0;
  DAT_14000a3b0 = 0;
  KeInitializeEvent(&DAT_14000a138,0,1);
  KeInitializeEvent(&DAT_14000a390,0,1);
  KeInitializeEvent(&DAT_14000a5d0,0,1);
  PsSetCreateProcessNotifyRoutineEx(FUN_140004480,0);
  PsSetLoadImageNotifyRoutine(FUN_1400049e0);
  uVar1 = PsSetCreateThreadNotifyRoutine(FUN_140004600);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}

