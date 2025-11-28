// Function: FUN_00013250
// Address: 00013250
// Decompiled by Ghidra


void FUN_00013250(undefined8 param_1)

{
  undefined8 uVar1;
  char *pcVar2;
  undefined1 auStack_5a8 [32];
  char local_588 [40];
  undefined1 local_560 [44];
  longlong local_534;
  undefined1 local_528 [76];
  undefined4 local_4dc;
  undefined1 local_428 [4];
  uint local_424;
  byte local_418;
  ulonglong local_18;
  
  local_18 = DAT_00015100 ^ (ulonglong)auStack_5a8;
  uVar1 = FUN_00012c00(param_1,local_588,0x24);
  if ((int)uVar1 == 0) {
    pcVar2 = strstr(local_588,"FACP");
    if (pcVar2 == local_588) {
      uVar1 = FUN_00012c00(param_1,local_528,0xf4);
      if ((int)uVar1 == 0) {
        DAT_00015140 = local_4dc;
        DAT_00015180 = local_4dc;
        DAT_00015190 = DAT_00014114;
      }
    }
    else {
      pcVar2 = strstr(local_588,"HPET");
      if ((((pcVar2 == local_588) && (uVar1 = FUN_00012c00(param_1,local_560,0x38), (int)uVar1 == 0)
           ) && (local_534 != 0)) &&
         ((uVar1 = FUN_00012c00(local_534,local_428,0x402), (int)uVar1 == 0 &&
          ((local_418 & 1) != 0)))) {
        DAT_00015188 = local_534;
        DAT_00015190 = DAT_00014110 / (float)local_424;
      }
    }
  }
  FUN_000133b0(local_18 ^ (ulonglong)auStack_5a8);
  return;
}

