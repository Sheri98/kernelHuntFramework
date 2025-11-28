// Function: FUN_14000d6e0
// Address: 14000d6e0
// Decompiled by Ghidra


/* WARNING: Removing unreachable block (ram,0x00014000da21) */
/* WARNING: Removing unreachable block (ram,0x00014000da30) */
/* WARNING: Removing unreachable block (ram,0x00014000da34) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_14000d6e0(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  uint uVar2;
  int extraout_EAX;
  undefined8 uVar3;
  longlong lVar4;
  ulonglong *puVar5;
  ulonglong uVar6;
  int iVar7;
  ulonglong uVar9;
  undefined8 local_198 [48];
  ulonglong *puVar8;
  
  lVar4 = *(longlong *)(param_2 + 0xb8);
  puVar8 = *(ulonglong **)(param_2 + 0x18);
  iVar7 = *(int *)(lVar4 + 0x18);
  uVar2 = *(uint *)(lVar4 + 0x10);
  uVar1 = *(uint *)(lVar4 + 8);
  uVar6 = (ulonglong)uVar1;
  *(undefined8 *)(param_2 + 0x38) = 0;
  if (iVar7 == -0x7fefc000) {
    uVar3 = FUN_1400021ec((longlong)puVar8,uVar2);
    _DAT_14000a110 = (int)uVar3;
    *(uint *)puVar8 = -(uint)(_DAT_14000a110 != 0) & 1;
  }
  else {
    if (((iVar7 + 0x7feec000U & 0xfffcffff) == 0) && (iVar7 != -0x7fecc000)) goto LAB_14000da4f;
    if (iVar7 != -0x7fecc000) {
      if (iVar7 == -0x7dfac000) {
        uVar2 = FUN_1400026d0((int)*puVar8,(longlong)puVar8 + 4,*(uint *)((longlong)puVar8 + 4));
      }
      else if (iVar7 == -0x7cfdc000) {
        uVar2 = FUN_1400062ec((longlong)puVar8 + 4,(int *)puVar8);
      }
      else if (iVar7 == -0x7cf8c000) {
        uVar3 = FUN_140005f18();
        uVar2 = (uint)uVar3;
      }
      else {
        if (iVar7 != -0x7cf9c000) {
          if (iVar7 == -0x7df8c000) {
            if (((uVar2 < 4) || (uVar1 < 0x38)) || (puVar8 == (ulonglong *)0x0)) goto LAB_14000da4f;
            puVar5 = (ulonglong *)ExAllocatePoolWithTag(1,uVar6,0x4746544d);
            *puVar5 = (uVar6 - 8) / 0x30 & 0xffffffff;
            iVar7 = FUN_1400032b0((uint *)puVar8,puVar5);
            puVar8 = (ulonglong *)CONCAT44((int)((ulonglong)puVar8 >> 0x20),iVar7);
            *(int *)(param_2 + 0x30) = extraout_EAX;
            if (extraout_EAX < 0) {
              uVar6 = 8;
              *puVar8 = *puVar5;
            }
            else {
              uVar9 = *puVar5 * 0x30 + 8;
LAB_14000d842:
              *(ulonglong *)(param_2 + 0x38) = uVar9;
              FUN_1400075c0(puVar8,puVar5,uVar9);
            }
          }
          else {
            if (iVar7 != -0x7defc000) {
              if (iVar7 == -0x7df6c000) {
                *(undefined4 *)puVar8 = 0;
                goto LAB_14000da4f;
              }
              if (iVar7 == -0x7ffcc000) {
                if (uVar2 == 0x10) {
                  puVar8[1] = puVar8[1] ^ 0xebbaaef4fff89042;
                  *puVar8 = *puVar8 ^ puVar8[1];
                  if (*(int *)((longlong)puVar8 + 4) == -0x45145114) {
                    FUN_1400051a8((int)*puVar8);
                    if (DAT_14000a108 == 0) {
                      FUN_14000301c((longlong *)&DAT_14000a0e8,puVar8[1]);
                      lVar4 = 7;
                      do {
                        uVar6 = FUN_140002eb0((longlong *)&DAT_14000a0e8);
                        *puVar8 = uVar6;
                        DAT_14000a108 = 1;
                        lVar4 = lVar4 + -1;
                      } while (lVar4 != 0);
                      uVar6 = 8;
                    }
                    else {
                      uVar6 = 0;
                    }
                  }
                }
                goto LAB_14000da4f;
              }
              if (iVar7 == -0x7eecc000) goto LAB_14000da4f;
              if (iVar7 != -0x7eebc000) {
                FUN_14000d000();
                goto LAB_14000da4f;
              }
              uVar6 = FUN_140006654((int)*puVar8,(longlong)local_198);
              uVar2 = (uint)uVar6;
              if (-1 < (int)uVar2) {
                uVar6 = (ulonglong)(uVar2 * 0x18);
                if (0 < (int)uVar2) {
                  FUN_1400075c0(puVar8,local_198,(longlong)(int)uVar2 * 0x18);
                }
                goto LAB_14000da4f;
              }
              uVar6 = 4;
              goto LAB_14000d7c1;
            }
            if (((uVar2 < 0x28) || (uVar1 < 0x20)) || (puVar8 == (ulonglong *)0x0))
            goto LAB_14000da4f;
            puVar5 = (ulonglong *)ExAllocatePoolWithTag(1,uVar6,0x4746544d);
            *(int *)puVar5 = (int)((uVar6 - 4) / 0x18);
            uVar3 = FUN_14000377c((longlong)puVar8,(uint *)puVar5);
            *(int *)(param_2 + 0x30) = (int)uVar3;
            if (-1 < (int)uVar3) {
              uVar9 = (ulonglong)(uint)*puVar5 * 0x18 + 4;
              goto LAB_14000d842;
            }
            uVar6 = 4;
            *(uint *)puVar8 = (uint)*puVar5;
          }
          ExFreePoolWithTag(puVar5,0x4746544d);
          goto LAB_14000da4f;
        }
        uVar3 = FUN_1400063a8((void *)((longlong)puVar8 + 4),*puVar8,(uint)puVar8[1]);
        uVar2 = (uint)uVar3;
      }
LAB_14000d7c1:
      *(uint *)puVar8 = uVar2;
      goto LAB_14000da4f;
    }
    lVar4 = FUN_140002314();
    *(int *)puVar8 = (int)lVar4;
  }
  uVar6 = 4;
LAB_14000da4f:
  *(ulonglong *)(param_2 + 0x38) = uVar6;
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}

