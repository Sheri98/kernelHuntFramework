// Function: FUN_140001ac0
// Address: 140001ac0
// Decompiled by Ghidra


void FUN_140001ac0(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  char *pcVar2;
  uint *puVar3;
  undefined4 *puVar4;
  byte bVar5;
  ushort uVar6;
  int iVar7;
  undefined4 uVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  undefined1 auStackY_88 [32];
  undefined2 local_58;
  uint local_56;
  char local_52;
  longlong local_50;
  longlong local_48;
  undefined8 local_40;
  longlong local_38;
  longlong local_30;
  ulonglong local_28;
  
  local_28 = DAT_140004000 ^ (ulonglong)auStackY_88;
  pcVar2 = *(char **)(param_2 + 0xb8);
  puVar3 = *(uint **)(param_2 + 0x18);
  uVar8 = 0;
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  uVar1 = *(uint *)(pcVar2 + 0x10);
  uVar9 = (ulonglong)uVar1;
  if (*pcVar2 != '\x0e') goto LAB_140001d2d;
  iVar7 = *(int *)(pcVar2 + 0x18);
  if (iVar7 == -0x7fefdfc0) {
    uVar11 = FUN_14000175c();
    if ((-1 < (int)uVar11) && (uVar1 != 0)) {
      FUN_140001f40(&local_50,(undefined8 *)puVar3,uVar9);
      iVar7 = FUN_1400017a8(local_48,local_50,&local_38,&local_40,&local_30);
      if (-1 < iVar7) {
        FUN_140001f40((undefined8 *)puVar3,&local_50,uVar9);
        *(ulonglong *)(param_2 + 0x38) = uVar9;
      }
      *(int *)(param_2 + 0x30) = iVar7;
      goto LAB_140001d2d;
    }
LAB_140001d25:
    uVar8 = 0xc000000d;
  }
  else {
    if (iVar7 != -0x7fefdfbc) {
      if (iVar7 == -0x7fefdfb0) {
        uVar11 = FUN_14000175c();
        if ((-1 < (int)uVar11) && (uVar1 != 0)) {
          FUN_140001f40((undefined8 *)&local_58,(undefined8 *)puVar3,uVar9);
          if (local_52 == '\x01') {
            bVar5 = in(local_58);
            local_56 = (uint)bVar5;
          }
          else if (local_52 == '\x02') {
            uVar6 = in(local_58);
            local_56 = (uint)uVar6;
          }
          else if (local_52 == '\x04') {
            local_56 = in(local_58);
          }
          *puVar3 = local_56;
          *(undefined8 *)(param_2 + 0x38) = 4;
          goto LAB_140001d2d;
        }
      }
      else if (iVar7 == -0x7fefdfac) {
        uVar11 = FUN_14000175c();
        if ((-1 < (int)uVar11) && (uVar1 != 0)) {
          FUN_140001f40((undefined8 *)&local_58,(undefined8 *)puVar3,uVar9);
          if (local_52 == '\x01') {
            out(local_58,(undefined1)local_56);
          }
          else if (local_52 == '\x02') {
            out(local_58,(undefined2)local_56);
          }
          else if (local_52 == '\x04') {
            out(local_58,local_56);
          }
          goto LAB_140001d2d;
        }
      }
      else {
        if (iVar7 != -0x7fefdfa8) {
          if (iVar7 == -0x7fefdfa4) {
            uVar9 = FUN_14000175c();
            if ((int)uVar9 < 0) goto LAB_140001d25;
            uVar10 = FUN_140001da0(param_2,(longlong)pcVar2);
            iVar7 = (int)uVar10;
          }
          else {
            if (iVar7 != -0x7fefdfa0) {
              *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
              goto LAB_140001d2d;
            }
            iVar7 = FUN_140001994(param_2,(longlong)pcVar2);
          }
          *(int *)(param_2 + 0x30) = iVar7;
          if (-1 < iVar7) {
            *(undefined8 *)(param_2 + 0x38) = 8;
          }
          goto LAB_140001d2d;
        }
        uVar9 = FUN_14000175c();
        if (-1 < (int)uVar9) {
          puVar4 = *(undefined4 **)(param_2 + 0x18);
          uVar10 = rdmsr(*puVar4);
          *puVar4 = (int)uVar10;
          puVar4[1] = (int)((ulonglong)uVar10 >> 0x20);
          *(undefined8 *)(param_2 + 0x38) = 8;
          goto LAB_140001d2a;
        }
      }
      goto LAB_140001d25;
    }
    uVar11 = FUN_14000175c();
    if (((int)uVar11 < 0) || (uVar1 == 0)) goto LAB_140001d25;
    FUN_140001f40(&local_50,(undefined8 *)puVar3,uVar9);
    uVar8 = FUN_140001a74(local_40,local_38,local_30);
  }
LAB_140001d2a:
  *(undefined4 *)(param_2 + 0x30) = uVar8;
LAB_140001d2d:
  IofCompleteRequest(param_2,0);
  FUN_140001e10(local_28 ^ (ulonglong)auStackY_88);
  return;
}

