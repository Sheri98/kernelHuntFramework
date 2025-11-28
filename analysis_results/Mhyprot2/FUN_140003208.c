// Function: FUN_140003208
// Address: 140003208
// Decompiled by Ghidra


void FUN_140003208(char param_1,longlong *param_2)

{
  longlong *plVar1;
  code *pcVar2;
  longlong lVar3;
  longlong *plVar4;
  
  if (param_2 != (longlong *)0x0) {
    plVar4 = (longlong *)*param_2;
    while (plVar4 != param_2) {
      lVar3 = plVar4[9];
      if (lVar3 != 0) {
        if ((param_1 != '\0') && (plVar4[8] != 0)) {
          MmUnmapLockedPages(plVar4[8]);
          lVar3 = plVar4[9];
        }
        if ((char)plVar4[10] != '\0') {
          MmUnlockPages(lVar3);
          lVar3 = plVar4[9];
        }
        IoFreeMdl(lVar3);
      }
      plVar1 = (longlong *)*param_2;
      if (((longlong *)plVar1[1] != param_2) ||
         (lVar3 = *plVar1, *(longlong **)(lVar3 + 8) != plVar1)) {
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)(3);
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      *param_2 = lVar3;
      *(longlong **)(lVar3 + 8) = param_2;
      ExFreePoolWithTag(plVar4,0x4746544d);
      plVar4 = (longlong *)*param_2;
    }
  }
  return;
}

