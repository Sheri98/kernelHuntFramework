// Function: FUN_00011030
// Address: 00011030
// Decompiled by Ghidra


void FUN_00011030(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  undefined1 local_18 [16];
  
  plVar4 = (longlong *)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x40) + 0x28);
  while (plVar3 = (longlong *)*plVar4, plVar3 != plVar4) {
    lVar1 = *plVar3;
    plVar2 = (longlong *)plVar3[1];
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    ExFreePoolWithTag(plVar3 + -3,0);
  }
  RtlInitUnicodeString(local_18,L"\\DosDevices\\AsrOmgDrv");
  IoDeleteSymbolicLink(local_18);
  IoDeleteDevice(*(undefined8 *)(param_1 + 8));
  return;
}

