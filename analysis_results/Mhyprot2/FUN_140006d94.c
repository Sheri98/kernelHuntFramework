// Function: FUN_140006d94
// Address: 140006d94
// Decompiled by Ghidra


char * FUN_140006d94(void)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  undefined1 local_18 [16];
  
  RtlInitUnicodeString(local_18,L"PsRemoveCreateThreadNotifyRoutine");
  pcVar3 = (char *)MmGetSystemRoutineAddress(local_18);
  if (pcVar3 == (char *)0x0) {
    return (char *)0x0;
  }
  if (0x3c < DAT_14000a748) {
    if (DAT_14000a748 < 0x40) {
      pcVar1 = pcVar3 + 0xff;
      for (; pcVar3 < pcVar1; pcVar3 = pcVar3 + 1) {
        if (((((*pcVar3 == 'H') && (pcVar3[1] == -0x73)) && (pcVar3[2] == '\r')) &&
            ((pcVar3[7] == -0x75 && (pcVar3[8] == -0x3a)))) && (pcVar3[9] == 'H'))
        goto LAB_140006e42;
      }
    }
    else if (DAT_14000a748 == 100) {
      pcVar1 = pcVar3 + 0xff;
      for (; pcVar3 < pcVar1; pcVar3 = pcVar3 + 1) {
        if (((*pcVar3 == 'L') && (pcVar3[1] == -0x73)) &&
           ((pcVar3[2] == '%' && ((pcVar3[7] == 'I' && (pcVar3[0xb] == 'H')))))) {
LAB_140006e42:
          pcVar3 = pcVar3 + (*(int *)(pcVar3 + 3) + 7);
          if (pcVar3 == (char *)0x0) {
            return (char *)0x0;
          }
          cVar2 = MmIsAddressValid(pcVar3);
          if (cVar2 == '\0') {
            return (char *)0x0;
          }
          return pcVar3;
        }
      }
    }
  }
  return (char *)0x0;
}

