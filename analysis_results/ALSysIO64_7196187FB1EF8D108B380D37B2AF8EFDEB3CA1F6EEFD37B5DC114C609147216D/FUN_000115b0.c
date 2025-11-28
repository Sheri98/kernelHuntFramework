// Function: FUN_000115b0
// Address: 000115b0
// Decompiled by Ghidra


undefined8
FUN_000115b0(undefined8 param_1,undefined4 *param_2,undefined8 param_3,undefined4 *param_4,
            undefined8 param_5,undefined4 *param_6)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar1 = *param_2;
  DbgPrint("io 22");
  uVar2 = rdmsr(uVar1);
  *param_4 = (int)((ulonglong)uVar2 >> 0x20);
  param_4[1] = (int)uVar2;
  *param_6 = 8;
  return 0;
}

