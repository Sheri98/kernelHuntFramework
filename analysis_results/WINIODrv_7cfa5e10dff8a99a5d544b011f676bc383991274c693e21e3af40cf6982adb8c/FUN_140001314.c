// Function: FUN_140001314
// Address: 140001314
// Decompiled by Ghidra


void FUN_140001314(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  char *pcVar2;
  uint *puVar3;
  byte bVar4;
  ushort uVar5;
  undefined4 uVar6;
  int iVar7;
  ulonglong uVar8;
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
  
  local_28 = DAT_140003100 ^ (ulonglong)auStackY_88;
  pcVar2 = *(char **)(param_2 + 0xb8);
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  puVar3 = *(uint **)(param_2 + 0x18);
  uVar1 = *(uint *)(pcVar2 + 0x10);
  uVar8 = (ulonglong)uVar1;
  if (*pcVar2 == '\x0e') {
    iVar7 = *(int *)(pcVar2 + 0x18);
    if (iVar7 == -0x7fefdfc0) {
      if (uVar1 != 0) {
        FUN_140001680(&local_50,(undefined8 *)puVar3,uVar8);
        iVar7 = FUN_1400010d0(local_48,local_50,&local_38,&local_40,&local_30);
        if (-1 < iVar7) {
          FUN_140001680((undefined8 *)puVar3,&local_50,uVar8);
          *(ulonglong *)(param_2 + 0x38) = uVar8;
        }
        *(int *)(param_2 + 0x30) = iVar7;
        goto LAB_1400014b2;
      }
    }
    else if (iVar7 == -0x7fefdfbc) {
      if (uVar1 != 0) {
        FUN_140001680(&local_50,(undefined8 *)puVar3,uVar8);
        uVar6 = FUN_1400012c4(local_40,local_38,local_30);
        *(undefined4 *)(param_2 + 0x30) = uVar6;
        goto LAB_1400014b2;
      }
    }
    else if (iVar7 == -0x7fefdfb0) {
      if (uVar1 != 0) {
        FUN_140001680((undefined8 *)&local_58,(undefined8 *)puVar3,uVar8);
        if (local_52 == '\x01') {
          bVar4 = in(local_58);
          local_56 = (uint)bVar4;
        }
        else if (local_52 == '\x02') {
          uVar5 = in(local_58);
          local_56 = (uint)uVar5;
        }
        else if (local_52 == '\x04') {
          local_56 = in(local_58);
        }
        *puVar3 = local_56;
        *(undefined8 *)(param_2 + 0x38) = 4;
        goto LAB_1400014b2;
      }
    }
    else if ((iVar7 == -0x7fefdfac) && (uVar1 != 0)) {
      FUN_140001680((undefined8 *)&local_58,(undefined8 *)puVar3,uVar8);
      if (local_52 == '\x01') {
        out(local_58,(undefined1)local_56);
      }
      else if (local_52 == '\x02') {
        out(local_58,(undefined2)local_56);
      }
      else if (local_52 == '\x04') {
        out(local_58,local_56);
      }
      goto LAB_1400014b2;
    }
    *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
  }
LAB_1400014b2:
  IofCompleteRequest(param_2,0);
  FUN_140001570(local_28 ^ (ulonglong)auStackY_88);
  return;
}

