// Function: FUN_140004480
// Address: 140004480
// Decompiled by Ghidra


void FUN_140004480(undefined8 param_1,undefined4 param_2,longlong param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  if ((((DAT_14000a120 != 0) && (DAT_14000a130 != 0)) && (DAT_14000a128 != 0)) && (param_3 != 0)) {
    KeWaitForSingleObject(&DAT_14000a138,0,0,0,0);
    KeClearEvent(&DAT_14000a138);
    puVar1 = (undefined8 *)FUN_140003468(*(undefined8 *)(param_3 + 0x10));
    uVar2 = FUN_140004c70(param_2,*(undefined4 *)(param_3 + 0x10),puVar1,
                          *(ushort **)(param_3 + 0x30));
    if ((char)uVar2 == '\0') {
      *(undefined4 *)(param_3 + 0x40) = 0xc0000001;
    }
    KeSetEvent(&DAT_14000a138,0,0);
  }
  return;
}

