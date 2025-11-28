// Function: FUN_00011ea0
// Address: 00011ea0
// Decompiled by Ghidra


void FUN_00011ea0(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined1 local_18 [24];
  
  plVar1 = *(longlong **)(*(longlong *)(param_1 + 8) + 0x40);
  RtlInitUnicodeString(local_18,L"\\DosDevices\\CrystalSysInfo");
  IoDeleteSymbolicLink(local_18);
  lVar4 = 0x10;
  plVar2 = plVar1;
  do {
    plVar3 = plVar2 + 7;
    if (plVar2[2] != 0) {
      IoDisconnectInterrupt();
      plVar2[2] = 0;
    }
    if (*plVar3 != 0) {
      ZwClose();
      *plVar3 = 0;
    }
    lVar4 = lVar4 + -1;
    plVar2 = plVar3;
  } while (lVar4 != 0);
  IoDeleteDevice(plVar1[1]);
  return;
}

