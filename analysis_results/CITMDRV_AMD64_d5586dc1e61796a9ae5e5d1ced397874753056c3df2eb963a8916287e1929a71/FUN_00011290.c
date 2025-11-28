// Function: FUN_00011290
// Address: 00011290
// Decompiled by Ghidra


int FUN_00011290(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 local_res18 [2];
  
  uVar3 = 0xffffffffffffffff;
  uVar5 = 0;
  uVar4 = param_2;
  local_res18[0] = param_3;
  iVar1 = ZwMapViewOfSection();
  iVar2 = iVar1;
  if (iVar1 == -0x3fffffe8) {
    if (DAT_00014110 != 0) {
      DbgPrint("CITMDRV.SYS: ZwMapViewOfSection conflicting address try with PAGE_NOCACHE\n");
      FUN_00011010("CITMDRV.SYS: ZwMapViewOfSection conflicting address try with PAGE_NOCACHE\n",
                   uVar3,uVar4,uVar5);
    }
    uVar5 = 0;
    uVar3 = 0xffffffffffffffff;
    uVar4 = param_2;
    iVar2 = ZwMapViewOfSection(param_1);
    if (iVar2 == -0x3fffffe8) {
      if (DAT_00014110 != 0) {
        DbgPrint("CITMDRV.SYS: ZwMapViewOfSection conflicting address try with PAGE_WRITECOMBINE\n")
        ;
        FUN_00011010("CITMDRV.SYS: ZwMapViewOfSection conflicting address try with PAGE_WRITECOMBINE\n"
                     ,uVar3,uVar4,uVar5);
      }
      iVar2 = ZwMapViewOfSection(param_1,0xffffffffffffffff,param_2,0,local_res18[0],param_4,
                                 local_res18,1,0,0x402);
    }
  }
  if (iVar2 == 0) {
    iVar1 = 0;
  }
  return iVar1;
}

