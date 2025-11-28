// Function: FUN_140006994
// Address: 140006994
// Decompiled by Ghidra


bool FUN_140006994(void)

{
  undefined4 local_res8;
  
  local_res8 = 1;
  LOCK();
  if (DAT_14000a6ec == 1) {
    local_res8 = -1;
  }
  UNLOCK();
  return local_res8 == -1;
}

