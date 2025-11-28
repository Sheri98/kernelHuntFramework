// Function: FUN_140003c9c
// Address: 140003c9c
// Decompiled by Ghidra


ulonglong FUN_140003c9c(undefined8 param_1,undefined8 *param_2,int param_3)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  undefined8 local_res20;
  ushort *local_18 [2];
  
  local_res20 = 0;
  local_18[0] = (ushort *)0x0;
  uVar2 = PsReferenceProcessFilePointer(param_1,&local_res20);
  if ((-1 < (int)uVar2) && (uVar2 = IoQueryFileDosDeviceName(local_res20,local_18), -1 < (int)uVar2)
     ) {
    uVar1 = (uint)*local_18[0];
    if (param_3 - 1U < (uint)*local_18[0]) {
      uVar1 = param_3 - 1U;
    }
    puVar3 = FUN_1400075c0(param_2,*(undefined8 **)(local_18[0] + 4),(ulonglong)uVar1);
    return CONCAT71((int7)((ulonglong)puVar3 >> 8),1);
  }
  return uVar2 & 0xffffffffffffff00;
}

