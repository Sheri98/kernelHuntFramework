// Function: FUN_140002b90
// Address: 140002b90
// Decompiled by Ghidra


void FUN_140002b90(void)

{
  undefined8 local_res10 [3];
  
  do {
    if (DAT_1400050c0 == 0) {
LAB_140002c14:
      FUN_14000289c();
      PsTerminateSystemThread(0);
      return;
    }
    local_res10[0] = 0xfffffffffff0bdc0;
    KeDelayExecutionThread(0,0,local_res10);
    if (9 < DAT_140005114) {
LAB_140002c0d:
      FUN_1400029c0(1);
      goto LAB_140002c14;
    }
    LOCK();
    DAT_140005114 = DAT_140005114 + 1;
    UNLOCK();
    if ((DAT_14000510c - 1U & 0xfffffffd) != 0) {
      FUN_140002930(0);
      goto LAB_140002c0d;
    }
    if (DAT_1400050e7 == '\0') {
      if (DAT_140005110 - 1U < 2) {
        LOCK();
        DAT_140005110 = DAT_140005110 + 1;
        UNLOCK();
      }
      else {
        FUN_1400029f0(0);
        FUN_140002a20('\x01');
      }
    }
  } while( true );
}

