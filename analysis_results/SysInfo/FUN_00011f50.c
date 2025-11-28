// Function: FUN_00011f50
// Address: 00011f50
// Decompiled by Ghidra


undefined4 FUN_00011f50(longlong param_1,longlong param_2)

{
  uint *puVar1;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined8 in_stack_ffffffffffffffe8;
  
  pcVar4 = *(char **)(param_2 + 0xb8);
  *(undefined8 *)(param_2 + 0x38) = 0;
  cVar2 = *pcVar4;
  puVar1 = (uint *)(param_2 + 0x38);
  uVar5 = 0xc0000002;
  if (cVar2 == '\0') {
    if (DAT_00014190 != -1) {
      DAT_00014190 = DAT_00014190 + 1;
    }
  }
  else {
    if (cVar2 != '\x02') {
      if (cVar2 != '\x0e') goto LAB_00012216;
      uVar3 = *(uint *)(pcVar4 + 0x18);
      if (uVar3 < 0x9c40a441) {
        if (uVar3 != 0x9c40a440) {
          if (uVar3 < 0x9c406405) {
            if (uVar3 != 0x9c406404) {
              if (uVar3 == 0x9c402604) {
                uVar6 = FUN_00011010((ulonglong)uVar3,*(undefined4 **)(param_2 + 0x18),
                                     (ulonglong)*(uint *)(pcVar4 + 0x10),
                                     (undefined8 *)*(undefined4 **)(param_2 + 0x18),
                                     CONCAT44((int)((ulonglong)in_stack_ffffffffffffffe8 >> 0x20),
                                              *(undefined4 *)(pcVar4 + 8)),puVar1);
                uVar5 = (undefined4)uVar6;
                goto LAB_00012216;
              }
              if (uVar3 == 0x9c402608) {
                uVar6 = FUN_00011050((ulonglong)uVar3,*(undefined4 **)(param_2 + 0x18));
                uVar5 = (undefined4)uVar6;
                goto LAB_00012216;
              }
              if (uVar3 == 0x9c402664) {
                **(int **)(param_2 + 0x18) = DAT_00014190;
                puVar1[0] = 4;
                puVar1[1] = 0;
                goto LAB_00012214;
              }
              if (uVar3 != 0x9c406400) goto LAB_00012216;
            }
          }
          else if (uVar3 != 0x9c406408) {
            if (uVar3 == 0x9c406480) {
              uVar6 = FUN_000111b0(*(undefined4 **)(param_2 + 0x18),*(int *)(pcVar4 + 0x10),
                                   *(undefined4 **)(param_2 + 0x18),*(uint *)(pcVar4 + 8),puVar1);
              uVar5 = (undefined4)uVar6;
            }
            else if (uVar3 == 0x9c406500) {
              uVar6 = FUN_00011d40(*(uint **)(param_2 + 0x18),*(int *)(pcVar4 + 0x10),
                                   *(uint **)(param_2 + 0x18),*(int *)(pcVar4 + 8),(int *)puVar1);
              uVar5 = (undefined4)uVar6;
            }
            goto LAB_00012216;
          }
          uVar6 = FUN_000110a0(uVar3,*(undefined4 **)(param_2 + 0x18),*(int *)(pcVar4 + 0x10),
                               *(undefined4 **)(param_2 + 0x18),*(uint *)(pcVar4 + 8),puVar1);
          uVar5 = (undefined4)uVar6;
          goto LAB_00012216;
        }
      }
      else {
        if (0x9c40a580 < uVar3) {
          if (uVar3 != 0x9c40a584) {
            if (uVar3 == 0x9c40a5c0) {
              uVar6 = FUN_000113c0(*(undefined4 **)(param_2 + 0x18),*(uint *)(pcVar4 + 0x10),
                                   *(undefined4 **)(param_2 + 0x18),(ulonglong)*(uint *)(pcVar4 + 8)
                                   ,puVar1);
              uVar5 = (undefined4)uVar6;
            }
            else if (uVar3 == 0x9c40a600) {
              uVar6 = FUN_00011540(*(undefined4 **)(param_2 + 0x18),*(uint *)(pcVar4 + 0x10),
                                   *(undefined4 **)(param_2 + 0x18),(ulonglong)*(uint *)(pcVar4 + 8)
                                   ,puVar1);
              uVar5 = (undefined4)uVar6;
            }
            goto LAB_00012216;
          }
          goto LAB_00012214;
        }
        if (uVar3 == 0x9c40a580) {
          if (*(int *)(pcVar4 + 0x10) == 4) {
            uVar6 = FUN_00011650(*(longlong *)(param_1 + 0x40),**(int **)(param_2 + 0x18));
            puVar1[0] = 0;
            puVar1[1] = 0;
            uVar5 = (undefined4)uVar6;
          }
          else {
            uVar5 = 0xc000000d;
          }
          goto LAB_00012216;
        }
        if ((uVar3 != 0x9c40a444) && (uVar3 != 0x9c40a448)) {
          if (uVar3 == 0x9c40a4c0) {
            uVar6 = FUN_000112b0(*(undefined4 **)(param_2 + 0x18),*(uint *)(pcVar4 + 0x10),
                                 *(undefined4 **)(param_2 + 0x18),(ulonglong)*(uint *)(pcVar4 + 8),
                                 puVar1);
            uVar5 = (undefined4)uVar6;
          }
          else if (uVar3 == 0x9c40a540) {
            uVar5 = FUN_00011e10(*(uint **)(param_2 + 0x18),*(uint *)(pcVar4 + 0x10),
                                 *(uint **)(param_2 + 0x18),(ulonglong)*(uint *)(pcVar4 + 8),puVar1)
            ;
          }
          goto LAB_00012216;
        }
      }
      uVar6 = FUN_00011130(uVar3,*(undefined4 **)(param_2 + 0x18),*(uint *)(pcVar4 + 0x10));
      uVar5 = (undefined4)uVar6;
      goto LAB_00012216;
    }
    if (DAT_00014190 != -1) {
      DAT_00014190 = DAT_00014190 + -1;
    }
  }
LAB_00012214:
  uVar5 = 0;
LAB_00012216:
  *(undefined4 *)(param_2 + 0x30) = uVar5;
  IofCompleteRequest(param_2,0);
  return uVar5;
}

