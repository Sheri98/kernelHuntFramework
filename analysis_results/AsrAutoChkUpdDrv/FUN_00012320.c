// Function: FUN_00012320
// Address: 00012320
// Decompiled by Ghidra


undefined8 FUN_00012320(undefined8 param_1,longlong param_2,longlong param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  
  if ((*(longlong *)(param_2 + 0x18) == 0) || ((*(byte *)(param_2 + 0x10) & 0x20) == 0)) {
    plVar2 = *(longlong **)(param_2 + 8);
    if (*(longlong **)(param_2 + 8) != (longlong *)0x0) {
      do {
        plVar1 = (longlong *)*plVar2;
        MmUnlockPages(plVar2);
        IoFreeMdl(plVar2);
        plVar2 = plVar1;
      } while (plVar1 != (longlong *)0x0);
      *(undefined8 *)(param_2 + 8) = 0;
    }
  }
  else {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x18),0);
  }
  *(undefined4 *)(param_3 + 0x30) = *(undefined4 *)(param_2 + 0x30);
  if (*(int *)(param_2 + 0x30) < 0) {
    *(undefined8 *)(param_3 + 0x38) = 0;
    *(undefined4 *)(param_3 + 0x30) = 0xc0000001;
  }
  IofCompleteRequest(param_3,0);
  IoFreeIrp(param_2);
  return 0xc0000016;
}

