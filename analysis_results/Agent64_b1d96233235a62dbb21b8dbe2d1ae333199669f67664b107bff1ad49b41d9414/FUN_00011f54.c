// Function: FUN_00011f54
// Address: 00011f54
// Decompiled by Ghidra


void FUN_00011f54(short *param_1,undefined8 param_2,longlong param_3,undefined8 param_4,uint param_5
                 )

{
  byte bVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  ushort uVar6;
  uint uVar7;
  uint uVar8;
  undefined1 auStackY_198 [32];
  short local_158;
  short local_156;
  ulonglong local_58;
  
  local_58 = DAT_00014100 ^ (ulonglong)auStackY_198;
  uVar6 = (ushort)*(byte *)((longlong)param_1 + 0xff);
  bVar1 = *(byte *)(param_1 + 0x7f);
  sVar2 = *param_1;
  sVar3 = param_1[1];
  if (*(byte *)((longlong)param_1 + 0xff) == 0) {
    uVar6 = 0x100;
  }
  uVar7 = 0;
  do {
    uVar8 = 0;
    do {
      uVar5 = 0;
      do {
        iVar4 = FUN_000119a0(uVar7,uVar8,uVar5,0x100,(int *)&local_158);
        if (((iVar4 != 0) && (local_158 == sVar2)) && (local_156 == sVar3)) {
          if (uVar6 != 0) {
            FUN_00012960((undefined8 *)((ulonglong)bVar1 + (longlong)param_1),
                         (undefined8 *)((longlong)&local_158 + (ulonglong)bVar1),(ulonglong)uVar6);
          }
          goto LAB_00012013;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < 8);
      uVar8 = uVar8 + 1;
    } while (uVar8 < 0x20);
    uVar7 = uVar7 + 1;
    if (0xf < uVar7) {
LAB_00012013:
      *(ulonglong *)(param_3 + 0x38) = (ulonglong)param_5;
      FUN_000127f0(local_58 ^ (ulonglong)auStackY_198);
      return;
    }
  } while( true );
}

