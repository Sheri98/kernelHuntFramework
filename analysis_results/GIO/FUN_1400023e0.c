// Function: FUN_1400023e0
// Address: 1400023e0
// Decompiled by Ghidra


undefined8 FUN_1400023e0(undefined8 param_1,longlong param_2,longlong param_3)

{
  short *psVar1;
  undefined1 uVar2;
  
  DbgPrint("Entry IoctlSMBUSCmd");
  if ((*(int *)(param_3 + 0x10) != 0xc) || (*(int *)(param_3 + 8) != 1)) {
    DbgPrint("Size check error!!");
    return 0xc000000d;
  }
  psVar1 = *(short **)(param_2 + 0x18);
  DbgPrint("ptr[0]=0x%x,ptr[1]=0x%x,ptr[2]=0x%x,ptr[3]=0x%x,ptr[4]=0x%x,ptr[5]=0x%x",*psVar1,
           psVar1[1],psVar1[2],psVar1[3],psVar1[4]);
  if (*psVar1 == 0) {
    uVar2 = FUN_140002c68(psVar1[1],(char)psVar1[2],(char)psVar1[3],psVar1[4],psVar1[5]);
  }
  else {
    if (*psVar1 != 1) goto LAB_140002497;
    uVar2 = FUN_140002d64(psVar1[1],(char)psVar1[2],(char)psVar1[3],psVar1[4],psVar1[5]);
  }
  *(undefined1 *)psVar1 = uVar2;
LAB_140002497:
  DbgPrint("Ret Value=0x%x",(char)*psVar1);
  *(undefined8 *)(param_2 + 0x38) = 1;
  return 0;
}

