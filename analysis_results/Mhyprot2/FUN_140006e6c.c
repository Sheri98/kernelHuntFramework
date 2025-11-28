// Function: FUN_140006e6c
// Address: 140006e6c
// Decompiled by Ghidra


char * FUN_140006e6c(void)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  longlong lVar4;
  uint local_res8;
  undefined1 local_18 [16];
  
  RtlInitUnicodeString(local_18,L"PsSetCreateProcessNotifyRoutine");
  pcVar3 = (char *)MmGetSystemRoutineAddress(local_18);
  if (pcVar3 == (char *)0x0) {
    return (char *)0x0;
  }
  if (DAT_14000a748 == 0x3d) {
LAB_140006ef8:
    if (pcVar3[3] != -0x17) {
      return (char *)0x0;
    }
    pcVar3 = pcVar3 + (longlong)*(int *)(pcVar3 + 4) + 8;
  }
  else {
    if (DAT_14000a748 == 0x3e) {
      if (pcVar3[3] != -0x15) {
        return (char *)0x0;
      }
      local_res8 = (uint)(byte)pcVar3[1];
      lVar4 = (longlong)(int)local_res8 + 5;
    }
    else {
      if (DAT_14000a748 == 0x3f) goto LAB_140006ef8;
      if (DAT_14000a748 != 100) {
        return (char *)0x0;
      }
      pcVar1 = pcVar3 + 0x20;
      while( true ) {
        if (pcVar1 <= pcVar3) {
          return (char *)0x0;
        }
        if ((*pcVar3 == -0x17) && (pcVar3[5] == -0x34)) break;
        pcVar3 = pcVar3 + 1;
      }
      lVar4 = (longlong)(*(int *)(pcVar3 + 1) + 1);
    }
    pcVar3 = pcVar3 + lVar4;
  }
  if ((pcVar3 != (char *)0x0) && (cVar2 = MmIsAddressValid(pcVar3), cVar2 != '\0')) {
    return pcVar3;
  }
  return (char *)0x0;
}

