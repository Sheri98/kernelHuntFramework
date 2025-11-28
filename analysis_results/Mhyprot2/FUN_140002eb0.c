// Function: FUN_140002eb0
// Address: 140002eb0
// Decompiled by Ghidra


ulonglong FUN_140002eb0(longlong *param_1)

{
  longlong lVar1;
  uint *puVar2;
  longlong lVar3;
  int iVar4;
  ulonglong uVar5;
  longlong lVar6;
  
  if ((param_1 == (longlong *)0x0) || (*(int *)((longlong)param_1 + 0xc) == 0)) {
    uVar5 = 0;
  }
  else {
    iVar4 = (int)param_1[1];
    if (0x137 < iVar4) {
      lVar3 = 0;
      lVar6 = 0x4e0;
      do {
        lVar1 = *param_1;
        uVar5 = (ulonglong)(*(uint *)(lVar3 + 8 + lVar1) ^ *(uint *)(lVar3 + lVar1)) & 0x7fffffff ^
                *(ulonglong *)(lVar3 + lVar1);
        *(ulonglong *)(lVar3 + lVar1) =
             *(ulonglong *)(&DAT_14000a000 + (ulonglong)((uint)uVar5 & 1) * 8) ^
             *(ulonglong *)(lVar3 + 0x4e0 + lVar1) ^ uVar5 >> 1;
        lVar3 = lVar3 + 8;
      } while (lVar3 < 0x4e0);
      do {
        lVar3 = *param_1;
        uVar5 = (ulonglong)(*(uint *)(lVar6 + 8 + lVar3) ^ *(uint *)(lVar6 + lVar3)) & 0x7fffffff ^
                *(ulonglong *)(lVar6 + lVar3);
        *(ulonglong *)(lVar6 + lVar3) =
             *(ulonglong *)(&DAT_14000a000 + (ulonglong)((uint)uVar5 & 1) * 8) ^
             *(ulonglong *)(lVar6 + -0x4e0 + lVar3) ^ uVar5 >> 1;
        lVar6 = lVar6 + 8;
      } while (lVar6 < 0x9b8);
      puVar2 = (uint *)*param_1;
      uVar5 = (ulonglong)(puVar2[0x26e] ^ *puVar2) & 0x7fffffff ^ *(ulonglong *)(puVar2 + 0x26e);
      *(ulonglong *)(puVar2 + 0x26e) =
           *(ulonglong *)(&DAT_14000a000 + (ulonglong)((uint)uVar5 & 1) * 8) ^
           *(ulonglong *)(puVar2 + 0x136) ^ uVar5 >> 1;
      *(undefined4 *)(param_1 + 1) = 0;
      iVar4 = 0;
    }
    uVar5 = *(ulonglong *)(*param_1 + (longlong)iVar4 * 8);
    *(int *)(param_1 + 1) = iVar4 + 1;
    uVar5 = uVar5 ^ uVar5 >> 0x1d & 0x555555555;
    uVar5 = uVar5 ^ (uVar5 & 0x38eb3ffff6d3) << 0x11;
    uVar5 = uVar5 ^ (uVar5 & 0xffffffffffffbf77) << 0x25;
    uVar5 = uVar5 >> 0x2b ^ uVar5;
  }
  return uVar5;
}

