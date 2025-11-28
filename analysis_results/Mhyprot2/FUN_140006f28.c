// Function: FUN_140006f28
// Address: 140006f28
// Decompiled by Ghidra


char * FUN_140006f28(void)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  undefined1 local_18 [16];
  
  RtlInitUnicodeString(local_18,L"PsRemoveLoadImageNotifyRoutine");
  pcVar2 = (char *)MmGetSystemRoutineAddress(local_18);
  if (pcVar2 != (char *)0x0) {
    if (0x3c < DAT_14000a748) {
      if (DAT_14000a748 < 0x40) {
        pcVar3 = pcVar2 + 0xff;
        for (; pcVar2 < pcVar3; pcVar2 = pcVar2 + 1) {
          if ((((*pcVar2 == 'H') && (pcVar2[1] == -0x73)) && (pcVar2[2] == '\r')) &&
             ((pcVar2[7] == -0x75 && (pcVar2[8] == -0x3a)))) {
            pcVar3 = pcVar2 + (*(int *)(pcVar2 + 3) + 7);
            goto LAB_140006fef;
          }
        }
      }
      else if (DAT_14000a748 == 100) {
        pcVar3 = pcVar2 + 0xc;
LAB_140006f7f:
        if (pcVar3 < pcVar2 + 0xff) {
          if (((pcVar3[-2] != '3') || (pcVar3[1] != -0x73)) ||
             ((pcVar3[-9] != 'D' || ((pcVar3[-10] != 'f' || (pcVar3[0xb] != 'H'))))))
          goto LAB_140006fa2;
          pcVar3 = pcVar3 + (*(int *)(pcVar3 + 3) + 7);
LAB_140006fef:
          if ((pcVar3 != (char *)0x0) && (cVar1 = MmIsAddressValid(pcVar3), cVar1 != '\0')) {
            return pcVar3;
          }
        }
      }
    }
    pcVar2 = (char *)0x0;
  }
  return pcVar2;
LAB_140006fa2:
  pcVar3 = pcVar3 + 1;
  goto LAB_140006f7f;
}

