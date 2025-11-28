// Function: FUN_00011040
// Address: 00011040
// Decompiled by Ghidra


undefined8 FUN_00011040(undefined8 param_1,longlong param_2,longlong param_3)

{
  uint uVar1;
  undefined8 *puVar2;
  char cVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  undefined4 local_res18 [2];
  undefined4 local_28;
  undefined4 uStack_24;
  
  local_res18[0] = 0;
  if (*(uint *)(param_3 + 0x10) < 0x10) {
    return 0xc0000023;
  }
  puVar2 = *(undefined8 **)(param_2 + 0x18);
  uVar1 = *(uint *)(puVar2 + 1);
  uVar5 = (ulonglong)uVar1;
  if (uVar1 == 0) {
    return 0xc000000d;
  }
  if (*(uint *)(param_3 + 8) < uVar1) {
    return 0xc0000023;
  }
  local_28 = *(undefined4 *)puVar2;
  uStack_24 = (undefined4)((ulonglong)*puVar2 >> 0x20);
  cVar3 = HalTranslateBusAddress(1,0,CONCAT44(uStack_24,local_28),local_res18,&local_28);
  if (cVar3 == '\0') {
    return 0x107;
  }
  puVar4 = (undefined8 *)MmMapIoSpace(CONCAT44(uStack_24,local_28),uVar5,0);
  FUN_000115a0(puVar2,puVar4,uVar5);
  MmUnmapIoSpace(puVar4,uVar5);
  *(ulonglong *)(param_2 + 0x38) = uVar5;
  return 0;
}

