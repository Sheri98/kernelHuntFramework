// Function: FUN_000112f0
// Address: 000112f0
// Decompiled by Ghidra


int FUN_000112f0(undefined8 param_1,longlong param_2)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 *puVar5;
  int iVar6;
  undefined1 uVar7;
  undefined2 uVar8;
  undefined4 uVar9;
  int iVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  undefined8 local_38;
  longlong local_30;
  longlong local_28;
  longlong local_20 [2];
  
  lVar4 = *(longlong *)(param_2 + 0xb8);
  uVar2 = *(uint *)(lVar4 + 8);
  uVar3 = *(uint *)(lVar4 + 0x10);
  uVar12 = (ulonglong)uVar3;
  puVar5 = *(undefined8 **)(param_2 + 0x18);
  iVar10 = 0;
  iVar6 = 0;
  switch(*(undefined4 *)(lVar4 + 0x18)) {
  case 0x9c402004:
    if ((1 < uVar3) && (uVar2 != 0)) {
      uVar7 = in(*(undefined2 *)puVar5);
      *(undefined1 *)puVar5 = uVar7;
    }
    *(undefined8 *)(param_2 + 0x38) = 1;
    goto LAB_000114ac;
  default:
    iVar6 = -0x3fffffff;
    break;
  case 0x9c402008:
    if (2 < uVar3) {
      uVar8 = *(undefined2 *)puVar5;
      uVar7 = *(undefined1 *)((longlong)puVar5 + 2);
      *(undefined8 *)(param_2 + 0x38) = 10;
      out(uVar8,uVar7);
      goto LAB_000114ac;
    }
    break;
  case 0x9c40200c:
    if ((1 < uVar3) && (1 < uVar2)) {
      uVar8 = in(*(undefined2 *)puVar5);
      *(undefined2 *)puVar5 = uVar8;
    }
    *(undefined8 *)(param_2 + 0x38) = 2;
    goto LAB_000114ac;
  case 0x9c402010:
    if (3 < uVar3) {
      uVar8 = *(undefined2 *)puVar5;
      uVar1 = *(undefined2 *)((longlong)puVar5 + 2);
      *(undefined8 *)(param_2 + 0x38) = 10;
      out(uVar8,uVar1);
      goto LAB_000114ac;
    }
    break;
  case 0x9c402014:
    if ((3 < uVar3) && (3 < uVar2)) {
      uVar9 = in(*(undefined2 *)puVar5);
      *(undefined4 *)puVar5 = uVar9;
    }
    *(undefined8 *)(param_2 + 0x38) = 4;
    goto LAB_000114ac;
  case 0x9c402018:
    iVar6 = 0;
    if (7 < uVar3) {
      uVar9 = *(undefined4 *)((longlong)puVar5 + 4);
      *(undefined8 *)(param_2 + 0x38) = 10;
      out((short)puVar5,uVar9);
      goto LAB_000114ac;
    }
    break;
  case 0x9c40201c:
    if (uVar3 != 0) {
      FUN_000116b0(&local_38,puVar5,uVar12);
      uVar11 = FUN_000110e0(local_28,local_30,local_20,&local_38);
      iVar10 = (int)uVar11;
      if (-1 < iVar10) {
        FUN_000116b0(puVar5,&local_38,uVar12);
        *(ulonglong *)(param_2 + 0x38) = uVar12;
      }
      *(int *)(param_2 + 0x30) = iVar10;
      goto LAB_000114ac;
    }
    goto LAB_0001149a;
  case 0x9c402020:
    if (uVar3 != 0) {
      FUN_000116b0(&local_38,puVar5,uVar12);
      iVar10 = ZwUnmapViewOfSection(0xffffffffffffffff,local_20[0]);
      ZwClose(local_38);
      *(int *)(param_2 + 0x30) = iVar10;
      goto LAB_000114ac;
    }
LAB_0001149a:
    *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
    goto LAB_000114ac;
  }
  iVar10 = iVar6;
  *(undefined8 *)(param_2 + 0x38) = 0;
LAB_000114ac:
  *(int *)(param_2 + 0x30) = iVar10;
  IofCompleteRequest(param_2,0);
  return iVar10;
}

