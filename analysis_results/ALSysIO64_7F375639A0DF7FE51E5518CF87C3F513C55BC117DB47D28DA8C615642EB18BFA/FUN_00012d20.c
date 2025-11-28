// Function: FUN_00012d20
// Address: 00012d20
// Decompiled by Ghidra


void FUN_00012d20(void)

{
  undefined8 uVar1;
  undefined1 auStackY_468 [32];
  undefined4 in_stack_fffffffffffffbbc;
  undefined4 local_438;
  undefined4 local_434 [3];
  undefined1 local_428 [242];
  undefined8 local_336;
  ulonglong local_18;
  
  local_18 = DAT_00015100 ^ (ulonglong)auStackY_468;
  if (DAT_00015110 != 0) {
    FUN_00013040();
  }
  DAT_00015110 = 0;
  if (DAT_00015188 == 0) {
    if (DAT_00015180 != 0) {
      FUN_000116b0(0,&DAT_00015180,4,&local_438,CONCAT44(in_stack_fffffffffffffbbc,4),local_434);
      DbgPrint("ReadTimerValue, PM = 0x%08I64X.\n",local_438);
    }
  }
  else {
    uVar1 = FUN_00012c00(DAT_00015188,local_428,0x402);
    if ((int)uVar1 == 0) {
      DbgPrint("ReadTimerValue, HPET = 0x%08I64X.\n",local_336);
    }
  }
  FUN_000133b0(local_18 ^ (ulonglong)auStackY_468);
  return;
}

