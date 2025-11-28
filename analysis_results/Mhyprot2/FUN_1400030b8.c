// Function: FUN_1400030b8
// Address: 1400030b8
// Decompiled by Ghidra


int FUN_1400030b8(longlong *param_1,ulonglong param_2,ulonglong param_3,char param_4)

{
  longlong *plVar1;
  code *pcVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined1 *puVar5;
  undefined8 local_res10;
  undefined1 auStack_88 [8];
  undefined1 auStack_80 [24];
  undefined8 local_68;
  undefined8 *local_60;
  longlong local_58;
  undefined8 uStack_50;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  int local_38;
  uint uStack_34;
  int iStack_30;
  undefined4 uStack_2c;
  
  puVar5 = auStack_88;
  iVar3 = 0;
  memset(&local_58,0,0x30);
  local_res10 = 0;
  do {
    if (param_3 <= param_2) {
      return iVar3;
    }
    local_60 = &local_res10;
    local_68 = 0x30;
    iVar3 = ZwQueryVirtualMemory(0xffffffffffffffff,param_2,0,&local_58);
    if (iVar3 < 0) {
      if (iVar3 != -0x3ffffff3) {
        return iVar3;
      }
      return 0;
    }
    if ((((local_38 == 0x1000) && (uStack_34 != 1)) && ((uStack_34 & 0x100) == 0)) &&
       ((iStack_30 == 0x20000 || (param_4 != '\0')))) {
      puVar4 = (undefined8 *)ExAllocatePoolWithTag(1);
      if (puVar4 == (undefined8 *)0x0) {
LAB_1400031d2:
        *(undefined8 *)(puVar5 + -8) = 0x1400031dc;
        FUN_140003208('\0',param_1);
        return -0x3fffffe9;
      }
      puVar4[2] = local_58;
      puVar4[3] = uStack_50;
      *(undefined4 *)(puVar4 + 4) = local_48;
      *(undefined4 *)((longlong)puVar4 + 0x24) = uStack_44;
      *(undefined4 *)(puVar4 + 5) = uStack_40;
      *(undefined4 *)((longlong)puVar4 + 0x2c) = uStack_3c;
      puVar4[8] = 0;
      puVar4[9] = 0;
      *(int *)(puVar4 + 6) = local_38;
      *(uint *)((longlong)puVar4 + 0x34) = uStack_34;
      *(int *)(puVar4 + 7) = iStack_30;
      *(undefined4 *)((longlong)puVar4 + 0x3c) = uStack_2c;
      *(undefined1 *)(puVar4 + 10) = 0;
      *(bool *)((longlong)puVar4 + 0x51) = iStack_30 != 0x20000;
      plVar1 = (longlong *)param_1[1];
      if ((longlong *)*plVar1 != param_1) {
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)();
        puVar5 = auStack_80;
        goto LAB_1400031d2;
      }
      *puVar4 = param_1;
      puVar4[1] = plVar1;
      *plVar1 = (longlong)puVar4;
      param_1[1] = (longlong)puVar4;
    }
    param_2 = CONCAT44(uStack_3c,uStack_40) + local_58;
  } while( true );
}

