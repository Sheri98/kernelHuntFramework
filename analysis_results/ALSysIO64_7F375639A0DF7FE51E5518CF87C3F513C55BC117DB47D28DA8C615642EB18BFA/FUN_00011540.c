// Function: FUN_00011540
// Address: 00011540
// Decompiled by Ghidra


void FUN_00011540(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined1 local_18 [16];
  
  plVar1 = *(longlong **)(*(longlong *)(param_1 + 8) + 0x40);
  RtlInitUnicodeString(local_18,L"\\DosDevices\\ALSysIO");
  IoDeleteSymbolicLink(local_18);
  lVar3 = 0x10;
  plVar2 = plVar1;
  do {
    plVar2 = plVar2 + 7;
    if (*plVar2 != 0) {
      ZwClose();
      *plVar2 = 0;
    }
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  IoDeleteDevice(plVar1[1]);
  return;
}

