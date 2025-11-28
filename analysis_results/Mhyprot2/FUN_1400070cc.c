// Function: FUN_1400070cc
// Address: 1400070cc
// Decompiled by Ghidra


bool FUN_1400070cc(void)

{
  longlong lVar1;
  longlong local_res8 [4];
  undefined1 local_128 [12];
  uint local_11c;
  
  if (DAT_14000a748 == 0x3d) {
    DAT_14000a700 = 0x180;
    DAT_14000a708 = 0x168;
    DAT_14000a710 = 0x1f0;
    DAT_14000a720 = 0x200;
    DAT_14000a718 = 0x268;
    DAT_14000a728 = 0x368;
    DAT_14000a730 = 0x418;
    DAT_14000a738 = 0x450;
    DAT_14000a740 = 0x2e0;
    goto LAB_140007301;
  }
  if (DAT_14000a748 == 0x3e) {
    DAT_14000a730 = 0x3f0;
    DAT_14000a738 = 0x42c;
  }
  else {
    if (DAT_14000a748 != 0x3f) {
      if (DAT_14000a748 == 100) {
        RtlGetVersion(local_128);
        if (local_11c < 0x4a61) {
          DAT_14000a710 = 0x420;
          DAT_14000a720 = 0x418;
          if (local_11c < 0x47ba) {
            DAT_14000a718 = 0x3b8;
            DAT_14000a740 = 0x388;
            if (local_11c < 0x3ad7) {
              DAT_14000a700 = 0x2e8;
              DAT_14000a730 = 0x688;
              DAT_14000a738 = 0x6c0;
            }
            else {
              DAT_14000a700 = 0x2e0;
              DAT_14000a708 = 0x308;
              DAT_14000a730 = 0x690;
              DAT_14000a738 = 0x6d0;
            }
            goto LAB_140007301;
          }
          DAT_14000a700 = 0x2e8;
          DAT_14000a718 = 0x3c0;
          DAT_14000a708 = 0x310;
          DAT_14000a730 = 0x6a0;
          DAT_14000a738 = 0x6e0;
        }
        else {
          DAT_14000a730 = 0;
          DAT_14000a700 = 0x440;
          DAT_14000a710 = 0x578;
          DAT_14000a718 = 0x518;
          DAT_14000a720 = 0x570;
          DAT_14000a708 = 0x468;
          DAT_14000a738 = 0x510;
        }
        DAT_14000a740 = 0x390;
      }
      goto LAB_140007301;
    }
    DAT_14000a730 = 0x678;
    DAT_14000a738 = 0x6b4;
  }
  DAT_14000a718 = 0x3a8;
  DAT_14000a720 = 0x408;
  DAT_14000a710 = 0x410;
  DAT_14000a700 = 0x2e0;
  DAT_14000a740 = 0x300;
LAB_140007301:
  local_res8[0] = 0;
  PsLookupProcessByProcessId(4,local_res8);
  lVar1 = FUN_140003d08(local_res8[0]);
  return lVar1 == 4;
}

