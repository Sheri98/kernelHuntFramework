// Function: FUN_00012e30
// Address: 00012e30
// Decompiled by Ghidra


ulonglong FUN_00012e30(void)

{
  ulonglong local_res8;
  
  DbgPrint("misc 117");
  local_res8 = rdmsr(0x1b);
  local_res8 = local_res8 & 0xfffffffff000;
  return local_res8;
}

