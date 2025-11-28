// Function: FUN_000110e4
// Address: 000110e4
// Decompiled by Ghidra


undefined4 FUN_000110e4(longlong param_1,longlong param_2)

{
  short sVar1;
  int iVar2;
  char *pcVar3;
  undefined2 *puVar4;
  ulonglong uVar5;
  char cVar6;
  ushort uVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  uint uVar10;
  
  pcVar3 = *(char **)(param_2 + 0xb8);
  *(undefined8 *)(param_2 + 0x38) = 0;
  uVar8 = 0xc0000002;
  if ((*pcVar3 != '\0') && (*pcVar3 != '\x02')) {
    if (*pcVar3 != '\x0e') goto LAB_000111f9;
    iVar2 = *(int *)(pcVar3 + 0x18);
    if (iVar2 == -0x63bfda80) {
      uVar9 = FUN_00011344(*(undefined8 *)(param_1 + 0x40),param_2,(longlong)pcVar3);
      uVar8 = (undefined4)uVar9;
      goto LAB_000111f9;
    }
    if (iVar2 == -0x63bfda7c) {
      iVar2 = *(int *)(pcVar3 + 0x10);
      *(undefined8 *)(param_2 + 0x38) = 0;
      if (iVar2 == 0x18) {
        uVar5 = *(ulonglong *)(*(longlong *)(param_2 + 0x18) + 8);
        DbgPrint("(UMMAPMEM) Unmap Addr %I64x [%x,%x]\n",uVar5,
                 *(undefined4 *)(*(longlong *)(param_2 + 0x18) + 0xc),uVar5 & 0xffffffff);
        uVar8 = ZwUnmapViewOfSection(0xffffffffffffffff,uVar5);
      }
      else {
        DbgPrint("(UMMAPMEM) Insufficient input or output buffer\n");
        uVar8 = 0xc000009a;
      }
      goto LAB_000111f9;
    }
    if (iVar2 == -0x63bfda78) {
      uVar9 = FUN_00011640(*(undefined8 *)(param_1 + 0x40),param_2,(longlong)pcVar3);
      uVar8 = (undefined4)uVar9;
      goto LAB_000111f9;
    }
    if (iVar2 != -0x63bfda74) {
      if (((iVar2 != -0x63bfda70) || (*(int *)(pcVar3 + 0x10) != *(int *)(pcVar3 + 8))) ||
         (*(int *)(pcVar3 + 8) != 0xc)) {
LAB_00011219:
        uVar8 = 0xc000000d;
        goto LAB_000111f9;
      }
      puVar4 = *(undefined2 **)(param_2 + 0x18);
      *(undefined8 *)(param_2 + 0x38) = 0;
      sVar1 = puVar4[5];
      if (sVar1 == 1) {
        if (puVar4[4] == 0) {
          cVar6 = in(*puVar4);
          uVar10 = (uint)cVar6;
LAB_000111e4:
          *(uint *)(puVar4 + 2) = uVar10;
        }
        else {
          out(*puVar4,*(undefined1 *)(puVar4 + 2));
        }
      }
      else if (sVar1 == 2) {
        if (puVar4[4] == 0) {
          uVar7 = in(*puVar4);
          uVar10 = (uint)uVar7;
          goto LAB_000111e4;
        }
        out(*puVar4,puVar4[2]);
      }
      else {
        if (sVar1 != 4) goto LAB_00011219;
        if (puVar4[4] == 0) {
          uVar8 = in(*puVar4);
          *(undefined4 *)(puVar4 + 2) = uVar8;
        }
        else {
          out(*puVar4,*(undefined4 *)(puVar4 + 2));
        }
      }
      *(undefined8 *)(param_2 + 0x38) = 0xc;
      goto LAB_000111f7;
    }
    *(undefined8 *)(param_2 + 0x38) = 0;
    if (DAT_00013118 == 0) {
      if (DAT_00013120 != 0) goto LAB_0001126b;
      if (DAT_00013110 == 0) {
        uVar8 = 0xc0000001;
        goto LAB_000111f9;
      }
LAB_00011277:
      MmFreeContiguousMemory();
    }
    else {
      if (DAT_00013120 != 0) {
        MmUnmapLockedPages();
        IoFreeMdl(DAT_00013118);
      }
LAB_0001126b:
      if (DAT_00013110 != 0) goto LAB_00011277;
    }
    DAT_00013118 = 0;
    DAT_00013120 = 0;
    DAT_00013110 = 0;
  }
LAB_000111f7:
  uVar8 = 0;
LAB_000111f9:
  *(undefined4 *)(param_2 + 0x30) = uVar8;
  IofCompleteRequest(param_2,0);
  return uVar8;
}

