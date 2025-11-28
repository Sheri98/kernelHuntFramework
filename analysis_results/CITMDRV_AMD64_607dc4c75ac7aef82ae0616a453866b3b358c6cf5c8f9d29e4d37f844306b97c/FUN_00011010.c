// Function: FUN_00011010
// Address: 00011010
// Decompiled by Ghidra


void FUN_00011010(char *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  uint uVar2;
  longlong lVar3;
  char *pcVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  undefined1 *puVar7;
  undefined8 uVar8;
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  undefined8 in_stack_fffffffffffffe40;
  undefined4 uVar9;
  undefined8 in_stack_fffffffffffffe50;
  undefined4 uVar10;
  undefined8 in_stack_fffffffffffffe58;
  undefined4 uVar11;
  undefined8 local_188;
  undefined4 local_180 [2];
  undefined8 local_178;
  undefined1 *local_170;
  undefined4 local_168;
  undefined8 local_160;
  undefined8 local_158;
  undefined1 local_150 [16];
  undefined1 local_140 [24];
  char local_128 [256];
  longlong local_28;
  
  uVar9 = (undefined4)((ulonglong)in_stack_fffffffffffffe40 >> 0x20);
  uVar10 = (undefined4)((ulonglong)in_stack_fffffffffffffe50 >> 0x20);
  uVar11 = (undefined4)((ulonglong)in_stack_fffffffffffffe58 >> 0x20);
  local_28 = DAT_00014108;
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20 = param_4;
  vsprintf(local_128,param_1,(va_list)&local_res10);
  RtlInitUnicodeString(local_140,L"\\??\\C:\\CITMDRV.LOG");
  local_170 = local_140;
  puVar7 = local_150;
  puVar5 = local_180;
  local_180[0] = 0x30;
  local_178 = 0;
  local_168 = 0x40;
  local_160 = 0;
  local_158 = 0;
  uVar2 = ZwCreateFile(&local_188,0x100004,puVar5,puVar7,0,CONCAT44(uVar9,0x80),0,CONCAT44(uVar10,3)
                       ,CONCAT44(uVar11,0x20),0,0);
  if ((int)uVar2 < 0) {
    if (DAT_00014110 != 0) {
      DbgPrint("CITMDRV.SYS: ZwCreateFile failed (0x%x)\n",uVar2);
      FUN_00011010("CITMDRV.SYS: ZwCreateFile failed (0x%x)\n",(ulonglong)uVar2,puVar5,puVar7);
    }
  }
  else {
    lVar3 = -1;
    uVar8 = 0;
    pcVar4 = local_128;
    do {
      if (lVar3 == 0) break;
      lVar3 = lVar3 + -1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    uVar6 = 0;
    uVar2 = ZwWriteFile(local_188,0,0,0,local_150,local_128,~(uint)lVar3 - 1,0,0);
    if (((int)uVar2 < 0) && (DAT_00014110 != 0)) {
      DbgPrint("CITMDRV.SYS: ZwWriteFile failed (0x%x)\n",uVar2);
      FUN_00011010("CITMDRV.SYS: ZwWriteFile failed (0x%x)\n",(ulonglong)uVar2,uVar6,uVar8);
    }
    ZwClose(local_188);
  }
  FUN_00012290(local_28);
  return;
}

