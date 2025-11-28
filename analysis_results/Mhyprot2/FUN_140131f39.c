// Function: FUN_140131f39
// Address: 140131f39
// Decompiled by Ghidra


/* WARNING: Removing unreachable block (ram,0x000140131f79) */

bool FUN_140131f39(void)

{
  char cStack0000000000000030;
  undefined4 uStack0000000000000038;
  
  uStack0000000000000038 = 0;
  _cStack0000000000000030 = 0;
  NtQuerySystemInformation(0x23,&stack0x00000030,2,&stack0x00000038);
  return cStack0000000000000030 != '\x01';
}

