// Function: FUN_140006a80
// Address: 140006a80
// Decompiled by Ghidra


void FUN_140006a80(undefined8 param_1,undefined8 param_2,char *param_3)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  char cVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  longlong lVar6;
  ulonglong uVar7;
  char local_res10 [8];
  int local_res18;
  int local_res20;
  char local_128 [256];
  
  uVar7 = 1;
  FUN_1400014e0();
  local_res18 = 1;
  LOCK();
  if (DAT_14000a6e8 == 1) {
    local_res18 = -1;
  }
  UNLOCK();
  while (local_res18 != -1) {
    local_res20 = 0;
    LOCK();
    if (DAT_14000a010 == 0) {
      local_res20 = -1;
    }
    UNLOCK();
    if (local_res20 == -1) {
      if (DAT_14000a6fc < 1) {
        DAT_14000a6fc = DAT_14000a6fc + 1;
        FUN_14001b5f8(L"Status false\r\n");
        DbgPrint(&LAB_140007da0);
        memset(local_128,0,0x100);
        param_3 = "Status  false\r\n";
        _snprintf(local_128,0x100,"Status  false\r\n");
        FUN_140005c0c(0);
        LOCK();
        DAT_14000a6f8 = 1;
        UNLOCK();
      }
    }
    else {
      LOCK();
      DAT_14000a010 = DAT_14000a010 + -1;
      UNLOCK();
      auVar1._8_8_ = 0;
      auVar1._0_8_ = uVar7;
      lVar6 = SUB168(ZEXT816(0x47ae147ae147ae15) * auVar1,8);
      if (uVar7 + ((uVar7 - lVar6 >> 1) + lVar6 >> 5) * -0x32 == 0xb) {
        param_3 = local_res10;
        local_res10[0] = '\0';
        KdChangeOption(0,1,param_3,0,0,0);
        KdDisableDebugger();
        *KdDebuggerEnabled_exref = (code)0x0;
        cVar3 = FUN_140001490();
        if (cVar3 == '\x01') {
          LOCK();
          DAT_14000a6ec = 1;
          UNLOCK();
        }
      }
    }
    auVar2._8_8_ = 0;
    auVar2._0_8_ = uVar7;
    lVar6 = SUB168(ZEXT816(0x47ae147ae147ae15) * auVar2,8);
    uVar5 = ((uVar7 - lVar6 >> 1) + lVar6 >> 5) * 0x32;
    if ((uVar7 == uVar5) &&
       (uVar4 = FUN_1400069b4(uVar5,lVar6,(ulonglong)param_3), (char)uVar4 == '\x01')) {
      LOCK();
      DAT_14000a6ec = 1;
      UNLOCK();
    }
    if ((uVar7 % 0x1e == 0xb) && (DAT_14000a5f0 != 0)) {
      param_3 = (char *)0x0;
      KeSetEvent(DAT_14000a5f0,0);
    }
    FUN_1400069d8(100);
    uVar7 = uVar7 + 1;
    FUN_1400014e0();
    local_res18 = 1;
    LOCK();
    if (DAT_14000a6e8 == 1) {
      local_res18 = -1;
    }
    UNLOCK();
  }
                    /* WARNING: Could not recover jumptable at 0x000140006c61. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  PsTerminateSystemThread(0);
  return;
}

