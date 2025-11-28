// Function: FUN_14000d0a3
// Address: 14000d0a3
// Decompiled by Ghidra


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_14000d0a3(undefined8 param_1,undefined8 param_2,ulonglong param_3,undefined8 param_4,
             undefined8 param_5,uint *param_6)

{
  uint uVar1;
  undefined8 uVar2;
  bool bVar3;
  uint uVar4;
  ulonglong in_RAX;
  undefined7 extraout_var;
  ulonglong uVar5;
  undefined8 uVar6;
  uint *puVar7;
  uint unaff_EBX;
  longlong unaff_RBP;
  char unaff_DIL;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000078;
  
  if (unaff_DIL != '\0') {
    return in_RAX & 0xffffffffffffff00;
  }
  if (unaff_EBX < 0x81104001) {
    if (unaff_EBX == 0x81104000) {
      uVar6 = FUN_140006834(*param_6);
LAB_14000d33a:
      *(undefined8 *)(unaff_RBP + 0x200) = uVar6;
    }
    else {
      puVar7 = (uint *)0x81054000;
      if (unaff_EBX < 0x81054001) {
        if (unaff_EBX == 0x81054000) {
          uVar4 = param_6[1];
          uVar1 = *param_6;
          puVar7 = (uint *)ExAllocatePool(0,(ulonglong)uVar4 * 0x318 + 4);
          uVar4 = FUN_14000274c(uVar1,(longlong)(puVar7 + 1),uVar4);
          *puVar7 = uVar4;
          FUN_140002270();
LAB_14000d2ac:
          puVar7 = (uint *)ExFreePoolWithTag(puVar7,0);
          goto LAB_14000d62b;
        }
        if (unaff_EBX == 0x80024000) {
          FUN_1400048fc(*param_6);
          *(undefined4 *)(unaff_RBP + 0x200) = 0;
        }
        else if (unaff_EBX == 0x81004000) {
          memset(&stack0x00000070,0,0x20);
          puVar7 = (uint *)FUN_140004310((longlong *)param_6,&stack0x00000070);
          if ((int)puVar7 != 0) goto LAB_14000d62b;
        }
        else {
          if (unaff_EBX == 0x81014000) {
            FUN_14000696c(*param_6);
            bVar3 = FUN_140006994();
            *(uint *)(unaff_RBP + 0x200) = (uint)bVar3;
          }
          else {
            if (unaff_EBX != 0x81034000) {
              if (unaff_EBX != 0x81044000) goto LAB_14000d62b;
              uVar4 = *param_6;
              memset((void *)(unaff_RBP + -0x60),0,0x208);
              FUN_140003bfc(uVar4,(undefined8 *)(unaff_RBP + -0x60),0x104,param_4);
              uVar2 = DAT_14000a100;
              uVar6 = _DAT_14000a0f8;
              in_stack_00000070 = _DAT_14000a0e8;
              in_stack_00000078 = uRam000000014000a0f0;
              *(undefined8 *)(unaff_RBP + -0x70) = _DAT_14000a108;
              *(undefined8 *)(unaff_RBP + -0x80) = uVar6;
              *(undefined8 *)(unaff_RBP + -0x78) = uVar2;
              goto LAB_14000d61b;
            }
            thunk_FUN_1400036b0(*param_6);
            *(undefined4 *)(unaff_RBP + 0x200) = 0;
          }
          uVar2 = DAT_14000a100;
          uVar6 = _DAT_14000a0f8;
          in_stack_00000070 = _DAT_14000a0e8;
          in_stack_00000078 = uRam000000014000a0f0;
          *(undefined8 *)(unaff_RBP + -0x70) = _DAT_14000a108;
          *(undefined8 *)(unaff_RBP + -0x80) = uVar6;
          *(undefined8 *)(unaff_RBP + -0x78) = uVar2;
        }
      }
      else if (unaff_EBX == 0x81064000) {
        uVar5 = FUN_140003614(*param_6,param_2,param_3,param_4);
        uVar4 = (uint)uVar5;
LAB_14000d2e9:
        *(uint *)(unaff_RBP + 0x200) = uVar4;
      }
      else if (unaff_EBX == 0x81074000) {
        *(undefined4 *)(unaff_RBP + 0x200) = 0;
        FUN_140004214((int *)param_6,(undefined4 *)(unaff_RBP + 0x200));
      }
      else {
        if (unaff_EBX != 0x81084000) {
          if (unaff_EBX != 0x81094000) goto LAB_14000d62b;
          bVar3 = FUN_1400035b0(*param_6,param_2,param_3,param_4);
          uVar4 = (uint)CONCAT71(extraout_var,bVar3);
          goto LAB_14000d2e9;
        }
        *(undefined4 *)(unaff_RBP + 0x200) = 0x133ecf0;
      }
    }
  }
  else {
    puVar7 = (uint *)0x82044000;
    if (unaff_EBX < 0x82044001) {
      if (unaff_EBX == 0x82044000) {
        memset(&stack0x00000070,0,0x20);
        FUN_140006268();
      }
      else {
        if (unaff_EBX == 0x81114000) {
          uVar6 = FUN_140003d44(*param_6);
          goto LAB_14000d33a;
        }
        if (unaff_EBX == 0x81124000) {
          uVar6 = FUN_140132672(&LAB_14000db10,param_2,param_3);
          return uVar6;
        }
        if (unaff_EBX == 0x82004000) {
          *(undefined4 *)(unaff_RBP + 0x200) = 0;
          FUN_140006408(*(undefined8 *)(param_6 + 4),*(undefined8 *)(param_6 + 2),
                        (int)*(undefined8 *)param_6);
        }
        else if (unaff_EBX == 0x82014000) {
          memset(&stack0x00000070,0,0x20);
          FUN_140005fa0();
        }
        else {
          if (unaff_EBX != 0x82024000) goto LAB_14000d62b;
          memset(&stack0x00000070,0,0x20);
          FUN_140005f1c();
        }
      }
    }
    else if (unaff_EBX == 0x82054000) {
      memset(&stack0x00000070,0,0x20);
      FUN_1400061bc(param_6,(uint)&stack0x00000070);
    }
    else {
      if (unaff_EBX != 0x82064000) {
        if (unaff_EBX == 0x82114000) {
          puVar7 = param_6;
          if ((*param_6 ^ 0xbaebaeec) != DAT_14000a688) goto LAB_14000d62b;
          uVar4 = DAT_14000a6ec ^ DAT_14000a688;
          goto LAB_14000d2e9;
        }
        if (((unaff_EBX != 0x83014000) || (*param_6 != 0x88)) ||
           (puVar7 = (uint *)ExAllocatePool(0,(ulonglong)param_6[1] * 0x2a8 + 4),
           puVar7 == (uint *)0x0)) goto LAB_14000d62b;
        uVar4 = FUN_140006038((longlong)(puVar7 + 1),(int *)param_6);
        *puVar7 = uVar4;
        FUN_140002270();
        goto LAB_14000d2ac;
      }
      memset(&stack0x00000070,0,0x20);
      FUN_14000630c((longlong)param_6,(undefined4 *)&stack0x00000070);
    }
  }
LAB_14000d61b:
  puVar7 = (uint *)FUN_140002270();
LAB_14000d62b:
  if (param_6 != (uint *)0x0) {
    puVar7 = (uint *)ExFreePoolWithTag(param_6,0);
  }
  return CONCAT71((int7)((ulonglong)puVar7 >> 8),1);
}

