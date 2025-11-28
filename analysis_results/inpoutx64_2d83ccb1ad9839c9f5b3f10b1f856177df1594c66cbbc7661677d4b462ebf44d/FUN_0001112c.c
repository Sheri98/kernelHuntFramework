// Function: FUN_0001112c
// Address: 0001112c
// Decompiled by Ghidra


int FUN_0001112c(undefined8 param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined1 uVar6;
  undefined2 uVar7;
  int iVar8;
  undefined4 uVar9;
  ulonglong uVar10;
  int iVar11;
  undefined8 local_28;
  longlong local_20;
  longlong local_18;
  longlong local_10;
  
  lVar4 = *(longlong *)(param_2 + 0xb8);
  puVar5 = *(undefined8 **)(param_2 + 0x18);
  iVar1 = *(int *)(lVar4 + 0x18);
  uVar2 = *(uint *)(lVar4 + 0x10);
  uVar10 = (ulonglong)uVar2;
  uVar3 = *(uint *)(lVar4 + 8);
  iVar11 = 0;
  iVar8 = 0;
  if (iVar1 == -0x63bfdffc) {
    if ((1 < uVar2) && (uVar3 != 0)) {
      uVar6 = in(*(undefined2 *)puVar5);
      *(undefined1 *)puVar5 = uVar6;
    }
    *(undefined8 *)(param_2 + 0x38) = 1;
    goto LAB_000112e3;
  }
  if (iVar1 == -0x63bfdff8) {
    if (uVar2 < 3) {
LAB_000112c4:
      *(undefined8 *)(param_2 + 0x38) = 0;
      iVar8 = iVar11;
      goto LAB_000112e3;
    }
    out(*(undefined2 *)puVar5,*(undefined1 *)((longlong)puVar5 + 2));
  }
  else {
    if (iVar1 == -0x63bfdff4) {
      if ((1 < uVar2) && (1 < uVar3)) {
        uVar7 = in(*(undefined2 *)puVar5);
        *(undefined2 *)puVar5 = uVar7;
      }
      *(undefined8 *)(param_2 + 0x38) = 2;
      goto LAB_000112e3;
    }
    if (iVar1 == -0x63bfdff0) {
      if (uVar2 < 4) goto LAB_000112c4;
      out(*(undefined2 *)puVar5,*(undefined2 *)((longlong)puVar5 + 2));
    }
    else {
      if (iVar1 == -0x63bfdfec) {
        if ((3 < uVar2) && (3 < uVar3)) {
          uVar9 = in(*(undefined2 *)puVar5);
          *(undefined4 *)puVar5 = uVar9;
        }
        *(undefined8 *)(param_2 + 0x38) = 4;
        goto LAB_000112e3;
      }
      if (iVar1 != -0x63bfdfe8) {
        if (iVar1 == -0x63bfdfe4) {
          if (uVar2 == 0) {
LAB_0001124c:
            *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
            iVar8 = iVar11;
            goto LAB_000112e3;
          }
          FUN_000115d0(&local_28,puVar5,uVar10);
          iVar8 = FUN_00011380(local_18,local_20,&local_10,&local_28);
          if (-1 < iVar8) {
            FUN_000115d0(puVar5,&local_28,uVar10);
            *(ulonglong *)(param_2 + 0x38) = uVar10;
          }
        }
        else {
          if (iVar1 != -0x63bfdfe0) {
            *(undefined8 *)(param_2 + 0x38) = 0;
            iVar8 = -0x3fffffff;
            goto LAB_000112e3;
          }
          if (uVar2 == 0) goto LAB_0001124c;
          FUN_000115d0(&local_28,puVar5,uVar10);
          iVar8 = ZwUnmapViewOfSection(0xffffffffffffffff,local_10);
          ZwClose(local_28);
        }
        *(int *)(param_2 + 0x30) = iVar8;
        goto LAB_000112e3;
      }
      if (uVar2 < 8) goto LAB_000112c4;
      out((short)puVar5,*(undefined4 *)((longlong)puVar5 + 4));
    }
  }
  *(undefined8 *)(param_2 + 0x38) = 10;
  iVar8 = iVar11;
LAB_000112e3:
  *(int *)(param_2 + 0x30) = iVar8;
  IofCompleteRequest(param_2,0);
  return iVar8;
}

