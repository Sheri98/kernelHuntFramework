// Function: FUN_0001047c
// Address: 0001047c
// Decompiled by Ghidra


void FUN_0001047c(longlong param_1)

{
  short sVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined2 *puVar4;
  undefined1 local_18 [16];
  
  uVar2 = *(undefined8 *)(param_1 + 8);
  lVar3 = 0;
  puVar4 = &DAT_00010800;
  do {
    sVar1 = *(short *)((longlong)L"\\DosDevices\\" + lVar3);
    *(short *)((longlong)&DAT_00010800 + lVar3) = sVar1;
    lVar3 = lVar3 + 2;
  } while (sVar1 != 0);
  FUN_000103ac(&DAT_00010800,(short *)&DAT_00010980);
  RtlInitUnicodeString(local_18,puVar4);
  IoDeleteSymbolicLink(local_18);
  IoDeleteDevice(uVar2);
  return;
}

