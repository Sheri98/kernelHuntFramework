// Function: FUN_00012b90
// Address: 00012b90
// Decompiled by Ghidra


ulonglong FUN_00012b90(void)

{
  undefined8 local_res8;
  
  local_res8 = rdmsr(0x1b);
  local_res8 = local_res8 & 0xfffffffff000;
  return local_res8;
}

