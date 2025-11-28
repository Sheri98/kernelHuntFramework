// Function: FUN_140005b74
// Address: 140005b74
// Decompiled by Ghidra


longlong FUN_140005b74(ulonglong param_1)

{
  char cVar1;
  ulonglong uVar2;
  longlong lVar3;
  int local_28;
  undefined1 local_24;
  undefined4 local_20;
  undefined1 local_1c;
  undefined4 local_18;
  undefined1 local_14;
  
  local_28 = 0;
  local_24 = 0xb2;
  local_20 = 1;
  local_1c = 3;
  local_18 = 2;
  local_14 = 0xe8;
  uVar2 = FUN_1400073f0(&local_28,3,param_1,100);
  cVar1 = MmIsAddressValid(uVar2 + 3);
  if (cVar1 == '\0') {
    lVar3 = 0;
  }
  else {
    lVar3 = (longlong)*(int *)(uVar2 + 3) + 7 + uVar2;
  }
  return lVar3;
}

