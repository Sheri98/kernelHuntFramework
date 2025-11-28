// Function: FUN_000124a0
// Address: 000124a0
// Decompiled by Ghidra


undefined8 FUN_000124a0(ulonglong *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  ulonglong *puVar4;
  uint *puVar5;
  ulonglong uVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 *puVar10;
  uint local_res10;
  undefined4 uStackX_14;
  undefined1 local_98 [8];
  undefined8 local_90;
  ulonglong local_88;
  undefined4 local_80;
  wchar_t *local_78;
  undefined4 *local_70;
  undefined4 *puVar9;
  
  FUN_000126f0(param_1,0,0x20);
  RtlInitUnicodeString(local_98);
  FUN_000126f0(&local_88,0,0x70);
  local_78 = L".Translated";
  local_80 = 0x24;
  puVar2 = (undefined4 *)ExAllocatePoolWithTag(1,0x400,0x7265736c);
  *puVar2 = 0x400;
  puVar10 = (undefined4 *)0x0;
  local_70 = puVar2;
  iVar1 = RtlQueryRegistryValues(0,local_90,&local_88,0,0);
  if (iVar1 != 0) {
    ExFreePoolWithTag(puVar2,0);
    puVar2 = puVar10;
  }
  if (puVar2 == (undefined4 *)0x0) {
    uVar3 = 0xc0000001;
  }
  else {
    uVar6 = CONCAT44(uStackX_14,local_res10);
    if (puVar2[2] != 0) {
      puVar5 = puVar2 + 6;
      puVar7 = puVar10;
      do {
        if (*puVar5 != 0) {
          puVar4 = (ulonglong *)(puVar5 + 2);
          puVar9 = puVar10;
          do {
            if ((*(char *)((longlong)puVar4 + -4) == '\x03') &&
               (*(short *)((longlong)puVar4 + -2) == 0)) {
              if (*(uint *)((longlong)puVar4 + 4) == 0) {
                *(uint *)(param_1 + 3) = (int)param_1[3] + (uint)puVar4[1];
                if (*(uint *)((longlong)param_1 + 0x1c) < (uint)*puVar4) {
                  *(uint *)((longlong)param_1 + 0x1c) = (uint)*puVar4;
                  local_res10 = (uint)puVar4[1];
                }
              }
              else {
                param_1[1] = param_1[1] + (ulonglong)(uint)puVar4[1];
                if (param_1[2] < *puVar4) {
                  param_1[2] = *puVar4;
                  uVar6 = (ulonglong)(uint)puVar4[1];
                }
              }
              *param_1 = *param_1 + (ulonglong)(uint)puVar4[1];
            }
            uVar8 = (int)puVar9 + 1;
            puVar9 = (undefined4 *)(ulonglong)uVar8;
            puVar4 = (ulonglong *)((longlong)puVar4 + 0x14);
          } while (uVar8 < *puVar5);
        }
        uVar8 = (int)puVar7 + 1;
        puVar7 = (undefined4 *)(ulonglong)uVar8;
        puVar5 = puVar5 + 9;
      } while (uVar8 < (uint)puVar2[2]);
    }
    ExFreePoolWithTag(puVar2,0);
    param_1[2] = param_1[2] + uVar6;
    *(int *)((longlong)param_1 + 0x1c) = *(int *)((longlong)param_1 + 0x1c) + local_res10;
    uVar3 = 0;
  }
  return uVar3;
}

