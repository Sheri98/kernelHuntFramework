// Function: FUN_14000700c
// Address: 14000700c
// Decompiled by Ghidra


char * FUN_14000700c(void)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  undefined1 local_18 [16];
  
  RtlInitUnicodeString(local_18,L"PsSetLoadImageNotifyRoutine");
  pcVar3 = (char *)MmGetSystemRoutineAddress(local_18);
  if (pcVar3 != (char *)0x0) {
    if ((DAT_14000a748 - 0x3dU < 3) || (DAT_14000a748 == 100)) {
      pcVar1 = pcVar3 + 0xff;
      for (; pcVar3 < pcVar1; pcVar3 = pcVar3 + 1) {
        if ((((*pcVar3 == -0x75) && (pcVar3[1] == '\x05')) && (pcVar3[6] == -0x58)) &&
           ((pcVar3[7] == '\x01' && (pcVar3[8] == 'u')))) {
          pcVar3 = pcVar3 + (*(int *)(pcVar3 + 2) + 6);
          if ((pcVar3 != (char *)0x0) && (cVar2 = MmIsAddressValid(pcVar3), cVar2 != '\0')) {
            return pcVar3;
          }
          break;
        }
      }
    }
    pcVar3 = (char *)0x0;
  }
  return pcVar3;
}

