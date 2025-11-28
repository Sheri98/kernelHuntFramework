// Function: FUN_140005998
// Address: 140005998
// Decompiled by Ghidra


ulonglong FUN_140005998(void)

{
  ulonglong uVar1;
  uint uVar2;
  int *piVar3;
  int local_1f8;
  undefined1 local_1f4;
  undefined4 local_1f0;
  undefined1 local_1ec;
  undefined4 local_1e8;
  undefined1 local_1e4;
  int local_1e0;
  undefined1 local_1dc;
  undefined4 local_1d8;
  undefined1 local_1d4;
  undefined4 local_1d0;
  undefined1 local_1cc;
  undefined4 local_1c8;
  undefined1 local_1c4;
  int local_1c0;
  undefined1 local_1bc;
  undefined4 local_1b8;
  undefined1 local_1b4;
  undefined4 local_1b0;
  undefined1 local_1ac;
  undefined4 local_1a8;
  undefined1 local_1a4;
  int local_1a0;
  undefined1 local_19c;
  undefined4 local_198;
  undefined1 local_194;
  undefined4 local_190;
  undefined1 local_18c;
  undefined4 local_188;
  undefined1 local_184;
  int local_180;
  undefined1 local_17c;
  undefined4 local_178;
  undefined1 local_174;
  undefined4 local_170;
  undefined1 local_16c;
  undefined4 local_168;
  undefined1 local_164;
  int local_160;
  undefined1 local_15c;
  undefined4 local_158;
  undefined1 local_154;
  undefined4 local_150;
  undefined1 local_14c;
  undefined4 local_148;
  undefined1 local_144;
  undefined1 local_140 [24];
  undefined1 local_128 [12];
  uint local_11c;
  
  RtlInitUnicodeString(local_140,L"PsLookupProcessByProcessId");
  uVar1 = MmGetSystemRoutineAddress(local_140);
  piVar3 = (int *)0x0;
  uVar2 = 0;
  if ((uVar1 == 0) ||
     (((DAT_14000a748 - 0x3eU < 2 || (DAT_14000a748 == 100)) &&
      (uVar1 = FUN_140005b74(uVar1), uVar1 == 0)))) {
    return 0;
  }
  local_160 = -4;
  local_15c = 0xd1;
  local_158 = 0xfffffffd;
  local_154 = 0x48;
  local_14c = 0x8b;
  local_150 = 0xfffffffe;
  local_180 = -5;
  local_1a0 = -5;
  local_1e0 = -5;
  local_1c0 = -5;
  local_148 = 0xffffffff;
  local_144 = 0xd;
  local_17c = 0xec;
  local_178 = 0xfffffffd;
  local_174 = 0x48;
  local_170 = 0xfffffffe;
  local_16c = 0x8b;
  local_168 = 0xffffffff;
  local_164 = 5;
  local_19c = 0xec;
  local_198 = 0xfffffffd;
  local_194 = 0x48;
  local_190 = 0xfffffffe;
  local_18c = 0x8b;
  local_188 = 0xffffffff;
  local_184 = 5;
  local_1dc = 0xec;
  local_1d8 = 0xfffffffd;
  local_1d4 = 0x48;
  local_1d0 = 0xfffffffe;
  local_1cc = 0x8b;
  local_1c8 = 0xffffffff;
  local_1c4 = 5;
  local_1bc = 0x24;
  local_1b8 = 0xfffffffd;
  local_1b4 = 0x48;
  local_1b0 = 0xfffffffe;
  local_1ac = 0x8b;
  local_1a8 = 0xffffffff;
  local_1a4 = 5;
  local_1f8 = -3;
  local_1f4 = 0x48;
  local_1f0 = 0xfffffffe;
  local_1ec = 0x8b;
  local_1e8 = 0xffffffff;
  local_1e4 = 5;
  if (DAT_14000a748 == 0x3d) {
    piVar3 = &local_160;
  }
  else if (DAT_14000a748 == 0x3e) {
    piVar3 = &local_180;
  }
  else {
    if (DAT_14000a748 != 0x3f) {
      if (DAT_14000a748 == 100) {
        piVar3 = &local_1e0;
        uVar2 = 4;
        RtlGetVersion(local_128);
        if (local_11c < 0x4a61) {
          if (0x47b9 < local_11c) {
            piVar3 = &local_1c0;
          }
        }
        else {
          piVar3 = &local_1f8;
          uVar2 = 3;
        }
      }
      goto LAB_140005b43;
    }
    piVar3 = &local_1a0;
  }
  uVar2 = 4;
LAB_140005b43:
  uVar1 = FUN_140007484(uVar1,piVar3,uVar2,100);
  return uVar1;
}

