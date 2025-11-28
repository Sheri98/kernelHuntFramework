// Function: FUN_140003bfc
// Address: 140003bfc
// Decompiled by Ghidra


ulonglong FUN_140003bfc(undefined4 param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4
                       )

{
  undefined1 uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  longlong local_res20;
  
  local_res20 = 0;
  uVar2 = PsLookupProcessByProcessId(param_1,&local_res20,param_3,param_4,0);
  if (local_res20 == 0) {
    uVar2 = uVar2 & 0xffffffffffffff00;
  }
  else {
    uVar3 = FUN_140003c9c(local_res20,param_2,(int)param_3);
    uVar1 = (undefined1)uVar3;
    if ((local_res20 != 0) && (-1 < (int)uVar2)) {
      uVar3 = ObfDereferenceObject();
    }
    uVar2 = CONCAT71((int7)((ulonglong)uVar3 >> 8),uVar1);
  }
  return uVar2;
}

