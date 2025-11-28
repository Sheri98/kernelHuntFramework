// Function: FUN_1400016c4
// Address: 1400016c4
// Decompiled by Ghidra


undefined8 FUN_1400016c4(longlong param_1,longlong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  uint uVar3;
  undefined8 local_res10 [3];
  
  if (4 < *(uint *)(param_2 + 0x10)) {
    lVar1 = *(longlong *)(param_1 + 0x18);
    uVar3 = (uint)*(byte *)(lVar1 + 3) * 0x100 + (uint)*(byte *)(lVar1 + 2);
    if (uVar3 != 0) {
      DAT_1400050ec = 1;
      FUN_140002e00((undefined8 *)&DAT_1400061c0,(undefined8 *)(lVar1 + 4),(ulonglong)uVar3);
      local_res10[0] = 0xfffffffffffcf2c0;
      DAT_1400050e8 = uVar3;
      KeDelayExecutionThread(0,0,local_res10);
      uVar2 = FUN_140002cf0();
      *(ulonglong *)(param_1 + 0x38) = uVar2 & 0xffffffff;
      local_res10[0] = 0xfffffffffffcf2c0;
      KeDelayExecutionThread(0,0,local_res10);
      DAT_1400050ec = 0;
      return 0;
    }
  }
  return 0xc000000d;
}

