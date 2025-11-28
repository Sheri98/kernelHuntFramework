// Function: FUN_00011d2c
// Address: 00011d2c
// Decompiled by Ghidra


undefined8 FUN_00011d2c(int *param_1,undefined8 *param_2,longlong param_3)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 local_res8 [8];
  undefined8 local_res10 [3];
  
  iVar2 = *param_1;
  if ((*(char *)(param_2 + 0xb) == '\0') && (iVar2 - 1U < 0xff)) {
    *(undefined1 *)(param_2 + 0xb) = 0;
    uVar3 = HalGetInterruptVector(1,0,iVar2,iVar2,local_res8,local_res10);
    param_2[2] = 0;
    iVar4 = IoConnectInterrupt(param_2 + 2,FUN_000122a4,*param_2,0,uVar3,local_res8[0],local_res8[0]
                               ,1,1,local_res10[0],0);
    if (-1 < iVar4) {
      *(int *)(param_2 + 0xd) = iVar2;
      *(char *)((longlong)param_2 + 0x6c) = (char)param_1[7];
      *(undefined1 *)((longlong)param_2 + 0x6f) = *(undefined1 *)((longlong)param_1 + 0x1f);
      *(int *)(param_2 + 0xe) = param_1[8];
      *(int *)((longlong)param_2 + 0x74) = param_1[9];
      *(undefined1 *)((longlong)param_2 + 0x6d) = *(undefined1 *)((longlong)param_1 + 0x1d);
      *(int *)(param_2 + 0xf) = param_1[10];
      uVar1 = *(undefined1 *)((longlong)param_1 + 0x1e);
      *(undefined4 *)((longlong)param_2 + 0x5c) = 0;
      *(undefined1 *)((longlong)param_2 + 0x6e) = uVar1;
      *(undefined4 *)param_2[0x16] = 0;
      param_2[0x10] = 0;
      *(undefined1 *)((longlong)param_2 + 0x6c) = 0;
      *(undefined1 *)(param_2 + 0xb) = 1;
    }
  }
  *(undefined8 *)(param_3 + 0x38) = 0;
  return 0;
}

