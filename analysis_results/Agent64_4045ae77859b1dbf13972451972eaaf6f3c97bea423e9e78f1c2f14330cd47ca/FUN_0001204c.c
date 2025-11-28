// Function: FUN_0001204c
// Address: 0001204c
// Decompiled by Ghidra


void FUN_0001204c(short *param_1,undefined8 param_2,longlong param_3)

{
  byte bVar1;
  undefined1 uVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  ushort uVar9;
  uint uVar10;
  uint uVar11;
  undefined1 *puVar12;
  undefined1 auStackY_198 [32];
  short local_158;
  short local_156;
  ulonglong local_58;
  
  local_58 = DAT_00014100 ^ (ulonglong)auStackY_198;
  uVar9 = (ushort)*(byte *)((longlong)param_1 + 0xff);
  bVar1 = *(byte *)(param_1 + 0x7f);
  sVar3 = *param_1;
  sVar4 = param_1[1];
  if (*(byte *)((longlong)param_1 + 0xff) == 0) {
    uVar9 = 0x100;
  }
  uVar8 = 0;
  do {
    uVar10 = 0;
    do {
      uVar11 = 0;
      do {
        iVar5 = FUN_000119a0(uVar8,uVar10,uVar11,0x100,(int *)&local_158);
        if (((iVar5 != 0) && (local_158 == sVar3)) && (local_156 == sVar4)) {
          uVar7 = 0;
          in(0xcf8);
          if (uVar9 != 0) {
            puVar12 = (undefined1 *)((ulonglong)(ushort)bVar1 + (longlong)param_1);
            do {
              uVar6 = uVar7 + (ushort)bVar1;
              uVar7 = uVar7 + 1;
              out(0xcf8,uVar6 | (((uVar8 & 0xf | 0xffff8000) << 5 | uVar10 & 0x1f) << 3 | uVar11 & 7
                                ) << 8);
              uVar2 = *puVar12;
              puVar12 = puVar12 + 1;
              out(0xcfc,uVar2);
            } while (uVar7 < uVar9);
          }
          goto LAB_00012142;
        }
        uVar11 = uVar11 + 1;
      } while (uVar11 < 8);
      uVar10 = uVar10 + 1;
    } while (uVar10 < 0x20);
    uVar8 = uVar8 + 1;
    if (0xf < uVar8) {
LAB_00012142:
      *(undefined8 *)(param_3 + 0x38) = 0;
      FUN_000127f0(local_58 ^ (ulonglong)auStackY_198);
      return;
    }
  } while( true );
}

