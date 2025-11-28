// Function: FUN_00011170
// Address: 00011170
// Decompiled by Ghidra


void FUN_00011170(undefined8 param_1,longlong *param_2)

{
  longlong *plVar1;
  int iVar2;
  undefined1 *puVar3;
  ulonglong uVar4;
  ushort uVar5;
  undefined8 unaff_RDI;
  uint6 uVar7;
  longlong lVar6;
  undefined1 local_188 [2];
  undefined2 local_186;
  undefined1 local_178 [2];
  undefined2 local_176;
  undefined2 local_168 [80];
  undefined2 local_c8 [80];
  longlong local_28;
  
  local_28 = DAT_00013108;
  local_168[0] = 0;
  RtlInitUnicodeString(local_188,local_168);
  local_186 = 0xa0;
  RtlAppendUnicodeToString(local_188,L"\\Device\\");
  RtlAppendUnicodeToString(local_188,L"ADV64DRV");
  iVar2 = IoCreateDevice(param_1,0x18,local_188,0x22,0,0,param_2);
  uVar4 = DAT_000120a0;
  uVar7 = (uint6)((ulonglong)unaff_RDI >> 0x10);
  if (iVar2 < 0) {
    lVar6 = (ulonglong)uVar7 << 0x10;
    if (DAT_000120a0 >> 0x20 != 0) {
      lVar6 = CONCAT62(uVar7,8);
    }
    iVar2 = (int)lVar6;
    if ((int)(DAT_000120a0 >> 0x20) != 0) {
      iVar2 = (int)CONCAT62((int6)((ulonglong)lVar6 >> 0x10),(short)lVar6 + 8);
    }
    puVar3 = (undefined1 *)IoAllocateErrorLogEntry(param_1,iVar2 + 0x30);
    if (puVar3 == (undefined1 *)0x0) goto LAB_00011387;
    uVar5 = (ushort)iVar2;
    *(undefined4 *)(puVar3 + 0xc) = 0xc4f80002;
    *(undefined4 *)(puVar3 + 0x18) = 0;
    *puVar3 = 0;
    puVar3[1] = 0;
    *(undefined4 *)(puVar3 + 0x10) = 2;
    *(undefined4 *)(puVar3 + 0x14) = 0;
    *(ushort *)(puVar3 + 2) = uVar5;
    if (uVar5 != 0) {
      *(ulonglong *)(puVar3 + 0x28) = uVar4;
LAB_00011376:
      if (8 < uVar5) {
        *(ulonglong *)(puVar3 + 0x30) = uVar4;
      }
    }
  }
  else {
    plVar1 = *(longlong **)(*param_2 + 0x40);
    *plVar1 = 0;
    plVar1[1] = 0;
    plVar1[2] = 0;
    *plVar1 = *param_2;
    *(undefined8 *)(*param_2 + 8) = param_1;
    local_c8[0] = 0;
    RtlInitUnicodeString(local_178,local_c8);
    local_176 = 0xa0;
    RtlAppendUnicodeToString(local_178,L"\\DosDevices\\");
    RtlAppendUnicodeToString(local_178,L"ADV64DRV");
    iVar2 = IoCreateSymbolicLink(local_178,local_188);
    if (-1 < iVar2) goto LAB_00011387;
    IoDeleteDevice(*param_2);
    lVar6 = (ulonglong)uVar7 << 0x10;
    *param_2 = 0;
    uVar4 = DAT_000120a0;
    if (DAT_000120a0 >> 0x20 != 0) {
      lVar6 = CONCAT62(uVar7,8);
    }
    iVar2 = (int)lVar6;
    if ((int)(DAT_000120a0 >> 0x20) != 0) {
      iVar2 = (int)CONCAT62((int6)((ulonglong)lVar6 >> 0x10),(short)lVar6 + 8);
    }
    puVar3 = (undefined1 *)IoAllocateErrorLogEntry(param_1,iVar2 + 0x30);
    if (puVar3 == (undefined1 *)0x0) goto LAB_00011387;
    uVar5 = (ushort)iVar2;
    *(undefined4 *)(puVar3 + 0xc) = 0xc4f80003;
    *(undefined4 *)(puVar3 + 0x18) = 0;
    *puVar3 = 0;
    puVar3[1] = 0;
    *(undefined4 *)(puVar3 + 0x10) = 5;
    *(undefined4 *)(puVar3 + 0x14) = 0;
    *(ushort *)(puVar3 + 2) = uVar5;
    if (uVar5 != 0) {
      *(ulonglong *)(puVar3 + 0x28) = uVar4;
      goto LAB_00011376;
    }
  }
  IoWriteErrorLogEntry(puVar3);
LAB_00011387:
  FUN_000118f0(local_28);
  return;
}

