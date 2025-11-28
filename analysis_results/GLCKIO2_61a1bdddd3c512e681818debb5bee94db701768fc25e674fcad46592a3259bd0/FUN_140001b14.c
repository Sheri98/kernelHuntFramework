// Function: FUN_140001b14
// Address: 140001b14
// Decompiled by Ghidra


void FUN_140001b14(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  uint *puVar4;
  undefined4 *puVar5;
  byte bVar6;
  ushort uVar7;
  int iVar8;
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
  pcVar3 = *(char **)(param_2 + 0xb8);
  puVar4 = *(uint **)(param_2 + 0x18);
  iVar8 = 0;
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  uVar1 = *(uint *)(pcVar3 + 0x10);
  uVar9 = (ulonglong)uVar1;
  if (*pcVar3 == '\x02') {
    FUN_140001a74();
    goto LAB_140001d86;
  }
  if (*pcVar3 != '\x0e') goto LAB_140001d86;
  iVar2 = *(int *)(pcVar3 + 0x18);
  if (iVar2 == -0x7fefdfc0) {
    uVar11 = FUN_14000175c();
    if (((int)uVar11 < 0) || (uVar1 == 0)) goto LAB_140001c7e;
    FUN_140001f80(&local_50,(undefined8 *)puVar4,uVar9);
    iVar8 = FUN_1400017a8(local_48,local_50,&local_38,&local_40,&local_30);
    if (-1 < iVar8) {
      FUN_140001f80((undefined8 *)puVar4,&local_50,uVar9);
      *(ulonglong *)(param_2 + 0x38) = uVar9;
    }
  }
  else {
    if (iVar2 == -0x7fefdfbc) {
      uVar11 = FUN_14000175c();
      if ((-1 < (int)uVar11) && (uVar1 != 0)) {
        FUN_140001f80(&local_50,(undefined8 *)puVar4,uVar9);
        iVar8 = FUN_140001ac8(local_40,local_38,local_30);
        goto LAB_140001c83;
      }
    }
    else if (iVar2 == -0x7fefdfb0) {
      uVar11 = FUN_14000175c();
      if ((-1 < (int)uVar11) && (uVar1 != 0)) {
        FUN_140001f80((undefined8 *)&local_58,(undefined8 *)puVar4,uVar9);
        if (local_52 == '\x01') {
          bVar6 = in(local_58);
          local_56 = (uint)bVar6;
        }
        else if (local_52 == '\x02') {
          uVar7 = in(local_58);
          local_56 = (uint)uVar7;
        }
        else if (local_52 == '\x04') {
          local_56 = in(local_58);
        }
        *puVar4 = local_56;
        *(undefined8 *)(param_2 + 0x38) = 4;
        goto LAB_140001d86;
      }
    }
    else if (iVar2 == -0x7fefdfac) {
      uVar11 = FUN_14000175c();
      if ((-1 < (int)uVar11) && (uVar1 != 0)) {
        FUN_140001f80((undefined8 *)&local_58,(undefined8 *)puVar4,uVar9);
        if (local_52 == '\x01') {
          out(local_58,(undefined1)local_56);
        }
        else if (local_52 == '\x02') {
          out(local_58,(undefined2)local_56);
        }
        else if (local_52 == '\x04') {
          out(local_58,local_56);
        }
        goto LAB_140001d86;
      }
    }
    else {
      if (iVar2 != -0x7fefdfa8) {
        if (iVar2 == -0x7fefdfa4) {
          uVar9 = FUN_14000175c();
          if ((int)uVar9 < 0) goto LAB_140001c7e;
          uVar10 = FUN_140001df8(param_2,(longlong)pcVar3);
          iVar8 = (int)uVar10;
        }
        else {
          if (iVar2 != -0x7fefdfa0) {
            *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
            goto LAB_140001d86;
          }
          iVar8 = FUN_140001994(param_2,(longlong)pcVar3);
        }
        *(int *)(param_2 + 0x30) = iVar8;
        if (-1 < iVar8) {
          *(undefined8 *)(param_2 + 0x38) = 8;
        }
        goto LAB_140001d86;
      }
      uVar9 = FUN_14000175c();
      if (-1 < (int)uVar9) {
        puVar5 = *(undefined4 **)(param_2 + 0x18);
        uVar10 = rdmsr(*puVar5);
        *puVar5 = (int)uVar10;
        puVar5[1] = (int)((ulonglong)uVar10 >> 0x20);
        *(undefined8 *)(param_2 + 0x38) = 8;
        goto LAB_140001c83;
      }
    }
LAB_140001c7e:
    iVar8 = -0x3ffffff3;
  }
LAB_140001c83:
  *(int *)(param_2 + 0x30) = iVar8;
LAB_140001d86:
  IofCompleteRequest(param_2,0);
  FUN_140001e60(local_28 ^ (ulonglong)auStackY_88);
  return;
}

