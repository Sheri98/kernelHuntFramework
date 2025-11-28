// Function: FUN_000117c0
// Address: 000117c0
// Decompiled by Ghidra


undefined8 FUN_000117c0(longlong param_1,longlong param_2,char param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  longlong lVar4;
  ushort *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  ushort *puVar8;
  int local_78 [2];
  undefined1 local_70;
  undefined1 uStack_6f;
  undefined2 uStack_6e;
  undefined4 uStack_6c;
  undefined8 local_68;
  undefined4 local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined8 local_48 [4];
  
  iVar1 = *(int *)(param_2 + 0x18);
  if (param_3 == '\0') {
    puVar3 = *(undefined4 **)(param_1 + 0x18);
    uVar2 = *puVar3;
    local_70 = (undefined1)uVar2;
    uStack_6f = (undefined1)((uint)uVar2 >> 8);
    uStack_6e = (undefined2)((uint)uVar2 >> 0x10);
    puVar5 = (ushort *)(puVar3 + 1);
    puVar8 = (ushort *)CONCAT44(uStack_6c,uVar2);
  }
  else {
    puVar3 = *(undefined4 **)(param_1 + 0x18);
    uVar2 = *puVar3;
    local_70 = (undefined1)uVar2;
    uStack_6f = (undefined1)((uint)uVar2 >> 8);
    uStack_6e = (undefined2)((uint)uVar2 >> 0x10);
    puVar8 = (ushort *)(puVar3 + 1);
    puVar5 = (ushort *)CONCAT44(uStack_6c,uVar2);
  }
  uStack_6c = 0;
  local_78[0] = 1;
  HalTranslateBusAddress(1,0,CONCAT22(uStack_6e,CONCAT11(uStack_6f,local_70)),local_78,&local_70);
  local_68._4_4_ = puVar3[3];
  local_60 = puVar3[4];
  local_58 = puVar3[6];
  local_54 = puVar3[7];
  local_50 = puVar3[8];
  if (local_78[0] == 1) {
    if (iVar1 == -0x5fbf5ac0) {
      puVar6 = &local_68;
      puVar7 = local_48;
      for (lVar4 = 3; lVar4 != 0; lVar4 = lVar4 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      *(undefined4 *)puVar7 = *(undefined4 *)puVar6;
      if (param_3 == '\0') {
        FUN_00011000(CONCAT11(uStack_6f,local_70),(uint)(byte)*puVar5,'\x01');
        return 0;
      }
      FUN_00011000(CONCAT11(uStack_6f,local_70),(uint)(byte)*puVar8,'\x01');
      return 0;
    }
    if (iVar1 == -0x5fbf5abc) {
      puVar6 = &local_68;
      puVar7 = local_48;
      for (lVar4 = 3; lVar4 != 0; lVar4 = lVar4 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      *(undefined4 *)puVar7 = *(undefined4 *)puVar6;
      if (param_3 == '\0') {
        FUN_00011000(CONCAT11(uStack_6f,local_70),(uint)*puVar5,'\x02');
        return 0;
      }
      FUN_00011000(CONCAT11(uStack_6f,local_70),(uint)*puVar8,'\x02');
      return 0;
    }
    if (iVar1 == -0x5fbf5ab8) {
      puVar6 = &local_68;
      puVar7 = local_48;
      for (lVar4 = 3; lVar4 != 0; lVar4 = lVar4 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      *(undefined4 *)puVar7 = *(undefined4 *)puVar6;
      if (param_3 == '\0') {
        FUN_00011000(CONCAT11(uStack_6f,local_70),*(undefined4 *)puVar5,'\x04');
        return 0;
      }
      FUN_00011000(CONCAT11(uStack_6f,local_70),*(undefined4 *)puVar8,'\x04');
      return 0;
    }
  }
  else if (iVar1 == -0x5fbf5ac0) {
    if (param_3 != '\0') {
      *(byte *)(ulonglong)CONCAT22(uStack_6e,CONCAT11(uStack_6f,local_70)) = (byte)*puVar8;
    }
  }
  else if (iVar1 == -0x5fbf5abc) {
    if (param_3 != '\0') {
      *(ushort *)(ulonglong)CONCAT22(uStack_6e,CONCAT11(uStack_6f,local_70)) = *puVar8;
    }
  }
  else if ((iVar1 == -0x5fbf5ab8) && (param_3 != '\0')) {
    *(undefined4 *)(ulonglong)CONCAT22(uStack_6e,CONCAT11(uStack_6f,local_70)) =
         *(undefined4 *)puVar8;
  }
  return 0;
}

