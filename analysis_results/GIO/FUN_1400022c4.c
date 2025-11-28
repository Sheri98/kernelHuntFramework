// Function: FUN_1400022c4
// Address: 1400022c4
// Decompiled by Ghidra


void FUN_1400022c4(longlong param_1)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined1 local_18 [16];
  
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 8) + 0x40);
  while (puVar2 = *(undefined8 **)(lVar1 + 0x18), puVar2 != (undefined8 *)0x0) {
    *(undefined8 *)(lVar1 + 0x18) = *puVar2;
    MmUnmapLockedPages(puVar2[3],puVar2[1]);
    IoFreeMdl(puVar2[1]);
    MmUnmapIoSpace(puVar2[2],*(undefined4 *)(puVar2 + 4));
    ExFreePoolWithTag(puVar2,0);
  }
  RtlInitUnicodeString(local_18,L"\\DosDevices\\GIO");
  IoDeleteSymbolicLink(local_18);
  IoDeleteDevice(*(undefined8 *)(lVar1 + 0x10));
  return;
}

