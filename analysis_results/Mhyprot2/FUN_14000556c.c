// Function: FUN_14000556c
// Address: 14000556c
// Decompiled by Ghidra


ulonglong FUN_14000556c(uint param_1)

{
  ulonglong uVar1;
  ulonglong *puVar2;
  code *pcVar3;
  
  if ((DAT_14000a6d0 == 0) && (DAT_14000a6d0 = FUN_140005954(), DAT_14000a6d0 == 0)) {
    return 0;
  }
  puVar2 = (ulonglong *)ExAllocatePool(1);
  pcVar3 = FUN_140005680;
  *puVar2 = (ulonglong)param_1;
  if (DAT_14000a748 != 0x3d) {
    pcVar3 = FUN_140005730;
  }
  ExEnumHandleTable(DAT_14000a6d0,pcVar3,puVar2,0);
  uVar1 = puVar2[1];
  ExFreePoolWithTag(puVar2,0);
  return uVar1;
}

