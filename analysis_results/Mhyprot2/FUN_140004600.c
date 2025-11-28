// Function: FUN_140004600
// Address: 140004600
// Decompiled by Ghidra


void FUN_140004600(undefined4 param_1,undefined4 param_2,char param_3)

{
  char cVar1;
  bool bVar2;
  
  cVar1 = FUN_14000141c();
  if (cVar1 == '\0') {
    FUN_1400036b0(DAT_14000a688);
  }
  if ((((param_3 != '\0') && (DAT_14000a3a8 != 0)) && (DAT_14000a3b8 != (undefined8 *)0x0)) &&
     (DAT_14000a3b0 != 0)) {
    bVar2 = FUN_140006974();
    if (bVar2) {
      KeWaitForSingleObject(&DAT_14000a5d0,0,0,0,0);
      KeClearEvent(&DAT_14000a5d0);
      DAT_14000a5e8._0_4_ = param_1;
      DAT_14000a5e8._4_4_ = param_2;
      *DAT_14000a3b8 = CONCAT44(param_2,param_1);
      KeSetEvent(DAT_14000a3b0,0,0);
      KeSetEvent(&DAT_14000a5d0,0,0);
    }
  }
  return;
}

