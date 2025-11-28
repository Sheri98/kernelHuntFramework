// Function: FUN_140005c0c
// Address: 140005c0c
// Decompiled by Ghidra


void FUN_140005c0c(uint param_1)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined8 local_res18 [2];
  undefined8 in_stack_fffffffffffffd70;
  undefined4 uVar6;
  undefined8 in_stack_fffffffffffffd80;
  undefined4 uVar7;
  undefined8 in_stack_fffffffffffffd88;
  undefined4 uVar8;
  undefined1 local_258 [16];
  undefined1 local_248 [16];
  undefined4 local_238 [2];
  undefined8 local_230;
  undefined1 *local_228;
  undefined4 local_220;
  undefined8 local_218;
  undefined8 uStack_210;
  char local_208 [512];
  longlong lVar5;
  
  uVar6 = (undefined4)((ulonglong)in_stack_fffffffffffffd70 >> 0x20);
  uVar7 = (undefined4)((ulonglong)in_stack_fffffffffffffd80 >> 0x20);
  uVar8 = (undefined4)((ulonglong)in_stack_fffffffffffffd88 >> 0x20);
  local_res18[0] = 0;
  memset(local_208,0,0x200);
  uVar3 = FUN_140002314();
  FUN_140005be0(local_208,"%d %d %s\r\n",uVar3 & 0xffffffff,(ulonglong)param_1);
  RtlInitUnicodeString(local_258,L"\\??\\c:\\windows\\kmlog.log");
  local_228 = local_258;
  local_230 = 0;
  local_238[0] = 0x30;
  local_220 = 0x240;
  local_218 = 0;
  uStack_210 = 0;
  iVar2 = ZwCreateFile(local_res18,4,local_238,local_248,0,CONCAT44(uVar6,0x80),2,CONCAT44(uVar7,3),
                       CONCAT44(uVar8,0x860),0,0);
  if (iVar2 == 0) {
    lVar5 = -1;
    do {
      lVar4 = lVar5 + 1;
      lVar1 = lVar5 + 1;
      lVar5 = lVar4;
    } while (local_208[lVar1] != '\0');
    ZwWriteFile(local_res18[0],0,0,0,local_248,local_208,(int)lVar4,0,0);
    ZwClose(local_res18[0]);
  }
  return;
}

