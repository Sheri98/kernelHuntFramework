// Function: FUN_140006974
// Address: 140006974
// Decompiled by Ghidra


bool FUN_140006974(void)

{
  undefined4 local_res8;
  
  local_res8 = 0;
  LOCK();
  if (DAT_14000a010 == 0) {
    local_res8 = -1;
  }
  UNLOCK();
  return local_res8 != -1;
}

