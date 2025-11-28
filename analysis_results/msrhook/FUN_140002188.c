// Function: FUN_140002188
// Address: 140002188
// Decompiled by Ghidra


undefined8 FUN_140002188(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined1 local_28 [32];
  
  KeInitializeEvent(local_28,0,0);
  if (*(char *)(param_2 + 0x43) == '\x01') {
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000010;
    IofCompleteRequest(param_2,0);
    uVar4 = 0xc0000010;
  }
  else {
    DAT_140005118 = DAT_140005118 + 1;
    puVar1 = *(undefined8 **)(param_2 + 0xb8);
    lVar2 = *(longlong *)(param_1 + 0x40);
    puVar1[-9] = *puVar1;
    puVar1[-8] = puVar1[1];
    puVar1[-7] = puVar1[2];
    puVar1[-6] = puVar1[3];
    *(undefined4 *)(puVar1 + -5) = *(undefined4 *)(puVar1 + 4);
    *(undefined4 *)((longlong)puVar1 + -0x24) = *(undefined4 *)((longlong)puVar1 + 0x24);
    *(undefined4 *)(puVar1 + -4) = *(undefined4 *)(puVar1 + 5);
    *(undefined4 *)((longlong)puVar1 + -0x1c) = *(undefined4 *)((longlong)puVar1 + 0x2c);
    puVar1[-3] = puVar1[6];
    *(undefined1 *)((longlong)puVar1 + -0x45) = 0;
    lVar3 = *(longlong *)(param_2 + 0xb8);
    *(code **)(lVar3 + -0x10) = FUN_1400023b8;
    *(longlong *)(lVar3 + -8) = param_1;
    *(undefined1 *)(lVar3 + -0x45) = 0xe0;
    uVar4 = IofCallDriver(*(undefined8 *)(lVar2 + 0x38),param_2);
  }
  return uVar4;
}

