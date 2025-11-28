// Function: FUN_00011410
// Address: 00011410
// Decompiled by Ghidra


int FUN_00011410(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4,
                ulonglong param_5,longlong param_6)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  longlong local_28 [3];
  
  local_28[0] = 0;
  iVar1 = FUN_00011290(param_1,local_28,param_2,param_3);
  if (-1 < iVar1) {
    if (DAT_00014110 != 0) {
      DbgPrint("CITMDRV.SYS: virtualAddress=0x%p\n",local_28[0]);
      FUN_00011010("CITMDRV.SYS: virtualAddress=0x%p\n",local_28[0],param_2,param_3);
      if (DAT_00014110 != 0) {
        DbgPrint("CITMDRV.SYS: copy %u bytes into user memory\n",param_5);
        FUN_00011010("CITMDRV.SYS: copy %u bytes into user memory\n",param_5,param_2,param_3);
      }
    }
    lVar3 = local_28[0];
    FUN_00011f40(param_4,(undefined8 *)(local_28[0] + param_6),param_5);
    uVar2 = ZwUnmapViewOfSection(0xffffffffffffffff);
    if ((int)uVar2 < 0) {
      if (DAT_00014110 != 0) {
        DbgPrint("CITMDRV.SYS: ZwUnmapViewOfSection failed (0x%x)\n",uVar2);
        FUN_00011010("CITMDRV.SYS: ZwUnmapViewOfSection failed (0x%x)\n",(ulonglong)uVar2,param_5,
                     param_3);
        return 0;
      }
    }
    else if (DAT_00014110 != 0) {
      DbgPrint("CITMDRV.SYS: Unmap ok\n");
      FUN_00011010("CITMDRV.SYS: Unmap ok\n",lVar3,param_5,param_3);
    }
    iVar1 = 0;
  }
  return iVar1;
}

