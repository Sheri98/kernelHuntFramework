// Function: FUN_140001788
// Address: 140001788
// Decompiled by Ghidra


undefined8 FUN_140001788(undefined8 param_1,longlong param_2)

{
  int iVar1;
  longlong *plVar2;
  longlong lVar3;
  
  plVar2 = *(longlong **)(param_2 + 0x18);
  *(undefined8 *)(param_2 + 0x38) = 0;
  iVar1 = (int)*plVar2;
  DbgPrint("Allocate Size=%d",iVar1);
  lVar3 = FUN_1400028d8(iVar1,plVar2);
  if ((char)lVar3 != '\0') {
    *(undefined8 *)(param_2 + 0x38) = 8;
  }
  return 0;
}

