// Function: FUN_00011b30
// Address: 00011b30
// Decompiled by Ghidra


undefined4 FUN_00011b30(undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  longlong *plVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  pcVar7 = *(char **)(param_2 + 0xb8);
  cVar1 = *pcVar7;
  plVar4 = *(longlong **)(param_2 + 0x18);
  uVar5 = *(uint *)(pcVar7 + 0x10);
  uVar2 = *(uint *)(pcVar7 + 8);
  if (cVar1 == '\0') {
    if (DAT_00014110 == 0) goto LAB_00011c44;
    DbgPrint("CITMDRV.SYS: IRP_MJ_CREATE\n");
    pcVar6 = "CITMDRV.SYS: IRP_MJ_CREATE\n";
  }
  else {
    if (cVar1 != '\x02') {
      if (cVar1 == '\x0e') {
        if (*(int *)(pcVar7 + 0x18) == -0x7fffe000) {
          if (DAT_00014110 != 0) {
            DbgPrint("CITMDRV.SYS: IOCTL_MAP_MEM\n");
            FUN_00011010("CITMDRV.SYS: IOCTL_MAP_MEM\n",pcVar7,param_3,param_4);
          }
          uVar5 = FUN_00011540(param_1,plVar4,(ulonglong)uVar5,(ulonglong)uVar2);
          *(uint *)(param_2 + 0x30) = uVar5;
          if (-1 < (int)uVar5) {
            *(undefined8 *)(param_2 + 0x38) = 8;
            goto LAB_00011c44;
          }
        }
        else if (DAT_00014110 != 0) {
          DbgPrint("CITMDRV.SYS: unknown IRP_MJ_DEVICE_CONTROL\n");
          FUN_00011010("CITMDRV.SYS: unknown IRP_MJ_DEVICE_CONTROL\n",pcVar7,param_3,param_4);
        }
        *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
      }
      goto LAB_00011c44;
    }
    if (DAT_00014110 == 0) goto LAB_00011c44;
    DbgPrint("CITMDRV.SYS: IRP_MJ_CLOSE\n");
    pcVar6 = "CITMDRV.SYS: IRP_MJ_CLOSE\n";
  }
  FUN_00011010(pcVar6,pcVar7,param_3,param_4);
LAB_00011c44:
  uVar3 = *(undefined4 *)(param_2 + 0x30);
  IofCompleteRequest(param_2,0);
  return uVar3;
}

