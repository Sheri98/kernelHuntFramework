// Function: FUN_140002a94
// Address: 140002a94
// Decompiled by Ghidra


int FUN_140002a94(longlong param_1,longlong param_2,uint param_3)

{
  uint uVar1;
  longlong lVar2;
  undefined8 *_Dst;
  undefined8 *_Dst_00;
  longlong lVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  ushort local_90 [4];
  undefined8 *local_88;
  ushort local_80 [4];
  undefined8 *local_78;
  undefined1 local_70 [56];
  
  iVar8 = 0;
  iVar7 = 0;
  uVar10 = 0;
  if (param_1 == 0) {
    iVar9 = 0;
  }
  else {
    lVar2 = PsGetProcessWow64Process();
    KeStackAttachProcess(param_1);
    iVar9 = iVar7;
    if (lVar2 == 0) {
      lVar2 = PsGetProcessPeb(param_1);
      if ((lVar2 != 0) && (*(longlong *)(lVar2 + 0x18) != 0)) {
        iVar9 = iVar8;
        for (puVar4 = *(undefined8 **)(*(longlong *)(lVar2 + 0x18) + 0x10);
            puVar4 != (undefined8 *)(*(longlong *)(lVar2 + 0x18) + 0x10);
            puVar4 = (undefined8 *)*puVar4) {
          if (uVar10 < param_3) {
            lVar3 = (ulonglong)uVar10 * 0x318;
            _Dst = (undefined8 *)(param_2 + 0xc + lVar3);
            memset(_Dst,0,0x100);
            _Dst_00 = (undefined8 *)(param_2 + 0x10c + lVar3);
            memset(_Dst_00,0,0x208);
            *(undefined8 *)(lVar3 + param_2) = puVar4[6];
            *(undefined4 *)(lVar3 + 8 + param_2) = *(undefined4 *)(puVar4 + 8);
            uVar5 = (ulonglong)*(ushort *)(puVar4 + 0xb);
            if (0x7f < *(ushort *)(puVar4 + 0xb)) {
              uVar5 = 0x7f;
            }
            FUN_1400075c0(_Dst,(undefined8 *)puVar4[0xc],uVar5);
            uVar5 = (ulonglong)*(ushort *)(puVar4 + 9);
            if (0x103 < *(ushort *)(puVar4 + 9)) {
              uVar5 = 0x103;
            }
            FUN_1400075c0(_Dst_00,(undefined8 *)puVar4[10],uVar5);
          }
          iVar9 = iVar9 + 1;
          uVar10 = uVar10 + 1;
        }
      }
    }
    else {
      lVar2 = PsGetProcessWow64Process();
      iVar9 = iVar8;
      if ((lVar2 != 0) && (iVar9 = iVar7, *(uint *)(lVar2 + 0xc) != 0)) {
        uVar1 = *(uint *)((ulonglong)*(uint *)(lVar2 + 0xc) + 0xc);
        while (puVar6 = (uint *)(ulonglong)uVar1, iVar9 = iVar8,
              puVar6 != (uint *)((ulonglong)*(uint *)(lVar2 + 0xc) + 0xc)) {
          FUN_140002e2c((short *)local_80,(short *)(ulonglong)puVar6[10]);
          FUN_140002e2c((short *)local_90,(short *)(ulonglong)puVar6[0xc]);
          if (uVar10 < param_3) {
            lVar3 = (ulonglong)uVar10 * 0x318;
            memset((void *)(lVar3 + param_2 + 0xc),0,0x100);
            memset((void *)(param_2 + lVar3 + 0x10c),0,0x208);
            *(ulonglong *)(lVar3 + param_2) = (ulonglong)puVar6[6];
            *(uint *)(lVar3 + 8 + param_2) = puVar6[8];
            uVar1 = 0x7f;
            if (local_90[0] < 0x80) {
              uVar1 = (uint)local_90[0];
            }
            FUN_1400075c0((undefined8 *)(lVar3 + param_2 + 0xc),local_88,(ulonglong)uVar1);
            uVar1 = 0x103;
            if (local_80[0] < 0x104) {
              uVar1 = (uint)local_80[0];
            }
            FUN_1400075c0((undefined8 *)(param_2 + lVar3 + 0x10c),local_78,(ulonglong)uVar1);
          }
          iVar8 = iVar8 + 1;
          uVar10 = uVar10 + 1;
          uVar1 = *puVar6;
        }
      }
    }
    KeUnstackDetachProcess(local_70);
  }
  return iVar9;
}

