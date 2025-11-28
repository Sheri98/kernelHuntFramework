// Function: FUN_1400013dc
// Address: 1400013dc
// Decompiled by Ghidra


undefined4 FUN_1400013dc(undefined8 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 5);
  if (iVar2 == 0) {
    uVar1 = FUN_140001510((longlong)param_1);
  }
  else if (iVar2 == 1) {
    uVar1 = FUN_140001440((longlong)param_1);
  }
  else {
    if (iVar2 == 2) {
      iVar2 = 1;
    }
    else {
      if (iVar2 != 3) {
        if (iVar2 == 4) {
          uVar1 = FUN_140001a2c(param_1);
          return uVar1;
        }
        DbgPrintEx(0,0,"ReadMemOutputClient ERROR...........");
        return 0;
      }
      iVar2 = 0;
    }
    uVar1 = FUN_1400016b0((longlong)param_1,iVar2);
  }
  return uVar1;
}

