// Function: FUN_000113f0
// Address: 000113f0
// Decompiled by Ghidra


undefined4 FUN_000113f0(undefined8 param_1,longlong param_2)

{
  char cVar1;
  undefined4 uVar2;
  uint *puVar3;
  byte bVar4;
  ushort uVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  ulonglong uVar9;
  undefined2 local_res10;
  uint local_res12;
  char local_res16;
  longlong local_48;
  ulonglong local_40;
  undefined8 local_38;
  longlong local_30;
  longlong local_28 [3];
  
  DbgPrint("---Entry MsIoDispatch---");
  pcVar8 = *(char **)(param_2 + 0xb8);
  puVar3 = *(uint **)(param_2 + 0x18);
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  cVar1 = *pcVar8;
  uVar6 = *(uint *)(pcVar8 + 0x10);
  uVar9 = (ulonglong)uVar6;
  if (cVar1 == '\0') {
    pcVar8 = "IRP_MJ_CREATE";
  }
  else {
    if (cVar1 != '\x02') {
      if (cVar1 == '\x0e') {
        DbgPrint("IRP_MJ_DEVICE_CONTROL");
        iVar7 = *(int *)(pcVar8 + 0x18);
        if (iVar7 == -0x7fefdfc0) {
          DbgPrint("IOCTL_MSIO_MAPPHYSTOLIN");
          if (uVar6 != 0) {
            FUN_000117e0(&local_48,(undefined8 *)puVar3,uVar9);
            iVar7 = FUN_00011090(local_40,local_48,&local_30,&local_38,local_28);
            if (-1 < iVar7) {
              FUN_000117e0((undefined8 *)puVar3,&local_48,uVar9);
              *(ulonglong *)(param_2 + 0x38) = uVar9;
            }
            *(int *)(param_2 + 0x30) = iVar7;
            goto LAB_0001167f;
          }
        }
        else if (iVar7 == -0x7fefdfbc) {
          DbgPrint("IOCTL_MSIO_UNMAPPHYSADDR");
          if (uVar6 != 0) {
            FUN_000117e0(&local_48,(undefined8 *)puVar3,uVar9);
            iVar7 = FUN_00011360(local_38,local_30,local_28[0]);
            *(int *)(param_2 + 0x30) = iVar7;
            goto LAB_0001167f;
          }
        }
        else if (iVar7 == -0x7fefdfb0) {
          DbgPrint("IOCTL_MSIO_READPORT");
          if (uVar6 != 0) {
            FUN_000117e0((undefined8 *)&local_res10,(undefined8 *)puVar3,uVar9);
            if (local_res16 == '\x01') {
              bVar4 = in(local_res10);
              *puVar3 = (uint)bVar4;
              *(undefined8 *)(param_2 + 0x38) = 4;
            }
            else if (local_res16 == '\x02') {
              uVar5 = in(local_res10);
              *puVar3 = (uint)uVar5;
              *(undefined8 *)(param_2 + 0x38) = 4;
            }
            else if (local_res16 == '\x04') {
              uVar6 = in(local_res10);
              *puVar3 = uVar6;
              *(undefined8 *)(param_2 + 0x38) = 4;
            }
            else {
              *puVar3 = local_res12;
              *(undefined8 *)(param_2 + 0x38) = 4;
            }
            goto LAB_0001167f;
          }
        }
        else if (iVar7 == -0x7fefdfac) {
          DbgPrint("IOCTL_MSIO_WRITEPORT");
          if (uVar6 != 0) {
            FUN_000117e0((undefined8 *)&local_res10,(undefined8 *)puVar3,uVar9);
            if (local_res16 == '\x01') {
              out(local_res10,(undefined1)local_res12);
            }
            else if (local_res16 == '\x02') {
              out(local_res10,(undefined2)local_res12);
            }
            else if (local_res16 == '\x04') {
              out(local_res10,local_res12);
            }
            goto LAB_0001167f;
          }
        }
        else {
          DbgPrint("ERROR: Unknown IRP_MJ_DEVICE_CONTROL");
        }
        *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
      }
      goto LAB_0001167f;
    }
    pcVar8 = "IRP_MJ_CLOSE";
  }
  DbgPrint(pcVar8);
LAB_0001167f:
  uVar2 = *(undefined4 *)(param_2 + 0x30);
  IofCompleteRequest(param_2,0);
  DbgPrint("Leaving MsIoDispatch");
  return uVar2;
}

