// Function: FUN_140006cb8
// Address: 140006cb8
// Decompiled by Ghidra


char * FUN_140006cb8(void)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  
  pcVar3 = FUN_140006e6c();
  if (pcVar3 == (char *)0x0) {
    return (char *)0x0;
  }
  if (DAT_14000a748 == 0x3d) {
    pcVar1 = pcVar3 + 0xff;
    for (; pcVar3 < pcVar1; pcVar3 = pcVar3 + 1) {
      if ((((*pcVar3 == 'L') && (pcVar3[1] == -0x73)) && (pcVar3[7] == 'A')) && (pcVar3[10] == 'M'))
      goto LAB_140006d6a;
    }
  }
  else if (0x3d < DAT_14000a748) {
    if (DAT_14000a748 < 0x40) {
      pcVar1 = pcVar3 + 0xff;
      for (; pcVar3 < pcVar1; pcVar3 = pcVar3 + 1) {
        if (((*pcVar3 == 'L') && (pcVar3[1] == -0x73)) &&
           ((pcVar3[7] == -0x75 && (pcVar3[9] == 'E')))) goto LAB_140006d6a;
      }
    }
    else if (DAT_14000a748 == 100) {
      pcVar1 = pcVar3 + 0xff;
      for (; pcVar3 < pcVar1; pcVar3 = pcVar3 + 1) {
        if (((*pcVar3 == 'L') && (pcVar3[1] == -0x73)) && ((pcVar3[2] == '%' && (pcVar3[7] == 'I')))
           ) {
LAB_140006d6a:
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

