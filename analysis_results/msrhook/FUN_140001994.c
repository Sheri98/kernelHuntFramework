// Function: FUN_140001994
// Address: 140001994
// Decompiled by Ghidra


void FUN_140001994(void)

{
  undefined1 local_18 [24];
  
  DAT_1400050e0 = DAT_1400050e0 + -1;
  if ((DAT_1400050e0 == 0) && (DAT_1400075c0 != 0)) {
    RtlInitUnicodeString(local_18,L"\\??\\msrhookctrls");
    IoDeleteSymbolicLink(local_18);
    IoDeleteDevice(DAT_1400075c0);
    DAT_1400075c0 = 0;
  }
  return;
}

