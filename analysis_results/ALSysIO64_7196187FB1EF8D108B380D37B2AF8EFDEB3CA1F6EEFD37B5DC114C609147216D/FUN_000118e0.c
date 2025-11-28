// Function: FUN_000118e0
// Address: 000118e0
// Decompiled by Ghidra


undefined8
FUN_000118e0(undefined8 param_1,undefined4 *param_2,undefined8 param_3,int *param_4,
            undefined8 param_5,undefined4 *param_6)

{
  undefined4 uVar1;
  char cVar2;
  
  uVar1 = *param_2;
  DbgPrint("io 266");
  cVar2 = in((short)uVar1);
  *param_4 = (int)cVar2;
  *param_6 = 4;
  return 0;
}

