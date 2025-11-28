// Function: FUN_00011620
// Address: 00011620
// Decompiled by Ghidra


undefined8 FUN_00011620(longlong param_1,longlong param_2,char param_3)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  uint *puVar4;
  uint *puVar5;
  uint local_68 [2];
  uint local_60 [2];
  uint local_58;
  undefined4 uStack_54;
  
  iVar1 = *(int *)(param_2 + 0x18);
  uVar2 = *(uint *)(param_2 + 0x10);
  if (param_3 == '\0') {
    puVar4 = *(uint **)(param_1 + 0x18);
    puVar5 = (uint *)CONCAT44(uStack_54,local_58);
  }
  else {
    puVar5 = *(uint **)(param_1 + 0x18);
    puVar4 = (uint *)CONCAT44(uStack_54,local_58);
  }
  DbgPrint("[GpdIoctlWritePort] In\n");
  if (iVar1 == -0x5fbf5bc0) {
    local_68[0] = 1;
  }
  else if (iVar1 == -0x5fbf5bbc) {
    local_68[0] = 2;
  }
  else if (iVar1 == -0x5fbf5bb8) {
    local_68[0] = 4;
  }
  if ((ulonglong)uVar2 < (ulonglong)local_68[0] + 4) {
    uVar3 = 0xc000000d;
  }
  else {
    if (param_3 == '\0') {
      local_58 = *puVar4;
      puVar4 = puVar4 + 1;
    }
    else {
      local_58 = *puVar5;
      puVar5 = puVar5 + 1;
    }
    uStack_54 = 0;
    local_68[0] = 1;
    HalTranslateBusAddress(1,0,local_58,local_68,local_60);
    if (local_68[0] == 1) {
      if (iVar1 == -0x5fbf5bc0) {
        if (param_3 == '\0') {
          out((short)local_60,(char)*puVar4);
        }
        else {
          out((undefined2)local_60[0],(char)*puVar5);
        }
      }
      else if (iVar1 == -0x5fbf5bbc) {
        if (param_3 == '\0') {
          out((short)local_60,(short)*puVar4);
        }
        else {
          out((undefined2)local_60[0],(short)*puVar5);
        }
      }
      else if (iVar1 == -0x5fbf5bb8) {
        if (param_3 == '\0') {
          out((short)local_60,*puVar4);
        }
        else {
          out((undefined2)local_60[0],*puVar5);
        }
      }
    }
    else if (iVar1 == -0x5fbf5bc0) {
      if (param_3 == '\0') {
        local_60[0] = CONCAT31(local_60[0]._1_3_,(char)*puVar4);
      }
      else {
        *(char *)(ulonglong)local_60[0] = (char)*puVar5;
      }
    }
    else if (iVar1 == -0x5fbf5bbc) {
      if (param_3 == '\0') {
        local_60[0] = CONCAT22(local_60[0]._2_2_,(short)*puVar4);
      }
      else {
        *(short *)(ulonglong)local_60[0] = (short)*puVar5;
      }
    }
    else if (iVar1 == -0x5fbf5bb8) {
      if (param_3 == '\0') {
        local_60[0] = *puVar4;
      }
      else {
        *(uint *)(ulonglong)local_60[0] = *puVar5;
      }
    }
    DbgPrint("[GpdIoctlWritePort] Out\n");
    uVar3 = 0;
  }
  return uVar3;
}

